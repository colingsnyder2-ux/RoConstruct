// from server: 100% by auto
// roc 2008-06 004228d0  unit: CSelectionTreeCtrl  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004228d0
//
// 004228d0  8b442410             mov eax, dword ptr [esp + 0x10]
// 004228d4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004228d8  50                   push eax
// 004228d9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004228dd  52                   push edx
// 004228de  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004228e2  50                   push eax
// 004228e3  52                   push edx
// 004228e4  e8b7962b00           call 0x6dbfa0
// 004228e9  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@IABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
