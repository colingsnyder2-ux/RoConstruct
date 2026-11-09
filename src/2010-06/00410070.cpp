// from server: 58% by atomic.potato
struct S {
    char pad[0x10];
    void* field10;
    void dtor();
};

void S::dtor() {
    *(int*)((char*)this + 0x20) = 0xa00920;
    *(int*)((char*)this + 0x00) = 0xa02844;
    *(int*)((char*)this + 0x0c) = 0xa0283c;
    *(int*)((char*)this + 0x0c) = 0xa00968;
    void* p = field10;
    if (p) {
        void** vt = *(void***)p;
        void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vt[4];
        fn(p);
    }
    extern void __stdcall sub_9EA91C();
    sub_9EA91C();
}
