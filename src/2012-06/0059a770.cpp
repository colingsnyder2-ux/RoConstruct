// from server: 40% by Intel
// roc-repair: genuine WinNT.h definitions (no SDK shipped)
typedef unsigned long DWORD;
struct RBX_Network_Marker
{
    DWORD field0;
    DWORD field1;
    DWORD field2;
    DWORD field3;
    DWORD field4;

    DWORD f(DWORD this_ptr, DWORD arg1);
};

DWORD RBX_Network_Marker::f(DWORD this_ptr, DWORD arg1)
{
    DWORD eax = this_ptr;
    DWORD ecx = arg1;
    eax = *(DWORD*)eax;
    ecx = *(DWORD*)ecx;
    if (eax == ecx)
        return 0xffffffff;
    return 1;
}
