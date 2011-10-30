#include "cellularautomata_gpgpu.h"


CellularAutomata_GPGPU::CellularAutomata_GPGPU(int dim, int seed) : CellularAutomata(dim, seed)
{
}


CellularAutomata_GPGPU::~CellularAutomata_GPGPU()
{

}

float CellularAutomata_GPGPU::nextTimeStep() {

	return CUDATimeStep(pFlatGrid, DIM);

}