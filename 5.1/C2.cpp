#include <cstdio>

int main(){
    double w, h, d ,m;
    while (scanf("%lf %lf %lf %lf",&w,&h,&d,&m)&&(w+h+d+m)){
        double sum = w*h;
        sum /= m;
        int k = 1;
        while (double(h*(w-d))/2>=k*sum){
            if (k!=1) printf(" ");
            printf("%.3lf %.3lf",w,2*k*sum/(w-d));
            k++;
        }
        while (double(h*(2*w-d))/2>=k*sum){
            if (k!=1) printf(" ");
            printf("%.3lf %.3lf",2*w-2*k*sum/h-d,h);
            k++;
        }
        while (k<m) {
            if (k!=1) printf(" ");
            printf("%.3lf %.3lf",0.0,2*(m-k)*sum/d);
            k++;
        }
        printf("\n");
    }
}
