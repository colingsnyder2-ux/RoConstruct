// from server: 100% by atomic.potato
struct C;

struct Vtbl {
    char pad[0x70];
    void (__thiscall *fn70)(C *, void *);
};

struct C {
    Vtbl *vtbl;
    void sub_6cc4c0(void *, void *);
    void sub_6cd5a0();
    void f(void *);
};

void C::f(void *arg) {
    char buf[12];
    sub_6cc4c0(buf, arg);
    vtbl->fn70(this, buf);
    sub_6cd5a0();
}
