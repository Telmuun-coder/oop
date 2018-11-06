package com.company;

public class Circle extends TwoDimensionalShape {

    /**
     * Тойргын анхдагч байгуулагч функц
     *
     * Circle гэсэн нэртэй
     * Радиосын нь 1
     * 0,0 цэг дээр координат дээр байгуулна
     */
//    }
    public Circle() {
        super("Circle", 1, 1);
    }
    /**
     * Тойргын байгуулагч функц өгөгдсөн координат, радиусын дагуу тойрог үүсгэнэ.
     *
     * @param name      - Шинээр үүсгэх тойргын нэр
     * @param radius    - Шинээр үүсгэх тойргын радиус
     * @param x         - Шинээр үүсгэх тойргын x координат
     * @param y         - Шинээр үүсгэх тойргын y координат
     */
    public Circle(String name, double radius, int x, int y) {
        super(name, 1, radius, x, y);
    }

    /**
     * Тойргын талбайг буцаана
     *
     * @return  double - Тойргын талбай
     */
    public double findArea() {
        return 3.141592653589793 * radius * radius;
    }
    /**
     * Тойргын преметерийг буцаана
     *
     * @return  double - Тойргын преметер
     */
    public double findPerimeter() {
        return 2 * 3.141592653589793 * radius;
    }
}
