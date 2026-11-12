// roc 2009-12 00870810  unit: PAVCXTPHookManagerHookAble::?$CArray  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00870810
//
// 00870810  6aff                 push -1
// 00870812  6898fc9500           push 0x95fc98
// 00870817  64a100000000         mov eax, dword ptr fs:[0]
// 0087081d  50                   push eax
// 0087081e  51                   push ecx
// 0087081f  56                   push esi
// 00870820  a10052b600           mov eax, dword ptr [0xb65200]
// 00870825  33c4                 xor eax, esp
// 00870827  50                   push eax
// 00870828  8d44240c             lea eax, [esp + 0xc]
// 0087082c  64a300000000         mov dword ptr fs:[0], eax
// 00870832  8bf1                 mov esi, ecx
// 00870834  89742408             mov dword ptr [esp + 8], esi
// 00870838  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00870840  e83bfdffff           call 0x870580
// 00870845  8bce                 mov ecx, esi
// 00870847  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0087084f  e80cfeffff           call 0x870660
// 00870854  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00870858  64890d00000000       mov dword ptr fs:[0], ecx
// 0087085f  59                   pop ecx
// 00870860  5e                   pop esi
// 00870861  83c410               add esp, 0x10
// 00870864  c3                   ret 
// library openrbx-raknet/DS_HuffmanEncodingTree.cpp (function ??1?$LinkedList@PAUHuffmanEncodingTreeNode@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DS_HuffmanEncodingTree.cpp
