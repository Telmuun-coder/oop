public class Node<T> {
    T value;
    Node next_node;

    public Node(T value) {
        this.value = value;
        this.next_node = null;
    }

    public Node(T value, Node<T> temp) {
        this.value = value;
        this.next_node = temp;
    }
}
