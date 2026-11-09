// from server: 100% by auto
// roc 2012-06 009f7d50  unit: CXTCaption  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f7d50
//
// 009f7d50  8b01                 mov eax, dword ptr [ecx]
// 009f7d52  50                   push eax
// 009f7d53  e862a6f8ff           call 0x9823ba
// 009f7d58  59                   pop ecx
// 009f7d59  c3                   ret 
// standard library vector<ptr> (function ??1?$_Container_base_aux_alloc_real@V?$allocator@PAUT@@@std@@@std@@IAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
