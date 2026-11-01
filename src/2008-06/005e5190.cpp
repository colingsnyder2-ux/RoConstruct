// from server: 100% by king_originala
extern "C" void __cdecl release(void*);

struct SimJob {
    unsigned int vtable;
    void* field4;
    unsigned int field8;
    unsigned int fieldC;
    void* field10;
    void* field14;
    void* field18;

    SimJob* destroy(unsigned int flags);
};

SimJob* SimJob::destroy(unsigned int flags) {
    *(volatile unsigned int*)&vtable = 0x83f72c;
    void* p = *(void* volatile*)&field10;
    if (p)
        release(p);
    field10 = 0;
    field14 = 0;
    field18 = 0;
    release(field4);
    if (flags & 1)
        release(this);
    return this;
}
