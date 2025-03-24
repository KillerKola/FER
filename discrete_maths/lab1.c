#include<stdio.h>
#include<math.h>

unsigned long long povrh(int n,int k)
{
    unsigned long long ans=1;
    k = k > n-k ? n-k : k;
    int j = 1;
    for(; j <= k; j++, n--){
        if(n % j == 0){
            ans *= n / j;
        }else
        if(ans % j == 0){
            ans = ans / j*n;
        }else{
            ans = (ans*n) / j;
        }
    }
    return ans;
}

int main(void){
    
    unsigned long long a, b, c, d, e, n, pot = 5, sol = 0;
    printf("Unesite broj vrecica caja Bohea (parametar a):");
     scanf("%llu", &a);
    printf("Unesite broj vrecica caja Congou (parametar b):");
     scanf("%llu", &b);
    printf("Unesite broj vrecica caja Souchong (parametar c):");
     scanf("%llu", &c);
    printf("Unesite broj vrecica caja Singlo (parametar d):");
      scanf("%llu", &d);
    printf("Unesite broj vrecica caja Hyson (parametar e):");
      scanf("%llu", &e);
    printf("Unesite broj n:");
      scanf("%llu", &n);

    //provjeravanje je li broj ikojeg caja 0 (potencija 1/(1-x))
    if(a == 0)pot--;
    if(b == 0)pot--;
    if(c == 0)pot--;
    if(d == 0)pot--;
    if(e == 0)pot--;
    
    if(a == -1)a = n;
    if(b == -1)b = n;
    if(c == -1)c = n;
    if(d == -1)d = n;
    if(e == -1)e = n;

    if(0 <= n){
        sol += povrh(n+pot-1, pot-1);
    }
    if(a + 1 <= n && a > 0){
        sol -= povrh(n+pot-1 - (a+1), pot-1);
    }
    if(b + 1 <= n && b > 0){
        sol -= povrh(n+pot-1 - (b+1), pot-1);
    }
    if(c + 1 <= n && c > 0){
        sol -= povrh(n+pot-1 - (c+1), pot-1);
    }
    if(d + 1 <= n && d > 0){
        sol -= povrh(n+pot-1 - (d+1), pot-1);
    }
    if(e + 1 <= n && e > 0){
        sol -= povrh(n+pot-1 - (e+1), pot-1);
    }
    if(a + b + 2 <= n && a > 0 && b > 0){
        sol += povrh(n+pot-1 - (a+b+2), pot-1);
    }
    if(a + c + 2 <= n && a > 0 && c > 0){
        sol += povrh(n+pot-1 - (a+c+2), pot-1);
    }
    if(a + d + 2 <= n && a > 0 && d > 0){
        sol += povrh(n+pot-1 - (a+d+2), pot-1);
    }
    if(a + e + 2 <= n && a > 0 && e > 0){
        sol += povrh(n+pot-1 - (a+e+2), pot-1);
    }
    if(b + c + 2 <= n && b > 0 && c > 0){
        sol += povrh(n+pot-1 - (b+c+2), pot-1);
    }
    if(b + d + 2 <= n && b > 0 && d > 0){
        sol += povrh(n+pot-1 - (b+d+2), pot-1);
    }
    if(b + e + 2 <= n && b > 0 && e > 0){
        sol += povrh(n+pot-1 - (b+e+2), pot-1);
    }
    if(c + d + 2 <= n && c > 0 && d > 0){
        sol += povrh(n+pot-1 - (c+d+2), pot-1);
    }
    if(c + e + 2 <= n && c > 0 && e > 0){
        sol += povrh(n+pot-1 - (c+e+2), pot-1);
    }
    if(d + e + 2 <= n && d > 0 && e > 0){
        sol += povrh(n+pot-1 - (d+e+2), pot-1);
    }
    if(a + b + c + 3 <= n && a > 0 && b > 0 && c > 0){
        sol -= povrh(n+pot-1 - (a+b+c+3), pot-1);
    }
    if(a + b + d + 3 <= n && a > 0 && b > 0 && d > 0){
        sol -= povrh(n+pot-1 - (a+b+d+3), pot-1);
    }
    if(a + b + e + 3 <= n && a > 0 && b > 0 && e > 0){
        sol -= povrh(n+pot-1 - (a+b+e+3), pot-1);
    }
    if(a + c + d + 3 <= n && a > 0 && c > 0 && d > 0){
        sol -= povrh(n+pot-1 - (a+c+d+3), pot-1);
    }
    if(a + c + e + 3 <= n && a > 0 && c > 0 && e > 0){
        sol -= povrh(n+pot-1 - (a+c+e+3), pot-1);
    }
    if(a + d + e + 3 <= n && a > 0 && d > 0 && e > 0){
        sol -= povrh(n+pot-1 - (a+d+e+3), pot-1);
    }
    if(b + c + d + 3 <= n && b > 0 && c > 0 && d > 0){
        sol -= povrh(n+pot-1 - (b+c+d+3), pot-1);
    }
    if(b + c + e + 3 <= n && b > 0 && c > 0 && e > 0){
        sol -= povrh(n+pot-1 - (b+c+e+3), pot-1);
    }
    if(b + d + e + 3 <= n && b > 0 && d > 0 && e > 0){
        sol -= povrh(n+pot-1 - (b+d+e+3), pot-1);
    }
    if(c + d + e + 3 <= n && c > 0 && d > 0 && e > 0){
        sol -= povrh(n+pot-1 - (c+d+e+3), pot-1);
    }
    if(a + b + c + d + 4 <= n && a > 0 && b > 0 && c > 0 && d > 0){
        sol += povrh(n+pot-1 - (a+b+c+d+4), pot-1);
    }
    if(a + b + c + e + 4 <= n && a > 0 && b > 0 && c > 0 && e > 0){
        sol += povrh(n+pot-1 - (a+b+c+e+4), pot-1);
    }
    if(a + b + d + e + 4 <= n && a > 0 && b > 0 && d > 0 && e > 0){
        sol += povrh(n+pot-1 - (a+b+d+e+4), pot-1);
    }
    if(a + c + d + e + 4 <= n && a > 0 && c > 0 && d > 0 && e > 0){
        sol += povrh(n+pot-1 - (a+c+d+e+4), pot-1);
    }
    if(b + c + d + e + 4 <= n && e > 0 && b > 0 && c > 0 && d > 0){
        sol += povrh(n+pot-1 - (b+c+d+e+4), pot-1);
    }

    if(pot == 0 || (a+b+c+d+e) < n){
        if(n == 0) {
            sol = 1;
        } else sol = 0;
    } else if(pot == 1){
        sol = 1;
    }

    printf("Gradjani Bostona mogu napraviti %llu razlicitih cajanki.", sol);

    return 0;
}
