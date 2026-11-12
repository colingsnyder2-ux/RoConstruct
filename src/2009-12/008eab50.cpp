// roc 2009-12 008eab50  unit: PAVCXTPRibbonTabContextHeader::?$CArray  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008eab50
//
// 008eab50  6aff                 push -1
// 008eab52  68e8659600           push 0x9665e8
// 008eab57  64a100000000         mov eax, dword ptr fs:[0]
// 008eab5d  50                   push eax
// 008eab5e  51                   push ecx
// 008eab5f  56                   push esi
// 008eab60  a10052b600           mov eax, dword ptr [0xb65200]
// 008eab65  33c4                 xor eax, esp
// 008eab67  50                   push eax
// 008eab68  8d44240c             lea eax, [esp + 0xc]
// 008eab6c  64a300000000         mov dword ptr fs:[0], eax
// 008eab72  8bf1                 mov esi, ecx
// 008eab74  89742408             mov dword ptr [esp + 8], esi
// 008eab78  c744241400000000     mov dword ptr [esp + 0x14], 0
// 008eab80  e8dbfeffff           call 0x8eaa60
// 008eab85  8bce                 mov ecx, esi
// 008eab87  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 008eab8f  e8ccfdffff           call 0x8ea960
// 008eab94  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008eab98  64890d00000000       mov dword ptr fs:[0], ecx
// 008eab9f  59                   pop ecx
// 008eaba0  5e                   pop esi
// 008eaba1  83c410               add esp, 0x10
// 008eaba4  c3                   ret 
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ??1?$LinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
