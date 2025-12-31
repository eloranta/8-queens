#include "chessboardwidget.h"

#include <QMouseEvent>
#include <QPainter>

ChessBoardWidget::ChessBoardWidget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(320, 320);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_neurons.resize(8);
    for (int row = 0; row < 8; ++row) {
        m_neurons[row].reserve(8);
        for (int col = 0; col < 8; ++col) {
            m_neurons[row].emplace_back(row, col);
        }
    }
}

QSize ChessBoardWidget::sizeHint() const
{
    return QSize(480, 480);
}

void ChessBoardWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, false);

    const QRect rect = boardRect();
    const int squareSize = rect.width() / 8;

    const QColor light(240, 217, 181);
    const QColor dark(181, 136, 99);

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            const int x = rect.left() + col * squareSize;
            const int y = rect.top() + row * squareSize;
            const QRect square(x, y, squareSize, squareSize);
            const bool isLight = ((row + col) % 2) == 0;
            painter.fillRect(square, isLight ? light : dark);

            const double value = m_neurons[row][col].value();
            const double radius = value * (squareSize * 0.45);
            if (radius > 0.0) {
                const QPointF center(square.center());
                painter.setPen(Qt::NoPen);
                painter.setBrush(QColor(30, 30, 30, 170));
                painter.drawEllipse(center, radius, radius);
            }
        }
    }

    if (m_selectedRow >= 0 && m_selectedCol >= 0) {
        const int x = rect.left() + m_selectedCol * squareSize;
        const int y = rect.top() + m_selectedRow * squareSize;
        QRect square(x, y, squareSize, squareSize);
        QPen pen(QColor(30, 180, 220));
        pen.setWidth(3);
        painter.setPen(pen);
        painter.drawRect(square.adjusted(1, 1, -1, -1));
    }
}

void ChessBoardWidget::mousePressEvent(QMouseEvent *event)
{
    const QRect rect = boardRect();
    if (!rect.contains(event->pos())) {
        return;
    }

    const int squareSize = rect.width() / 8;
    const int col = (event->pos().x() - rect.left()) / squareSize;
    const int row = (event->pos().y() - rect.top()) / squareSize;

    if (row < 0 || row > 7 || col < 0 || col > 7) {
        return;
    }

    m_selectedRow = row;
    m_selectedCol = col;
    update();

    emit squareClicked(squareName(row, col));
}

QRect ChessBoardWidget::boardRect() const
{
    const int side = qMin(width(), height());
    const int squareSize = side / 8;
    const int boardSide = squareSize * 8;
    const int x = (width() - boardSide) / 2;
    const int y = (height() - boardSide) / 2;
    return QRect(x, y, boardSide, boardSide);
}

QString ChessBoardWidget::squareName(int row, int col) const
{
    const QChar file = QChar('a' + col);
    const int rank = 8 - row;
    return QString("%1%2").arg(file).arg(rank);
}
