package com.company;

public class Main {

    public static void main(String[] args) {
        Employee e = new Employee();
        e.marry(new Spouse());

        e.addJobDescription(new JobDescription("HEY"));

        e.removeJobDescription("JOB DESCRIPTION!");
        e.removeJobDescription("HEY");



        System.out.println(e.countJobDescription());
    }
}
