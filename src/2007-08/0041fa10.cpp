// from server: 100% by auto
// roc 2007-08 0041fa10  unit: CSelectionTreeCtrl  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041fa10
//
// 0041fa10  8b442410             mov eax, dword ptr [esp + 0x10]
// 0041fa14  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0041fa18  50                   push eax
// 0041fa19  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041fa1d  52                   push edx
// 0041fa1e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0041fa22  50                   push eax
// 0041fa23  52                   push edx
// 0041fa24  e8a7572400           call 0x6651d0
// 0041fa29  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@IABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
