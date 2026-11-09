// from server: 100% by auto
// roc 2008-06 00401f50  unit: VCWorkspace::?$CComObject  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401f50
//
// 00401f50  0fbe4c2404           movsx ecx, byte ptr [esp + 4]
// 00401f55  8d41d0               lea eax, [ecx - 0x30]
// 00401f58  83f836               cmp eax, 0x36
// 00401f5b  7716                 ja 0x401f73
// 00401f5d  0fb690881f4000       movzx edx, byte ptr [eax + 0x401f88]
// 00401f64  ff2495781f4000       jmp dword ptr [edx*4 + 0x401f78]
// 00401f6b  8d41c9               lea eax, [ecx - 0x37]
// 00401f6e  c3                   ret 
// 00401f6f  8d41a9               lea eax, [ecx - 0x57]
// 00401f72  c3                   ret 
// 00401f73  32c0                 xor al, al
// 00401f75  c3                   ret 
// 00401f76  8bff                 mov edi, edi
// 00401f78  751f                 jne 0x401f99
// 00401f7a  40                   inc eax
// 00401f7b  006b1f               add byte ptr [ebx + 0x1f], ch
// 00401f7e  40                   inc eax
// 00401f7f  006f1f               add byte ptr [edi + 0x1f], ch
// 00401f82  40                   inc eax
// 00401f83  00731f               add byte ptr [ebx + 0x1f], dh
// 00401f86  40                   inc eax
// 00401f87  0000                 add byte ptr [eax], al
// 00401f89  0000                 add byte ptr [eax], al
// 00401f8b  0000                 add byte ptr [eax], al
// 00401f8d  0000                 add byte ptr [eax], al
// 00401f8f  0000                 add byte ptr [eax], al
// 00401f91  0003                 add byte ptr [ebx], al
// 00401f93  0303                 add eax, dword ptr [ebx]
// 00401f95  0303                 add eax, dword ptr [ebx]
// 00401f97  0303                 add eax, dword ptr [ebx]
// 00401f99  0101                 add dword ptr [ecx], eax
// 00401f9b  0101                 add dword ptr [ecx], eax
// 00401f9d  0101                 add dword ptr [ecx], eax
// 00401f9f  0303                 add eax, dword ptr [ebx]
// 00401fa1  0303                 add eax, dword ptr [ebx]
// 00401fa3  0303                 add eax, dword ptr [ebx]
// 00401fa5  0303                 add eax, dword ptr [ebx]
// 00401fa7  0303                 add eax, dword ptr [ebx]
// 00401fa9  0303                 add eax, dword ptr [ebx]
// 00401fab  0303                 add eax, dword ptr [ebx]
// 00401fad  0303                 add eax, dword ptr [ebx]
// 00401faf  0303                 add eax, dword ptr [ebx]
// 00401fb1  0303                 add eax, dword ptr [ebx]
// 00401fb3  0303                 add eax, dword ptr [ebx]
// 00401fb5  0303                 add eax, dword ptr [ebx]
// 00401fb7  0303                 add eax, dword ptr [ebx]
// 00401fb9  0202                 add al, byte ptr [edx]
// 00401fbb  0202                 add al, byte ptr [edx]
// 00401fbd  0202                 add al, byte ptr [edx]
// library atl-8.0/atl.cpp (function ?ChToByte@CRegParser@ATL@@KAED@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
