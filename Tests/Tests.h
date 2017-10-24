//
// Created by luis on 22/10/17.
//

#ifndef GBP_TESTS_H
#define GBP_TESTS_H

#include "../Pathfinding/PathFinding.h"

int map[5][5] = {
        1,0,0,0,0,
        1,1,1,1,1,
        0,1,0,0,0,
        1,1,1,1,1,
        0,0,0,1,1

};

/**void sortingTest(){
//Map* ok = new Map();
    LinkedList<mapNode>* ok = new LinkedList<mapNode>;
    mapNode one ={1,1,NULL,5};
    mapNode two ={1,2,NULL,24};
    mapNode three={1,3,NULL,78};
    mapNode four = {1,4,NULL,3};
    mapNode five = {1,5,NULL,1};
    mapNode six = {1,6,NULL,9};
    mapNode mapArr[6] = {one,two,three,four,five,six};
    for(int i = 0;i<6;i++){
//mapArr[i].cost = i;
        ok->add(mapArr[i]);
    }
    ok->remove(mapArr[4]);
    ok->sort();
    ok->remove(three);
    ok->run();}**/
void pathfindingTest(){
    PathFinding test(*(map),4,4);
    test.aStar(4,4,0,0,NULL);
}
#endif //GBP_TESTS_H
