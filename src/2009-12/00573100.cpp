// from server: 100% by auto
// roc 2009-12 00573100  unit: CSHA1  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00573100
//
// 00573100  8b442404             mov eax, dword ptr [esp + 4]
// 00573104  f7d8                 neg eax
// 00573106  89442404             mov dword ptr [esp + 4], eax
// 0057310a  e961ffffff           jmp 0x573070
// standard library vector<double> (function ??Z?$_Vector_const_iterator@NV?$allocator@N@std@@@std@@QAEAAV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
