import java.util.ArrayList;

class Author{
    private String name;
    private String email;
    private char gender;

    public Author(String name, String email, char gender){
        this.name = name;
        this.email = email;
        this.gender = gender;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public char getGender() {
        return gender;
    }

    public void setGender(char gender) {
        this.gender = gender;
    }

    @Override
    public String toString() {
        return "Author[" +
                "name=" + name +
                ",email=" + email +
                ",gender=" + gender +
                ']';
    }
}

class Book{
    private String name;
    private Author author;
    private double price;
    private int qty;

    public Book(String name, Author author, double price){
        this.name = name;
        this.author = author;
        this.price = price;
    }

    public Book(String name, Author author, double price, int qty){
        this.name = name;
        this.author = author;
        this.price = price;
        this.qty = qty;
    }

    public String getName(){
        return name;
    }

    public Author getAuthor(){
        return author;
    }

    public double getPrice(){
        return price;
    }

    public void setPrice(double price){
        this.price = price;
    }

    public int getQty() {
        return qty;
    }

    public void setQty(int qty){
        this.qty = qty;
    }

    @Override
    public String toString() {
        return "Book[" +
                "name=" + name +
                "," + author.toString() +
                ",price=" + price +
                ",qty=" + qty +
                ']';
    }
}

class Library{
    private ArrayList<Book> books;

    public Library(ArrayList<Book> books){
        this.books = books;
    }

    public ArrayList<Book> getBooks() {
        return books;
    }

    public void setBooks(ArrayList<Book> books) {
        this.books = books;
    }

    public void addBook(Book b){
        this.books.add(b);
    }

    public void removeBook(Book b){
        this.books.remove(b);
    }

    public void displayBooks(){
        for (int i = 0; i < this.books.size(); i++) {
            System.out.println(i+1 + " book - " + books.get(i).toString());
        }
    }

    @Override
    public String toString() {
        return "Library{" +
                "books=" + books +
                '}';
    }
}

public class ex2 {
    public static void main(String[] args){
        // creating authors
        Author Pushkin = new Author("Pushkin", "-", 'm');
        Author Esenin = new Author("Esenin", "-", 'm');

        // creating books
        Book RiL = new Book("Ruslan i Ludmila", Pushkin, 1200);
        Book Yeseninspoems = new Book("Yesenin\'s poems", Esenin, 1200, 100);

        // creating library
        Library MainLibrary = new Library(new ArrayList<Book>());

        // adding books to library
        MainLibrary.addBook(RiL);
        MainLibrary.addBook(Yeseninspoems);

        // printing library
        MainLibrary.displayBooks();
        System.out.println();

        // removing books
        MainLibrary.removeBook(RiL);

        // printing library
        MainLibrary.displayBooks();
        System.out.println();

        // adding books to library
        MainLibrary.addBook(RiL);

        // changing states
        RiL.setPrice(1000);
        Yeseninspoems.setPrice(900);
        RiL.setQty(100);
        Yeseninspoems.setQty(10);

        // printing library
        MainLibrary.displayBooks();
        System.out.println();
    }
}
