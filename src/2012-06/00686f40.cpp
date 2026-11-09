// from server: 91% by atomic.potato
struct S
{
    int f();
};

extern "C" void* __cdecl G_00983448(void*, void*, void*, void*, void*);

int S::f()
{
    void* p = G_00983448(*((void**)((char*)this + 0x14c)), 0, (void*)0xD601E8, (void*)0xD9A458, 0);
    if (p)
        return *((int*)((char*)p + 0x34)) == 1;
    return 0;
}
