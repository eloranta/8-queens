#include "neuron.h"

#include <cmath>
#include <random>

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
