// from server: 100% by auto
// roc 2009-06 004af0a0  unit: G3D::Win32Window  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004af0a0
//
// 004af0a0  8b01                 mov eax, dword ptr [ecx]
// 004af0a2  50                   push eax
// 004af0a3  e8369c2600           call 0x718cde
// 004af0a8  59                   pop ecx
// 004af0a9  c3                   ret 
// standard library vector<ptr> (function ??1?$_Container_base_aux_alloc_real@V?$allocator@PAUT@@@std@@@std@@IAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
