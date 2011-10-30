#ifndef GLDRAWER_H
#define GLDRAWER_H

#include <QGLWidget>
#include <QtGui/QMouseEvent>
#include "cellularautomata.h"

class GLDrawer : public QGLWidget
{
	Q_OBJECT

public:
	GLDrawer(QWidget *parent);
	~GLDrawer();

	//really bad coupling here.....not to mention accessibility
	CellularAutomata *CA;

protected:
	void paintGL();
	void initalizeGL();
	void resizeGL(int w, int h);

	void drawCell(int x, int y, float cellSpace);

	//events
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
	GLfloat rot;
	int cellScale;

};

#endif // GLDRAWER_H
