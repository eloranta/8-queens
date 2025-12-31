#pragma once

class Neuron
{
public:
    Neuron();
    Neuron(int row, int col);

    int row() const { return m_row; }
    int col() const { return m_col; }
    double value() const { return m_value; }

private:
    int m_row = -1;
    int m_col = -1;
    double m_value = 0.0;
};
