// from server: 35% by atomic.potato
struct S {
    char pad0[4];
    char pad1[0x24];
    char pad2[0x30];
    char pad3[0x34];
    char pad4[0x38];
    char pad5[0x3c];
    char pad6[0x48];
    char pad7[0x4c];
    char pad8[0x50];
    char pad9[0x54];
    char pad10[0x58];
    char pad11[0x5c];
    char pad12[0x60];
    char pad13[0x64];
    S* f();
};

extern "C" void* __stdcall sub_a404c8(void*, void*);
extern "C" void __stdcall sub_a404d0(void*);
extern "C" void sub_61acb0(void*, void*, void*);

S* S::f()
{
    char buf[0x24];
    char buf2[0x1c];
    void* p;
    S* result;
    sub_a404c8(&buf2, &p);
    sub_61acb0(&buf, *(void**)(buf2 + 0x1c), *(void**)(buf2 + 0x18));
    result = *(S**)(buf + 0x8);
    *(int*)result = *(int*)(buf + 0xc);
    sub_a404c8((char*)result + 4, &p);
    sub_a404d0(&buf);
    sub_a404d0(&buf2);
    return result;
}
