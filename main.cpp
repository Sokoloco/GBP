//#include <stdio.h>
//#include <allegro5/allegro.h>//must be here no matter what
//#include <iostream>
//#include <opencv2/core/types_c.h>
//#include <highgui.h>
//#include "GUI/Map.h"
//#include "Tests/Tests.h"
#include "GUI/Map2.h"

int main(int argc, char **argv){
    /**IplImage *img = cvLoadImage ("imagen.png");
    cvNamedWindow ("Ventana", CV_WINDOW_AUTOSIZE);
    cvShowImage ("Ventana", img);
    cvWaitKey (0);
    cvReleaseImage (&img);
    cvDestroyWindow ("Ventana"); **/
    //Map* ok = new Map;

    Map2* ok = new Map2;
    //pathfindingTest();
    //
    //for(int i=0; i< 20; i++){
      //  std::cout<<(rand()%14)<<std::endl;
    //}
    return 0;
}
