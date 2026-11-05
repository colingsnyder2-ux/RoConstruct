// from server: 100% by colin
struct S {
    void f();
};

void S::f() {
    int* p = *(int**)this;
    *p = *(int*)((char*)this + 4);
}
