#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

class HelloWindow : public QWidget
{
    Q_OBJECT

public:
    HelloWindow(QWidget *parent = nullptr) : QWidget(parent)
    {
        setWindowTitle("Hello Qt!");
        setFixedSize(300, 200);
        
        // Create layout and widgets
        QVBoxLayout *layout = new QVBoxLayout(this);
        
        QLabel *label = new QLabel("Welcome to Qt Development!", this);
        label->setAlignment(Qt::AlignCenter);
        
        QPushButton *button = new QPushButton("Click Me!", this);
        
        // Add widgets to layout
        layout->addWidget(label);
        layout->addWidget(button);
        
        // Connect button signal to slot
        connect(button, &QPushButton::clicked, this, &HelloWindow::onButtonClicked);
    }

private slots:
    void onButtonClicked()
    {
        QMessageBox::information(this, "Hello Qt", "Button clicked! Qt is working perfectly!");
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    HelloWindow window;
    window.show();
    
    return app.exec();
}

#include "main.moc"