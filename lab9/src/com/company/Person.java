package com.company;

import java.util.Collection;

public class Person {
    private String name;
    private String SSN;
    private int age;

    public Spouse spource;
    public Collection<Child> children;
    public Division division;
    public Collection<JobDescription> jobDescriptions;

    Person() {
        // Заавал нэг салбарт байна.
    }

    void marry(Spouse bride) {
        if (this.spource != null) {
            System.out.println("Already Married!");
            return;
        }
        this.spource = new Spouse();
        this.spource = bride;
    }

    void divorce() {
        if (this.spource == null){
            System.out.println("You are not married!");
            return;
        }
        this.spource = null;
    }

    int countSpource() {
        if (this.spource == null){
            return 0;
        }
        return 1;
    }

    void addChild(Child child) {
        this.children.add(child);
    }

    void removeChild(String name) {
        this.children.removeIf((Child child) -> child.getName() == name);
    }

    int countChild() {
        return this.children.size();
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
        this.age = age;
    }
}
