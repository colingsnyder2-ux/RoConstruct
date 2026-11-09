// from server: 100% by auto
// roc 2009-06 005143b0  unit: CSHA1  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005143b0
//
// 005143b0  8b442404             mov eax, dword ptr [esp + 4]
// 005143b4  f7d8                 neg eax
// 005143b6  89442404             mov dword ptr [esp + 4], eax
// 005143ba  e961ffffff           jmp 0x514320
// standard library vector<double> (function ??Z?$_Vector_const_iterator@NV?$allocator@N@std@@@std@@QAEAAV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
