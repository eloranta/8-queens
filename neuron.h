#pragma once

class Neuron
{
public:
    Neuron() = default;
    Neuron(int row, int col);

    int row() const { return m_row; }
    int col() const { return m_col; }

private:
    int m_row = -1;
    int m_col = -1;
};
