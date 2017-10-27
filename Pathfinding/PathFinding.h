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
        mapNode* parent;
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
    PathFinding(int *map, int sizeX, int sizeY);
    PathFinding(int *map, int sizeX, int sizeY,int* path);
    mapNode getLowest();
    int *getNextMove();
    int *aStar(int destinyX, int destinyY, int i, int j, mapNode *current);
    int backTracking(int i, int j, int destinyX, int destinyY);
};


#endif //GBP_PATHFINDING_H
