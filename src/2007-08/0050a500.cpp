// from server: 100% by auto
// roc 2007-08 0050a500  unit: G3D::GCamera  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0050a500
//
// 0050a500  b801000000           mov eax, 1
// 0050a505  8405000a8c00         test byte ptr [0x8c0a00], al
// 0050a50b  753e                 jne 0x50a54b
// 0050a50d  d9e8                 fld1 
// 0050a50f  0905000a8c00         or dword ptr [0x8c0a00], eax
// 0050a515  83ec24               sub esp, 0x24
// 0050a518  d9542420             fst dword ptr [esp + 0x20]
// 0050a51c  d9ee                 fldz 
// 0050a51e  b9dc098c00           mov ecx, 0x8c09dc
// 0050a523  d954241c             fst dword ptr [esp + 0x1c]
// 0050a527  d9542418             fst dword ptr [esp + 0x18]
// 0050a52b  d9542414             fst dword ptr [esp + 0x14]
// 0050a52f  d9c9                 fxch st(1)
// 0050a531  d9542410             fst dword ptr [esp + 0x10]
// 0050a535  d9c9                 fxch st(1)
// 0050a537  d954240c             fst dword ptr [esp + 0xc]
// 0050a53b  d9542408             fst dword ptr [esp + 8]
// 0050a53f  d95c2404             fstp dword ptr [esp + 4]
// 0050a543  d91c24               fstp dword ptr [esp]
// 0050a546  e8e5fbffff           call 0x50a130
// 0050a54b  b8dc098c00           mov eax, 0x8c09dc
// 0050a550  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?identity@Matrix3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: rbx2016-g3d Box.cpp
