// from server: 100% by auto
// roc 2010-06 00740760  unit: seg_00740000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00740760
//
// 00740760  8b01                 mov eax, dword ptr [ecx]
// 00740762  50                   push eax
// 00740763  e832720600           call 0x7a799a
// 00740768  59                   pop ecx
// 00740769  c3                   ret 
// standard library vector<ptr> (function ??1?$_Container_base_aux_alloc_real@V?$allocator@PAUT@@@std@@@std@@IAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
