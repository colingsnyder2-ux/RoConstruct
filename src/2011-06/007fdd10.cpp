// from server: 70% by atomic.potato
struct S
{
    int f(void*);
};

extern "C" void __stdcall func_0073f730(void*, void*);

int S::f(void* p)
{
    func_0073f730((char*)this + 0x54, p);
    return (int)p;
}
