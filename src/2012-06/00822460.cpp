// from server: 100% by auto
// roc 2012-06 00822460  unit: RBX::P8ModelInstance::?$GetSetImpl  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00822460
//
// 00822460  8b01                 mov eax, dword ptr [ecx]
// 00822462  50                   push eax
// 00822463  e8acfc1500           call 0x982114
// 00822468  59                   pop ecx
// 00822469  c3                   ret 
// standard library vector<ptr> (function ??1?$_Container_base_aux_alloc_real@V?$allocator@PAUT@@@std@@@std@@IAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
