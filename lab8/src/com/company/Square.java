package com.company;

public class Square extends TwoDimensionalShape {

    /**
     * Тэгш өнцөгтийн анхдагч байгуулагч функц
     *
     * Square гэсэн нэртэй
     * Радиосын нь 1
     * 0,0 цэг дээр координат дээр байгуулна
     */
//    }
    public Square() {
        super("Square", 4, 1);
    }
    /**
     * Тэгш өнцөгтийн байгуулагч функц өгөгдсөн координат, радиусын дагуу тойрог үүсгэнэ.
     *
     * @param name      - Шинээр үүсгэх тэгш өнцөгтийн нэр
     * @param radius    - Шинээр үүсгэх тэгш өнцөгтийн радиус
     * @param x         - Шинээр үүсгэх тэгш өнцөгтийн x координат
     * @param y         - Шинээр үүсгэх тэгш өнцөгтийн y координат
     */
    public Square(String name, double radius, int x, int y) {
        super(name, 4, radius, x, y);
    }

    /**
     * Тэгш өнцөгтийн талбайг буцаана
     *
     * @return  double - Тойргын талбай
     */
    public double findArea() {
        return 2 * getRadius() * getRadius();
    }

    /**
     * Тэгш өнцөгтийн преметерийг буцаана
     *
     * @return  double - Тойргын преметер
     */
    public double findPerimeter() {
        return 4 * getRadius();
    }
}