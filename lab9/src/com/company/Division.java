package com.company;

public class Division {
    private String divisionName;

    Division() {
        setDivisionName("DEFAULT DIVISION!");
    }

    Division(String divisionName) {
        setDivisionName(divisionName);
    }

    public String getDivisionName() {
        return divisionName;
    }

    public void setDivisionName(String divisionName) {
        this.divisionName = divisionName;
    }
}
