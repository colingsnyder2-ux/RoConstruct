// from server: 100% by colin
// roc 2007-08 00647510  unit: CXTPCommandBar  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00647510
//
// 00647510  e85bfbffff           call 0x647070
// 00647515  85c0                 test eax, eax
// 00647517  740c                 je 0x647525
// 00647519  83786800             cmp dword ptr [eax + 0x68], 0
// 0064751d  7406                 je 0x647525
// 0064751f  b801000000           mov eax, 1
// 00647524  c3                   ret
// 00647525  33c0                 xor eax, eax
// 00647527  c3                   ret

struct CXTPCommandBarHelper
{
    char pad_0x00[0x68];
    int field_0x68;
};

extern "C" CXTPCommandBarHelper* __cdecl sub_647070();

struct CXTPCommandBar
{
    int IsVisible();
};

int CXTPCommandBar::IsVisible()
{
    CXTPCommandBarHelper* p = sub_647070();
    if (p != 0 && p->field_0x68 != 0)
        return 1;
    return 0;
}
