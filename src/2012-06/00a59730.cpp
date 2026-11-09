// from server: 50% by atomic.potato
extern "C" void __stdcall func_00b24780(void*, void*);

struct S
{
    S* f(void*);
};

S* S::f(void* arg)
{
    func_00b24780((char*)this + 0x48, arg);
    return this;
}
