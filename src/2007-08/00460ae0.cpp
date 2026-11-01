// from server: 57% by colin
struct CriticalSection {
    int data[6];
};

extern "C" void __stdcall LeaveCriticalSection(CriticalSection*);

struct MarshaledListener {
    char pad[0x18];
    int field18;
    void func(int a, int b, int c);
};

void MarshaledListener::func(int a, int b, int c)
{
    CriticalSection* cs = (CriticalSection*)(field18 + 0x2c);
    char flag = 0;
    void* guard = &cs;
    void* guardFlag = &flag;
    (void)guard;
    (void)guardFlag;
    // call 0x41d870 - some function taking &cs and &flag
    extern void __stdcall sub_41d870(void*, void*);
    sub_41d870(&cs, &flag);
    int* vtable = *(int**)this;
    void (__thiscall *fn)(void*, int, int, int) = (void (__thiscall *)(void*, int, int, int))vtable[3];
    fn(this, a, b, c);
    if (flag) {
        LeaveCriticalSection(cs);
    }
}
