// from server: 69% by colin
struct CRobloxWnd
{
    char pad[0x2c];
    double field_2c;
    void func_00458940(double);
};

extern "C" void __stdcall LeaveCriticalSection(void*);

extern void* G_008bc078;

extern void sub_0041d870(void*);

void CRobloxWnd::func_00458940(double value)
{
    struct Local
    {
        void* p;
        char flag;
    };

    Local local;
    local.p = &G_008bc078;
    local.flag = 0;
    sub_0041d870(&local);
    field_2c = value;
    if (local.flag != 0)
    {
        LeaveCriticalSection(local.p);
    }
}
