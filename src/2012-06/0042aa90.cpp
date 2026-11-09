// from server: 100% by auto
// roc 2012-06 0042aa90  unit: CSelectionTreeCtrl  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0042aa90
//
// 0042aa90  8b442410             mov eax, dword ptr [esp + 0x10]
// 0042aa94  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0042aa98  50                   push eax
// 0042aa99  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0042aa9d  52                   push edx
// 0042aa9e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0042aaa2  50                   push eax
// 0042aaa3  52                   push edx
// 0042aaa4  e8d74a5900           call 0x9bf580
// 0042aaa9  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@IABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
