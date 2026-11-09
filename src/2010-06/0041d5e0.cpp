// from server: 100% by auto
// roc 2010-06 0041d5e0  unit: CSelectionTreeCtrl  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041d5e0
//
// 0041d5e0  8b442410             mov eax, dword ptr [esp + 0x10]
// 0041d5e4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0041d5e8  50                   push eax
// 0041d5e9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041d5ed  52                   push edx
// 0041d5ee  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0041d5f2  50                   push eax
// 0041d5f3  52                   push edx
// 0041d5f4  e847823c00           call 0x7e5840
// 0041d5f9  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@IABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
