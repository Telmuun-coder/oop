package com.company;

abstract class Shape {
    // Дүрсийн нэр
    private String name;

    /**
     * Анхдагч байгуулагч функц Shape гэсэн нэртэй дүрс үүсгэх
     */
    Shape() {
        setName("Shape");
    }

    /**
     * Прамертэй байгуулагч функц дүрсд нэр олгнр
     * 
     * @param name  - Шинээр үүсэх дүрсэд нэр өгнө
     */
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
