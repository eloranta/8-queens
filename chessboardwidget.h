#pragma once

#include <QWidget>

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
};
