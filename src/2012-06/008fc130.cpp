// from server: 59% by atomic.potato
struct EventDesc
{
    void f(float, float);
};

extern "C" void __cdecl func_008f82a0(float);
extern "C" void func_008fbd80(EventDesc *, float);

void EventDesc::f(float a, float b)
{
    func_008f82a0(b);
    func_008fbd80((EventDesc *)0x00e5662c, a);
}
