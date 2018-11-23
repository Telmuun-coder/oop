package com.company;

import java.util.Collection;

public class Person {
    private String name;
    private String SSN;
    private int age;

    Person() {
        this.setName("Default");
        this.setSSN("0000");
        this.setAge(1);
    }

    Person(String name, String SSN, int age) {
        this.setName(name);
        this.setSSN(SSN);
        this.setAge(age);
    }

    public String getName() {
        return name;
    }

    public String getSSN() {
        return SSN;
    }

    public int getAge() {
        return age;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSSN(String SSN) {
        this.SSN = SSN;
    }

    public void setAge(int age) {
        if (age < 0) {
            age = 0;
        }
        this.age = age;
    }
}
