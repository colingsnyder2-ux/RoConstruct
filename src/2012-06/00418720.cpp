// from server: 73% by atomic.potato
extern "C" void __cdecl func_00409290(void*);

struct CChildFrame
{
    void* __cdecl f(void* value);
};

void* CChildFrame::f(void* value)
{
    func_00409290(value);
    return value;
}
