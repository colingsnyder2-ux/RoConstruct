// from server: 100% by auto
// roc 2012-06 00809df0  unit: RBX::InsertService  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00809df0
//
// 00809df0  8bc1                 mov eax, ecx
// 00809df2  c70000000000         mov dword ptr [eax], 0
// 00809df8  c3                   ret 
// standard library vector<ptr> (function ??0_Iterator_base_aux@std@@QAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
