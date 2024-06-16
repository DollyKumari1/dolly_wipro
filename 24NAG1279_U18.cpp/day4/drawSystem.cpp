#include <iostream>
#include <string>

using namespace std;

struct Rectangle {
    double width;
    double height;

    Rectangle(double w, double h) : width(w), height(h) {}

    void display() {
        cout << "Rectangle: width = " << width << ", height = " << height << endl;
    }
};

struct Circle {
    double radius;

    Circle(double r) : radius(r) {}

    void display() {
        cout << "Circle: radius = " << radius << endl;
    }
};

struct Square {
    double side;

    Square(double s) : side(s) {}

    void display() {
        cout << "Square: side = " << side << endl;
    }
};

// Structure for Triangle
struct Triangle {
    double base;
    double height;

    Triangle(double b, double h) : base(b), height(h) {}

    void display() {
        cout << "Triangle: base = " << base << ", height = " << height << endl;
    }
};

struct Arrow {
    double length;
    double width;

    Arrow(double l, double w) : length(l), width(w) {}

    void display() {
        cout << "Arrow: length = " << length << ", width = " << width << endl;
    }
};

int main() {
    Rectangle rect(5.0, 3.0);
    Circle circle(4.0);
    Square square(5.0);
    Triangle triangle(4.0, 3.0);
    Arrow arrow(7.0, 2.0);

    rect.display();
    circle.display();
    square.display();
    triangle.display();
    arrow.display();

    return 0;
}
