
#include <iostream>
#include "vector.h"
int main(int argc, const char * argv[]) {
    int t=5;
    double a[]={5,79,4,12,7};
    vector v1(t,a);//tamaño y vector
    
    //v1.agre(1,1);
    //v1.vaci();
    //v1.app(54);
    //v1.del(0);
    //std::cout << "Mayor: " << v1.mayor() << std::endl;
    //std::cout << "Menor: " << v1.menor() << std::endl;
    //v1.orde();
    //v1.inver();
    
    //std::cout << "Mayor Primo: " << v1.pmayor() << std::endl;
    //std::cout << "Menor Primo: " << v1.pmenor() << std::endl;
    //std::cout << "Suma: " <<v1.suma() << std::endl;
    v1.impri();
}
