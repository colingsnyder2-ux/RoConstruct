// from server: 28% by atomic.potato
extern "C" void __cdecl func_007f53bc(const void *, int);

struct ActiveDocView
{
    void __cdecl f(int, int, void (__thiscall *)(int));
};

void ActiveDocView::f(int value, int count, void (__thiscall *callback)(int))
{
    int guard = 0;
    func_007f53bc((const void *)0x00ad5b20, 20);
    while (--count >= 0)
    {
        value -= count;
        callback(value);
    }
}
