package com.company;

public class JobDescription {
    private String description;

    JobDescription() {
        System.out.println("HEY");
        setDescription("DEFAULT JOB DESCRIPTION!");
    }

    JobDescription(String description) {
        setDescription(description);
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }
}
