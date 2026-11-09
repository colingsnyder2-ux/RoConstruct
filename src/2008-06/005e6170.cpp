// from server: 100% by king_originala
struct Link {
    void update();
};

struct Node {
    char padding[0xA4];
    Link* link;
};

struct Iterator {
    Node* node;
    int mode;
    void advance();
};

struct Clump {
    char padding[0x1C];
    Node* root;
    void f();
};

void Clump::f() {
    Iterator it;
    it.node = root;
    it.mode = 1;
    while (it.node) {
        it.node->link->update();
        it.advance();
    }
}
