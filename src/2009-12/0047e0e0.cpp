// from server: 100% by auto
// roc 2009-12 0047e0e0  unit: RBX::ManualObjectMeshGenAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047e0e0
//
// 0047e0e0  b980cbb700           mov ecx, 0xb7cb80
// 0047e0e5  ff15dcbc9800         call dword ptr [0x98bcdc]
// 0047e0eb  b990cbb700           mov ecx, 0xb7cb90
// 0047e0f0  ff15dcbc9800         call dword ptr [0x98bcdc]
// 0047e0f6  b9f4cbb700           mov ecx, 0xb7cbf4
// 0047e0fb  ff15dcbc9800         call dword ptr [0x98bcdc]
// 0047e101  b9a0cbb700           mov ecx, 0xb7cba0
// 0047e106  ff25d8bc9800         jmp dword ptr [0x98bcd8]
// library rbx2016-g3d/System.cpp (function ??__Fthesystem@?1??instance@System@G3D@@CAAAV12@XZ@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d System.cpp
