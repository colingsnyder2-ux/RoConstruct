// from server: 100% by auto
// roc 2007-08 004c5610  unit: RakPeer  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004c5610
//
// 004c5610  51                   push ecx
// 004c5611  890c24               mov dword ptr [esp], ecx
// 004c5614  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 004c5617  b8a1a0a0a0           mov eax, 0xa0a0a0a1
// 004c561c  f7e1                 mul ecx
// 004c561e  53                   push ebx
// 004c561f  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 004c5623  55                   push ebp
// 004c5624  8b2dd0e67700         mov ebp, dword ptr [0x77e6d0]
// 004c562a  56                   push esi
// 004c562b  57                   push edi
// 004c562c  8bf2                 mov esi, edx
// 004c562e  51                   push ecx
// 004c562f  33ff                 xor edi, edi
// 004c5631  c1ee08               shr esi, 8
// 004c5634  ffd5                 call ebp
// 004c5636  894308               mov dword ptr [ebx + 8], eax
// 004c5639  8d04b500000000       lea eax, [esi*4]
// 004c5640  50                   push eax
// 004c5641  ffd5                 call ebp
// 004c5643  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004c5646  83c408               add esp, 8
// 004c5649  85f6                 test esi, esi
// 004c564b  8903                 mov dword ptr [ebx], eax
// 004c564d  7e17                 jle 0x4c5666
// 004c564f  90                   nop 
// 004c5650  899994010000         mov dword ptr [ecx + 0x194], ebx
// 004c5656  890cb8               mov dword ptr [eax + edi*4], ecx
// 004c5659  83c701               add edi, 1
// 004c565c  81c198010000         add ecx, 0x198
// 004c5662  3bfe                 cmp edi, esi
// 004c5664  7cea                 jl 0x4c5650
// 004c5666  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c566a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004c566e  5f                   pop edi
// 004c566f  897304               mov dword ptr [ebx + 4], esi
// 004c5672  8b11                 mov edx, dword ptr [ecx]
// 004c5674  5e                   pop esi
// 004c5675  5d                   pop ebp
// 004c5676  89530c               mov dword ptr [ebx + 0xc], edx
// 004c5679  894310               mov dword ptr [ebx + 0x10], eax
// 004c567c  5b                   pop ebx
// 004c567d  59                   pop ecx
// 004c567e  c20800               ret 8
// library openrbx-raknet/ReliabilityLayer.cpp (function ?InitPage@?$MemoryPool@U?$Page@IPAUInternalPacket@@$0CA@@DataStructures@@@DataStructures@@IAEXPAUPage@12@0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
