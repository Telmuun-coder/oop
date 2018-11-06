package com.company;

public class Main {

    public static void main(String[] args) {
        Circle a = new Circle();
        Square b = new Square();
        Triangle c = new Triangle();

        System.out.println(a.getName() + " Area: " + a.findArea());
        System.out.println(b.getName() + " Area: " + b.findArea());
        System.out.println(c.getName() + " Area: " + c.findArea());
    }
}
