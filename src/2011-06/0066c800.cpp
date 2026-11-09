// from server: 84% by atomic.potato
extern "C" void* __cdecl Function_640af0(void*);
extern "C" void Function_6de430(void*, unsigned int);

struct S
{
    unsigned int value;
    void f();
};

void S::f()
{
    void* p = Function_640af0(this);
    if (p)
        Function_6de430(p, *(unsigned int*)((char*)this + 0x168));
}
