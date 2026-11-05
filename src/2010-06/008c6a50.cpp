// from server: 30% by atomic.potato
struct S {
    void* vfptr;
    void* field4;
    int field8;
    int fieldC;
    void* ctor(void*);
};

extern "C" {
    void __stdcall sub_9EA410(void*);
    void __stdcall sub_9EA400(void*);
}

void* S::ctor(void* a) {
    char buf[0x1c];
    vfptr = (void*)0xa88250;
    field4 = a;
    field8 = 0;
    fieldC = 0;
    sub_9EA410(buf);
    (*(void (__thiscall**)(void*, int, void*))(*(int*)a + 0xf4))(a, 4, buf);
    sub_9EA400(buf);

    return this;
}
