#include "widgetdisplay.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WidgetDisplay w;
	w.show();
	return a.exec();
}
