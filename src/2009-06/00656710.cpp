// from server: 100% by why2
struct S {
    double f();
};

double S::f() {
    void (__thiscall *fn)(S*) = *(void (__thiscall **)(S*))(*(int*)this + 0x44);
    fn(this);
    return *(double*)((char*)this + 0x90);
}
