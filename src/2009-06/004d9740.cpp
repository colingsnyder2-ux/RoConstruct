// from server: 100% by why2
struct S {
    void f();
};

void S::f() {
    *(int*)this = 0;
    *(int*)((char*)this + 8) = 0;
}
