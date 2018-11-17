package com.company;

import java.util.Date;

public class Spouse extends Person {
    private Date anniversaryDate;

    Spouse() {
        super("DEFAULT Spouse", "DEFAULT Spouse SSN", 20);
    }

    Spouse(String name, String SSN, int age, Date anniversaryDate) {
        super(name, SSN, age);

        setAnniversaryDate(anniversaryDate);
    }

    public Date getAnniversaryDate() {
        return anniversaryDate;
    }

    public void setAnniversaryDate(Date anniversaryDate) {
        this.anniversaryDate = anniversaryDate;
    }
}
