#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Canvas* c = new Canvas(this, 100, 100);
    ui->tabWidget->clear();
    ui->tabWidget->addTab(c, "My first tab");

    m_colorPicker = new QColorDialog(this);
    m_colorPicker->show();
}

MainWindow::~MainWindow()
{
    m_colorPicker->close();
    delete m_colorPicker;
    delete ui;
}
#include <QDebug>
QColor MainWindow::getSelectedColor()
{
    qDebug() << m_colorPicker->selectedColor();
    return m_colorPicker->selectedColor();
}


void MainWindow::on_pushButton_clicked()
{

}
