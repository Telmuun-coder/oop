package com.company;

public class Shape {
    // Дүрсийн нэр
    protected String name;

    public Shape(String name) {
        setName(name);
    }

    // Get
    /**
     * Дүрсийн нэрийг авна
     *
     * @return  - Дүрсийн нэр
     */
    public String getName() {
        return name;
    }

    // Set
    /**
     * Дүрсийн нэрийг өөрчилнө
     *
     * @param name  :String - Дүрсийн нэрийг өөрчилөх нэр
     */
    public void setName(String name) {
        this.name = name;
    }
}
