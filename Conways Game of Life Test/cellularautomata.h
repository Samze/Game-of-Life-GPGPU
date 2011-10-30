#ifndef CELLULARAUTOMATA_H
#define CELLULARAUTOMATA_H

#include <cstdlib>


class CellularAutomata 
{

public:
	CellularAutomata(int,int); //random data
	CellularAutomata(int*, int);
	~CellularAutomata();

	const unsigned DIM; //Should make const?
	int *pFlatGrid;

	virtual float nextTimeStep() = 0;
};

#endif // CELLULARAUTOMATA_H
