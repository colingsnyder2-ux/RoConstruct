// from server: 100% by auto
// roc 2009-06 00403470  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00403470
//
// 00403470  0fbe4c2404           movsx ecx, byte ptr [esp + 4]
// 00403475  8d41d0               lea eax, [ecx - 0x30]
// 00403478  83f836               cmp eax, 0x36
// 0040347b  7716                 ja 0x403493
// 0040347d  0fb690a8344000       movzx edx, byte ptr [eax + 0x4034a8]
// 00403484  ff249598344000       jmp dword ptr [edx*4 + 0x403498]
// 0040348b  8d41c9               lea eax, [ecx - 0x37]
// 0040348e  c3                   ret 
// 0040348f  8d41a9               lea eax, [ecx - 0x57]
// 00403492  c3                   ret 
// 00403493  32c0                 xor al, al
// 00403495  c3                   ret 
// 00403496  8bff                 mov edi, edi
// 00403498  95                   xchg ebp, eax
// 00403499  3440                 xor al, 0x40
// 0040349b  008b3440008f         add byte ptr [ebx - 0x70ffbfcc], cl
// 004034a1  3440                 xor al, 0x40
// 004034a3  009334400000         add byte ptr [ebx + 0x4034], dl
// 004034a9  0000                 add byte ptr [eax], al
// 004034ab  0000                 add byte ptr [eax], al
// 004034ad  0000                 add byte ptr [eax], al
// 004034af  0000                 add byte ptr [eax], al
// 004034b1  0003                 add byte ptr [ebx], al
// 004034b3  0303                 add eax, dword ptr [ebx]
// 004034b5  0303                 add eax, dword ptr [ebx]
// 004034b7  0303                 add eax, dword ptr [ebx]
// 004034b9  0101                 add dword ptr [ecx], eax
// 004034bb  0101                 add dword ptr [ecx], eax
// 004034bd  0101                 add dword ptr [ecx], eax
// 004034bf  0303                 add eax, dword ptr [ebx]
// 004034c1  0303                 add eax, dword ptr [ebx]
// 004034c3  0303                 add eax, dword ptr [ebx]
// 004034c5  0303                 add eax, dword ptr [ebx]
// 004034c7  0303                 add eax, dword ptr [ebx]
// 004034c9  0303                 add eax, dword ptr [ebx]
// 004034cb  0303                 add eax, dword ptr [ebx]
// 004034cd  0303                 add eax, dword ptr [ebx]
// 004034cf  0303                 add eax, dword ptr [ebx]
// 004034d1  0303                 add eax, dword ptr [ebx]
// 004034d3  0303                 add eax, dword ptr [ebx]
// 004034d5  0303                 add eax, dword ptr [ebx]
// 004034d7  0303                 add eax, dword ptr [ebx]
// 004034d9  0202                 add al, byte ptr [edx]
// 004034db  0202                 add al, byte ptr [edx]
// 004034dd  0202                 add al, byte ptr [edx]
// library atl-8.0/atl.cpp (function ?ChToByte@CRegParser@ATL@@KAED@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
