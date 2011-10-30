#ifndef CELLULARAUTOMATA_GPGPU_H
#define CELLULARAUTOMATA_GPGPU_H

#include "cellularautomata.h"

// declaration, forward
extern "C" float CUDATimeStep(int* pFlatGrid, const int DIM);

class CellularAutomata_GPGPU : public CellularAutomata
{
public:
	CellularAutomata_GPGPU(int, int);
	~CellularAutomata_GPGPU();

	float nextTimeStep();
};

#endif

