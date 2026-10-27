class Animal{
    private String name;
    private int height;
    private int weight;
    private String color;

    public Animal(String n, int h, int w, String c){
        this.name = n;
        this.height = h;
        this.weight = w;
        this.color = c;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public void makeSound(){
        System.out.println("Some sound");
    }

    public void sleep(){
        System.out.println("zZzZ");
    }

    public void eat(String food){
        System.out.println(this.name + " ate " + food);
    }

}

class Dog extends Animal{

    public Dog(String n, int h, int w, String c) {
        super(n, h, w, c);
    }

    @Override
    public void makeSound(){
        System.out.println("Woof-woof");
    }
}

class Cat extends Animal{

    public Cat(String n, int h, int w, String c) {
        super(n, h, w, c);
    }

    @Override
    public void makeSound(){
        System.out.println("meow-meow");
    }
}

class Cow extends Animal{

    public Cow(String n, int h, int w, String c) {
        super(n, h, w, c);
    }

    @Override
    public void makeSound(){
        System.out.println("moo-moo");
    }
}


public class ex1 {
    public static void main(String[] args) {
        Dog d = new Dog("Hero", 45, 70, "black");
        Cat c = new Cat("Meow", 25, 30, "gray");
        Animal a = new Cow("Momo", 100, 200, "white-brown");

        d.eat("snacks");
        d.sleep();
        d.makeSound();

        System.out.println();

        c.eat("fish");
        c.sleep();
        c.makeSound();

        System.out.println();

        a.eat("grass");
        a.sleep();
        a.makeSound();
    }
}
