#include <iostream>
using namespace std;

class Rectangle {
private:
    int topX;
    int topY;
    int width;
    int height;

public:
    Rectangle() : topX(0), topY(0), width(0), height(0) {}

    Rectangle(int x, int y, int w, int h) : topX(x), topY(y), width(w), height(h) {}

    int getTopX() const { return topX; }
    int getTopY() const { return topY; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void setTopX(int x) { topX = x; }
    void setTopY(int y) { topY = y; }
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }

    void Move(int x, int y) {
        topX += x;
        topY += y;
    }

    void Reduce(int w, int h) {
        if (width > w) width -= w;
        else width = 0;
        
        if (height > h) height -= h;
        else height = 0;
    }

    void Inflate(int w, int h) {
        width += w;
        height += h;
    }

    void DisplayRect() const {
        cout << "Rectangle: topX = " << topX << ", topY = " << topY
                  << ", width = " << width << ", height = " << height << endl;
    }
};

int main() {

    Rectangle rect1;
    rect1.DisplayRect(); 
    Rectangle rect2(4, 5, 8, 7);
    rect2.DisplayRect(); 

    rect2.Move(1, -3);
    rect2.DisplayRect(); 

    rect2.Reduce(5, 2);
    rect2.DisplayRect(); 
    rect2.Inflate(3, 1);
    rect2.DisplayRect(); 

    return 0;
}
