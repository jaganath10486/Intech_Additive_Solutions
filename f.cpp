#include <iostream>

using namespace std;

class Rectangle
{
private:
    int x1, y1, x2, y2; // Coordinates of the top-left and bottom-right corners of the rectangle

public:
    // Constructor to initialize the coordinates of the rectangle
    Rectangle(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

    // Function to check if two rectangles intersect
    bool intersect(Rectangle &second)
    {
        // Check if one rectangle is to the left to the second rectangle
        if (x2 <= second.x1 || second.x2 <= x1)
            return false;

        // Check if one rectangle is above the second rectange
        if (y2 <= second.y1 || second.y2 <= y1)
            return false;

        return true;
    }
};

int main()
{
    Rectangle rect1(0, 0, 4, 4); // Rectangle with top-left corner at (0, 0) and bottom-right corner at (4, 4)
    Rectangle rect2(2, 2, 6, 6); // Rectangle with top-left corner at (2, 2) and bottom-right corner at (6, 6)

    if (rect1.intersect(rect2))
    {
        cout << "Rectangles intersect." << endl;
    }
    else
    {
        cout << "Rectangles do not intersect." << endl;
    }

    return 0;
}
