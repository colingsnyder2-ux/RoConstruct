// from server: 100% by auto
// roc 2011-06 0087f7a0  unit: CXTCaption  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0087f7a0
//
// 0087f7a0  8b01                 mov eax, dword ptr [ecx]
// 0087f7a2  50                   push eax
// 0087f7a3  e85cabf8ff           call 0x80a304
// 0087f7a8  59                   pop ecx
// 0087f7a9  c3                   ret 
// standard library vector<ptr> (function ??1?$_Container_base_aux_alloc_real@V?$allocator@PAUT@@@std@@@std@@IAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
