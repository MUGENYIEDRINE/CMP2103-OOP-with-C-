#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Point {
private:
    double x, y;

public:
    Point(double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    
    double distanceTo(const Point& other) const {
        return sqrt(pow(x - other.x, 2) +
                    pow(y - other.y, 2));
    }

    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};


class Buffer {
private:
    Point center;
    double radius;

public:
    Buffer(Point center, double radius) {
        this->center = center;
        this->radius = radius;
    }

    
    bool contains(const Point& point) const {
        return center.distanceTo(point) <= radius;
    }

    double getRadius() const {
        return radius;
    }

    void findPoints(const vector<Point>& points) const {
        cout << "\nPoints within " << radius
             << " km buffer:\n";

        bool found = false;

        for (int i = 0; i < points.size(); i++) {
            if (contains(points[i])) {
                cout << "Point " << i + 1 << ": ";
                points[i].display();
                cout << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No points found within this buffer.\n";
        }
    }
};

int main() {

    
    Point center(0, 0);

    
    vector<Point> points = {
        Point(1, 1),
        Point(2, 2),
        Point(3, 1),
        Point(4, 4),
        Point(5, 2),
        Point(6, 6)
    };

    
    vector<double> bufferSizes = {2, 4, 6};

    cout << "CENTER POINT: ";
    center.display();
    cout << endl;

    
    for (double radius : bufferSizes) {
        Buffer buffer(center, radius);
        buffer.findPoints(points);
    }

    return 0;
}
