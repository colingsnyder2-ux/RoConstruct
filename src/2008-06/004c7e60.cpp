// from server: 100% by auto
// roc 2008-06 004c7e60  unit: RBX::VInstance::?$Association::Item  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c7e60
//
// 004c7e60  d9ee                 fldz 
// 004c7e62  8b442404             mov eax, dword ptr [esp + 4]
// 004c7e66  51                   push ecx
// 004c7e67  d91c24               fstp dword ptr [esp]
// 004c7e6a  50                   push eax
// 004c7e6b  e8b0feffff           call 0x4c7d20
// 004c7e70  c20400               ret 4
// standard library vector<float> (function ?resize@?$vector@MV?$allocator@M@std@@@std@@QAEXI@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
