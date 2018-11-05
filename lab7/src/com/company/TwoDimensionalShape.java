package com.company;

public class TwoDimensionalShape extends Shape {
    // Тухайн 2 хэмжээст бие хэдэн талтайг заана
    protected int numberOfSide;
    // Нэг талын утыг заана
    protected double sideLength;
    // 2 хэмжээст бие координатын заана
    protected double coordinats[][];

    // Get
    /**
     * 2 хэмжээст дүрсийн талын тоог авна
     *
     * @return  int   - 2 хэмжээст дүрсийн талын тоо
     */
    public int getNumberOfSide() {
        return numberOfSide;
    }

    /**
     * 2 хэмжээст дүрсийн талын уртыг авна
     *
     * @return  double  - 2 хэмжээст дүрсийн нэг талын урт
     */
    public double getSideLength() {
        return sideLength;
    }

    /**
     * 2 хэмжээст дүрсийн оройн координатуудыг авна
     *
     * @return  double  - 2 хэмжээст дүрсийн нэг талын урт
     */
    public double[][] getCoordinats() {
        return coordinats;
    }

    /**
     * 2 хэмжээст дүрсийн оройн координатыг авна
     *
     * @param   row     :int - авах координатын мөр
     *
     * @return  double  - 2 хэмжээст дүрсийн нэг талын урт
     */
    public double[] getCoordinat(int row) {
        return coordinats[row];
    }

    // Set
    /**
     * Талын тоог шинэчлнэ
     *
     * @param numberOfSide:int  - Шинээр оноогдох талын тоо
     */
    public void setNumberOfSide(int numberOfSide) {
        this.numberOfSide = numberOfSide;
    }

    /**
     * Талын уртыг шинэчлнэ
     *
     * @param sideLength:int    - Шинээр оноогдоч талын урт
     */
    public void setSideLength(double sideLength) {
        this.sideLength = sideLength;
    }

    /**
     * 2 хэмжээст дүрсийн оройн координатыг хадаглах 2 хэмжээст хүснэгт зарлах
     *
     * @param row:int   - 2 хэмжээст дүрсийн оройн тоо
     */
    public void setCoordinats(int row) {
        this.coordinats = new double[row][2];
    }

    /**
     * Оройн координатид x, y-2 утга өгнө
     *
     * @param row:int       - Хэддэх оройн цэгийг заах утга
     * @param x:double      - x-н утга
     * @param y:double      - y-н утга
     */
    public void setCoordinat(int row, double x, double y) {
        if (this.coordinats.length < 0) {
            System.out.println("First initialize coordinates!");
            return;
        }
        this.coordinats[row][0] = x;
        this.coordinats[row][1] = y;
    }

    // Functions!
    /**
     * 2 хэмжээст биен талбайг олно
     *
     * @return double  - 2 хэмжээст биен талбай
     */
    public double findArea() {
        return 0.0;
    }

    /**
     * 2 хэмжээст биен талын урт буюу переметэр олно
     *
     * @return double  - 2 хэмжээст биен талын урт буюу переметэр
     */
    public double findPerimeter() {
        return 0.0;
    }


}
