#include <stdio.h>

int main()
{
    int i,j,k,flag=1;
    double width,height,door,workers;
    double node[105][2];
    while(scanf("%lf %lf %lf %lf",&width,&height,&door,&workers)&&(width+height+door+workers)) {
        double s = width*height;
        double each = s/workers;
        for(i=1;i<workers;i++) {
            if(double(height*(width-door))/2>i*each) {
                node[i][0]=width;
                node[i][1]=2*i*each/(width-door);
            }
            else if(double(height*(2*width-door))/2>=i*each) {
                node[i][0]=2*width-2*i*each/height-door;
                node[i][1]=height;
            }
            else {
                node[i][0]=0.0;
                node[i][1]=2*(workers-i)*each/door;
            }
        }
        for(i=1;i<workers-1;i++)
            printf("%.3lf %.3lf ",node[i][0],node[i][1]);
        printf("%.3lf %.3lf\n",node[int(workers)-1][0],node[int(workers)-1][1]);
    }
}
