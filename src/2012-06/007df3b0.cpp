// from server: 72% by atomic.potato
extern "C" void __cdecl Function_00982114(void*);
extern "C" void __cdecl Function_00b2263c();

struct S
{
    void f();
};

void S::f()
{
    void* p = *(void**)((char*)this + 4);
    if (p != 0)
    {
        if (*(unsigned char*)((char*)this + 9) != 0)
            Function_00b2263c();
        Function_00982114(p);
    }
}
