// from server: 100% by auto
// roc 2011-06 005450b0  unit: G3D::BinaryInput  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005450b0
//
// 005450b0  6aff                 push -1
// 005450b2  6829e09e00           push 0x9ee029
// 005450b7  64a100000000         mov eax, dword ptr fs:[0]
// 005450bd  50                   push eax
// 005450be  64892500000000       mov dword ptr fs:[0], esp
// 005450c5  51                   push ecx
// 005450c6  56                   push esi
// 005450c7  8bf1                 mov esi, ecx
// 005450c9  57                   push edi
// 005450ca  89742408             mov dword ptr [esp + 8], esi
// 005450ce  8b4634               mov eax, dword ptr [esi + 0x34]
// 005450d1  33ff                 xor edi, edi
// 005450d3  50                   push eax
// 005450d4  897c2418             mov dword ptr [esp + 0x18], edi
// 005450d8  e8639bffff           call 0x53ec40
// 005450dd  83c404               add esp, 4
// 005450e0  8bce                 mov ecx, esi
// 005450e2  897e34               mov dword ptr [esi + 0x34], edi
// 005450e5  897e38               mov dword ptr [esi + 0x38], edi
// 005450e8  897e3c               mov dword ptr [esi + 0x3c], edi
// 005450eb  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 005450f3  ff15d004a400         call dword ptr [0xa404d0]
// 005450f9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005450fd  5f                   pop edi
// 005450fe  5e                   pop esi
// 005450ff  64890d00000000       mov dword ptr fs:[0], ecx
// 00545106  83c410               add esp, 0x10
// 00545109  c3                   ret 
// library rbx2016-g3d/BinaryOutput.cpp (function ??1BinaryOutput@G3D@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryOutput.cpp
