// from server: 100% by auto
// roc 2010-06 00403190  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00403190
//
// 00403190  0fbe4c2404           movsx ecx, byte ptr [esp + 4]
// 00403195  8d41d0               lea eax, [ecx - 0x30]
// 00403198  83f836               cmp eax, 0x36
// 0040319b  7716                 ja 0x4031b3
// 0040319d  0fb690c8314000       movzx edx, byte ptr [eax + 0x4031c8]
// 004031a4  ff2495b8314000       jmp dword ptr [edx*4 + 0x4031b8]
// 004031ab  8d41c9               lea eax, [ecx - 0x37]
// 004031ae  c3                   ret 
// 004031af  8d41a9               lea eax, [ecx - 0x57]
// 004031b2  c3                   ret 
// 004031b3  32c0                 xor al, al
// 004031b5  c3                   ret 
// 004031b6  8bff                 mov edi, edi
// 004031b8  b531                 mov ch, 0x31
// 004031ba  40                   inc eax
// 004031bb  00ab314000af         add byte ptr [ebx - 0x50ffbfcf], ch
// 004031c1  314000               xor dword ptr [eax], eax
// 004031c4  b331                 mov bl, 0x31
// 004031c6  40                   inc eax
// 004031c7  0000                 add byte ptr [eax], al
// 004031c9  0000                 add byte ptr [eax], al
// 004031cb  0000                 add byte ptr [eax], al
// 004031cd  0000                 add byte ptr [eax], al
// 004031cf  0000                 add byte ptr [eax], al
// 004031d1  0003                 add byte ptr [ebx], al
// 004031d3  0303                 add eax, dword ptr [ebx]
// 004031d5  0303                 add eax, dword ptr [ebx]
// 004031d7  0303                 add eax, dword ptr [ebx]
// 004031d9  0101                 add dword ptr [ecx], eax
// 004031db  0101                 add dword ptr [ecx], eax
// 004031dd  0101                 add dword ptr [ecx], eax
// 004031df  0303                 add eax, dword ptr [ebx]
// 004031e1  0303                 add eax, dword ptr [ebx]
// 004031e3  0303                 add eax, dword ptr [ebx]
// 004031e5  0303                 add eax, dword ptr [ebx]
// 004031e7  0303                 add eax, dword ptr [ebx]
// 004031e9  0303                 add eax, dword ptr [ebx]
// 004031eb  0303                 add eax, dword ptr [ebx]
// 004031ed  0303                 add eax, dword ptr [ebx]
// 004031ef  0303                 add eax, dword ptr [ebx]
// 004031f1  0303                 add eax, dword ptr [ebx]
// 004031f3  0303                 add eax, dword ptr [ebx]
// 004031f5  0303                 add eax, dword ptr [ebx]
// 004031f7  0303                 add eax, dword ptr [ebx]
// 004031f9  0202                 add al, byte ptr [edx]
// 004031fb  0202                 add al, byte ptr [edx]
// 004031fd  0202                 add al, byte ptr [edx]
// library atl-8.0/atl.cpp (function ?ChToByte@CRegParser@ATL@@KAED@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
