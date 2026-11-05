// from server: 100% by atomic.potato
struct CRobloxControlMaterialSelector
{
    void f(int);
};

extern "C" void __stdcall g(int);

void CRobloxControlMaterialSelector::f(int value)
{
    *(int *)((char *)this + 0x188) = value;
    g(1);
}
