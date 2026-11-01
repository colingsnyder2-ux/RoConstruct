// from server: 100% by auto
// roc 2011-06 00403b80  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403b80
//
// 00403b80  0fbe4c2404           movsx ecx, byte ptr [esp + 4]
// 00403b85  8d41d0               lea eax, [ecx - 0x30]
// 00403b88  83f836               cmp eax, 0x36
// 00403b8b  7716                 ja 0x403ba3
// 00403b8d  0fb690b83b4000       movzx edx, byte ptr [eax + 0x403bb8]
// 00403b94  ff2495a83b4000       jmp dword ptr [edx*4 + 0x403ba8]
// 00403b9b  8d41c9               lea eax, [ecx - 0x37]
// 00403b9e  c3                   ret 
// 00403b9f  8d41a9               lea eax, [ecx - 0x57]
// 00403ba2  c3                   ret 
// 00403ba3  32c0                 xor al, al
// 00403ba5  c3                   ret 
// 00403ba6  8bff                 mov edi, edi
// 00403ba8  a5                   movsd dword ptr es:[edi], dword ptr [esi]
// 00403ba9  3b4000               cmp eax, dword ptr [eax]
// 00403bac  9b                   wait 
// 00403bad  3b4000               cmp eax, dword ptr [eax]
// 00403bb0  9f                   lahf 
// 00403bb1  3b4000               cmp eax, dword ptr [eax]
// 00403bb4  a33b400000           mov dword ptr [0x403b], eax
// 00403bb9  0000                 add byte ptr [eax], al
// 00403bbb  0000                 add byte ptr [eax], al
// 00403bbd  0000                 add byte ptr [eax], al
// 00403bbf  0000                 add byte ptr [eax], al
// 00403bc1  0003                 add byte ptr [ebx], al
// 00403bc3  0303                 add eax, dword ptr [ebx]
// 00403bc5  0303                 add eax, dword ptr [ebx]
// 00403bc7  0303                 add eax, dword ptr [ebx]
// 00403bc9  0101                 add dword ptr [ecx], eax
// 00403bcb  0101                 add dword ptr [ecx], eax
// 00403bcd  0101                 add dword ptr [ecx], eax
// 00403bcf  0303                 add eax, dword ptr [ebx]
// 00403bd1  0303                 add eax, dword ptr [ebx]
// 00403bd3  0303                 add eax, dword ptr [ebx]
// 00403bd5  0303                 add eax, dword ptr [ebx]
// 00403bd7  0303                 add eax, dword ptr [ebx]
// 00403bd9  0303                 add eax, dword ptr [ebx]
// 00403bdb  0303                 add eax, dword ptr [ebx]
// 00403bdd  0303                 add eax, dword ptr [ebx]
// 00403bdf  0303                 add eax, dword ptr [ebx]
// 00403be1  0303                 add eax, dword ptr [ebx]
// 00403be3  0303                 add eax, dword ptr [ebx]
// 00403be5  0303                 add eax, dword ptr [ebx]
// 00403be7  0303                 add eax, dword ptr [ebx]
// 00403be9  0202                 add al, byte ptr [edx]
// 00403beb  0202                 add al, byte ptr [edx]
// 00403bed  0202                 add al, byte ptr [edx]
// library atl-8.0/atl.cpp (function ?ChToByte@CRegParser@ATL@@KAED@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
