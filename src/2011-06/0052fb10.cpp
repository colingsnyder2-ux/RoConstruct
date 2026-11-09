// from server: 24% by atomic.potato





struct Node {
    Node* next;
    char pad[0x100];
};

struct List {
    void remove(Node* n);
};

struct ReliabilityLayer {
    char pad0[0x28];
    Node** table;
    int count;
    char pad1[0x4];
    int mask;
    List list;
    int offset;

    void Clear(int index);
};

void List::remove(Node* n) {
    // placeholder; real body at 0052f230
}

void ReliabilityLayer::Clear(int index) {
    int idx = (index - offset) & 0xffffff;
    Node* n;
    if (count + idx >= mask) {
        n = table[(count - mask) + idx];
    } else {
        n = table[count + idx];
    }
    while (n) {
        Node* next = n->next;
        list.remove(n);
        n = next;
    }
    if (count + idx >= mask) {
        table[(count - mask) + idx] = 0;
    } else {
        table[count + idx] = 0;
    }
}
