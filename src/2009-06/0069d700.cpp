// from server: 100% by atomic.potato
struct S {
    char pad0[0x14];
    char pad14[4];
    char pad18[8];
    char pad20[4];
    void* f(int);
};

extern "C" void __stdcall sub_5d2b60();
extern "C" void __cdecl sub_718a32(void*);

void* S::f(int arg) {
    *(void**)this = (void*)0x8e8f3c;
    *(void**)((char*)this + 0x14) = (void*)0x8e8f2c;
    *(void**)((char*)this + 0x18) = (void*)0x8e8f24;
    *(void**)((char*)this + 0x20) = (void*)0x8e8f1c;
    sub_5d2b60();
    if (arg & 1) {
        sub_718a32(this);
    }
    return this;
}
