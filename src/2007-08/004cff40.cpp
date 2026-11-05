// from server: 100% by auto
// roc 2007-08 004cff40  unit: RBX::TextureProxyBase  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004cff40
//
// 004cff40  8bc1                 mov eax, ecx
// 004cff42  c70000000000         mov dword ptr [eax], 0
// 004cff48  c3                   ret 
// standard library vector<ptr> (function ??0_Iterator_base@std@@QAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
