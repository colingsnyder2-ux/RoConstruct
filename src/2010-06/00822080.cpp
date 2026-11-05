// from server: 100% by auto
// roc 2010-06 00822080  unit: CXTCaption  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00822080
//
// 00822080  8b01                 mov eax, dword ptr [ecx]
// 00822082  50                   push eax
// 00822083  e8be5bf8ff           call 0x7a7c46
// 00822088  59                   pop ecx
// 00822089  c3                   ret 
// standard library vector<ptr> (function ??1?$_Container_base_aux_alloc_real@V?$allocator@PAUT@@@std@@@std@@IAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
