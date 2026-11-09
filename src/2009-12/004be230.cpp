// from server: 75% by atomic.potato
struct Node {
    Node* next;
    char pad[0x28];
};

struct Visiter {
    Node* head;
    Node* acquire();
    Node* f();
};

Node* Visiter::f() {
    Node* n = head;
    if (n != 0) {
        head = n->next;
    } else {
        n = acquire();
    }
    if (n == 0)
        return 0;
    n->next = 0;
    *(int*)((char*)n + 8) = 0;
    *(int*)((char*)n + 0xc) = 0;
    *(int*)((char*)n + 0x10) = 0;
    *(unsigned short*)n = 0xffff;
    *(int*)((char*)n + 4) = -1;
    *(int*)((char*)n + 0x28) = 0;
    *(int*)((char*)n + 0x2c) = 0;
    *((char*)n + 0x24) = 0;
    *(int*)((char*)n + 0x14) = 0xffffffff;
    *(int*)((char*)n + 0x18) = 0xffffffff;
    *(int*)((char*)n + 0x1c) = 0xffffffff;
    *(int*)((char*)n + 0x20) = 0xffffffff;
    return n;
}
