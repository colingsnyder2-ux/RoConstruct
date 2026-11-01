// from server: 100% by tester
struct CXTPCommandBar {
    void f();
};

void CXTPCommandBar::f() {
    void* p = this;
    (*(void (__thiscall **)(void*, int, int))(*(int*)p + 0x19c))(p, 0, 1);
    void* q = (*(void* (__thiscall **)(void*))(*(int*)p + 0x184))(p);
    while (q) {
        (*(void (__thiscall **)(void*, int, int))(*(int*)q + 0x19c))(q, 0, 1);
        q = (*(void* (__thiscall **)(void*))(*(int*)q + 0x184))(q);
    }
}
