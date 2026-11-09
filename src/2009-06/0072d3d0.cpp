// from server: 100% by tester
struct CXTPCommandBar {
    void f();
};

void CXTPCommandBar::f() {
    void* p = this;
    (*(void (__thiscall **)(void*, int, int))(*(int*)p + 0x1ac))(p, 0, 1);
    void* q = (*(void* (__thiscall **)(void*))(*(int*)p + 0x194))(p);
    while (q) {
        (*(void (__thiscall **)(void*, int, int))(*(int*)q + 0x1ac))(q, 0, 1);
        q = (*(void* (__thiscall **)(void*))(*(int*)q + 0x194))(q);
    }
}
