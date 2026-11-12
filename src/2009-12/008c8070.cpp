// roc 2009-12 008c8070  unit: VCEdit::?$CXTMaskEditT  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c8070
//
// 008c8070  6aff                 push -1
// 008c8072  6848489600           push 0x964848
// 008c8077  64a100000000         mov eax, dword ptr fs:[0]
// 008c807d  50                   push eax
// 008c807e  51                   push ecx
// 008c807f  56                   push esi
// 008c8080  a10052b600           mov eax, dword ptr [0xb65200]
// 008c8085  33c4                 xor eax, esp
// 008c8087  50                   push eax
// 008c8088  8d44240c             lea eax, [esp + 0xc]
// 008c808c  64a300000000         mov dword ptr fs:[0], eax
// 008c8092  8bf1                 mov esi, ecx
// 008c8094  89742408             mov dword ptr [esp + 8], esi
// 008c8098  c744241400000000     mov dword ptr [esp + 0x14], 0
// 008c80a0  e86bf9ffff           call 0x8c7a10
// 008c80a5  8bce                 mov ecx, esi
// 008c80a7  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 008c80af  e87cf8ffff           call 0x8c7930
// 008c80b4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008c80b8  64890d00000000       mov dword ptr fs:[0], ecx
// 008c80bf  59                   pop ecx
// 008c80c0  5e                   pop esi
// 008c80c1  83c410               add esp, 0x10
// 008c80c4  c3                   ret 
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ??1?$LinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
