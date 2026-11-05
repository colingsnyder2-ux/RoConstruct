// from server: 43% by atomic.potato
struct S_func_004a3410 {
    struct Node {
        Node* next;
        int value;
        Node* key;
    };

    Node* m_head;
    Node* f(Node* key);
};

S_func_004a3410::Node* S_func_004a3410::f(Node* key)
{
    Node* node = m_head;
    while (node != 0) {
        if (node->key == key)
            return node;
        node = node->next;
    }
    return 0;
}
