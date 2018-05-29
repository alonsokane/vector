

#ifndef vector_h
#define vector_h
class vector{
private:
    int t;
    bool verprimo(int);
public:
    vector();
    vector(int);
    vector(int, double *);
    ~vector();
    double *a;
    void app(double);
    void del(int);
    void agre(int,double);
    void vaci();
    void impri();
    void orde();
    void inver();
    double mayor();
    double menor();
    double pmayor();
    double pmenor();
    double suma();
    
};


#endif /* vector_h */
