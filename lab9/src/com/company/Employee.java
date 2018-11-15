package com.company;

import java.util.Collection;
import java.util.Date;

public class Employee extends Person {
    private String companyID;
    private String title;
    private Date startDate;

    public Spouse spource;
    public Collection<Child> children;
    public Division division;
    public Collection<JobDescription> jobDescriptions;

    Employee() {
        super();

        // Заавал нэг салбартай байна
        addDivision(new Division());
        // Заавал нэг болон түүнээс дээш ажилын тайлбартай байна
        // 
        adDescription(new JobDescription());
    }

    Employee(String name, String SSN, int age, Division division, JobDescription jobDescription) {
        super(name, SSN, age);

        // Заавал нэг салбартай байна
        addDivision(new Division(division));
        // Заавал нэг болон түүнээс дээш ажилын тайлбартай байна
        addDescription(new JobDescription(jobDescription));
        // 
    }

    marry(Spouse bride) {
        if (this.spource != null) {   
            System.out.println("Already Married!");
            return;
        }
        this.spource = new Spouse(bride);
    }

    void divorce() {
        if (this.spource == null) {
            System.out.println("You are not married!");
            return;
        }
        this.spource = null;
    }

    int countSpource() {
        if (this.spource == null) {
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

    void addDivision(Division division) {
        if (this.division != null) {
            System.out.println("Already Has Division!");
            return;
        }
        this.division = new Division(division);
    }

    void swapDivision(Division division) {
        this.division = new Division(division);
    }

    int countDivision() {
        return 1;
    }

    void addJobDescription(JobDescription jobDescription) {
        this.jobDescriptions.add(jobDescription);
    }

    void removeJobDescription(String description) {
        if (jobDescriptions.size() == 1) {
            System.out.println("CANNOT REMOVE DESCRIPTION. ONLY ONE LEFT!");
        }
        this.jobDescriptions
                .removeIf((JobDescription JobDescription) -> JobDescription.getDescription() == description);
    }

    int countJobDescription() {
        return this.jobDescriptions.size();
    }

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
