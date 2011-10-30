/********************************************************************************
** Form generated from reading UI file 'widgetdisplay.ui'
**
** Created: Sun 30. Oct 21:07:20 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETDISPLAY_H
#define UI_WIDGETDISPLAY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>
#include "gldrawer.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetDisplayClass
{
public:
    GLDrawer *glWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *WidgetDisplayClass)
    {
        if (WidgetDisplayClass->objectName().isEmpty())
            WidgetDisplayClass->setObjectName(QString::fromUtf8("WidgetDisplayClass"));
        WidgetDisplayClass->resize(868, 848);
        glWidget = new GLDrawer(WidgetDisplayClass);
        glWidget->setObjectName(QString::fromUtf8("glWidget"));
        glWidget->setGeometry(QRect(30, 20, 800, 800));
        glWidget->setMouseTracking(true);
        glWidget->setFocusPolicy(Qt::ClickFocus);
        pushButton = new QPushButton(WidgetDisplayClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(780, 0, 75, 23));

        retranslateUi(WidgetDisplayClass);

        QMetaObject::connectSlotsByName(WidgetDisplayClass);
    } // setupUi

    void retranslateUi(QWidget *WidgetDisplayClass)
    {
        WidgetDisplayClass->setWindowTitle(QApplication::translate("WidgetDisplayClass", "WidgetDisplay", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("WidgetDisplayClass", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WidgetDisplayClass: public Ui_WidgetDisplayClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETDISPLAY_H
