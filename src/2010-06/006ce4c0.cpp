// from server: 29% by atomic.potato
struct T4_006ce4c0 {
    void f_006ce4c0();
};

struct T4_006cd070 {
    void f_006cd070();
};

struct T4_006cd560 {
    void f_006cd560();
};

extern "C" void __stdcall sub_006ce4c0_helper(void*, void*, int);

void T4_006ce4c0::f_006ce4c0()
{
    char buf[0x20];
    *(int*)buf = 0;
    void* p = *(void**)((char*)this + 0x44);
    *(int*)(buf + 0x30) = 1;
    *(void**)(buf + 0x24) = buf;
    if (p != 0) {
        *(void**)buf = p;
        void** vt = *(void***)p;
        void* q = *(void**)((char*)this + 0x44);
        void* r = buf + 8;
        void (*fn)(void*, void*, int) = (void (*)(void*, void*, int))vt[0];
        fn(q, r, 0);
    }
    T4_006cd070* a = (T4_006cd070*)this;
    a->f_006cd070();
    T4_006cd560* b = (T4_006cd560*)a;
    b->f_006cd560();
}
