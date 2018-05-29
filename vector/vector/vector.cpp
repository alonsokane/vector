
#include "vector.h"
#include <iostream>
vector::vector(){
    t=0;
    a=new double[t];
    
}
vector::vector(int tm){
    t=tm;
    a=new double[t];
    for (double *ptr=a; ptr != a+t;ptr++){
        *ptr=0;
    }
}
vector::vector(int tm, double *x){
    t=tm;
    a=new double [t];
    for (double *ptr=a;ptr!=a+t;ptr++,x++){
        *ptr=*x;
    }
    
}
bool vector::verprimo(int x){
    if (x<=1){
        return false;
    }
    for (int i=2;i<x;i++){
        if (!(x%i)){
            return false;
        }
    }
    return true;
}
void vector::app(double x=0){
        t+=1;
        double *ar=new double[t];
        for (double *ptr=ar, *ptr1=a;ptr!=ar+t-1;ptr++,ptr1++){
            *ptr=*ptr1;
        }
        delete [] a;
        a=ar;
        double *ptr=a+t-1;
        *ptr=x;
        }
void vector::del(int x){
    t--;
    double *ar=new double [t];
    int i=0;
    double *ptr=a;
    double *ptr1=ar;
    while (ptr <a+t+1){
        if (i==x){
            ptr++;
            i++;
            continue;
        }
        *ptr1=*ptr;
        ptr1++;
        ptr++;
        i++;
        
    }
    delete[] a;
    a=ar;
}
void vector::agre(int in, double v){
    t++;
    double *ar=new double[t];
    double *ptr= a;
    double *ptr1=ar;
    int i=0;
    while (ptr1<ar+t){
        if (i==in){
            *ptr1=v;
            ptr1++;
            i++;
            continue;
        }
        *ptr1=*ptr;
        ptr1++;
        ptr++;
        i++;
    }
    delete[] a;
    a=ar;
    
}

void vector::vaci(){
    t=0;
    double *ar=new double [0];
    delete[] a;
    a=ar;
}
void vector::orde(){
    double *ini;
    double cam;
    for (double *ptr=a;ptr<a+t;ptr++){
        ini=ptr;
        for (double *ptr1=ptr;ptr1<a+t;ptr1++){
            if (*ptr1<*ini){
                ini=ptr1;}}
        cam=*ini;
        *ini=*ptr;
        *ptr=cam;
    
    }
    
}
void vector::inver(){
    double cam;
    for (double *ptr=a,*ptr1=a+t-1;ptr<a+t/2;ptr++,ptr1--){
        cam=*ptr;
        *ptr=*ptr1;
        *ptr1=cam;
    }
}
void vector::impri(){
    if (t==0){
        std::cout<<0<<std::endl;
        return ;
    }
    for(double *ptr=a;ptr<a+t;ptr++){
        std::cout<<*ptr<<" ";
    }
    std::cout<<'\n';
}
double vector::mayor(){
    double ma=*a;
    for (double *ptr =a+1; ptr<a+t;ptr++){
        if (*ptr>ma){
            ma=*ptr;
        }
    }
    return ma;
}
double vector::menor(){
    double me=*a;
    for (double *ptr =a+1; ptr<a+t;ptr++){
        if (*ptr<me){
            me=*ptr;
        }
    }
    return me;
}
double vector::pmayor(){
    double mayor =-999999;
    for(double *ptr=a;ptr<a+t;ptr++){
        if (verprimo(*ptr)){
            if (*ptr>mayor){
                mayor=*ptr;
            }
        }
    }
    return mayor;
}
double vector::pmenor(){
    double menor =999999;
    for(double *ptr=a;ptr<a+t;ptr++){
        if (verprimo(*ptr)){
            if (*ptr<menor){
                menor=*ptr;
            }
        }
    }
    return menor;
}
double vector::suma(){
    double su=0;
    for (double *ptr=a;ptr<a+t;ptr++){
        su+=*ptr;
    }
    return su;
}

vector::~vector(){delete[] a;}
