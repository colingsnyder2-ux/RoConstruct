// from server: 42% by atomic.potato
struct Node {
    Node* next;
    char pad[0x6c];
};

struct Job {
    char pad0[8];
    Node** begin;
    char pad1[8];
    Node** end;
    bool f(Node** a, int b, Node** c);
};

bool Job::f(Node** a, int b, Node** c) {
    Node** e = end;
    Node** s = begin;
    Node* n = *a;
    Node** p = e + (s - e);
    while ((Node**)n < e || (Node**)n > p) {
        n = n->next;
    }
    if (b != (int)((char*)n - (char*)e) / 4) {
        return false;
    }
    Node* cur = *a;
    if (cur != (Node*)a) {
        Node* t = *c;
        do {
            cur = cur->next;
            if (cur == n) {
                return true;
            }
            Node* q;
            if (cur) {
                q = (Node*)((char*)cur - 0x70);
            } else {
                q = 0;
            }
            if (t == *(Node**)q) {
                return false;
            }
        } while (cur->next != (Node*)a);
    }
    return true;
}
