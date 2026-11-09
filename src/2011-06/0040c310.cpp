// from server: 63% by atomic.potato
struct S {
    void* vfptr0;
    char pad1[8];
    void* field_c;
    char pad2[0x18];
    void* field_28;
    void* field_2c;
    void* dtor(char flag);
};

extern "C" void __stdcall sub_80a058(void* p);
extern "C" void __stdcall sub_a404d0(void* p);
extern "C" void __stdcall sub_a40a64(void* p);

void* S::dtor(char flag)
{
    *(void**)this = (void*)0xa5c224;
    *(void**)((char*)this + 0x28) = (void*)0xa5c21c;
    *(void**)((char*)this + 0x28) = (void*)0xa5bfdc;
    void* p = *(void**)((char*)this + 0x2c);
    if (p) {
        (*(void(__thiscall**)(void*))(*(void**)p))(p);
    }
    *(void**)this = (void*)0xa5b5c0;
    sub_a404d0((char*)this + 0xc);
    sub_a40a64(this);
    if (flag & 1) {
        sub_80a058(this);
    }

    return this;
}
