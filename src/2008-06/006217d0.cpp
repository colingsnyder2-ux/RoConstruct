// from server: 100% by auto
// roc 2008-06 006217d0  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006217d0
//
// 006217d0  d9ee                 fldz 
// 006217d2  8b442404             mov eax, dword ptr [esp + 4]
// 006217d6  83ec08               sub esp, 8
// 006217d9  dd1c24               fstp qword ptr [esp]
// 006217dc  50                   push eax
// 006217dd  e8fefcffff           call 0x6214e0
// 006217e2  c20400               ret 4
// standard library vector<double> (function ?resize@?$vector@NV?$allocator@N@std@@@std@@QAEXI@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
