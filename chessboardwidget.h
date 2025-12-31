#pragma once

#include <QWidget>
#include <vector>

#include "neuron.h"

class ChessBoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChessBoardWidget(QWidget *parent = nullptr);

    QSize sizeHint() const override;

signals:
    void squareClicked(const QString &squareName);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    QRect boardRect() const;
    QString squareName(int row, int col) const;

    int m_selectedRow = -1;
    int m_selectedCol = -1;
    std::vector<std::vector<Neuron>> m_neurons;
};
