// from server: 100% by auto
// roc 2012-06 00635540  unit: G3D::LineSegment  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00635540
//
// 00635540  6aff                 push -1
// 00635542  68e9f3a900           push 0xa9f3e9
// 00635547  64a100000000         mov eax, dword ptr fs:[0]
// 0063554d  50                   push eax
// 0063554e  64892500000000       mov dword ptr fs:[0], esp
// 00635555  51                   push ecx
// 00635556  56                   push esi
// 00635557  8bf1                 mov esi, ecx
// 00635559  57                   push edi
// 0063555a  89742408             mov dword ptr [esp + 8], esi
// 0063555e  8b4634               mov eax, dword ptr [esi + 0x34]
// 00635561  33ff                 xor edi, edi
// 00635563  50                   push eax
// 00635564  897c2418             mov dword ptr [esp + 0x18], edi
// 00635568  e8d355ffff           call 0x62ab40
// 0063556d  83c404               add esp, 4
// 00635570  8bce                 mov ecx, esi
// 00635572  897e34               mov dword ptr [esi + 0x34], edi
// 00635575  897e38               mov dword ptr [esi + 0x38], edi
// 00635578  897e3c               mov dword ptr [esi + 0x3c], edi
// 0063557b  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00635583  ff153c26b200         call dword ptr [0xb2263c]
// 00635589  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0063558d  5f                   pop edi
// 0063558e  5e                   pop esi
// 0063558f  64890d00000000       mov dword ptr fs:[0], ecx
// 00635596  83c410               add esp, 0x10
// 00635599  c3                   ret 
// library rbx2016-g3d/BinaryOutput.cpp (function ??1BinaryOutput@G3D@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryOutput.cpp
