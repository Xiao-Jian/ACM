#include <stdio.h>

int main()
{
    int i,j,k,workers,flag=1;
    double width,height,door;
    double node[105][2];
    while(1) {
        scanf("%lf %lf %lf %d",&width,&height,&door,&workers);
        if(width==0) break;
        double s = width*height;
        double each = s/workers;
        double s1 = height*door/2;
        double s2 = height*(width-door)/2;
        double x=0,area=0;
        for(i=0;i<workers-1;i++) {
            if(each<=s1) {
                node[i][0]=0;
                node[i][1]=2*each/door+x;
                x=node[i][1];
                s1-=each;
                area+=each;
            }
            else if(s1>0) {
                x=each-s1;
                if(x>(s-s2)-door*height/2) {
                    node[i][0]=width;
                    node[i][1]=height-2*(area+each-s+s2)/(width-door);
                    s1=0;
                }
                else {
                    node[i][1]=height;
                    node[i][0]=2*x/height;
                    s1=0;
                }
                area+=each;
            }
            else if(area<=(s-s2)) {
                x=node[i-1][0];
                area+=each;
                if(area<=(s-s2)) {
                    node[i][1]=height;
                    node[i][0]=x+2*each/height;
                }
            }
            else if(flag) {
                node[i][0]=width;
                x=area-(s-s2);
                node[i][1]=height-2*x/(width-door);
                s2-=x;
                x=node[i][1];
                flag=0;
            }
            else if(s2>0) {
                node[i][0]=width;
                node[i][1]=x-2*each/(width-door);
                x=node[i][1];
                s2-=each;
            }
        }
        for(i=workers-2;i>0;i--)
            printf("%.3lf %.3lf ",node[i][0],node[i][1]);
        printf("%.3lf %.3lf\n",node[0][0],node[0][1]);
    }
}
