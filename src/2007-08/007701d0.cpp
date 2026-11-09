// from server: 100% by auto
// roc 2007-08 007701d0  unit: seg_00770000  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 007701d0
//
// 007701d0  d9ee                 fldz 
// 007701d2  83ec40               sub esp, 0x40
// 007701d5  d954243c             fst dword ptr [esp + 0x3c]
// 007701d9  b9500a8c00           mov ecx, 0x8c0a50
// 007701de  d9542438             fst dword ptr [esp + 0x38]
// 007701e2  d9542434             fst dword ptr [esp + 0x34]
// 007701e6  d9542430             fst dword ptr [esp + 0x30]
// 007701ea  d954242c             fst dword ptr [esp + 0x2c]
// 007701ee  d9542428             fst dword ptr [esp + 0x28]
// 007701f2  d9542424             fst dword ptr [esp + 0x24]
// 007701f6  d9542420             fst dword ptr [esp + 0x20]
// 007701fa  d954241c             fst dword ptr [esp + 0x1c]
// 007701fe  d9542418             fst dword ptr [esp + 0x18]
// 00770202  d9542414             fst dword ptr [esp + 0x14]
// 00770206  d9542410             fst dword ptr [esp + 0x10]
// 0077020a  d954240c             fst dword ptr [esp + 0xc]
// 0077020e  d9542408             fst dword ptr [esp + 8]
// 00770212  d9542404             fst dword ptr [esp + 4]
// 00770216  d91c24               fstp dword ptr [esp]
// 00770219  e842aad9ff           call 0x50ac60
// 0077021e  c3                   ret 
// library wildmagic-2-core/Math\WmlMatrix4.cpp (function ??__E?ZERO@?$Matrix4@M@Wml@@2V12@B@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Math/WmlMatrix4.cpp
