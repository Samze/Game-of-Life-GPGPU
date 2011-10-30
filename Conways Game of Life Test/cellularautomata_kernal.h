#ifndef CELLULARAUTOMATA_KERNAL_H
#define CELLULARAUTOMATA_KERNAL_H

__global__ void kernal(int*,int*);
__device__ int applyRules(int state, int liveCells);
__device__ int liveCellsInNeigh(int* g_data, int x, int y, int xDIM);

#endif