#include <iostream>
using namespace std;
const double pi = 3.14159265359;
class figura{
    string m_nazwa;
    string m_color;
public:
    figura(string nazwa = "default",string color = "default"):m_nazwa(nazwa),m_color(color){
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
    virtual double area() = 0;


};

class square : public figura{
public:
    double m_a;
    double m_b;

    square(double a = 2, double b = 3, string name = "square"): m_a(a),m_b(b), figura(name,"red"){
    }
    virtual double area() {
        return this->m_b* this->m_a;
    }
    void printSquare(){
        printFigura();
        cout << m_a << ", " << m_b << endl;
    }
};
class triangle : public square{
private:
    double m_h;
public:
    triangle(double h = 2, double a = 2,double b = 3, string name = "Triangle"):m_h(h), square(a,b,name){
    }
    virtual double area() {
        return square::area()*0.5;
    }
    void printTriangle(){
        printSquare();
        cout << "and height: "<< m_h << endl;
    }
};
class Circle : public figura{
private:
    double m_radius;
public:
    Circle(double radius):m_radius(radius), figura("circle","no color, wtf"){

    }
    virtual double area(){
        printFigura();
        return (m_radius*m_radius*pi);
    }
};
class Rectangle :  public figura{
private:
    double m_a;
    double m_b;
public:
    Rectangle(double a,double b):m_a(a),m_b(b), figura("rectangle","color? what"){

    }
    virtual double area(){
        return m_a*m_b;
    }

};
int main( int argc, char *argv[] ) {

     figura *circle = new Circle(5);
    figura *rectangle = new Rectangle(5, 18);
     cout << "Circle area: " << circle->area() << endl;
    cout << "Rectangle area: " << rectangle->area() << endl;


	return 0;
}