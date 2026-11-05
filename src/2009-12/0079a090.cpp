// from server: 100% by auto
// roc 2009-12 0079a090  unit: lua_exception  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079a090
//
// 0079a090  d9ee                 fldz 
// 0079a092  8b442404             mov eax, dword ptr [esp + 4]
// 0079a096  83ec08               sub esp, 8
// 0079a099  dd1c24               fstp qword ptr [esp]
// 0079a09c  50                   push eax
// 0079a09d  e8aef7ffff           call 0x799850
// 0079a0a2  c20400               ret 4
// standard library vector<double> (function ?resize@?$vector@NV?$allocator@N@std@@@std@@QAEXI@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
