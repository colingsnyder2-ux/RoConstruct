// from server: 100% by auto
// roc 2008-06 004023f0  unit: std::bad_alloc  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004023f0
//
// 004023f0  8b442404             mov eax, dword ptr [esp + 4]
// 004023f4  8b10                 mov edx, dword ptr [eax]
// 004023f6  8911                 mov dword ptr [ecx], edx
// 004023f8  c20400               ret 4
// standard library vector<ptr> (function ?_Set_container@_Iterator_base_aux@std@@QAEXQBV_Container_base_aux@2@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
