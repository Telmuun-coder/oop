package com.company;

public class TwoDimensionalShape extends Shape {
    // Тухайн 2 хэмжээст бие хэдэн талтайг заана
    protected int numberOfSide;
    // Нэг талын утыг заана
    protected double radius;
    // Эхний мөр нь төв цэгийг заана
    // 2 хэмжээст бие координатын заана
    protected double coordinats[][];

    public TwoDimensionalShape(String name, int numberOfSide, double radius) {
        super(name);
        setNumberOfSide(numberOfSide);
        setRadius(radius);
        if (this.numberOfSide != 1) {
            setCoordinats(this.numberOfSide + 1);
            calculateCoordinates();
        } else {
            setCoordinats(this.numberOfSide);
        }
    }

    public TwoDimensionalShape(String name, int numberOfSide, double radius, double x, double y) {
        super(name);
        setNumberOfSide(numberOfSide);
        setRadius(radius);
        if (this.numberOfSide != 1) {
            setCoordinats(this.numberOfSide + 1);
            setCoordinat(0, x, y);
            calculateCoordinates();
        } else {
            setCoordinats(this.numberOfSide);
            setCoordinat(0, x, y);
        }
    }

    public void calculateCoordinates() {
        int row_i = 1;
        for (int i = 0; i < 360; i += 360 / this.numberOfSide) {
            double x = this.coordinats[0][0] + this.radius * Math.cos(Math.toRadians(i));
            double y = this.coordinats[0][1] + this.radius * Math.sin(Math.toRadians(i));

            this.setCoordinat(row_i, x, y);
            row_i++;
        }
    }

    // Get

    /**
     * 2 хэмжээст дүрсийн талын тоог авна
     *
     * @return int   - 2 хэмжээст дүрсийн талын тоо
     */
    public int getNumberOfSide() {
        return numberOfSide;
    }

    /**
     * 2 хэмжээст дүрсийн талын уртыг авна
     *
     * @return double  - 2 хэмжээст дүрсийн нэг талын урт
     */
    public double getRadius() {
        return radius;
    }

    /**
     * 2 хэмжээст дүрсийн оройн координатуудыг авна
     *
     * @return double  - 2 хэмжээст дүрсийн нэг талын урт
     */
    public double[][] getCoordinats() {
        return coordinats;
    }

    /**
     * 2 хэмжээст дүрсийн оройн координатыг авна
     *
     * @param row :int - авах координатын мөр
     * @return double  - 2 хэмжээст дүрсийн нэг талын урт
     */
    public double[] getCoordinat(int row) {
        return coordinats[row];
    }

    // Set

    /**
     * Талын тоог шинэчлнэ
     *
     * @param numberOfSide:int - Шинээр оноогдох талын тоо
     */
    private void setNumberOfSide(int numberOfSide) {
        this.numberOfSide = numberOfSide;
    }

    /**
     * Талын уртыг шинэчлнэ
     *
     * @param Radius:int - Шинээр оноогдоч талын урт
     */
    private void setRadius(double Radius) {
        this.radius = Radius;
    }

    /**
     * 2 хэмжээст дүрсийн оройн координатыг хадаглах 2 хэмжээст хүснэгт зарлах
     *
     * @param row:int - 2 хэмжээст дүрсийн оройн тоо
     */
    private void setCoordinats(int row) {
        this.coordinats = new double[row][2];
    }

    /**
     * Оройн координатид x, y-2 утга өгнө
     *
     * @param row:int  - Хэддэх оройн цэгийг заах утга
     * @param x:double - x-н утга
     * @param y:double - y-н утга
     */
    private void setCoordinat(int row, double x, double y) {
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
