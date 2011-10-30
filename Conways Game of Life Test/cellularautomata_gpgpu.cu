#include "cellularautomata_kernal.h"

#include <vector_types.h>
#include <cstdio>

//extern "C" bool
extern "C" float CUDATimeStep(int* pFlatGrid, int DIM) {

	int *dev_pFlatGrid; //Pointers to device allocated memory
	int *dev_DIM;

	cudaEvent_t start,stop; //Events for timings

	//START: Record duration of GPGPU processing
	cudaEventCreate(&start);
	cudaEventCreate(&stop);

	cudaEventRecord(start,0);

	size_t noCells = DIM * DIM * sizeof(int);
	//Might need to flatten the 2d array ormaybe try "int2" type
	
	//Allocate suitable size memory on device
	cudaMalloc((void**) &dev_pFlatGrid, noCells);
	cudaMalloc((void**) &dev_DIM, sizeof(int));

	//Make our 2D grid of blocks & threads (DIM/No of threads)
	dim3 blocks (DIM/10, DIM/10);
	dim3 threads(10,10);
	
	//Copy our memory from Host to Device
	cudaMemcpy(dev_pFlatGrid, pFlatGrid, noCells,
		cudaMemcpyHostToDevice);
	cudaMemcpy(dev_DIM, &DIM, sizeof(int),
		cudaMemcpyHostToDevice);

	//Probably really bad way to do this....look into const mem
	//cudaMemcpy(dev_DIM, pDim, sizeof(int),
	//	cudaMemcpyHostToDevice);

	kernal<<<blocks,threads>>>(dev_pFlatGrid, dev_DIM);

	//Copy back to host
	cudaMemcpy(pFlatGrid, dev_pFlatGrid, noCells,
		cudaMemcpyDeviceToHost);

	//STOP : processing done
	cudaEventRecord(stop,0);
	cudaEventSynchronize(stop);

	float elapsedTime = 0;
	cudaEventElapsedTime(&elapsedTime, start, stop);

	
	cudaEventDestroy(start);
	cudaEventDestroy(stop);

	//fix up states - normalize
	for (int i = 0; i < DIM; ++i) {
		for (int j = 0; j < DIM; ++j) {
				pFlatGrid[i * DIM +j] = pFlatGrid[i * DIM +j] >> 1;
		}
	}

	//Free memory on Device
	cudaFree(dev_pFlatGrid);
	cudaFree(dev_DIM);

	return elapsedTime;
}
