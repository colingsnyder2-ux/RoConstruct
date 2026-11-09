// from server: 100% by auto
// roc 2007-08 00770130  unit: seg_00770000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00770130
//
// 00770130  d9e8                 fld1 
// 00770132  83ec24               sub esp, 0x24
// 00770135  d9542420             fst dword ptr [esp + 0x20]
// 00770139  b9280a8c00           mov ecx, 0x8c0a28
// 0077013e  d9ee                 fldz 
// 00770140  d954241c             fst dword ptr [esp + 0x1c]
// 00770144  d9542418             fst dword ptr [esp + 0x18]
// 00770148  d9542414             fst dword ptr [esp + 0x14]
// 0077014c  d9c9                 fxch st(1)
// 0077014e  d9542410             fst dword ptr [esp + 0x10]
// 00770152  d9c9                 fxch st(1)
// 00770154  d954240c             fst dword ptr [esp + 0xc]
// 00770158  d9542408             fst dword ptr [esp + 8]
// 0077015c  d95c2404             fstp dword ptr [esp + 4]
// 00770160  d91c24               fstp dword ptr [esp]
// 00770163  e8c89fd9ff           call 0x50a130
// 00770168  c3                   ret 
// library wildmagic-2-core/Math\WmlMatrix3.cpp (function ??__E?IDENTITY@?$Matrix3@M@Wml@@2V12@B@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Math/WmlMatrix3.cpp
