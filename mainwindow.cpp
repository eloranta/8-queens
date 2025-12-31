#include "mainwindow.h"
#include "chessboardwidget.h"

#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("8 Queens");
    resize(640, 640);

    m_board = new ChessBoardWidget(this);
    setCentralWidget(m_board);

    statusBar()->showMessage("Click a square");
    connect(m_board, &ChessBoardWidget::squareClicked, this, [this](const QString &name) {
        statusBar()->showMessage(QString("Selected %1").arg(name));
    });
}
