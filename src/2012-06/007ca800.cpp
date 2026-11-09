// from server: 76% by atomic.potato
struct S {
    char pad0[0x3c];
    void* field3c;
    void destroy();
};

extern "C" void __cdecl free_ptr(void*);
extern "C" void __cdecl sub_591ef0();

void S::destroy()
{
    if (field3c) {
        free_ptr(field3c);
    }
    sub_591ef0();
    if (*(unsigned char*)((char*)this - 4) & 1) {
        free_ptr(this);
    }
}
