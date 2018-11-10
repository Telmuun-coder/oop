package com.company;

abstract class TwoDimensionalShape extends Shape {
    // Тухайн 2 хэмжээст бие хэдэн талтайг заана
    private int numberOfSide;
    // Нэг талын утыг заана
    private double radius;
    // Эхний мөр нь төв цэгийг заана
    // 2 хэмжээст бие координатын заана
    private double coordinates[][];

    TwoDimensionalShape(String name, int numberOfSide, double radius) {
        super(name);
        setNumberOfSide(numberOfSide);
        setRadius(radius);
        if (this.numberOfSide != 1) {
            setCoordinates(this.numberOfSide + 1);
            calculateCoordinates();
        } else {
            setCoordinates(this.numberOfSide);
        }
    }

    TwoDimensionalShape(String name, int numberOfSide, double radius, double x, double y) {
        super(name);
        setNumberOfSide(numberOfSide);
        setRadius(radius);
        if (this.numberOfSide != 1) {
            setCoordinates(this.numberOfSide + 1);
            setCoordinate(0, x, y);
            calculateCoordinates();
        } else {
            setCoordinates(this.numberOfSide);
            setCoordinate(0, x, y);
        }
    }

    private void calculateCoordinates() {
        int row_i = 1;
        for (int i = 0; i < 360; i += 360 / this.numberOfSide) {
            double x = this.coordinates[0][0] + this.radius * Math.cos(Math.toRadians(i));
            double y = this.coordinates[0][1] + this.radius * Math.sin(Math.toRadians(i));

            this.setCoordinate(row_i, x, y);
            row_i++;
        }
    }


    /**
     *
     * @param shapes
     */
    static void sortShapesByArea(TwoDimensionalShape[] shapes) {
        for (int i = 0; i < shapes.length; i++) {
            for (int j = 0; j < shapes.length - 1; j++) {
                if (shapes[j].findArea() > shapes[j + 1].findArea()) {
                    TwoDimensionalShape temp = shapes[j];
                    shapes[j] = shapes[j + 1];
                    shapes[j + 1] = temp;
                }
            }

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
    public double[][] getCoordinates() {
        return coordinates;
    }

    /**
     * 2 хэмжээст дүрсийн оройн координатыг авна
     *
     * @param row :int - авах координатын мөр
     * @return double  - 2 хэмжээст дүрсийн нэг талын урт
     */
    public double[] getCoordinate(int row) {
        return coordinates[row];
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
    private void setCoordinates(int row) {
        this.coordinates = new double[row][2];
    }

    /**
     * Оройн координатид x, y-2 утга өгнө
     *
     * @param row:int  - Хэддэх оройн цэгийг заах утга
     * @param x:double - x-н утга
     * @param y:double - y-н утга
     */
    private void setCoordinate(int row, double x, double y) {
        if (this.coordinates.length < 0) {
            System.out.println("First initialize Coordinatees!");
            return;
        }
        this.coordinates[row][0] = x;
        this.coordinates[row][1] = y;
    }

    // Functions!

    /**
     * 2 хэмжээст биен талбайг олно
     *
     * @return double  - 2 хэмжээст биен талбай
     */
     public abstract double findArea();

    /**
     * 2 хэмжээст биен талын урт буюу переметэр олно
     *
     * @return double  - 2 хэмжээст биен талын урт буюу переметэр
     */
     public abstract double findPerimeter();
}
