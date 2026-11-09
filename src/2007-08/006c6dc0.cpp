// from server: 100% by colin
struct CCustomizeEdit {
    void* getSomething();
    void* doSomething(void* arg);
};

void* CCustomizeEdit::doSomething(void* arg) {
    void* p = getSomething();
    void** vtbl = *(void***)p;
    void (__thiscall *fn)(void*, void*, void*) = (void (__thiscall *)(void*, void*, void*))vtbl[0x38];
    fn(p, this, arg);
    return p;
}
