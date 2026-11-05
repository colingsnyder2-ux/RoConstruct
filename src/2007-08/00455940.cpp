// from server: 30% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl func_00630298();
extern "C" void __cdecl func_00403830();
extern "C" void __cdecl func_004555b0();

struct CRobloxReportPaneView
{
    void func_00455940();
};

void CRobloxReportPaneView::func_00455940()
{
    func_00630298();

    int* p = (int*)((char*)this + 0x54);
    int local1;
    int local2;
    if (*p != 0)
    {
        func_00403830();
    }
    else
    {
        local1 = 0;
        local2 = 0;
    }

    func_004555b0();

    int local3 = 0;
    int local4 = 0;

    int* g1 = (int*)0x8bae3c;
    int* g2 = (int*)0x8bae40;

    int v1 = *g1;
    int v2 = *g2;

    if (v2 != 0)
    {
        _InterlockedExchangeAdd((volatile long*)(v2 + 4), 1);
    }

    int* obj = (int*)((char*)this + 0x318);
    int* vtbl = (int*)*obj;
    typedef void (__thiscall *Fn)(void*);
    ((Fn)vtbl[0])(obj);
}
