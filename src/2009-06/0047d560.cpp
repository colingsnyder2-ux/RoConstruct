// from server: 100% by tester
struct S {
    int f();
};

int S::f() {
    return (*(int (__thiscall **)(S *))(*(int *)this + 0x1bc))(this);
}