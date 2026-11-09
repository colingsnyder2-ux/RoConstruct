// from server: 56% by atomic.potato
extern "C" void __cdecl func_00409110(void*, int);

struct CChildFrame
{
    void* __thiscall f(void* value);
};

void* __thiscall CChildFrame::f(void* value)
{
    func_00409110(value, 0);
    return value;
}
