// from server: 100% by colin
struct CXTPMenuBar {
    void* GetSomething();
    void* Method(void* arg);
};

void* CXTPMenuBar::Method(void* arg) {
    void* p = GetSomething();
    void* vtable = *(void**)p;
    void (__thiscall *fn)(void*, void*, void*) = *(void (__thiscall **)(void*, void*, void*))((char*)vtable + 0x1c8);
    fn(p, this, arg);
    return p;
}
