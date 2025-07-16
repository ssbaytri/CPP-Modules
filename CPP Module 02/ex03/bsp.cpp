#include "Point.hpp"
#include "Fixed.hpp"
#include <cmath>

Fixed triangleArea(Point const& a, Point const& b, Point const&c)
{
	Fixed area = (	a.getX() * (b.getY() - c.getY()) +
					b.getX() * (c.getY() - a.getY()) +
					c.getX() * (a.getY() - b.getY()));
	
	return Fixed(fabs(area.toFloat() / 2.0f));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed total = triangleArea(a, b, c);
	Fixed area1 = triangleArea(point, a, b);
	Fixed area2 = triangleArea(point, b, c);
	Fixed area3 = triangleArea(point, c, a);

	return area1 > 0 && area2 > 0 && area3 > 0 && (area1 + area2 + area3 == total);
}
