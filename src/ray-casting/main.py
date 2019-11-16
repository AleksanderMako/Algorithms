import objects
import ray_casting


def main():
    polygon = objects.Polygon([objects.Point(20, 10), 
                               objects.Point( 50, 125),
                               objects.Point(125, 90),
                               objects.Point(150, 10)])
    p1 = objects.Point(75, 50)
    print("point p1 is inside :" + str(ray_casting.rayCasting(p1, polygon)))

    p2 = objects.Point(200, 50)
    print("point p2 is inside :" + str(ray_casting.rayCasting(p2, polygon)))

    p3 = objects.Point(35, 90)
    print("point p3 is inside :" + str(ray_casting.rayCasting(p3, polygon)))

    p4 = objects.Point(50, 10)
    print("point p4 is inside :" + str(ray_casting.rayCasting(p4, polygon)))

main()