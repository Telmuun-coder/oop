package com.company;

public class Person {
    private String Name;
    private String SSN;
    private int age;

    public Spouse spource;
    public Division division;



    public String getName() {
        return Name;
    }

    public String getSSN() {
        return SSN;
    }

    public int getAge() {
        return age;
    }

    public void setName(String name) {
        Name = name;
    }

    public void setSSN(String SSN) {
        this.SSN = SSN;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
