import sys


def rayCasting(point, polygon):
    edgeList = []
    edgeList = polygon.getEdges()
    _eps = 0.00001
    intersects = False
    # assign a an b
    # check if point is above b or below y
    # check if p is to the right of the line
    for edge in edgeList:

        A, B = edge[0], edge[1]
        if A.y > B.y:
            A, B = B, A

        if point.y > B.y or point.y < A.y or point.x > max(A.x, B.x):
            continue

        if point.y == A.y or point.y == B.y:
            point.y += _eps

        if point.x < min(A.x, B.x):
            intersects = not intersects
            continue

        APslope = slope(A, point)
        ABslope = slope(A, B)
        if APslope >= ABslope:
            intersects = not intersects
            continue

    return intersects


def slope(p1, p2):
    try:
        slope = (p2.y - p1.y) / (p2.x - p1.x)
        return slope
    except ZeroDivisionError:
        slp = 1000000000
        return slp
