// from server: 100% by auto
// roc 2007-03 00771350  unit: seg_00770000  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00771350
//
// 00771350  d9e8                 fld1 
// 00771352  83ec40               sub esp, 0x40
// 00771355  d954243c             fst dword ptr [esp + 0x3c]
// 00771359  b960af8b00           mov ecx, 0x8baf60
// 0077135e  d9ee                 fldz 
// 00771360  d9542438             fst dword ptr [esp + 0x38]
// 00771364  d9542434             fst dword ptr [esp + 0x34]
// 00771368  d9542430             fst dword ptr [esp + 0x30]
// 0077136c  d954242c             fst dword ptr [esp + 0x2c]
// 00771370  d9c9                 fxch st(1)
// 00771372  d9542428             fst dword ptr [esp + 0x28]
// 00771376  d9c9                 fxch st(1)
// 00771378  d9542424             fst dword ptr [esp + 0x24]
// 0077137c  d9542420             fst dword ptr [esp + 0x20]
// 00771380  d954241c             fst dword ptr [esp + 0x1c]
// 00771384  d9542418             fst dword ptr [esp + 0x18]
// 00771388  d9c9                 fxch st(1)
// 0077138a  d9542414             fst dword ptr [esp + 0x14]
// 0077138e  d9c9                 fxch st(1)
// 00771390  d9542410             fst dword ptr [esp + 0x10]
// 00771394  d954240c             fst dword ptr [esp + 0xc]
// 00771398  d9542408             fst dword ptr [esp + 8]
// 0077139c  d95c2404             fstp dword ptr [esp + 4]
// 007713a0  d91c24               fstp dword ptr [esp]
// 007713a3  e8f8efd8ff           call 0x5003a0
// 007713a8  c3                   ret 
// library wildmagic-2-core/Math\WmlMatrix4.cpp (function ??__E?IDENTITY@?$Matrix4@M@Wml@@2V12@B@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Math/WmlMatrix4.cpp
