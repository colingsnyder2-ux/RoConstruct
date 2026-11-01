// from server: 100% by tester
extern "C" void (*free)(void*);

struct S {
    void* p;
    void f();
};

void S::f() {
    free(p);
}
