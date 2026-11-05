// from server: 100% by why2
struct CXTPPopupBar {
    void f();
};

void CXTPPopupBar::f() {
    void (__thiscall *fn)(void*, int, int);
    fn = *(void (__thiscall **)(void*, int, int))(*(int*)this + 0x1ac);
    fn(this, 0, 1);
}
