#include "cellularautomata_kernal.h"

__global__ void kernal(int* g_data, int* DIM) {
	int x = threadIdx.x + blockIdx.x * blockDim.x;
    int y = threadIdx.y + blockIdx.y * blockDim.y;

	//calculates number of live neighbour cells
	int neighLiveCells = liveCellsInNeigh(g_data, x * *DIM, y, *DIM);	

	//set new cell state.
	g_data[(x * *DIM) + y] = applyRules(g_data[x * *DIM + y],neighLiveCells);

}


//probably a much better way to figure out the moores neighbourhood
__device__ int liveCellsInNeigh(int* g_data, int x, int y, int xDIM) {
	//get neighbours for cell x,y

	int numlivecells = 0;

	// [-1,-1]
	if (x != 0 && y != 0)
		if (g_data[x - (xDIM * 1) + y - 1] & 1 == 1)
			++numlivecells;

	// [0,-1]
	if ( y != 0)
		if (g_data[x + y - 1] & 1 == 1)
			++numlivecells;

	// [1,-1]
	if (x != xDIM - 1 && y != 0 )
		if (g_data[x + (xDIM * 1) + y - 1] & 1 == 1)
			++numlivecells;
	
	// [-1,0]
	if (x != 0)
		if (g_data[x - (xDIM * 1) + y] & 1 == 1)
			++numlivecells;	
	
	// [1,0]
	if (x != xDIM - 1)
		if (g_data[x + (xDIM * 1) + y] & 1 == 1)
			++numlivecells;

	// [-1,1]
	if (x != 0 && y != xDIM -1 )
		if (g_data[x - (xDIM * 1) + y + 1] & 1 == 1)
			++numlivecells;

	// [0,1]
	if (y != xDIM -1 )
		if (g_data[x + y + 1] & 1 == 1)
			++numlivecells;

	// [1,1]
	if (x != xDIM -1 && y != xDIM -1 )
		if (g_data[x + (xDIM * 1) + y + 1] & 1 == 1)
			++numlivecells;

	return numlivecells;
}

__device__ int applyRules(int state, int liveCells) {    
	//Any live cell with fewer than two live neighbours dies, as if caused by under-population.
	if (state && liveCells < 2)  return state;
	
	//Any live cell with two or three live neighbours lives on to the next generation.
	if (state && liveCells > 1 && liveCells < 4) return state | 2;
	
	//Any live cell with more than three live neighbours dies, as if by overcrowding.
	if (state && liveCells > 3) return state;

	//Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
	if (!state && liveCells == 3) return state | 2;

	//default
	return 0;
}