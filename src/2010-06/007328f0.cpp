// from server: 100% by auto
// roc 2010-06 007328f0  unit: lua_exception  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007328f0
//
// 007328f0  d9ee                 fldz 
// 007328f2  8b442404             mov eax, dword ptr [esp + 4]
// 007328f6  83ec08               sub esp, 8
// 007328f9  dd1c24               fstp qword ptr [esp]
// 007328fc  50                   push eax
// 007328fd  e8aef7ffff           call 0x7320b0
// 00732902  c20400               ret 4
// standard library vector<double> (function ?resize@?$vector@NV?$allocator@N@std@@@std@@QAEXI@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
