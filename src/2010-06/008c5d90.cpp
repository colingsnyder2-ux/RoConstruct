// from server: 100% by auto
// roc 2010-06 008c5d90  unit: RBX::AdornRbxGfx  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c5d90
//
// 008c5d90  b9dcc3c200           mov ecx, 0xc2c3dc
// 008c5d95  ff151cb89e00         call dword ptr [0x9eb81c]
// 008c5d9b  b9ecc3c200           mov ecx, 0xc2c3ec
// 008c5da0  ff151cb89e00         call dword ptr [0x9eb81c]
// 008c5da6  b950c4c200           mov ecx, 0xc2c450
// 008c5dab  ff151cb89e00         call dword ptr [0x9eb81c]
// 008c5db1  b9fcc3c200           mov ecx, 0xc2c3fc
// 008c5db6  ff2520b89e00         jmp dword ptr [0x9eb820]
// library rbx2016-g3d/System.cpp (function ??__Fthesystem@?1??instance@System@G3D@@CAAAV12@XZ@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: rbx2016-g3d System.cpp
