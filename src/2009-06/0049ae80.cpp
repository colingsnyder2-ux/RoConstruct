// from server: 100% by auto
// roc 2009-06 0049ae80  unit: G3D::ReferenceCountedObject  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0049ae80
//
// 0049ae80  8bc1                 mov eax, ecx
// 0049ae82  c70000000000         mov dword ptr [eax], 0
// 0049ae88  c3                   ret 
// standard library vector<ptr> (function ??0_Iterator_base_aux@std@@QAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
