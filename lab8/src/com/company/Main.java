package com.company;

public class Main {

    public static void main(String[] args) {
        int size = 10;
        TwoDimensionalShape[] shapes = new TwoDimensionalShape[size];


        for (int i = 0; i < size; i++) {
            int n = (int) (Math.random() * 100 + 1);
            double radius = Math.random() * 50 + 1;

            switch (n % 3) {
                case 0:
                    shapes[i] = new Circle("Circle_" + i, radius, 0, 0);
                    break;
                case 1:
                    shapes[i] = new Square("Square_" + i, radius, 0, 0);
                    break;
                case 2:
                    shapes[i] = new Triangle("Triangle_" + i, radius, 0, 0);
                    break;
                default:
                    break;
            }
        }

        TwoDimensionalShape.sortShapesByArea(shapes);


        for (int i = 0; i < size; i++) {
            System.out.println("Area of " + shapes[i].getName() + " is: " + shapes[i].findArea());
        }
    }
}
