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

void factorization(int a, int b, int c) {
    if(b*b - 4*a*c<0) {
        printf("%g+%gi\n%g%gi\n", -(double)b/2, sqrt(abs(b*b-4*a*c))/2, -(double)b/2,  -sqrt(abs(b*b-4*a*c))/2);
    } else {
        printf("%g\n%g\n", (-b + sqrt(b*b-4*a*c))/2, (-b - sqrt(b*b-4*a*c))/2);
    }
}

char * df(int a) {
    char *res = malloc(sizeof(char)*100); // 최종 문자열
    strcpy(res, "");
    
    for(int i = a; i>0; i--) {
        int n;
        scanf("%d", &n); // 계수 입력
        
        char r[100]; // 문자열을 임시저장할 변수
        char x[100];
        
        sprintf(r, "%d", n*i); // n*계수를 문자열로 r에 저장
        strcat(res, n*(i) < 0 ? "" : "+"); // 부호 붙이기
        strcat(res, r); // 문자열 합치기
        
        if(i==2) { // 만약 x^1 일 경우
            strcat(res, "x");
        }
        else if(i!=1) {
            strcat(res, "x^");
            sprintf(x, "%d", i-1); // 미분된 계수를 추가
            strcat(res, x);
        }
    }
    return res[0] == '+' ? res+1 : res; // 맨 처음 부호를 없애기 위해
}
int derivative(int a, int x) {
    int num = 0; // 순간변화율
    for(int i = a; i>0; i--) { // 최고차항의 차수만큼 반복
        int n;
        scanf("%d", &n); // 계수 입력받기
        
        int tn = i*n; // 차수 * 계수
        for(int j = i-1; j>0; j--) {
            tn*=x; // x의 제곱만큼 곱하기
        }
        num+=tn;
    }
    return num;
}

double integral(int a, int x1, int x2) {
    double j = a+2,val1,val2,tn1,tn2;

    val1=val2=0;
    while(j--) {
        if(j==0) break;
        double n;
        scanf("%lf", &n);
        tn1 = tn2 = n/j;
        for(int i=j;i>0;i--){
            tn1*=x1;
            tn2*=x2;
        }
        val1+=tn1;
        val2+=tn2;
    }
    return fabs(val1 - val2);
}

double* Riemann(int a /* 최고차항의 차수 */, int x1, int x2 /* 폐구간 정의 */) {
    double xh = fabs((double)x1 - (double)x2)/1000000; // 폐구간 사이를 1000000개로 나눔
    double *sum = malloc(sizeof(double)*2); // 리만 오른쪽 합과 왼쪽 합의 배열
    int coef[a+1]; // 계수를 저장할 배열
    for(int i = a+1; i>0; i--) {
        scanf("%d", &coef[i-1]); // 계수 입력
    }
    for(int i = 0; i<1000000; i++) { // 1000000개로 나눈 구간 각각의 넓이를 구해서 sum에 저장
        for(int j = a+1; j>0; j--) { // 항의 갯수 만큼 반복
            double tmp1 = 0, tmp2 = 0;
            tmp1 += coef[j-1]; tmp2 += coef[j-1];
            for(int k = j-1; k>0; k--) { // x의 차수를 곱하기
                tmp1 *= ((x1 < x2 ? x1 : x2)+(xh*(i+1))); // 오른쪽 y
                tmp2 *= ((x1 < x2 ? x1 : x2)+(xh*(i))); // 왼쪽 y
            }
            sum[0] += tmp1*xh; // 오른쪽 넓이
            sum[1] += tmp2*xh; // 왼쪽 넓이
        }
    }
    return sum;
}

int main(void) {
    int a, x1, x2;
    scanf("%d %d %d", &a, &x1, &x2);
    double *res = Riemann(a, x1, x2);
    printf("%g\n%g\n", res[0], res[1]);
}

