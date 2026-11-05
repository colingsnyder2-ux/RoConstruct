// from server: 64% by atomic.potato
struct Tool
{
    void f();
    char padding[0x138];
    int value_138;
};

extern "C" void __cdecl func_00695050(int);

void Tool::f()
{
    int value = value_138;
    int delta = (value + 1) & 0x80000001;
    if (delta < 0)
        delta = (delta - 1) | -2;
    func_00695050(delta + value + 1);
}
