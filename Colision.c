#include "Colision.h"
#include <math.h>

int Colision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
    int radio1, radio2;
    int cx1=x1+(w1/2);
    int cy1=y1+(h1/2);
    int cx2=x2+(w2/2);
    int cy2=y2+(h2/2);

    if(w1>h1){
        radio1=h1;
    } else {
        radio1=w1;
    }

    if(w2>h2){
        radio2=h2;
    } else {
        radio2=w2;
    }

    if(sqrt(pow(cx1-cx2,2)+pow(cy1-cy2,2))<((radio1/2.0)+(radio2/2.0)))
    {
        return 1;
    }
    return 0;
}
