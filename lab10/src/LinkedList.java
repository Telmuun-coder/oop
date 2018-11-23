public class LinkedList<T> {
    Node<T> head;
    int length;

    public LinkedList() {
        this.length = 0;
    }

    public LinkedList(T value) {
        head = new Node<T>(value);
        this.length = 1;
    }

    public void add(T value) {
        add(this.head, value);
        this.length++;
    }

    private Node<T> add(Node<T> current, T value) {
        if (current == null) {
            current = new Node<T>(value);
        } else {
            current.next_node = add(current.next_node, value);
        }

        return current;
    }

    public void insert(T value, int index) {
        if (index < this.length) {
            this.head = insert(this.head, value, index);
            this.length++;
        } else {
            add(value);
        }
    }

    private Node<T> insert(Node<T> current, T value, int index) {
        if (index == 0) {
            Node<T> temp = current;
            current = new Node<T>(value, temp);
        } else {
            current.next_node = insert(current.next_node, value, --index);
        }

        return current;
    }
}
