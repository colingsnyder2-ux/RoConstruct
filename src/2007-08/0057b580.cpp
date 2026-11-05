// from server: 43% by colin
struct Instance {
    char pad[0x2ec];
};

struct Arg {
    virtual void f(int, Instance*);
};

void target(Instance* a, Arg* b) {
    Instance* p = 0;
    if (a) {
        p = (Instance*)((char*)a - 0x2ec);
    }
    b->f(0, p);
}
