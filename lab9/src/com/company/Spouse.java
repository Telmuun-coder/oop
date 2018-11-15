package com.company;

public class Spouse extends Person {
    private String anniversaryDate;

    Spouse() {
        super("DEFAULT CHILD", "DEFAULT CHILD SSN", 1);
    }

    Spouse(String name, String SSN, int age, Division division, JobDescription jobDescription) {
        super(name, SSN, age);

        // Заавал нэг салбартай байна
        addDivision(new Division(division));
        // Заавал нэг болон түүнээс дээш ажилын тайлбартай байна
        // 
        //
        adJobDescription(new JobDescription(jobDescription));
        //
    }

    public String getAnniversaryDate() {
        return anniversaryDate;
    }

    public void setAnniversaryDate(String anniversaryDate) {
        this.anniversaryDate = anniversaryDate;
    }
}
