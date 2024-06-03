// 수학적 계산
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// 사칙연산
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a*b;
}

int quotient(int a, int b) {
    if(!b) return 0;
    else return a/b;
}

int remain(int a, int b) {
    return a%b;
}

int power(int a, int b) {
    int sum = 1;
    while(b--) {
        sum *= a;
    }
    return sum;
}

void quadfunc(int a, int b, int c) {
//    ax2 + bx + c;
//    a(x2 + b/ax + b2/4a2 - b2/4a2) + c;
//    a(x2 + b/ax + b2/4a2) - b2/4a + c;
//    a(x + b/2a)2 -b2/4a + c;
    if(a<0) {
        printf("최댓값 : %d\n", -(b*b)/(4*a) + c);
    } else {
        printf("최솟값 : %d\n", -(b*b)/(4*a) + c);
    }
    
}

void quadfunc_xscope(int a, int b, int c, int xmin, int xmax) {
    //    ax2 + bx + c;
    //    a(x2 + b/ax + b2/4a2 - b2/4a2) + c;
    //    a(x2 + b/ax + b2/4a2) - b2/4a + c;
    //    a(x + b/2a)2 -b2/4a + c;
    int rmax, rmin;
    if(-b/(2*a) <= xmax && -b/(2*a) >= xmin) {
        if(a>0) {
            rmin = -(b*b)/(4*a) + c;
            rmax = -b/(2*a) - xmax > -b/(2*a) - xmin ? a*(xmin + b/(2*a))*(xmin + b/(2*a)) - (b*b)/(4*a) + c : a*(xmax + b/(2*a))*(xmax + b/(2*a)) - (b*b)/(4*a) + c;
        } else {
            rmax = -(b*b)/(4*a) + c;
            rmin = -b/(2*a) - xmax < -b/(2*a) - xmin ? a*(xmin + b/(2*a))*(xmin + b/(2*a)) - (b*b)/(4*a) + c : a*(xmax + b/(2*a))*(xmax + b/(2*a)) - (b*b)/(4*a) + c;
        }
    } else {
        if(-b/(2*a) - xmax > -b/(2*a) - xmin) {
            rmax = a*(xmin + b/(2*a))*(xmin + b/(2*a)) - (b*b)/(4*a) + c;
            rmin = a*(xmax + b/(2*a))*(xmax + b/(2*a)) - (b*b)/(4*a) + c;
        } else {
            rmin = a*(xmin + b/(2*a))*(xmin + b/(2*a)) - (b*b)/(4*a) + c;
            rmax = a*(xmax + b/(2*a))*(xmax + b/(2*a)) - (b*b)/(4*a) + c;
        }
    }
    
    printf("최댓값 : %d 최솟값 : %d\n", rmax, rmin);
}

int abs(int a) {
    if(a<0) {
        return -a;
    } else {
        return a;
    }
}

void factorization(int a, int b, int c) {
    if(b*b - 4*a*c<0) {
        printf("%g+%gi\n%g%gi\n", -(double)b/2, sqrt(abs(b*b-4*a*c))/2, -(double)b/2,  -sqrt(abs(b*b-4*a*c))/2);
    } else {
        printf("%g\n%g\n", (-b + sqrt(b*b-4*a*c))/2, (-b - sqrt(b*b-4*a*c))/2);
    }
}

char * df(int a) {
    char *res = malloc(sizeof(char)*100);
    strcpy(res, "");
    for(int i = a+1; i>0; i--) {
        if(i==1) break;
        int n;
        scanf("%d", &n);
        char k[100];
        char x[100];
        sprintf(k, "%d", n*(i-1));
        strcat(res, n*(i-1) < 0 ? "" : "+");
        strcat(res, k);
        if(i==3) {
            strcat(res, "x");
        }
        else if(i!=2) {
            strcat(res, "x^");
            sprintf(x, "%d", i-2);
            strcat(res, x);
        }
    }
    return res+1;
}
int derivative(int a, int x) {
    int num = 0;
    for(int i = a+1; i>0; i--) {
        if(i==1) break;
        int n;
        scanf("%d", &n);
        int j = i-1;
        int tn = j*n;
        j--;
        while(j--) {
            tn*=x;
        }
        num+=tn;
    }
    return num;
}

double integral(int a, int x1, int x2) {
    double j = a+2;
    double val1 = 0;
    double val2 = 0;
    while(j--) {
        if(j==0) break;
        double n;
        scanf("%lf", &n);
        double k = j;
        double tn1 = n/j;
        double tn2 = n/j;
        while(k--) {
            tn1*=x1;
            tn2*=x2;
        }
        val1+=tn1;
        val2+=tn2;
    }
    return val1 > val2 ? val1 - val2 : val2 - val1;
}
int main() {
    int a;
    scanf("%d", &a);
    printf("%s", df(a));
}
