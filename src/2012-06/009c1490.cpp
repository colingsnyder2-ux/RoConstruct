// roc 2012-06 009c1490  unit: CRobloxTreeCtrl  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c1490
//
// 009c1490  8b442404             mov eax, dword ptr [esp + 4]
// 009c1494  6a10                 push 0x10
// 009c1496  50                   push eax
// 009c1497  e874eeffff           call 0x9c0310
// 009c149c  83e010               and eax, 0x10
// 009c149f  c20400               ret 4
// copied from an identical function in another client (function ?GetItemState@CRobloxTreeCtrl@ns_ROCX00000e@@QBEHH@Z)

namespace ns_ROCX00000e {
struct CRobloxTreeCtrl {
    int GetItemState(int item) const;
};

extern "C" int __stdcall sub_665F90(int item, int mask);

int CRobloxTreeCtrl::GetItemState(int item) const {
    return sub_665F90(item, 0x10) & 0x10;
}
}
