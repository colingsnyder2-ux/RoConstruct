// from server: 50% by atomic.potato
struct S
{
    void* f();
};

extern "C" void __cdecl sub_525070(void*, void*);

void* S::f()
{
    void* p = 0;
    if (this)
        p = (char*)this + 0x1c;
    sub_525070((void*)0x00e3165c, p);
    return 0;
}
