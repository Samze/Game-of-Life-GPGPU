#include "cellularautomata.h"
#include <cstdlib>

CellularAutomata::CellularAutomata(int dimension, int range) : dim(dimension)
{
	//initialize array based on dim with random values
	pFlatGrid = new int[dim * dim];

	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dim; ++j) {

		//get random state value bettwen 0 & 1;
		int random = std::rand() % range;

		//assign
		pFlatGrid[i * dim + j] = random == range - 1 ? 1 : 0;
		}
	}
}

CellularAutomata::CellularAutomata(int dimension, int *lattice) : dim(dimension), pFlatGrid(lattice)
{

}

CellularAutomata::~CellularAutomata()
{
	//clean up our allocated array
	delete [] pFlatGrid;

}

float CellularAutomata::nextTimeStep() {

	return CUDATimeStep(pFlatGrid, dim);

}