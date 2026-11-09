// from server: 100% by auto
// roc 2011-06 006c6b50  unit: RBX::InstanceLocksmith  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006c6b50
//
// 006c6b50  8bc1                 mov eax, ecx
// 006c6b52  c70000000000         mov dword ptr [eax], 0
// 006c6b58  c3                   ret 
// standard library vector<ptr> (function ??0_Iterator_base_aux@std@@QAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
