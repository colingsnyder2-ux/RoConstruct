// from server: 100% by auto
// roc 2012-06 004c1ff0  unit: RBX::MeshGen  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004c1ff0
//
// 004c1ff0  b9a8c2e100           mov ecx, 0xe1c2a8
// 004c1ff5  ff151c30b200         call dword ptr [0xb2301c]
// 004c1ffb  b9b8c2e100           mov ecx, 0xe1c2b8
// 004c2000  ff151c30b200         call dword ptr [0xb2301c]
// 004c2006  b918c3e100           mov ecx, 0xe1c318
// 004c200b  ff151c30b200         call dword ptr [0xb2301c]
// 004c2011  b9c8c2e100           mov ecx, 0xe1c2c8
// 004c2016  ff251830b200         jmp dword ptr [0xb23018]
// library rbx2016-g3d/System.cpp (function ??__Fthesystem@?1??instance@System@G3D@@CAAAV12@XZ@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: rbx2016-g3d System.cpp
