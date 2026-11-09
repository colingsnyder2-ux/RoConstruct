// from server: 100% by auto
// roc 2010-06 00635890  unit: RBX::VExplosion::?$EventDesc  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00635890
//
// 00635890  8bc1                 mov eax, ecx
// 00635892  c70000000000         mov dword ptr [eax], 0
// 00635898  c3                   ret 
// standard library vector<ptr> (function ??0_Iterator_base_aux@std@@QAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
