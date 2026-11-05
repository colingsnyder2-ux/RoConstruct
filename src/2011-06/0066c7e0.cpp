// from server: 88% by atomic.potato
extern "C" void* __cdecl Function_640af0(void*);
extern "C" void __stdcall Function_6dda00(void*, unsigned int);

struct S
{
    int value;
    void f();
};

void S::f()
{
    void* p = Function_640af0(this);
    if (p)
        Function_6dda00(p, *(unsigned int*)((char*)this + 0x168));
}
