#include "widgetdisplay.h"
#include <Qt>

WidgetDisplay::WidgetDisplay(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);

	int timerTick = 50; //in Milliseconds
	int CellularDim = 800; //Specifies the width/height for our CA
	int initSeed = 2; //Random "0 to initseed" chance of each cell being live to start with, lower is a higher chance.

	//setup timer
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()),this,SLOT(tick()));
	timer->start(timerTick);


	//Create random CA, lower range is more concentrate

	//GPU Version
	//CA = new CellularAutomata_GPGPU(CellularDim,initSeed);

	//CPU Version
	//CA = new CellularAutomata_CPU(CellularDim,initSeed);

	//Create custom CA as defined in the following method
	//int** grid = createSpecialCA(50);
	//CA = new CellularAutomata(50,grid);	

	//Give pointer to openGL class
	ui.glWidget->CA = CA;

}

WidgetDisplay::~WidgetDisplay()
{
	delete timer;
	delete CA;
}

//This is called every x-time based on timer settings
void WidgetDisplay::tick(){
	float timeTaken = CA->nextTimeStep();
	qDebug("Time taken:%3.1f ms\n",timeTaken);
	ui.glWidget->updateGL();
}

//must be at least 10 items
int** WidgetDisplay::createSpecialCA(int dim) {

	int** p2dGrid = new int*[dim];

	for (int i = 0; i < dim; ++i) {
		p2dGrid[i] = new int[dim];
	}

	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dim; ++j) {
			//10 in a line
			p2dGrid[i][j] = j == 25 && i >= 25 - 10 && i < 25 ? 1 : 0; //and who said ternary operators were hard to read.
		}
	}
	return  p2dGrid;
}