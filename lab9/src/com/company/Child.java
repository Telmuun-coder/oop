package com.company;

public class Child extends Person {
    private String favoriteToy;

    Child() {
        super("DEFAULT Child", "DEFAULT Child SSN", 1);
    }

    Child(String name, String SSN, int age, String favoriteToy) {
        super(name, SSN, age);

        setFavoriteToy(favoriteToy);
    }

    public String getFavoriteToy() {
        return favoriteToy;
    }

    public void setFavoriteToy(String favoriteToy) {
        this.favoriteToy = favoriteToy;
    }
}
