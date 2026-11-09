// from server: 75% by atomic.potato
extern "C" void __stdcall Call917430(void *);

struct VTable8
{
    void *pad0;
    void *pad1;
    void (__thiscall *call8)(void *);
};

struct VTable4
{
    void *pad0;
    void (__thiscall *call4)(void *);
};

struct SimulateStage
{
    VTable8 *vtable;
    void f(void *);
};

void __thiscall SimulateStage::f(void *arg)
{
    Call917430(arg);
    this->vtable->call8(this);
    ((VTable4 *)*(void **)arg)->call4(arg);
}
