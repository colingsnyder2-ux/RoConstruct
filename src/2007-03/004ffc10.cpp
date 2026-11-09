// from server: 100% by auto
// roc 2007-03 004ffc10  unit: seg_004f0000  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004ffc10
//
// 004ffc10  b801000000           mov eax, 1
// 004ffc15  8405d4ae8b00         test byte ptr [0x8baed4], al
// 004ffc1b  753e                 jne 0x4ffc5b
// 004ffc1d  d9e8                 fld1 
// 004ffc1f  0905d4ae8b00         or dword ptr [0x8baed4], eax
// 004ffc25  83ec24               sub esp, 0x24
// 004ffc28  d9542420             fst dword ptr [esp + 0x20]
// 004ffc2c  d9ee                 fldz 
// 004ffc2e  b9b0ae8b00           mov ecx, 0x8baeb0
// 004ffc33  d954241c             fst dword ptr [esp + 0x1c]
// 004ffc37  d9542418             fst dword ptr [esp + 0x18]
// 004ffc3b  d9542414             fst dword ptr [esp + 0x14]
// 004ffc3f  d9c9                 fxch st(1)
// 004ffc41  d9542410             fst dword ptr [esp + 0x10]
// 004ffc45  d9c9                 fxch st(1)
// 004ffc47  d954240c             fst dword ptr [esp + 0xc]
// 004ffc4b  d9542408             fst dword ptr [esp + 8]
// 004ffc4f  d95c2404             fstp dword ptr [esp + 4]
// 004ffc53  d91c24               fstp dword ptr [esp]
// 004ffc56  e855faffff           call 0x4ff6b0
// 004ffc5b  b8b0ae8b00           mov eax, 0x8baeb0
// 004ffc60  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?identity@Matrix3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
