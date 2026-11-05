// from server: 36% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_630022(int);
extern "C" void __stdcall sub_40D550();
extern "C" void __stdcall sub_42CE80();
extern "C" void __stdcall sub_5595A0();
extern "C" void __stdcall sub_77E698();

struct CLuaHtmlView
{
    char pad[0xfc];
    int field_fc;
    int field_100;
    int field_104;
    void func(int);
};

void CLuaHtmlView::func(int arg)
{
    sub_630022(arg);
    if (field_104 != 0)
    {
        int a = field_fc;
        int b = field_100;
        if (b != 0)
        {
            _InterlockedExchangeAdd((volatile long*)(b + 4), 1);
        }
        sub_40D550();
        int* p = (int*)field_104;
        int* q;
        if (p != 0)
            q = p + 1;
        else
            q = 0;
        sub_77E698();
        sub_42CE80();
        sub_5595A0();
    }
}
