// from server: 100% by auto
// roc 2009-06 0041d090  unit: CSelectionTreeCtrl  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041d090
//
// 0041d090  8b442410             mov eax, dword ptr [esp + 0x10]
// 0041d094  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0041d098  50                   push eax
// 0041d099  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041d09d  52                   push edx
// 0041d09e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0041d0a2  50                   push eax
// 0041d0a3  52                   push edx
// 0041d0a4  e897973300           call 0x756840
// 0041d0a9  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@IABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
