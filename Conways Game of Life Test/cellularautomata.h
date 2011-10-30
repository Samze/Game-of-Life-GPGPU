#ifndef CELLULARAUTOMATA_H
#define CELLULARAUTOMATA_H

#include <cstdlib>

// declaration, forward
extern "C" float CUDATimeStep(int* pFlatGrid, const int DIM);

class CellularAutomata 
{

public:
	CellularAutomata(int,int); //random data
	CellularAutomata(int, int*);
	~CellularAutomata();
	const unsigned dim; //Should make const?
	int *pFlatGrid;
	float nextTimeStep();

private:
	int transitionFunction(int, int);
};

#endif // CELLULARAUTOMATA_H
