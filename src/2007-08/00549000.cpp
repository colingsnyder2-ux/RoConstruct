// from server: 100% by colin
// roc 2007-08 00549000  unit: seg_00540000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00549000

struct IStringStream {
    void __thiscall destroy();
};

extern "C" void __cdecl sub_62FC62(void* p);

extern void* (__thiscall* const g_destroy)(void*);

struct S {
    char pad[0x50];
    void* f(unsigned int flags);
};

void* S::f(unsigned int flags)
{
    S* self = (S*)((char*)this - 0x50);
    g_destroy(self);
    if (flags & 1) {
        sub_62FC62(self);
    }
    return self;
}
