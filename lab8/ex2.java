import static java.lang.Math.pow;
import static java.lang.Math.sqrt;

class Rectangle{
    private double a;
    private double b;

    public Rectangle(double a, double b){
        this.a = a;
        this.b = b;
    }

    public double area(){
        return this.a*this.b;
    }

    public double perimeter(){
        return (this.a+this.b) * 2;
    }
}

class Square extends Rectangle{

    public Square(double a) {
        super(a, a);
    }

}

class Ellipse{
    private double a;
    private double b;

    public Ellipse(double a, double b){
        this.a = a;
        this.b = b;
    }

    public double area(){
        return this.a/2 * this.b/2 * Math.PI;
    }

    public double perimeter(){
        return 2*Math.PI * sqrt(( (pow(this.a/2, 2) + pow(this.b/2, 2)) / 2 ));
    }
}

class Circle extends Ellipse{

    public Circle(double a) {
        super(a, a);
    }


}

class Triangle{
    private double a;
    private double b;
    private double c;

    public Triangle(double a, double b, double c){
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public double area(){
        double p = (this.a + this.b + this.c)/2;
        return sqrt(p * (p - this.a) * (p - this.b) * (p - this.c));
    }

    public double perimeter(){
        return this.a + this.b + this.c;
    }
}


public class ex2 {
    public static void main(String[] args) {
        Rectangle r = new Rectangle(10, 5);
        System.out.println(r.area() + " " + r.perimeter());
        Rectangle s = new Square(4);
        System.out.println(s.area() + " " + s.perimeter());

        Ellipse e = new Ellipse(12, 10);
        System.out.println(e.area() + " " + e.perimeter());
        Ellipse c = new Circle(5);
        System.out.println(c.area() + " " + c.perimeter());

        Triangle t = new Triangle(3, 4, 5);
        System.out.println(t.area() + " " + t.perimeter());
    }
}
