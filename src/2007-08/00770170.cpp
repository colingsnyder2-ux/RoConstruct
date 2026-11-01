// from server: 100% by auto
// roc 2007-08 00770170  unit: seg_00770000  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00770170
//
// 00770170  d9e8                 fld1 
// 00770172  83ec40               sub esp, 0x40
// 00770175  d954243c             fst dword ptr [esp + 0x3c]
// 00770179  b9900a8c00           mov ecx, 0x8c0a90
// 0077017e  d9ee                 fldz 
// 00770180  d9542438             fst dword ptr [esp + 0x38]
// 00770184  d9542434             fst dword ptr [esp + 0x34]
// 00770188  d9542430             fst dword ptr [esp + 0x30]
// 0077018c  d954242c             fst dword ptr [esp + 0x2c]
// 00770190  d9c9                 fxch st(1)
// 00770192  d9542428             fst dword ptr [esp + 0x28]
// 00770196  d9c9                 fxch st(1)
// 00770198  d9542424             fst dword ptr [esp + 0x24]
// 0077019c  d9542420             fst dword ptr [esp + 0x20]
// 007701a0  d954241c             fst dword ptr [esp + 0x1c]
// 007701a4  d9542418             fst dword ptr [esp + 0x18]
// 007701a8  d9c9                 fxch st(1)
// 007701aa  d9542414             fst dword ptr [esp + 0x14]
// 007701ae  d9c9                 fxch st(1)
// 007701b0  d9542410             fst dword ptr [esp + 0x10]
// 007701b4  d954240c             fst dword ptr [esp + 0xc]
// 007701b8  d9542408             fst dword ptr [esp + 8]
// 007701bc  d95c2404             fstp dword ptr [esp + 4]
// 007701c0  d91c24               fstp dword ptr [esp]
// 007701c3  e898aad9ff           call 0x50ac60
// 007701c8  c3                   ret 
// library wildmagic-2-core/Math\WmlMatrix4.cpp (function ??__E?IDENTITY@?$Matrix4@M@Wml@@2V12@B@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Math/WmlMatrix4.cpp
