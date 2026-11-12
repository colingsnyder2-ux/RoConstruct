// from server: 100% by auto
// roc 2007-08 004c5370  unit: RakPeer  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004c5370
//
// 004c5370  51                   push ecx
// 004c5371  890c24               mov dword ptr [esp], ecx
// 004c5374  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 004c5377  b8398ee338           mov eax, 0x38e38e39
// 004c537c  f7e1                 mul ecx
// 004c537e  53                   push ebx
// 004c537f  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 004c5383  55                   push ebp
// 004c5384  8b2dd0e67700         mov ebp, dword ptr [0x77e6d0]
// 004c538a  56                   push esi
// 004c538b  57                   push edi
// 004c538c  8bf2                 mov esi, edx
// 004c538e  51                   push ecx
// 004c538f  33ff                 xor edi, edi
// 004c5391  c1ee04               shr esi, 4
// 004c5394  ffd5                 call ebp
// 004c5396  894308               mov dword ptr [ebx + 8], eax
// 004c5399  8d04b500000000       lea eax, [esi*4]
// 004c53a0  50                   push eax
// 004c53a1  ffd5                 call ebp
// 004c53a3  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004c53a6  83c408               add esp, 8
// 004c53a9  85f6                 test esi, esi
// 004c53ab  8903                 mov dword ptr [ebx], eax
// 004c53ad  7e11                 jle 0x4c53c0
// 004c53af  90                   nop 
// 004c53b0  895940               mov dword ptr [ecx + 0x40], ebx
// 004c53b3  890cb8               mov dword ptr [eax + edi*4], ecx
// 004c53b6  83c701               add edi, 1
// 004c53b9  83c148               add ecx, 0x48
// 004c53bc  3bfe                 cmp edi, esi
// 004c53be  7cf0                 jl 0x4c53b0
// 004c53c0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c53c4  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004c53c8  5f                   pop edi
// 004c53c9  897304               mov dword ptr [ebx + 4], esi
// 004c53cc  8b11                 mov edx, dword ptr [ecx]
// 004c53ce  5e                   pop esi
// 004c53cf  5d                   pop ebp
// 004c53d0  89530c               mov dword ptr [ebx + 0xc], edx
// 004c53d3  894310               mov dword ptr [ebx + 0x10], eax
// 004c53d6  5b                   pop ebx
// 004c53d7  59                   pop ecx
// 004c53d8  c20800               ret 8
// library openrbx-raknet/ReliabilityLayer.cpp (function ?InitPage@?$MemoryPool@UInternalPacket@@@DataStructures@@IAEXPAUPage@12@0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
