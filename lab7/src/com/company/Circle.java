package com.company;

public class Circle extends TwoDimensionalShape {
    private double radius;

    /**
     * Тойргын анхдагч байгуулагч функц
     *
     * Нэрыг нь Default
     * Радиосын нь 1
     * Талын тоог нь 1
     * Талын уртыг нь тойргын перемерт
     */
    public Circle() {
        setName("Default");
        setRadius(1.0);
        setNumberOfSide(1);
        setCoordinats(getNumberOfSide());
        setCoordinat(0, 0, 0);
        setSideLength(findPerimeter());
    }

    /**
     * Тойргын байгуулагч функц 0 0 координатид өгсөн радиусын дагуу тойрог үүсгэнэ.
     */
    public Circle(String name, double radius) {
        setName(name);
        setRadius(radius);
        setNumberOfSide(1);
        setCoordinats(getNumberOfSide());
        setCoordinat(0, 0, 0);
        setSideLength(findPerimeter());
    }

    /**
     * Тойргын байгуулагч функц өгөгдсөн координат, радиусын дагуу тойрог үүсгэнэ.
     */
    public Circle(String name, double radius, int x, int y) {
        setName(name);
        setRadius(radius);
        setNumberOfSide(1);
        setCoordinats(getNumberOfSide());
        setCoordinat(0, x, y);
        setSideLength(findPerimeter());
    }

    // Get

    /**
     * Тойргийн радиусыг буцаана
     *
     * @return double   - Тойргийг радиус
     */
    public double getRadius() {
        return radius;
    }

    // Set
    /**
     * Тойргийн радиусыг өөрчилнө
     *
     * @param radius:double - Шинээр оноох тойргийн радиус
     */
    public void setRadius(double radius) {
        if (radius <= 0) {
            radius = 1;
        }
        this.radius = radius;
    }

    // Functions
    /**
     *
     * @return
     */
    public double findArea() {
        return 3.141592653589793 * radius * radius;
    }
    /**
     *
     * @return
     */
    public double findPerimeter() {
        return 2 * 3.141592653589793 * radius;
    }
}
