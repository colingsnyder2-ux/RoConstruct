// from server: 100% by auto
// roc 2010-06 005219f0  unit: CSHA1  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005219f0
//
// 005219f0  8b442404             mov eax, dword ptr [esp + 4]
// 005219f4  f7d8                 neg eax
// 005219f6  89442404             mov dword ptr [esp + 4], eax
// 005219fa  e961ffffff           jmp 0x521960
// standard library vector<double> (function ??Z?$_Vector_const_iterator@NV?$allocator@N@std@@@std@@QAEAAV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
