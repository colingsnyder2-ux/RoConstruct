// from server: 100% by auto
// roc 2011-06 0077ada0  unit: seg_00770000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0077ada0
//
// 0077ada0  d9ee                 fldz 
// 0077ada2  8b442404             mov eax, dword ptr [esp + 4]
// 0077ada6  83ec08               sub esp, 8
// 0077ada9  dd1c24               fstp qword ptr [esp]
// 0077adac  50                   push eax
// 0077adad  e88efbffff           call 0x77a940
// 0077adb2  c20400               ret 4
// standard library vector<double> (function ?resize@?$vector@NV?$allocator@N@std@@@std@@QAEXI@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
