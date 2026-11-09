// from server: 100% by auto
// roc 2011-06 00538cd0  unit: CSHA1  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00538cd0
//
// 00538cd0  8b442404             mov eax, dword ptr [esp + 4]
// 00538cd4  f7d8                 neg eax
// 00538cd6  89442404             mov dword ptr [esp + 4], eax
// 00538cda  e961ffffff           jmp 0x538c40
// standard library vector<double> (function ??Z?$_Vector_const_iterator@NV?$allocator@N@std@@@std@@QAEAAV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
