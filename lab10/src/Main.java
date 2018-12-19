import java.util.ArrayList;

public class Main {
    /*
    Template буюу загвар класс ашиглан дурын төрлийн
    өгөгдөл хадгалдаг жагсаалтыг зохион байгуул.
    ПХ, КУ, МТ ангийн хүүхдүүд linked list зохион байгуулна.

    Жагсаалт нь дараах функцуудтай байна:
    * void add(T t); // жагсаалтын сүүлд элемент нэмнэ
    * void insert(T t, int index); // index - дүгээрт элеменет оруулна
    * T get(int index); // i-р элементийн утгыг буцаана
    * void delete(int index); // i -р элементийг устгана
    * int length();    //жагсаалтын уртыг буцаана
    */

    public static void main(String[] args) {
        LinkedList<Integer> a =new LinkedList<Integer>(10);
        a.add(20);
        a.add(30);
        a.add(40);
        a.delete(9);
//        a.insert(6, 0);
        System.out.println(a.get(a.length - 1));
        System.out.println(a.length_rec());
    }
}
