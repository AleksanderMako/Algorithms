 
# jordan curve theorem: any non self intersecting curve(simple curve )cuts the plane in two parts.The inside part and the outside part
# ray casting algorithm if a ray starting from point x cuts the curve an even number of times it is outside it and if it cuts it an odd number of times it is
# inside


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


class Polygon:
    def __init__(self, points):
        self.points = points

    def getEdges(self):
        edgeList = []

        for index, point in enumerate(self.points):
            point1 = point
            point2 = self.points[(index+1) % len(self.points)]
            edgeList.append((point1, point2))
        
        return edgeList
