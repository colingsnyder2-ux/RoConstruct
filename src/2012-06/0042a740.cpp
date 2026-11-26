// from server: 100% by Xemicl
// roc 2012-06 0042a740  unit: CRobloxTreeCtrl  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0042a740
//
// 0042a740  8b442404             mov eax, dword ptr [esp + 4]
// 0042a744  56                   push esi
// 0042a745  8bf1                 mov esi, ecx
// 0042a747  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0042a74a  83e1ef               and ecx, 0xffffffef
// 0042a74d  83c92d               or ecx, 0x2d
// 0042a750  894820               mov dword ptr [eax + 0x20], ecx
// 0042a753  50                   push eax
// 0042a754  8bce                 mov ecx, esi
// 0042a756  e8437a5500           call 0x98219e
// 0042a75b  85c0                 test eax, eax
// 0042a75d  7504                 jne 0x42a763
// 0042a75f  5e                   pop esi
// 0042a760  c20400               ret 4
// 0042a763  c6869000000000       mov byte ptr [esi + 0x90], 0
// 0042a76a  b801000000           mov eax, 1
// 0042a76f  5e                   pop esi
// 0042a770  c20400               ret 4
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