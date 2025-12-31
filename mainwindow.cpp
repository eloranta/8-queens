#include "mainwindow.h"
#include "chessboardwidget.h"
#include "neuron.h"

#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("8 Queens");
    resize(640, 640);

    auto *container = new QWidget(this);
    auto *layout = new QVBoxLayout(container);
    layout->setContentsMargins(8, 8, 8, 8);
    layout->setSpacing(8);

    auto *updateButton = new QPushButton("Update", container);
    updateButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    auto *inputLayout = new QHBoxLayout();
    auto *inputLabel = new QLabel("Positive input", container);
    auto *inputSpin = new QDoubleSpinBox(container);
    inputSpin->setRange(0.0, 1000.0);
    inputSpin->setDecimals(2);
    inputSpin->setSingleStep(0.1);
    inputSpin->setValue(Neuron::positiveInput());
    inputLayout->addWidget(inputLabel);
    inputLayout->addWidget(inputSpin);
    inputLayout->addStretch();

    auto *gainLayout = new QHBoxLayout();
    auto *gainLabel = new QLabel("Input gain", container);
    auto *gainSpin = new QDoubleSpinBox(container);
    gainSpin->setRange(0.0, 5.0);
    gainSpin->setDecimals(2);
    gainSpin->setSingleStep(0.1);
    gainSpin->setValue(Neuron::inputGain());
    gainLayout->addWidget(gainLabel);
    gainLayout->addWidget(gainSpin);
    gainLayout->addStretch();

    m_board = new ChessBoardWidget(container);

    layout->addWidget(m_board, 1);
    layout->addLayout(inputLayout);
    layout->addLayout(gainLayout);
    layout->addWidget(updateButton, 0, Qt::AlignLeft);

    setCentralWidget(container);

    connect(updateButton, &QPushButton::clicked, m_board, &ChessBoardWidget::updateNeurons);
    connect(inputSpin, &QDoubleSpinBox::valueChanged, this, [](double value) {
        Neuron::setPositiveInput(value);
    });
    connect(gainSpin, &QDoubleSpinBox::valueChanged, this, [](double value) {
        Neuron::setInputGain(value);
    });

}
