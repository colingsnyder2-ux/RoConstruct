// from server: 100% by auto
// roc 2008-06 004cf660  unit: RBX::Network::PhysicsSender  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cf660
//
// 004cf660  51                   push ecx
// 004cf661  890c24               mov dword ptr [esp], ecx
// 004cf664  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 004cf667  b8a1a0a0a0           mov eax, 0xa0a0a0a1
// 004cf66c  f7e1                 mul ecx
// 004cf66e  53                   push ebx
// 004cf66f  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 004cf673  55                   push ebp
// 004cf674  8b2db0288000         mov ebp, dword ptr [0x8028b0]
// 004cf67a  56                   push esi
// 004cf67b  57                   push edi
// 004cf67c  8bf2                 mov esi, edx
// 004cf67e  51                   push ecx
// 004cf67f  33ff                 xor edi, edi
// 004cf681  c1ee08               shr esi, 8
// 004cf684  ffd5                 call ebp
// 004cf686  894308               mov dword ptr [ebx + 8], eax
// 004cf689  8d04b500000000       lea eax, [esi*4]
// 004cf690  50                   push eax
// 004cf691  ffd5                 call ebp
// 004cf693  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004cf696  83c408               add esp, 8
// 004cf699  8903                 mov dword ptr [ebx], eax
// 004cf69b  85f6                 test esi, esi
// 004cf69d  7e15                 jle 0x4cf6b4
// 004cf69f  90                   nop 
// 004cf6a0  899994010000         mov dword ptr [ecx + 0x194], ebx
// 004cf6a6  890cb8               mov dword ptr [eax + edi*4], ecx
// 004cf6a9  47                   inc edi
// 004cf6aa  81c198010000         add ecx, 0x198
// 004cf6b0  3bfe                 cmp edi, esi
// 004cf6b2  7cec                 jl 0x4cf6a0
// 004cf6b4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004cf6b8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004cf6bc  5f                   pop edi
// 004cf6bd  897304               mov dword ptr [ebx + 4], esi
// 004cf6c0  8b11                 mov edx, dword ptr [ecx]
// 004cf6c2  5e                   pop esi
// 004cf6c3  5d                   pop ebp
// 004cf6c4  89530c               mov dword ptr [ebx + 0xc], edx
// 004cf6c7  894310               mov dword ptr [ebx + 0x10], eax
// 004cf6ca  5b                   pop ebx
// 004cf6cb  59                   pop ecx
// 004cf6cc  c20800               ret 8
// library openrbx-raknet/ReliabilityLayer.cpp (function ?InitPage@?$MemoryPool@U?$Page@IPAUInternalPacket@@$0CA@@DataStructures@@@DataStructures@@IAEXPAUPage@12@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
