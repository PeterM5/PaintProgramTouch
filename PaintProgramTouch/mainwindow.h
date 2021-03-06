#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QColor getSelectedColor();

private slots:
    void on_pushButton_clicked();
    void on_btn_color_picker_clicked();

private:
    Ui::MainWindow *ui;

    QColorDialog* m_colorPicker;
};
#endif // MAINWINDOW_H
