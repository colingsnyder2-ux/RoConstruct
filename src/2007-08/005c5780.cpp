// from server: 100% by auto
// roc 2007-08 005c5780  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c5780
//
// 005c5780  d9ee                 fldz 
// 005c5782  8b442404             mov eax, dword ptr [esp + 4]
// 005c5786  51                   push ecx
// 005c5787  d91c24               fstp dword ptr [esp]
// 005c578a  50                   push eax
// 005c578b  e8b0fdffff           call 0x5c5540
// 005c5790  c20400               ret 4
// standard library vector<float> (function ?resize@?$vector@MV?$allocator@M@std@@@std@@QAEXI@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
