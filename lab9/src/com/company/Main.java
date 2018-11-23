package com.company;

import java.util.Date;

public class Main {

    public static void main(String[] args) {
        Division marketing = new Division("Marketing");
        Division finance = new Division("Finance");
        Division reseacher = new Division("Researcher");

        JobDescription calculate = new JobDescription("Calculate salary");
        JobDescription tell = new JobDescription("Tell other people about company");
        JobDescription find = new JobDescription("Find the best possible solution for company");

        Employee a = new Employee("Sam Dan", "AAB1", 21, "CID_01", "CEO", new Date("2015/02/27"), reseacher, calculate);
        Employee b = new Employee("Danzo Polima", "BOM9", 30, "CID_99", "Employee", new Date("2017/12/01"), marketing, tell);

        a.marry(new Spouse("Leonie Kathleen", "BBA1", 20, new Date("2017/03/24")));
        a.addChild(new Child("Kodomo Kun", "OIU1", 1, "Superman"));

        b.marry(new Spouse("Dale Holmes", "QAZ9", 29, new Date("2000/09/12")));
        b.addChild(new Child("Onnanoko Chan", "NHY9", 9, "Bear"));
        b.addChild(new Child("Alexis Aisha", "BVZ9", 5, "Rubik's Cube"));

        System.out.println(a);
        System.out.println(b);
    }
}
