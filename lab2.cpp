#include <bits/stdc++.h>

using namespace std;


unsigned long long gcd(unsigned long long a,unsigned long long b){
    
    while(b != 0){
        unsigned long long t = a%b;
        a = b;
        b = t;
    }
    return a;
}

unsigned long long power(unsigned long long b,unsigned long long e,unsigned long long m){
    unsigned long long res = 1;
    b = b%m;
    while(e > 0){
        if(e%2 != 0){
            res = (res*b)%m;
        }
        e = e/2;
        b = (b*b)%m;
    }
    return res;
}

bool primeTesting(unsigned long long n){
    
    if(n <= 1 && n == 4){
        return false;
    }
    if(n <= 3){
        return true;
    }
    
    int k = 100;
    while(k--){
        unsigned long long a = 2 + rand()%(n-4);
        if(gcd(n,a) != 1){
            return false;
        }
        if(power(a,n-1,n)!= 1){
            return false;
        }
    }
    return true;
}



int main()
{
    unsigned long long n=561;
    // cin>>n;
    srand(time(NULL));
    int cn  = 0;
    for(int i = 2; i <= n - 2; i++){
        if(power(i,n-1,n) == 1l){
            cn++;
        }
    }
    cout<<cn<<endl;
    cout<<(float)cn/(n-3)<<endl;

    if(primeTesting(n)){
        cout<<"Prime"<<endl;
    }
    else{
        cout<<"notPrime"<<endl;
    }

    return 0;
}



