#include <allegro5/allegro.h>//must be here no matter what
#include <iostream>
#include "GUI/Map.h"
#include "Tests/Tests.h"

int main(int argc, char **argv){
    for(int i = 0;i<20;i++){
        std::cout<<(rand()% 5)<<std::endl;
    }
    //pathfindingTest();
    return 0;
}

/**Map* ok = new Map;
int ok [5][6];
int num = 0;
for (int i = 0;i<5;i++){
for(int j = 0;j<6;j++){
ok[i][j] = num++;
}
}
int* okp = *ok;
for (int i = 0;i<5;i++){
for(int j = 0;j<6;j++){
std::cout<<*(okp+i*(5+1)+j)<<std::endl;
}
}**/
