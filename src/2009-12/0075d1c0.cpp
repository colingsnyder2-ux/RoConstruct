// from server: 100% by atomic.potato
struct S {
    char pad0[0x18];
    void* p18;
    void* p1c;
    void* dtor(unsigned int);
};

extern "C" void __stdcall sub_637b00();
extern "C" void __cdecl sub_7f385a(void*);

void* S::dtor(unsigned int flags)
{
    *(void**)this = (void*)0x9e6d4c;
    *(void**)((char*)this + 4) = (void*)0x9e6d40;
    *(void**)((char*)this + 0x18) = (void*)0x9e6d34;
    *(void**)((char*)this + 0x1c) = (void*)0x9e6d2c;
    sub_637b00();
    if (flags & 1) {
        sub_7f385a(this);
    }
    return this;
}
