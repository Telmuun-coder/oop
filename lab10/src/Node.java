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

    // GET
    public T getValue() {
        return value;
    }

    public Node getNext_node() {
        return next_node;
    }

    // SET
    public void setValue(T value) {
        this.value = value;
    }

    public void setNext_node(Node<T> next_node) {
        this.next_node = next_node;
    }
}
