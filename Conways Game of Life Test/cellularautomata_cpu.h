#ifndef CELLULARAUTOMATA_CPU_H
#define CELLULARAUTOMATA_CPU_H

#include "cellularautomata.h"

class CellularAutomata_CPU : public CellularAutomata
{
public:
	CellularAutomata_CPU(int, int);
	~CellularAutomata_CPU();

	float nextTimeStep();

private:
	int liveCellsInNeigh(int, int);
	int applyRules(int,int);
	int transitionFunction(int, int);

};

#endif