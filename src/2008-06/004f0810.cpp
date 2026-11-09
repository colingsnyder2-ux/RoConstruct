// from server: 100% by auto
// roc 2008-06 004f0810  unit: RBX::ViewNew::Texture  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004f0810
//
// 004f0810  8bc1                 mov eax, ecx
// 004f0812  c70000000000         mov dword ptr [eax], 0
// 004f0818  c3                   ret 
// standard library vector<ptr> (function ??0_Iterator_base_aux@std@@QAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
