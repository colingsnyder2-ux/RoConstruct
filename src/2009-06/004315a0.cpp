// from server: 100% by why2
struct S {
    int f();
};

int S::f() {
    return (*(int (__thiscall **)(S *))(*(int *)this + 0xec))(this);
}
