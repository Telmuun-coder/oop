package com.company;

public class Triangle extends TwoDimensionalShape {

    /**
     * Зөв гурвалжингийн анхдагч байгуулагч функц
     *
     * Triangle гэсэн нэртэй
     * Радиосын нь 1
     * 0,0 цэг дээр координат дээр байгуулна
     */
//    }
    Triangle() {
        super("Triangle", 3, 1);
    }
    /**
     * Зөв гурвалжингийн байгуулагч функц өгөгдсөн координат, радиусын дагуу тойрог үүсгэнэ.
     *
     * @param name      - Шинээр үүсгэх зөв гурвалжингийн нэр
     * @param radius    - Шинээр үүсгэх зөв гурвалжингийн радиус
     * @param x         - Шинээр үүсгэх зөв гурвалжингийн x координат
     * @param y         - Шинээр үүсгэх зөв гурвалжингийн y координат
     */
    Triangle(String name, double radius, int x, int y) {
        super(name, 3, radius, x, y);
    }

    /**
     * Зөв гурвалжингийн талбайг буцаана
     *
     * @return  double - Зөв гурвалжингийн
     * https://www.quora.com/What-is-the-area-of-an-equilateral-triangle-inside-a-circle-with-radius-of-10-cm
     */
    public double findArea() {
        return Math.sqrt(3.0) * 3/4 * getRadius() * getRadius();
    }

    /**
     * Зөв гурвалжингийн преметерийг буцаана
     *
     * @return  double - Зөв гурвалжингийн преметер
     */
    public double findPerimeter() {
        return 3 * getRadius();
    }
}