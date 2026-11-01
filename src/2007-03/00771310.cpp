// from server: 100% by auto
// roc 2007-03 00771310  unit: seg_00770000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00771310
//
// 00771310  d9e8                 fld1 
// 00771312  83ec24               sub esp, 0x24
// 00771315  d9542420             fst dword ptr [esp + 0x20]
// 00771319  b9fcae8b00           mov ecx, 0x8baefc
// 0077131e  d9ee                 fldz 
// 00771320  d954241c             fst dword ptr [esp + 0x1c]
// 00771324  d9542418             fst dword ptr [esp + 0x18]
// 00771328  d9542414             fst dword ptr [esp + 0x14]
// 0077132c  d9c9                 fxch st(1)
// 0077132e  d9542410             fst dword ptr [esp + 0x10]
// 00771332  d9c9                 fxch st(1)
// 00771334  d954240c             fst dword ptr [esp + 0xc]
// 00771338  d9542408             fst dword ptr [esp + 8]
// 0077133c  d95c2404             fstp dword ptr [esp + 4]
// 00771340  d91c24               fstp dword ptr [esp]
// 00771343  e868e3d8ff           call 0x4ff6b0
// 00771348  c3                   ret 
// library wildmagic-2-core/Math\WmlMatrix3.cpp (function ??__E?IDENTITY@?$Matrix3@M@Wml@@2V12@B@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Math/WmlMatrix3.cpp
