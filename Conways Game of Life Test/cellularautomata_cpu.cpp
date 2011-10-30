#include "cellularautomata_cpu.h"


CellularAutomata_CPU::CellularAutomata_CPU(int dim, int seed) : CellularAutomata(dim, seed)
{
}


CellularAutomata_CPU::~CellularAutomata_CPU()
{
}

float CellularAutomata_CPU::nextTimeStep() {

	float elapsedTime = 0.0f;

	//loop through CA, non-parallel
	for (int i = 0; i < DIM; ++i) {
		for (int j = 0; j < DIM; ++j) {
			pFlatGrid[i * DIM + j] = transitionFunction(i * DIM,j);

			if (pFlatGrid[i * DIM + j] % 2)
				int jj=0;
		}
	}

	//fix up states - normalize
	for (int i = 0; i < DIM; ++i) {
		for (int j = 0; j < DIM; ++j) {
				pFlatGrid[i * DIM + j] = pFlatGrid[i * DIM + j] >> 1;
		}
	}

	return elapsedTime;
}

int CellularAutomata_CPU::transitionFunction(int x, int y) {
	
	int numLiveCells = liveCellsInNeigh(x,y);

	//return new state of cell
	return applyRules(pFlatGrid[x + y],numLiveCells);
}

int CellularAutomata_CPU::applyRules(int state, int liveCells) {    
	
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

	//Probably a much better way to figure out the moores neighbourhood
int CellularAutomata_CPU::liveCellsInNeigh(int x, int y) {
	//get neighbours for cell x,y

	int numlivecells = 0;

	// [-1,-1]
	if (x != 0 && y != 0)
		if (pFlatGrid[x - (DIM * 1) + y - 1] & 1 == 1)
			++numlivecells;

	// [0,-1]
	if ( y != 0)
		if (pFlatGrid[x + y - 1] & 1 == 1)
			++numlivecells;

	// [1,-1]
	if (x != DIM - 1 && y != 0 )
		if (pFlatGrid[x + (DIM * 1) + y - 1] & 1 == 1)
			++numlivecells;
	
	// [-1,0]
	if (x != 0)
		if (pFlatGrid[x - (DIM * 1) + y] & 1 == 1)
			++numlivecells;	
	
	// [1,0]
	if (x != DIM - 1)
		if (pFlatGrid[x + (DIM * 1) + y] & 1 == 1)
			++numlivecells;

	// [-1,1]
	if (x != 0 && y != DIM -1 )
		if (pFlatGrid[x - (DIM * 1) + y + 1] & 1 == 1)
			++numlivecells;

	// [0,1]
	if (y != DIM -1 )
		if (pFlatGrid[x + y + 1] & 1 == 1)
			++numlivecells;

	// [1,1]
	if (x != DIM -1 && y != DIM -1 )
		if (pFlatGrid[x + (DIM * 1) + y + 1] & 1 == 1)
			++numlivecells;

	return numlivecells;
}