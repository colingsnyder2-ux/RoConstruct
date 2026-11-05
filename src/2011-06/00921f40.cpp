// from server: 100% by auto
// roc 2011-06 00921f40  unit: RBX::MeshGen  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00921f40
//
// 00921f40  b920f0d100           mov ecx, 0xd1f020
// 00921f45  ff153818a400         call dword ptr [0xa41838]
// 00921f4b  b930f0d100           mov ecx, 0xd1f030
// 00921f50  ff153818a400         call dword ptr [0xa41838]
// 00921f56  b990f0d100           mov ecx, 0xd1f090
// 00921f5b  ff153818a400         call dword ptr [0xa41838]
// 00921f61  b940f0d100           mov ecx, 0xd1f040
// 00921f66  ff254c18a400         jmp dword ptr [0xa4184c]
// library rbx2016-g3d/System.cpp (function ??__Fthesystem@?1??instance@System@G3D@@CAAAV12@XZ@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: rbx2016-g3d System.cpp
