// from server: 100% by auto
// roc 2008-06 004cf420  unit: RBX::Network::PhysicsSender  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cf420
//
// 004cf420  51                   push ecx
// 004cf421  890c24               mov dword ptr [esp], ecx
// 004cf424  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 004cf427  b8398ee338           mov eax, 0x38e38e39
// 004cf42c  f7e1                 mul ecx
// 004cf42e  53                   push ebx
// 004cf42f  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 004cf433  55                   push ebp
// 004cf434  8b2db0288000         mov ebp, dword ptr [0x8028b0]
// 004cf43a  56                   push esi
// 004cf43b  57                   push edi
// 004cf43c  8bf2                 mov esi, edx
// 004cf43e  51                   push ecx
// 004cf43f  33ff                 xor edi, edi
// 004cf441  c1ee04               shr esi, 4
// 004cf444  ffd5                 call ebp
// 004cf446  894308               mov dword ptr [ebx + 8], eax
// 004cf449  8d04b500000000       lea eax, [esi*4]
// 004cf450  50                   push eax
// 004cf451  ffd5                 call ebp
// 004cf453  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004cf456  83c408               add esp, 8
// 004cf459  8903                 mov dword ptr [ebx], eax
// 004cf45b  85f6                 test esi, esi
// 004cf45d  7e0f                 jle 0x4cf46e
// 004cf45f  90                   nop 
// 004cf460  895940               mov dword ptr [ecx + 0x40], ebx
// 004cf463  890cb8               mov dword ptr [eax + edi*4], ecx
// 004cf466  47                   inc edi
// 004cf467  83c148               add ecx, 0x48
// 004cf46a  3bfe                 cmp edi, esi
// 004cf46c  7cf2                 jl 0x4cf460
// 004cf46e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004cf472  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004cf476  5f                   pop edi
// 004cf477  897304               mov dword ptr [ebx + 4], esi
// 004cf47a  8b11                 mov edx, dword ptr [ecx]
// 004cf47c  5e                   pop esi
// 004cf47d  5d                   pop ebp
// 004cf47e  89530c               mov dword ptr [ebx + 0xc], edx
// 004cf481  894310               mov dword ptr [ebx + 0x10], eax
// 004cf484  5b                   pop ebx
// 004cf485  59                   pop ecx
// 004cf486  c20800               ret 8
// library openrbx-raknet/ReliabilityLayer.cpp (function ?InitPage@?$MemoryPool@UInternalPacket@@@DataStructures@@IAEXPAUPage@12@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
