// from server: 100% by Xemicl
// roc 2012-06 004184d0  unit: CRbxChildFrame  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004184d0
//
// 004184d0  56                   push esi
// 004184d1  8b742408             mov esi, dword ptr [esp + 8]
// 004184d5  33c0                 xor eax, eax
// 004184d7  894618               mov dword ptr [esi + 0x18], eax
// 004184da  89461c               mov dword ptr [esi + 0x1c], eax
// 004184dd  b8ff7f0000           mov eax, 0x7fff
// 004184e2  56                   push esi
// 004184e3  894610               mov dword ptr [esi + 0x10], eax
// 004184e6  894614               mov dword ptr [esi + 0x14], eax
// 004184e9  e85ea35600           call 0x98284c
// 004184ee  85c0                 test eax, eax
// 004184f0  7504                 jne 0x4184f6
// 004184f2  5e                   pop esi
// 004184f3  c20400               ret 4
// 004184f6  814e2000000002       or dword ptr [esi + 0x20], 0x2000000
// 004184fd  b801000000           mov eax, 1
// 00418502  5e                   pop esi
// 00418503  c20400               ret 4
// copied from an identical function in another client (function ?Init@ns_ROCX00000e@@YGHPAUCChildFrame@1@@Z)

namespace ns_ROCX00000e {
struct CChildFrame
{
    char pad0[0x10];
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
};

extern "C" int __stdcall sub_007191a6(CChildFrame*);

int __stdcall Init(CChildFrame* self)
{
    self->field18 = 0;
    self->field1c = 0;
    self->field10 = 0x7fff;
    self->field14 = 0x7fff;
    if (sub_007191a6(self) == 0)
        return 0;
    self->field20 |= 0x2000000;
    return 1;
}
}
