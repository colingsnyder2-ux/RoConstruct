// from server: 100% by auto
// roc 2007-03 007713b0  unit: seg_00770000  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007713b0
//
// 007713b0  d9ee                 fldz 
// 007713b2  83ec40               sub esp, 0x40
// 007713b5  d954243c             fst dword ptr [esp + 0x3c]
// 007713b9  b920af8b00           mov ecx, 0x8baf20
// 007713be  d9542438             fst dword ptr [esp + 0x38]
// 007713c2  d9542434             fst dword ptr [esp + 0x34]
// 007713c6  d9542430             fst dword ptr [esp + 0x30]
// 007713ca  d954242c             fst dword ptr [esp + 0x2c]
// 007713ce  d9542428             fst dword ptr [esp + 0x28]
// 007713d2  d9542424             fst dword ptr [esp + 0x24]
// 007713d6  d9542420             fst dword ptr [esp + 0x20]
// 007713da  d954241c             fst dword ptr [esp + 0x1c]
// 007713de  d9542418             fst dword ptr [esp + 0x18]
// 007713e2  d9542414             fst dword ptr [esp + 0x14]
// 007713e6  d9542410             fst dword ptr [esp + 0x10]
// 007713ea  d954240c             fst dword ptr [esp + 0xc]
// 007713ee  d9542408             fst dword ptr [esp + 8]
// 007713f2  d9542404             fst dword ptr [esp + 4]
// 007713f6  d91c24               fstp dword ptr [esp]
// 007713f9  e8a2efd8ff           call 0x5003a0
// 007713fe  c3                   ret 
// library wildmagic-2-core/Math\WmlMatrix4.cpp (function ??__E?ZERO@?$Matrix4@M@Wml@@2V12@B@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Math/WmlMatrix4.cpp
