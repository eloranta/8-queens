#include "mainwindow.h"
#include "chessboardwidget.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("8 Queens");
    resize(640, 640);

    auto *container = new QWidget(this);
    auto *layout = new QVBoxLayout(container);
    layout->setContentsMargins(8, 8, 8, 8);
    layout->setSpacing(8);

    auto *updateButton = new QPushButton("Update", container);
    updateButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_board = new ChessBoardWidget(container);

    layout->addWidget(m_board, 1);
    layout->addWidget(updateButton, 0, Qt::AlignLeft);

    setCentralWidget(container);

    connect(updateButton, &QPushButton::clicked, m_board, &ChessBoardWidget::updateNeurons);

}
