// from server: 100% by auto
// roc 2011-06 00a34380  unit: seg_00a30000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00a34380
//
// 00a34380  a1b0a3cb00           mov eax, dword ptr [0xcba3b0]
// 00a34385  50                   push eax
// 00a34386  c705a8a3cb00d457a800 mov dword ptr [0xcba3a8], 0xa857d4
// 00a34390  e86f5fddff           call 0x80a304
// 00a34395  83c404               add esp, 4
// 00a34398  c705b0a3cb0000000000 mov dword ptr [0xcba3b0], 0
// 00a343a2  c3                   ret 
// library rbx2016-g3d/Random.cpp (function ??__Fr@?1??common@Random@G3D@@SAAAV12@XZ@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d Random.cpp
