// from server: 100% by auto
// roc 2009-06 006c2a40  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c2a40
//
// 006c2a40  d9ee                 fldz 
// 006c2a42  8b442404             mov eax, dword ptr [esp + 4]
// 006c2a46  83ec08               sub esp, 8
// 006c2a49  dd1c24               fstp qword ptr [esp]
// 006c2a4c  50                   push eax
// 006c2a4d  e8fefcffff           call 0x6c2750
// 006c2a52  c20400               ret 4
// standard library vector<double> (function ?resize@?$vector@NV?$allocator@N@std@@@std@@QAEXI@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
