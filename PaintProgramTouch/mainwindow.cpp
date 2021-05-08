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

    //Connections
    connect(ui->actionColor_Picker, SIGNAL(triggered()), this, SLOT(on_btn_color_picker_clicked()));
}

MainWindow::~MainWindow()
{
    m_colorPicker->close();
    delete m_colorPicker;
    delete ui;
}

QColor MainWindow::getSelectedColor()
{
    return m_colorPicker->currentColor();
}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_btn_color_picker_clicked()
{
    m_colorPicker->show();
}
