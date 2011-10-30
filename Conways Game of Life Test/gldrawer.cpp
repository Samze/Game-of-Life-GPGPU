#include "gldrawer.h"

GLDrawer::GLDrawer(QWidget *parent)
	: QGLWidget(parent)
{
	//flicker problem because of a widget attribute...this may be the soltuion.
	setAttribute(Qt::WidgetAttribute::WA_OpaquePaintEvent );
}

GLDrawer::~GLDrawer()
{

}
void GLDrawer::initalizeGL() {
    glDisable(GL_TEXTURE_2D); // no need for setting the depth up
    glDisable(GL_DEPTH_TEST);

    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glEnable(GL_POLYGON_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0, 0, 0, 0);
}
void GLDrawer::paintGL(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);

	float cellSpace = (float) width() / CA->dim;
	
	for(int i = 0; i < CA->dim; ++i) {
		for(int j = 0; j < CA->dim; ++j) {
			if (CA->pFlatGrid[i * CA->dim + j] == 1) {
				//draw!
				//qDebug("%d + %d",x,y);
				drawCell(i,j,cellSpace);
			}
		}
	}

	//glTranslatef(1.0f,0.0f,0.0f);

 //   glBegin(GL_POLYGON);
	//	glVertex2f(0,0);
	//	glVertex2f(100,300);
	//	glVertex2f(300,100);
 //   glEnd();
}

void GLDrawer::drawCell(int x, int y, float cellSpace) {
	glLoadIdentity();
	glTranslatef(x* cellSpace,y * cellSpace,0.0f);
	glScalef(cellSpace, cellSpace,0.0f); //minus an ammount here to get a "grid" look if desired
	//glScalef(9.0, 9.0,0.0f);
	glBegin(GL_QUADS);
		glVertex2f(0,0); //top left
		glVertex2f(1,0); //top right
		glVertex2f(1,1); //bottom right
		glVertex2f(0,1); //bottom left
	glEnd();
}

//ran on opening scene too
void GLDrawer::resizeGL(int w, int h){

	//setup view
	glViewport(0, 0, w, h);
	
	//clean slate && origin set to top left
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, h, 0);

	//set model and reset matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GLDrawer::mousePressEvent(QMouseEvent *event) {

}
void GLDrawer::mouseMoveEvent(QMouseEvent *event) {
   // qDebug("%d, %d\n", event->x(), event->y());
}

void GLDrawer::keyPressEvent(QKeyEvent* event) {
    switch(event->key()) {
    case Qt::Key_Escape:
        close();
        break;
    default:
        event->ignore();
        break;
    }
}