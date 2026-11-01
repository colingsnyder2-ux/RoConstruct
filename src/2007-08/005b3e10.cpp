// from server: 100% by colin
struct Inner {
    void method(void** p);
};

struct Assembly {
    char pad[0x18];
    Inner inner;
    void f(void* arg);
};

void Assembly::f(void* arg) {
    inner.method(&arg);
}
