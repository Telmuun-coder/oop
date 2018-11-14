package com.company;

import java.util.Date;

public class Employee extends Person {
    private String companyID;
    private String title;
    private Date startDate;

    public String getCompanyID() {
        return companyID;
    }

    public String getTitle() {
        return title;
    }

    public Date getStartDate() {
        return startDate;
    }

    public void setCompanyID(String companyID) {
        this.companyID = companyID;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setStartDate(Date startDate) {
        this.startDate = startDate;
    }
}
