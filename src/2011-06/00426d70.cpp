// from server: 100% by auto
// roc 2011-06 00426d70  unit: CSelectionTreeCtrl  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00426d70
//
// 00426d70  8b442410             mov eax, dword ptr [esp + 0x10]
// 00426d74  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00426d78  50                   push eax
// 00426d79  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00426d7d  52                   push edx
// 00426d7e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00426d82  50                   push eax
// 00426d83  52                   push edx
// 00426d84  e877034200           call 0x847100
// 00426d89  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@IABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
