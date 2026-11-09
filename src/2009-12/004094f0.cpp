// from server: 100% by atomic.potato
struct S {
    void* vtable;
    void* field4;
    int field8;
    int fieldC;
    int field10;
    S* construct(void* arg);
};

S* S::construct(void* arg)
{
    char* src = (char*)arg;
    this->vtable = (void*)0x99fdd8;
    void* p = *(void**)(src + 4);
    this->field4 = p;
    if (p != 0) {
        void** vt = *(void***)p;
        void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))vt[3];
        fn(p);
    }
    this->field8 = *(int*)(src + 8);
    this->fieldC = *(int*)(src + 0xc);
    this->field10 = *(int*)(src + 0x10);
    return this;
}
