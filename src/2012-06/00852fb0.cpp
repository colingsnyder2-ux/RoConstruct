// from server: 100% by auto
// roc 2012-06 00852fb0  unit: RBX::CoreScript  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00852fb0
//
// 00852fb0  d9ee                 fldz 
// 00852fb2  8b442404             mov eax, dword ptr [esp + 4]
// 00852fb6  83ec08               sub esp, 8
// 00852fb9  dd1c24               fstp qword ptr [esp]
// 00852fbc  50                   push eax
// 00852fbd  e8eefeffff           call 0x852eb0
// 00852fc2  c20400               ret 4
// standard library vector<double> (function ?resize@?$vector@NV?$allocator@N@std@@@std@@QAEXI@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
