#include "neuron.h"

#include <cmath>
#include <random>

namespace {
double randomValue()
{
    static std::mt19937 rng{std::random_device{}()};
    static std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(rng);
}
} // namespace

Neuron::Neuron()
    : m_value(randomValue())
{
}

Neuron::Neuron(int row, int col)
    : m_row(row)
    , m_col(col)
    , m_value(randomValue())
{
}

double Neuron::sigmoid(double x)
{
    return 1.0 / (1.0 + std::exp(-x));
}
