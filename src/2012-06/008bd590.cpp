// from server: 91% by tajop
struct Node;

struct Container {
    int pad0;
    int pad4;
    int pad8;
    Node* head;
    Node* forward(Node* node, int n);
    Node* backward(Node* node, int n);
};

struct Iterator {
    Container* container;
    Node* node;
    Iterator(Container* c, Node* p) : container(c), node(p) {}
    Iterator& operator+=(int n);
    Iterator operator+(int n) const;
};

Iterator Iterator::operator+(int n) const {
    Container* c = container;
    Node* p = node;
    Iterator tmp(c, p);
    if (n > 0) {
        p = c->forward(p, n);
        tmp.node = p;
        if (p == c->head) {
            p = 0;
            return Iterator(c, p);
        }
    } else if (n < 0) {
        int m = -n;
        if (m > 0) {
            if (!p)
                p = c->head;
            p = c->backward(p, m);
            return Iterator(c, p);
        } else if (m < 0) {
            tmp += -m;
            p = tmp.node;
            c = tmp.container;
        }
    }
    return Iterator(c, p);
}
