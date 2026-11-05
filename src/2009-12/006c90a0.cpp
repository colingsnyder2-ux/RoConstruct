// from server: 33% by atomic.potato
struct Sub {
    void f(void*);
};

struct S {
    char pad[0x34];
    Sub* sub;
    void f(void*, void*);
};

void S::f(void* a, void* b) {
    if (a) {
        a = (char*)a - 0x1c;
    } else {
        a = 0;
    }
    sub->f(b);
}
