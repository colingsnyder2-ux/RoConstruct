// from server: 58% by atomic.potato
extern "C" int __stdcall func_007f3e30(int);
extern "C" void __stdcall func_0041b2f0(void*);

struct CSelectionCaption
{
    int f(int);
};

int CSelectionCaption::f(int value)
{
    int result = func_007f3e30(value);
    if (result == -1)
        return result;
    func_0041b2f0((char*)this + 0x190);
    return 0;
}
