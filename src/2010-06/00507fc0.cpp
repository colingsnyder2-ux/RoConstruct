// from server: 65% by atomic.potato
typedef unsigned int DWORD;

extern "C" bool __cdecl Function_004c70b(void *object, void *argument);
extern "C" void __cdecl Function_004f30a0(void *object);

struct S
{
    void f(void *argument);
};

void S::f(void *argument)
{
    void *object = *(void **)((char *)this + 0x2688);
    if (object != 0 && !Function_004c70b(object, argument))
        Function_004f30a0(this);
}
