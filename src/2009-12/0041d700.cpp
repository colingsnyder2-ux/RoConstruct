// from server: 100% by auto
// roc 2009-12 0041d700  unit: CSelectionTreeCtrl  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041d700
//
// 0041d700  8b442410             mov eax, dword ptr [esp + 0x10]
// 0041d704  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0041d708  50                   push eax
// 0041d709  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041d70d  52                   push edx
// 0041d70e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0041d712  50                   push eax
// 0041d713  52                   push edx
// 0041d714  e8d73f4100           call 0x8316f0
// 0041d719  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@IABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
