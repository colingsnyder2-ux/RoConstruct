// from server: 100% by auto
// roc 2009-12 00403140  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00403140
//
// 00403140  0fbe4c2404           movsx ecx, byte ptr [esp + 4]
// 00403145  8d41d0               lea eax, [ecx - 0x30]
// 00403148  83f836               cmp eax, 0x36
// 0040314b  7716                 ja 0x403163
// 0040314d  0fb69078314000       movzx edx, byte ptr [eax + 0x403178]
// 00403154  ff249568314000       jmp dword ptr [edx*4 + 0x403168]
// 0040315b  8d41c9               lea eax, [ecx - 0x37]
// 0040315e  c3                   ret 
// 0040315f  8d41a9               lea eax, [ecx - 0x57]
// 00403162  c3                   ret 
// 00403163  32c0                 xor al, al
// 00403165  c3                   ret 
// 00403166  8bff                 mov edi, edi
// 00403168  65314000             xor dword ptr gs:[eax], eax
// 0040316c  5b                   pop ebx
// 0040316d  314000               xor dword ptr [eax], eax
// 00403170  5f                   pop edi
// 00403171  314000               xor dword ptr [eax], eax
// 00403174  6331                 arpl word ptr [ecx], si
// 00403176  40                   inc eax
// 00403177  0000                 add byte ptr [eax], al
// 00403179  0000                 add byte ptr [eax], al
// 0040317b  0000                 add byte ptr [eax], al
// 0040317d  0000                 add byte ptr [eax], al
// 0040317f  0000                 add byte ptr [eax], al
// 00403181  0003                 add byte ptr [ebx], al
// 00403183  0303                 add eax, dword ptr [ebx]
// 00403185  0303                 add eax, dword ptr [ebx]
// 00403187  0303                 add eax, dword ptr [ebx]
// 00403189  0101                 add dword ptr [ecx], eax
// 0040318b  0101                 add dword ptr [ecx], eax
// 0040318d  0101                 add dword ptr [ecx], eax
// 0040318f  0303                 add eax, dword ptr [ebx]
// 00403191  0303                 add eax, dword ptr [ebx]
// 00403193  0303                 add eax, dword ptr [ebx]
// 00403195  0303                 add eax, dword ptr [ebx]
// 00403197  0303                 add eax, dword ptr [ebx]
// 00403199  0303                 add eax, dword ptr [ebx]
// 0040319b  0303                 add eax, dword ptr [ebx]
// 0040319d  0303                 add eax, dword ptr [ebx]
// 0040319f  0303                 add eax, dword ptr [ebx]
// 004031a1  0303                 add eax, dword ptr [ebx]
// 004031a3  0303                 add eax, dword ptr [ebx]
// 004031a5  0303                 add eax, dword ptr [ebx]
// 004031a7  0303                 add eax, dword ptr [ebx]
// 004031a9  0202                 add al, byte ptr [edx]
// 004031ab  0202                 add al, byte ptr [edx]
// 004031ad  0202                 add al, byte ptr [edx]
// library atl-8.0/atl.cpp (function ?ChToByte@CRegParser@ATL@@KAED@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
