#include <iostream>
using namespace std;

class figura{
    string m_nazwa;
    string m_color;
public:
    figura(string nazwa,string color):m_nazwa(nazwa),m_color(color){

    }
    string getnazwa(){
        return m_nazwa;
    }
    string getcolor(){
        return m_color;
    }
    void printFigura(){
        cout << getnazwa() << "\t" << getcolor() << endl;
    }
};

class square : public figura{
protected:
    double m_a;
    double m_b;
public:
    square(double a, double b, string name = "square"): m_a(a),m_b(b), figura(name,"red"){
    }
    double areaSquare(){
        return this->m_b* this->m_a;
    }
    void printSquare(){
        printFigura();
        cout << m_a << ", " << m_b << endl;
    }
};
class triangle : protected square{
private:
    double m_h;
public:
    triangle(double h, double a,double b, string name = "Triangle"):m_h(h), square(a,b,name){
    }
    double areaTriangle(){
        return areaSquare()*0.5;
    }
    void printTriangle(){
        printSquare();
        cout << "and height: "<< m_h << endl;
    }
};
int main( int argc, char *argv[] ) {
   figura a("figura1", "purple");
   a.printFigura();
   square b(5,3);
   b.printSquare();
   cout << b.areaSquare() << endl;
   triangle c(2,5,3);
   c.printTriangle();
   cout << "area of Triangle: " << c.areaTriangle() << endl;

	return 0;
}