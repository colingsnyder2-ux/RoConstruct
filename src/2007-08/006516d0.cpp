// from server: 100% by colin
// roc 2007-08 006516d0  unit: CXTPToolBar  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006516d0
//
// 006516d0  8b442404             mov eax, dword ptr [esp + 4]
// 006516d4  56                   push esi
// 006516d5  8bf1                 mov esi, ecx
// 006516d7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006516db  51                   push ecx
// 006516dc  50                   push eax
// 006516dd  8bce                 mov ecx, esi
// 006516df  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 006516e5  e806e0ffff           call 0x64f6f0
// 006516ea  85c0                 test eax, eax
// 006516ec  7504                 jne 0x6516f2
// 006516ee  5e                   pop esi
// 006516ef  c20800               ret 8
// 006516f2  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 006516f8  e853ba0200           call 0x67d150
// 006516fd  b801000000           mov eax, 1
// 00651702  5e                   pop esi
// 00651703  c20800               ret 8

struct CXTPToolBar {
    char pad[0xd4];
    int field_d4;
    char pad2[0xf8 - 0xd4 - 4];
    int field_f8;
    int sub_64f6f0(int, int);
    int func(int, int);
};

extern "C" int __fastcall sub_67d150(int);

int CXTPToolBar::func(int a, int b) {
    field_d4 = a;
    if (sub_64f6f0(a, b) == 0) {
        return 0;
    }
    sub_67d150(field_f8);
    return 1;
}
