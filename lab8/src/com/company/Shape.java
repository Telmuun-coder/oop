package com.company;

abstract class Shape {
    // Дүрсийн нэр
    private String name;

    Shape(String name) {
        setName(name);
    }

    // Get
    /**
     * Дүрсийн нэрийг авна
     *
     * @return  - Дүрсийн нэр
     */
    String getName() {
        return name;
    }

    // Set
    /**
     * Дүрсийн нэрийг өөрчилнө
     *
     * @param name  :String - Дүрсийн нэрийг өөрчилөх нэр
     */
    private void setName(String name) {
        this.name = name;
    }
}
