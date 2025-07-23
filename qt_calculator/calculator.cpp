#include "calculator.h"
#include <QApplication>
#include <QMessageBox>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent), leftOperand(0.0), waitingForOperand(true)
{
    setWindowTitle("Qt Calculator");
    setFixedSize(300, 400);

    // Create display
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);
    
    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);

    // Create buttons
    for (int i = 0; i < 10; ++i) {
        createButton(digitButtons[i], QString::number(i));
        connect(digitButtons[i], &QPushButton::clicked, this, &Calculator::digitClicked);
    }

    createButton(dotButton, ".");
    createButton(plusButton, "+");
    createButton(minusButton, "-");
    createButton(multiplyButton, "×");
    createButton(divideButton, "÷");
    createButton(equalButton, "=");
    createButton(clearButton, "Clear");

    connect(dotButton, &QPushButton::clicked, this, &Calculator::digitClicked);
    connect(plusButton, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(minusButton, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(multiplyButton, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(divideButton, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(equalButton, &QPushButton::clicked, this, &Calculator::equalClicked);
    connect(clearButton, &QPushButton::clicked, this, &Calculator::clearClicked);

    // Layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(display);

    buttonLayout = new QGridLayout;
    
    // Row 0
    buttonLayout->addWidget(clearButton, 0, 0, 1, 2);
    buttonLayout->addWidget(divideButton, 0, 2);
    buttonLayout->addWidget(multiplyButton, 0, 3);
    
    // Row 1
    buttonLayout->addWidget(digitButtons[7], 1, 0);
    buttonLayout->addWidget(digitButtons[8], 1, 1);
    buttonLayout->addWidget(digitButtons[9], 1, 2);
    buttonLayout->addWidget(minusButton, 1, 3);
    
    // Row 2
    buttonLayout->addWidget(digitButtons[4], 2, 0);
    buttonLayout->addWidget(digitButtons[5], 2, 1);
    buttonLayout->addWidget(digitButtons[6], 2, 2);
    buttonLayout->addWidget(plusButton, 2, 3);
    
    // Row 3
    buttonLayout->addWidget(digitButtons[1], 3, 0);
    buttonLayout->addWidget(digitButtons[2], 3, 1);
    buttonLayout->addWidget(digitButtons[3], 3, 2);
    buttonLayout->addWidget(equalButton, 3, 3, 2, 1);
    
    // Row 4
    buttonLayout->addWidget(digitButtons[0], 4, 0, 1, 2);
    buttonLayout->addWidget(dotButton, 4, 2);

    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);
}

Calculator::~Calculator()
{
}

void Calculator::createButton(QPushButton *&button, const QString &text)
{
    button = new QPushButton(text);
    button->setMinimumSize(60, 60);
    
    QFont font = button->font();
    font.setPointSize(font.pointSize() + 2);
    button->setFont(font);
}

void Calculator::digitClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedDigit = clickedButton->text();

    if (display->text() == "0" && clickedDigit == "0.0")
        return;

    if (waitingForOperand) {
        display->clear();
        waitingForOperand = false;
    }

    display->setText(display->text() + clickedDigit);
}

void Calculator::operatorClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    if (!pendingOperator.isEmpty()) {
        if (!waitingForOperand) {
            double result = 0.0;
            
            if (pendingOperator == "+") {
                result = leftOperand + operand;
            } else if (pendingOperator == "-") {
                result = leftOperand - operand;
            } else if (pendingOperator == "×") {
                result = leftOperand * operand;
            } else if (pendingOperator == "÷") {
                if (operand != 0.0)
                    result = leftOperand / operand;
                else {
                    QMessageBox::warning(this, "Calculator", "Division by zero!");
                    return;
                }
            }
            
            display->setText(QString::number(result));
            leftOperand = result;
        }
    } else {
        leftOperand = operand;
    }

    pendingOperator = clickedOperator;
    waitingForOperand = true;
}

void Calculator::equalClicked()
{
    double operand = display->text().toDouble();

    if (!pendingOperator.isEmpty()) {
        double result = 0.0;
        
        if (pendingOperator == "+") {
            result = leftOperand + operand;
        } else if (pendingOperator == "-") {
            result = leftOperand - operand;
        } else if (pendingOperator == "×") {
            result = leftOperand * operand;
        } else if (pendingOperator == "÷") {
            if (operand != 0.0)
                result = leftOperand / operand;
            else {
                QMessageBox::warning(this, "Calculator", "Division by zero!");
                return;
            }
        }
        
        display->setText(QString::number(result));
        leftOperand = result;
        pendingOperator.clear();
        waitingForOperand = true;
    }
}

void Calculator::clearClicked()
{
    display->setText("0");
    leftOperand = 0.0;
    pendingOperator.clear();
    waitingForOperand = true;
}