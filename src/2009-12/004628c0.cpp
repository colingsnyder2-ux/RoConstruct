// from server: 83% by atomic.potato
struct CRobloxWnd
{
    char pad[0xd8];
    void* fieldD8;
    void f(void*);
};

extern void __stdcall func_00473860(void*, int);
extern void __stdcall func_007F3E30(CRobloxWnd*);

void CRobloxWnd::f(void* value)
{
    if (fieldD8)
        func_00473860(fieldD8, 0);
    func_007F3E30(this);
}
