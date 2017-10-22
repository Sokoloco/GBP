//
// Created by luis on 19/10/17.
//

#ifndef GBP_PATHFINDING_H
#define GBP_PATHFINDING_H

#include "/home/luis/CLionProjects/GBP/Structures/LinkedList.cpp"

class PathFinding {
private:
    int* map;
    int sizeX;
    int sizeY;
    int* path;
    struct mapNode{
        int x;
        int y;
        mapNode parent;
        int cost;
        bool operator==(mapNode a){
            return( a.x == x
                    && a.y == y);
        }
        bool operator<(mapNode a){
            return (cost < a.cost);
        }
        bool operator>(mapNode a){
            return (cost > a.cost);
        }
    };

    LinkedList<mapNode> closed,open;

public:
    int backTracking(int i, int j);
    PathFinding(int *map, int sizeX,int sizeY, int* path,int destinyY, int destinyX);
    void addOpen(int x, int y,int preX,int preY,int currentVal);
    mapNode getLowest();
//    PathFinding(int open[],int* map,int closed[],int sizeX,int sizeY, int* path,int destinyY, int destinyX);
    ~PathFinding();

    int aStar(int *open, int *closed, int i, int j, int currentVal);

    int aStar(int i, int j, int currentVal);

    int aStar(int i, int j);

    int aStar(int i, int j, mapNode current);

    int * aStar(int destinyX, int destinyY, int i, int j, mapNode current);

    int *getNextMove();
};


#endif //GBP_PATHFINDING_H
