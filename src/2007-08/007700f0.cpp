// from server: 100% by auto
// roc 2007-08 007700f0  unit: seg_00770000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 007700f0
//
// 007700f0  d9ee                 fldz 
// 007700f2  83ec24               sub esp, 0x24
// 007700f5  d9542420             fst dword ptr [esp + 0x20]
// 007700f9  b9040a8c00           mov ecx, 0x8c0a04
// 007700fe  d954241c             fst dword ptr [esp + 0x1c]
// 00770102  d9542418             fst dword ptr [esp + 0x18]
// 00770106  d9542414             fst dword ptr [esp + 0x14]
// 0077010a  d9542410             fst dword ptr [esp + 0x10]
// 0077010e  d954240c             fst dword ptr [esp + 0xc]
// 00770112  d9542408             fst dword ptr [esp + 8]
// 00770116  d9542404             fst dword ptr [esp + 4]
// 0077011a  d91c24               fstp dword ptr [esp]
// 0077011d  e80ea0d9ff           call 0x50a130
// 00770122  c3                   ret 
// library wildmagic-2-core/Math\WmlMatrix3.cpp (function ??__E?ZERO@?$Matrix3@M@Wml@@2V12@B@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Math/WmlMatrix3.cpp
