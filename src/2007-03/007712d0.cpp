// from server: 100% by auto
// roc 2007-03 007712d0  unit: seg_00770000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007712d0
//
// 007712d0  d9ee                 fldz 
// 007712d2  83ec24               sub esp, 0x24
// 007712d5  d9542420             fst dword ptr [esp + 0x20]
// 007712d9  b9d8ae8b00           mov ecx, 0x8baed8
// 007712de  d954241c             fst dword ptr [esp + 0x1c]
// 007712e2  d9542418             fst dword ptr [esp + 0x18]
// 007712e6  d9542414             fst dword ptr [esp + 0x14]
// 007712ea  d9542410             fst dword ptr [esp + 0x10]
// 007712ee  d954240c             fst dword ptr [esp + 0xc]
// 007712f2  d9542408             fst dword ptr [esp + 8]
// 007712f6  d9542404             fst dword ptr [esp + 4]
// 007712fa  d91c24               fstp dword ptr [esp]
// 007712fd  e8aee3d8ff           call 0x4ff6b0
// 00771302  c3                   ret 
// library wildmagic-2-core/Math\WmlMatrix3.cpp (function ??__E?ZERO@?$Matrix3@M@Wml@@2V12@B@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Math/WmlMatrix3.cpp
