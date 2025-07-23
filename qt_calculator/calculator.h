#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void digitClicked();
    void operatorClicked();
    void equalClicked();
    void clearClicked();

private:
    void createButton(QPushButton *&button, const QString &text);
    
    QLineEdit *display;
    QGridLayout *buttonLayout;
    
    // Number buttons
    QPushButton *digitButtons[10];
    
    // Operator buttons
    QPushButton *plusButton;
    QPushButton *minusButton;
    QPushButton *multiplyButton;
    QPushButton *divideButton;
    QPushButton *equalButton;
    QPushButton *clearButton;
    QPushButton *dotButton;
    
    double leftOperand;
    QString pendingOperator;
    bool waitingForOperand;
};

#endif // CALCULATOR_H