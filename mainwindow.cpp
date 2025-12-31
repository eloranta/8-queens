#include "mainwindow.h"
#include "chessboardwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("8 Queens");
    resize(640, 640);

    m_board = new ChessBoardWidget(this);
    setCentralWidget(m_board);

}
