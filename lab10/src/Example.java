public class Example {

    public static < E > void printArray( E[] inputArray ) {
        // Display array elements
        for(E element : inputArray) {
            System.out.printf("%s ", element);
        }
        System.out.println();
    }


    public static void main(String[] args) {
        Integer[] intArray = { 1, 2, 3, 4, 5 };
        String[] stringArray = {"a", "b", "c", "d", "e"};
        printArray(intArray);
        printArray(stringArray);
    }
}