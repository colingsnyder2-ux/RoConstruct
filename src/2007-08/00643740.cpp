// from server: 100% by colin
struct CXTPCommandBarCmdUI {
    void f();
};

void CXTPCommandBarCmdUI::f() {
    void (__thiscall *fn)(void*, int, int);
    fn = *(void (__thiscall **)(void*, int, int))(*(int*)this + 0x1e0);
    fn(this, 1, 0);
}
