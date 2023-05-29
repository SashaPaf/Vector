#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include "vector.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Vector Operations");
    window.setStyleSheet("QPushButton {"
                         "    padding: 6px;"
                         "    font-size: 14px;"
                         "    border: none;"
                         "    background-color: #6A5ACD;"
                         "    color: white;"
                         "}"
                         "QLabel {"
                         "    font-size: 14px;"
                         "}"
                         "QLineEdit {"
                         "    padding: 8px;"
                         "    font-size: 14px;"
                         "}");

    QVBoxLayout *layout = new QVBoxLayout(&window);

    // Create input fields for vector values
    QLabel *vectorALabel = new QLabel("Vector A");
    QLineEdit *vectorAXEdit = new QLineEdit();
    QLineEdit *vectorAYEdit = new QLineEdit();
    QLineEdit *vectorAZEdit = new QLineEdit();

    QLabel *vectorBLabel = new QLabel("Vector B");
    QLineEdit *vectorBXEdit = new QLineEdit();
    QLineEdit *vectorBYEdit = new QLineEdit();
    QLineEdit *vectorBZEdit = new QLineEdit();

    QLabel *scalarLabel = new QLabel("Constanta");
    QLineEdit *scalarEdit = new QLineEdit();

    layout->addWidget(vectorALabel);
    layout->addWidget(vectorAXEdit);
    layout->addWidget(vectorAYEdit);
    layout->addWidget(vectorAZEdit);
    layout->addWidget(vectorBLabel);
    layout->addWidget(vectorBXEdit);
    layout->addWidget(vectorBYEdit);
    layout->addWidget(vectorBZEdit);
    layout->addWidget(scalarLabel);
    layout->addWidget(scalarEdit);

    QPushButton *magnitudeButton = new QPushButton("Magnitude");
    QPushButton *dotProductButton = new QPushButton("Dot Product");
    QPushButton *addButton = new QPushButton("Add");
    QPushButton *subtractButton = new QPushButton("Subtract");
    QPushButton *multiplyButton = new QPushButton("Multiply");
    QPushButton *collinearButton = new QPushButton("Collinear");
    QPushButton *orthogonalButton = new QPushButton("Orthogonal");

    layout->addWidget(magnitudeButton);
    layout->addWidget(dotProductButton);
    layout->addWidget(addButton);
    layout->addWidget(subtractButton);
    layout->addWidget(multiplyButton);
    layout->addWidget(collinearButton);
    layout->addWidget(orthogonalButton);

    QLabel *resultLabel = new QLabel();
    layout->addWidget(resultLabel);

    QObject::connect(magnitudeButton, &QPushButton::clicked, [&]() {
        double x = vectorAXEdit->text().toDouble();
        double y = vectorAYEdit->text().toDouble();
        double z = vectorAZEdit->text().toDouble();
        Vector vectorA(x, y, z);

        double magnitude = vectorA.magnitude();
        resultLabel->setText("Magnitude of Vector A: " + QString::number(magnitude));
    });

    QObject::connect(dotProductButton, &QPushButton::clicked, [&]() {
        double x1 = vectorAXEdit->text().toDouble();
        double y1 = vectorAYEdit->text().toDouble();
        double z1 = vectorAZEdit->text().toDouble();
        Vector vectorA(x1, y1, z1);

        double x2 = vectorBXEdit->text().toDouble();
        double y2 = vectorBYEdit->text().toDouble();
        double z2 = vectorBZEdit->text().toDouble();
        Vector vectorB(x2, y2, z2);

        double dotProduct = vectorA.dotProduct(vectorB);
        resultLabel->setText("Dot Product of Vector A and Vector B: " + QString::number(dotProduct));
    });

    QObject::connect(addButton, &QPushButton::clicked, [&]() {
        double x1 = vectorAXEdit->text().toDouble();
        double y1 = vectorAYEdit->text().toDouble();
        double z1 = vectorAZEdit->text().toDouble();
        Vector vectorA(x1, y1, z1);

        double x2 = vectorBXEdit->text().toDouble();
        double y2 = vectorBYEdit->text().toDouble();
        double z2 = vectorBZEdit->text().toDouble();
        Vector vectorB(x2, y2, z2);

        Vector sum = vectorA.add(vectorB);
        resultLabel->setText("Sum of Vector A and Vector B: (" +
                             QString::number(sum.x) + ", " +
                             QString::number(sum.y) + ", " +
                             QString::number(sum.z) + ")");
    });

    QObject::connect(subtractButton, &QPushButton::clicked, [&]() {
        double x1 = vectorAXEdit->text().toDouble();
        double y1 = vectorAYEdit->text().toDouble();
        double z1 = vectorAZEdit->text().toDouble();
        Vector vectorA(x1, y1, z1);

        double x2 = vectorBXEdit->text().toDouble();
        double y2 = vectorBYEdit->text().toDouble();
        double z2 = vectorBZEdit->text().toDouble();
        Vector vectorB(x2, y2, z2);

        Vector difference = vectorA.subtract(vectorB);
        resultLabel->setText("Difference of Vector A and Vector B: (" +
                             QString::number(difference.x) + ", " +
                             QString::number(difference.y) + ", " +
                             QString::number(difference.z) + ")");
    });

    QObject::connect(multiplyButton, &QPushButton::clicked, [&]() {
        double x = vectorAXEdit->text().toDouble();
        double y = vectorAYEdit->text().toDouble();
        double z = vectorAZEdit->text().toDouble();
        Vector vectorA(x, y, z);

        double constanta = scalarEdit->text().toDouble();
        Vector product = vectorA.multiply(constanta);
        resultLabel->setText("Multiplication of Vector A by Constanta: (" +
                             QString::number(product.x) + ", " +
                             QString::number(product.y) + ", " +
                             QString::number(product.z) + ")");
    });

    QObject::connect(collinearButton, &QPushButton::clicked, [&]() {
        double x1 = vectorAXEdit->text().toDouble();
        double y1 = vectorAYEdit->text().toDouble();
        double z1 = vectorAZEdit->text().toDouble();
        Vector vectorA(x1, y1, z1);

        double x2 = vectorBXEdit->text().toDouble();
        double y2 = vectorBYEdit->text().toDouble();
        double z2 = vectorBZEdit->text().toDouble();
        Vector vectorB(x2, y2, z2);

        bool isCollinear = vectorA.isCollinear(vectorB);
        if (isCollinear) {
            resultLabel->setText("Vectors A and B are collinear.");
        } else {
            resultLabel->setText("Vectors A and B are not collinear.");
        }
    });

    QObject::connect(orthogonalButton, &QPushButton::clicked, [&]() {
        double x1 = vectorAXEdit->text().toDouble();
        double y1 = vectorAYEdit->text().toDouble();
        double z1 = vectorAZEdit->text().toDouble();
        Vector vectorA(x1, y1, z1);

        double x2 = vectorBXEdit->text().toDouble();
        double y2 = vectorBYEdit->text().toDouble();
        double z2 = vectorBZEdit->text().toDouble();
        Vector vectorB(x2, y2, z2);

        bool isOrthogonal = vectorA.isOrthogonal(vectorB);
        if (isOrthogonal) {
            resultLabel->setText("Vectors A and B are orthogonal.");
        } else {
            resultLabel->setText("Vectors A and B are not orthogonal.");
        }
    });


    layout->setContentsMargins(20, 20, 20, 20);
    layout->setSpacing(10);

    window.show();

    return app.exec();
}



