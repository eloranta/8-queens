#pragma once

#include <QMainWindow>

class ChessBoardWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    ChessBoardWidget *m_board = nullptr;
};
