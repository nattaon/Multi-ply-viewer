/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *openfolder_pushButton;
    QLineEdit *foldername_lineEdit;
    QTreeWidget *files_treeWidget;
    QPushButton *printpoint_pushButton;
    QPushButton *obb_pushButton;
    QPushButton *aabb_pushButton;
    QPushButton *histogram_pushButton;
    QPushButton *save_histimg_pushButton;
    QLineEdit *prefiximg_lineEdit;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openfolder_pushButton = new QPushButton(centralWidget);
        openfolder_pushButton->setObjectName(QStringLiteral("openfolder_pushButton"));
        openfolder_pushButton->setGeometry(QRect(10, 0, 61, 25));
        foldername_lineEdit = new QLineEdit(centralWidget);
        foldername_lineEdit->setObjectName(QStringLiteral("foldername_lineEdit"));
        foldername_lineEdit->setGeometry(QRect(82, 0, 311, 25));
        files_treeWidget = new QTreeWidget(centralWidget);
        files_treeWidget->setObjectName(QStringLiteral("files_treeWidget"));
        files_treeWidget->setGeometry(QRect(10, 30, 191, 192));
        printpoint_pushButton = new QPushButton(centralWidget);
        printpoint_pushButton->setObjectName(QStringLiteral("printpoint_pushButton"));
        printpoint_pushButton->setGeometry(QRect(210, 30, 89, 25));
        obb_pushButton = new QPushButton(centralWidget);
        obb_pushButton->setObjectName(QStringLiteral("obb_pushButton"));
        obb_pushButton->setGeometry(QRect(210, 60, 89, 25));
        aabb_pushButton = new QPushButton(centralWidget);
        aabb_pushButton->setObjectName(QStringLiteral("aabb_pushButton"));
        aabb_pushButton->setGeometry(QRect(210, 90, 89, 25));
        histogram_pushButton = new QPushButton(centralWidget);
        histogram_pushButton->setObjectName(QStringLiteral("histogram_pushButton"));
        histogram_pushButton->setGeometry(QRect(210, 120, 89, 25));
        save_histimg_pushButton = new QPushButton(centralWidget);
        save_histimg_pushButton->setObjectName(QStringLiteral("save_histimg_pushButton"));
        save_histimg_pushButton->setGeometry(QRect(210, 180, 89, 25));
        prefiximg_lineEdit = new QLineEdit(centralWidget);
        prefiximg_lineEdit->setObjectName(QStringLiteral("prefiximg_lineEdit"));
        prefiximg_lineEdit->setGeometry(QRect(260, 150, 51, 25));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 155, 41, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        openfolder_pushButton->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = files_treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Filename", Q_NULLPTR));
        printpoint_pushButton->setText(QApplication::translate("MainWindow", "Print points", Q_NULLPTR));
        obb_pushButton->setText(QApplication::translate("MainWindow", "OBB", Q_NULLPTR));
        aabb_pushButton->setText(QApplication::translate("MainWindow", "AABB", Q_NULLPTR));
        histogram_pushButton->setText(QApplication::translate("MainWindow", "Histogram", Q_NULLPTR));
        save_histimg_pushButton->setText(QApplication::translate("MainWindow", "Save image", Q_NULLPTR));
        prefiximg_lineEdit->setText(QApplication::translate("MainWindow", "hist1_", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "prefix", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
