#include "cellularautomata.h"
#include <cstdlib>

CellularAutomata::CellularAutomata(int dimension, int range) : DIM(dimension)
{
	//initialize array based on dim with random values
	pFlatGrid = new int[DIM * DIM];

	for (int i = 0; i < DIM; ++i) {
		for (int j = 0; j < DIM; ++j) {

		//get random state value bettwen 0 & 1;
		int random = std::rand() % range;

		//assign
		pFlatGrid[i * DIM + j] = random == range - 1 ? 1 : 0;
		}
	}
}

CellularAutomata::CellularAutomata(int *pFlatGrid, int dimension) : DIM(dimension), pFlatGrid(pFlatGrid)
{

}

CellularAutomata::~CellularAutomata()
{
	//clean up our allocated array
	delete [] pFlatGrid;

}