// from server: 53% by atomic.potato
struct Primitive {
    void f();
};

struct Sub {
    char pad[0xb0];
    void g(Primitive*);
};

struct Sub2 {
    char pad[0x94];
    void g(Primitive*);
};

void Primitive::f() {
    int* vtable = *(int**)this;
    int (*func)(Primitive*) = (int (*)(Primitive*))vtable[4];
    Sub* a = *(Sub**)((char*)this + 0x10);
    Sub2* b = *(Sub2**)((char*)this + 0x14);
    if (func(this) == 0) {
        a->g(this);
        if (b != 0) {
            b->g(this);
        }
    } else {
        ((Sub2*)a)->g(this);
        b->g(this);
    }
}
