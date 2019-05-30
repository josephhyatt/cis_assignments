#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Struct for Point with x and y coordinates
struct Point {
    int xpos, ypos;
};

//Structure for triangle with three Points`
struct Triangle {
    Point a, b, c;

};

//Function to calculate distance between two Points to find the length of the edge
double getDist(const Point &p1, const Point &p2) {

    const double distX = (p1.xpos - p2.xpos);
    const double distXSquared = (distX * distX);
    const double distY = (p1.ypos - p2.ypos);
    const double distYSquared = (distY * distY);
    const double distXY = std::sqrt(distXSquared + distYSquared);
    return distXY;

}

//Calculate Perimeter by adding all the edges.
//I have added printouts for edges you can remove if you want.
void calculatePerimeter(Triangle t) {
    double perimeter = 0.0;
    Point x = t.a;
    Point y = t.b;
    Point z = t.c;
    double edgeA = getDist(x, y);
    cout << "edgeA=" << edgeA << endl;
    double edgeB = getDist(y, z);
    cout << "edgeB=" << edgeB << endl;
    double edgeC = getDist(z, x);
    cout << "edgeC=" << edgeC << endl;
    perimeter = edgeA + edgeB + edgeC;
    cout << "\nThe Perimeter Of The Triangle is= " << perimeter << endl;

}

int main() {
    Triangle triangle;

//declare three points
    Point A;
    Point B;
    Point C;

// read coordinates for 3 Points
    cout << "Please Enter x-coordinate of Point A:";
    cin >> A.xpos;
    cout << "Please Enter y-coordinate of Point A:";
    cin >> A.ypos;
    cout << "Please Enter x-coordinate of Point B:";
    cin >> B.xpos;
    cout << "Please Enter y-coordinate of Point B:";
    cin >> B.ypos;
    cout << "Please Enter x-coordinate of Point C:";
    cin >> C.xpos;
    cout << "Please Enter y-coordinate of Point C:";
    cin >> C.ypos;
    triangle.a = A;

    triangle.b = B;

    triangle.c = C;

//Call function to calculate Perimeter
    calculatePerimeter(triangle);
    return 0;

}