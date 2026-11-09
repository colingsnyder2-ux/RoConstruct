// from server: 100% by EspClaude
// roc 2009-06 0041cd40  unit: CRobloxTreeCtrl  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041cd40
//
// 0041cd40  8b442404             mov eax, dword ptr [esp + 4]
// 0041cd44  56                   push esi
// 0041cd45  8bf1                 mov esi, ecx
// 0041cd47  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0041cd4a  83e1ef               and ecx, 0xffffffef
// 0041cd4d  83c92d               or ecx, 0x2d
// 0041cd50  894820               mov dword ptr [eax + 0x20], ecx
// 0041cd53  50                   push eax
// 0041cd54  8bce                 mov ecx, esi
// 0041cd56  e861bd2f00           call 0x718abc
// 0041cd5b  85c0                 test eax, eax
// 0041cd5d  7504                 jne 0x41cd63
// 0041cd5f  5e                   pop esi
// 0041cd60  c20400               ret 4
// 0041cd63  c6869000000000       mov byte ptr [esi + 0x90], 0
// 0041cd6a  b801000000           mov eax, 1
// 0041cd6f  5e                   pop esi
// 0041cd70  c20400               ret 4
// copied from an identical function in another client (function ?func@CRobloxTreeCtrl@ns_ROCX00007d@@QAEHPAX@Z)

namespace ns_ROCX00007d {
struct CRobloxTreeCtrl {
    char pad[0x90];
    char field_90;
    int sub_6a070a(void*);
    int func(void*);
};

int CRobloxTreeCtrl::func(void* arg) {
    int* p = (int*)arg;
    p[8] = (p[8] & 0xffffffef) | 0x2d;
    if (sub_6a070a(arg) == 0)
        return 0;
    field_90 = 0;
    return 1;
}
}
