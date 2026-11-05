// from server: 50% by atomic.potato
struct S {
    void* vtbl;
    char pad[0x10];
    void* vtbl2;
    void* field18;
    void dtor();
    void sub_a40a64();
};

extern "C" void __stdcall sub_80a058(void*);


void S::dtor()
{
    *(void**)this = (void*)0xa9114c;
    *(void**)((char*)this + 0x14) = (void*)0xa91144;
    *(void**)((char*)this + 0x14) = (void*)0xa5bfdc;
    void* p = *(void**)((char*)this + 0x18);
    if (p) {
        void** vt = *(void***)p;
        ((void (__stdcall*)(void*))vt[4])(p);
    }
    sub_a40a64();
    if (*(unsigned char*)((char*)this + 8) & 1) {
        sub_80a058(this);
    }
}
