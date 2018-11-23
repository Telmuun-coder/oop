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
        if (index < this.length - 1) {
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

    public T get(int index) {
        if (index > this.length - 1)
            return null;

        Node <T> current = this.head;

        while (index != 0) {
            current = current.next_node;
            index--;
        }

        return current.value;
    }

    public int length() {
        return length;
    }

    public int length_rec() {
        return length_rec(this.head);
    }

    void delete(int index) {
        if (index > this.length)
            index = this.length - 1;

        this.length--;

        if (index == 0) {
            Node temp = this.head;
            this.head = temp.next_node;
            temp = null;
            return;
        }

        delete(this.head, index);
    }

    private Node<T> delete(Node<T> current, int index) {
        if (index == 1) {
            Node <T> temp = current.next_node;
            current.next_node = temp.next_node;
            temp = null;
        } else {
            current.next_node = delete(current.next_node, --index);
        }

        return current;
    }

    private int length_rec(Node current) {
        if(current != null) {
            return 1 + length_rec(current.next_node);
        } else {
            return 0;
        }
    }

}
