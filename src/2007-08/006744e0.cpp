// from server: 12% by colin
struct CXTPCustomizeSheet
{
    void func_006744e0();
};

extern "C" void __stdcall GlobalAlloc_stub();
extern "C" void __stdcall CloseClipboard_stub();
extern "C" void __stdcall EmptyClipboard_stub();
extern "C" void __stdcall GetSysColor_stub();
extern "C" void __stdcall OpenClipboard_stub();
extern "C" void __stdcall SetClipboardData_stub();

extern "C" void __stdcall sub_41F680();
extern "C" void __stdcall sub_4605A0();
extern "C" void __stdcall sub_630238();
extern "C" void __stdcall sub_6321F0();
extern "C" void __stdcall sub_639C90();
extern "C" void __stdcall sub_63D780();
extern "C" void __stdcall sub_648620();
extern "C" void __stdcall sub_648630();
extern "C" void __stdcall sub_648730();
extern "C" void __stdcall sub_649110();
extern "C" void __stdcall sub_649A10();
extern "C" void __stdcall sub_64B2C0();
extern "C" void __stdcall sub_64CB40();
extern "C" void __stdcall sub_64D9B0();
extern "C" void __stdcall sub_64DFD0();
extern "C" void __stdcall sub_64E070();
extern "C" void __stdcall sub_651980();
extern "C" void __stdcall sub_673C00();
extern "C" void __stdcall sub_7383A6();
extern "C" void __stdcall sub_7383AC();
extern "C" void __stdcall sub_7383CA();
extern "C" void __stdcall sub_7383DC();
extern "C" void __stdcall sub_7383E2();
extern "C" void __stdcall sub_73843C();

void CXTPCustomizeSheet::func_006744e0()
{
    int* p = *(int**)((char*)this + 0xb8);
    int* edi = *(int**)((char*)p + 0x58);
    if (edi == 0)
        return;

    int eax = *(int*)((char*)edi + 0x90);
    int edx;
    if (eax != 0)
    {
        edx = eax;
    }
    else
    {
        edx = *(int*)((char*)edi + 0x88);
        if (edx <= 0)
        {
            int* esi = *(int**)((char*)edi + 0x158);
            if (esi != 0)
            {
                edx = *(int*)((char*)esi + 0x2c);
                if (edx <= 0)
                    edx = *(int*)((char*)esi + 0x28);
            }
            else
            {
                edx = *(int*)((char*)edi + 0x84);
            }
        }
    }
    if (edx == 0)
        return;

    if (eax == 0)
    {
        eax = *(int*)((char*)edi + 0x88);
        if (eax <= 0)
        {
            int* esi = *(int**)((char*)edi + 0x158);
            if (esi != 0)
            {
                eax = *(int*)((char*)esi + 0x2c);
                if (eax <= 0)
                    eax = *(int*)((char*)esi + 0x28);
            }
            else
            {
                eax = *(int*)((char*)edi + 0x84);
            }
        }
    }

    sub_6321F0();
    sub_64D9B0();
    if (0 == 0)
        return;

    sub_648730();
    int* esi2 = 0;
    int ebp = 0x788300;
    sub_648620();
    if (0 != 0)
    {
        sub_648630();
        sub_649A10();
        sub_630238();
    }
    else
    {
        sub_64B2C0();
        sub_7383AC();
        sub_7383E2();
        sub_63D780();
        sub_649110();
        if (0 == 0)
        {
            sub_7383DC();
            sub_7383A6();
        }
        else
        {
            sub_651980();
            sub_7383CA();
            sub_4605A0();
            sub_673C00();
            sub_651980();
            sub_7383DC();
            sub_7383A6();
        }
    }

    sub_73843C();
    sub_648620();
    if (0 != 0)
    {
        sub_64DFD0();
        sub_639C90();
        sub_6321F0();
        sub_64CB40();
        if (0 != 0)
        {
            sub_639C90();
            sub_6321F0();
            sub_64E070();
        }
    }
    sub_41F680();
}
