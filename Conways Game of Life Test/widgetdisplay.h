#ifndef WIDGETDISPLAY_H
#define WIDGETDISPLAY_H

#include <QtGui/QWidget>
#include "ui_widgetdisplay.h"
#include "gldrawer.h"
#include <QTimer>
#include "cellularautomata_gpgpu.h"
#include "cellularautomata_cpu.h"

class WidgetDisplay : public QWidget
{
	Q_OBJECT

public:
	WidgetDisplay(QWidget *parent = 0, Qt::WFlags flags = 0);
	~WidgetDisplay();

private:
	Ui::WidgetDisplayClass ui;
	QTimer *timer;
	CellularAutomata *CA;
	int** createSpecialCA(int);

private slots:
	void tick();
};

#endif // WIDGETDISPLAY_H
