// from server: 66% by atomic.potato
extern "C" void __stdcall fn_00b24780(void*, void*);

struct S
{
    void* __thiscall f(void*);
};

void* __thiscall S::f(void* arg)
{
    void* p = (char*)this + 0x7c;
    fn_00b24780(arg, p);
    return arg;
}
