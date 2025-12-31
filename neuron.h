#pragma once

#include <vector>

class Neuron
{
public:
    Neuron();
    Neuron(int row, int col);

    int row() const { return m_row; }
    int col() const { return m_col; }
    double value() const { return m_value; }
    static double sigmoid(double x);
    static double positiveInput() { return s_positiveInput; }
    static void setPositiveInput(double value) { s_positiveInput = value; }
    double update(const std::vector<std::vector<double>> &values);

private:
    int m_row = -1;
    int m_col = -1;
    double m_value = 0.0;
    static double s_positiveInput;
};
