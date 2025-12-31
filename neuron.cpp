#include "neuron.h"

#include <cmath>
#include <random>
#include <QDebug>

namespace {
double randomX()
{
    static std::mt19937 rng{std::random_device{}()};
    static std::uniform_real_distribution<double> dist(-10.0, 10.0);
    return dist(rng);
}
} // namespace

Neuron::Neuron()
    : m_value(sigmoid(randomX()))
{
}

Neuron::Neuron(int row, int col)
    : m_row(row)
    , m_col(col)
    , m_value(sigmoid(randomX()))
{
}

double Neuron::sigmoid(double x)
{
    return 1.0 / (1.0 + std::exp(-x));
}

double Neuron::update(const std::vector<std::vector<double>> &values)
{
    const int rows = static_cast<int>(values.size());
    if (rows == 0) {
        return 0.0;
    }
    const int cols = static_cast<int>(values.front().size());
    if (m_row < 0 || m_col < 0 || m_row >= rows || m_col >= cols) {
        return 0.0;
    }

    double sum = 0.0;
    for (int col = 0; col < cols; ++col) {
        if (col == m_col) {
            continue;
        }
        sum += values[m_row][col];
    }
    for (int row = 0; row < rows; ++row) {
        if (row == m_row) {
            continue;
        }
        sum += values[row][m_col];
    }

    for (int row = m_row - 1, col = m_col - 1; row >= 0 && col >= 0; --row, --col) {
        sum += values[row][col];
    }
    for (int row = m_row + 1, col = m_col + 1; row < rows && col < cols; ++row, ++col) {
        sum += values[row][col];
    }
    for (int row = m_row - 1, col = m_col + 1; row >= 0 && col < cols; --row, ++col) {
        sum += values[row][col];
    }
    for (int row = m_row + 1, col = m_col - 1; row < rows && col >= 0; ++row, --col) {
        sum += values[row][col];
    }

    qDebug() << "Neuron" << m_row << m_col << "sum" << sum;
    return sum;
}
