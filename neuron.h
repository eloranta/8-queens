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
    static double inputGain() { return s_inputGain; }
    static void setInputGain(double value) { s_inputGain = value; }
    double update(const std::vector<std::vector<double>> &values);

private:
    int m_row = -1;
    int m_col = -1;
    double m_value = 0.0;
    double m_sum = 0.0;
    static double s_positiveInput;
    static double s_inputGain;
};
