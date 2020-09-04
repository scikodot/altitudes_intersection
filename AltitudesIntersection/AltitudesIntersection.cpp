#include "R2Graph/R2Graph.h"

using namespace std;

R2Point getAltsIntPoint(const R2Point& p1, const R2Point& p2, const R2Point& p3);

int main()
{
    R2Point p1, p2, p3;
    while (true)
    {
        cout << "Enter vertices of a triangle: " << endl;
        cin >> p1 >> p2 >> p3;
        if (cin.bad())
            break;

        R2Point intPoint = getAltsIntPoint(p1, p2, p3);
        cout << "Altitudes intersection point: " << intPoint << endl;
    }

    return 0;
}

R2Point getAltsIntPoint(const R2Point& p1, const R2Point& p2, const R2Point& p3)
{
    R2Vector v1 = p2 - p1, v2 = p3 - p2;  // direction vectors of two sides of a triangle
    R2Vector n1 = v1.normal(), n2 = v2.normal();  // direction vectors of two altitudes of a triangle

    R2Point intPoint;
    intersectStraightLines(p3, n1, p1, n2, intPoint);  // find an intersection point of two determined altitudes

    return intPoint;
}
