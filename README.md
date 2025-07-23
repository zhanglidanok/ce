# Qt Development Examples

This repository contains Qt development examples demonstrating GUI application development with Qt 5.15.

## Projects

### 1. Hello Qt (`hello_qt/`)
A simple Qt application demonstrating:
- Basic window creation
- Widget layouts (QVBoxLayout)
- Button interactions
- Signal-slot connections
- Message boxes

**To build and run:**
```bash
cd hello_qt
qmake
make
./hello_qt
```

### 2. Qt Calculator (`qt_calculator/`)
A fully functional calculator application demonstrating:
- Complex widget layouts (QGridLayout)
- Multiple button handling
- Event-driven programming
- Object-oriented design with header/source separation
- Error handling (division by zero)

**To build and run:**
```bash
cd qt_calculator
qmake
make
./qt_calculator
```

## Qt Version
These examples are built with Qt 5.15.15 and use C++11 features.

## Key Qt Concepts Demonstrated

### Widgets Used
- `QApplication` - Main application class
- `QWidget` - Base widget class
- `QPushButton` - Clickable buttons
- `QLabel` - Text display
- `QLineEdit` - Text input/display
- `QVBoxLayout` - Vertical layout
- `QGridLayout` - Grid-based layout
- `QMessageBox` - Dialog boxes

### Programming Patterns
- Signal-slot mechanism for event handling
- Object-oriented design with inheritance
- Layout management for responsive UIs
- Event-driven programming model

## Building Qt Applications

Qt applications use the qmake build system:
1. Create a `.pro` file defining the project
2. Run `qmake` to generate a Makefile
3. Run `make` to compile the application

The basic `.pro` file structure:
```pro
QT += core widgets
CONFIG += c++11
TARGET = your_app_name
TEMPLATE = app
SOURCES += main.cpp your_class.cpp
HEADERS += your_class.h
```