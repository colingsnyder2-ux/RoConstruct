// from server: 100% by auto
// roc 2008-06 004cea10  unit: RBX::Network::PhysicsSender  size: 336 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cea10
//
// 004cea10  53                   push ebx
// 004cea11  56                   push esi
// 004cea12  8bf1                 mov esi, ecx
// 004cea14  6880000000           push 0x80
// 004cea19  33db                 xor ebx, ebx
// 004cea1b  8d86d4020000         lea eax, [esi + 0x2d4]
// 004cea21  53                   push ebx
// 004cea22  50                   push eax
// 004cea23  e8dc2c1d00           call 0x6a1704
// 004cea28  6880000000           push 0x80
// 004cea2d  8d8e54030000         lea ecx, [esi + 0x354]
// 004cea33  53                   push ebx
// 004cea34  51                   push ecx
// 004cea35  e8ca2c1d00           call 0x6a1704
// 004cea3a  6880000000           push 0x80
// 004cea3f  8d96d4010000         lea edx, [esi + 0x1d4]
// 004cea45  53                   push ebx
// 004cea46  52                   push edx
// 004cea47  e8b82c1d00           call 0x6a1704
// 004cea4c  6880000000           push 0x80
// 004cea51  8d8654020000         lea eax, [esi + 0x254]
// 004cea57  53                   push ebx
// 004cea58  50                   push eax
// 004cea59  e8a62c1d00           call 0x6a1704
// 004cea5e  68c8000000           push 0xc8
// 004cea63  8d8ee0030000         lea ecx, [esi + 0x3e0]
// 004cea69  53                   push ebx
// 004cea6a  51                   push ecx
// 004cea6b  e8942c1d00           call 0x6a1704
// 004cea70  83c43c               add esp, 0x3c
// 004cea73  e898aeffff           call 0x4c9910
// 004cea78  33d2                 xor edx, edx
// 004cea7a  8986a0040000         mov dword ptr [esi + 0x4a0], eax
// 004cea80  668996d6030000       mov word ptr [esi + 0x3d6], dx
// 004cea87  899e20050000         mov dword ptr [esi + 0x520], ebx
// 004cea8d  899e24050000         mov dword ptr [esi + 0x524], ebx
// 004cea93  899eb0000000         mov dword ptr [esi + 0xb0], ebx
// 004cea99  e8f2acffff           call 0x4c9790
// 004cea9e  8bca                 mov ecx, edx
// 004ceaa0  8996d4040000         mov dword ptr [esi + 0x4d4], edx
// 004ceaa6  8986d0040000         mov dword ptr [esi + 0x4d0], eax
// 004ceaac  898610050000         mov dword ptr [esi + 0x510], eax
// 004ceab2  8bd0                 mov edx, eax
// 004ceab4  8bc1                 mov eax, ecx
// 004ceab6  899e18050000         mov dword ptr [esi + 0x518], ebx
// 004ceabc  899e1c050000         mov dword ptr [esi + 0x51c], ebx
// 004ceac2  889ed5030000         mov byte ptr [esi + 0x3d5], bl
// 004ceac8  889ed4030000         mov byte ptr [esi + 0x3d4], bl
// 004ceace  899eb8000000         mov dword ptr [esi + 0xb8], ebx
// 004cead4  899ebc000000         mov dword ptr [esi + 0xbc], ebx
// 004ceada  899ef8040000         mov dword ptr [esi + 0x4f8], ebx
// 004ceae0  899efc040000         mov dword ptr [esi + 0x4fc], ebx
// 004ceae6  899ec4040000         mov dword ptr [esi + 0x4c4], ebx
// 004ceaec  899e88070000         mov dword ptr [esi + 0x788], ebx
// 004ceaf2  899e84070000         mov dword ptr [esi + 0x784], ebx
// 004ceaf8  899edc040000         mov dword ptr [esi + 0x4dc], ebx
// 004ceafe  899ee8040000         mov dword ptr [esi + 0x4e8], ebx
// 004ceb04  899eec040000         mov dword ptr [esi + 0x4ec], ebx
// 004ceb0a  899ef0040000         mov dword ptr [esi + 0x4f0], ebx
// 004ceb10  899ef4040000         mov dword ptr [esi + 0x4f4], ebx
// 004ceb16  899ee0040000         mov dword ptr [esi + 0x4e0], ebx
// 004ceb1c  899ee4040000         mov dword ptr [esi + 0x4e4], ebx
// 004ceb22  889e04050000         mov byte ptr [esi + 0x504], bl
// 004ceb28  899ea8040000         mov dword ptr [esi + 0x4a8], ebx
// 004ceb2e  899eac040000         mov dword ptr [esi + 0x4ac], ebx
// 004ceb34  899eb0040000         mov dword ptr [esi + 0x4b0], ebx
// 004ceb3a  898e14050000         mov dword ptr [esi + 0x514], ecx
// 004ceb40  899608050000         mov dword ptr [esi + 0x508], edx
// 004ceb46  89860c050000         mov dword ptr [esi + 0x50c], eax
// 004ceb4c  c686c804000001       mov byte ptr [esi + 0x4c8], 1
// 004ceb53  c786d8040000a0860100 mov dword ptr [esi + 0x4d8], 0x186a0
// 004ceb5d  5e                   pop esi
// 004ceb5e  5b                   pop ebx
// 004ceb5f  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ?InitializeVariables@ReliabilityLayer@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
