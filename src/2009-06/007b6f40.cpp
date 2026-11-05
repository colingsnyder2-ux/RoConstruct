// from server: 100% by tester
struct CXTPMenuBar {
    void* GetSomething();
    void* Method(void* arg);
};

void* CXTPMenuBar::Method(void* arg) {
    void* p = GetSomething();
    void* vtable = *(void**)p;
    void (__thiscall *fn)(void*, void*, void*) = *(void (__thiscall **)(void*, void*, void*))((char*)vtable + 0x1dc);
    fn(p, this, arg);
    return p;
}
