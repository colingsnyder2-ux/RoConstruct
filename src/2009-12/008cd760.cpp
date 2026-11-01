// from server: 100% by auto
// roc 2009-12 008cd760  unit: CXTPPropertyGridInplaceList  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008cd760
//
// 008cd760  83ec10               sub esp, 0x10
// 008cd763  53                   push ebx
// 008cd764  56                   push esi
// 008cd765  57                   push edi
// 008cd766  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008cd76a  8b4718               mov eax, dword ptr [edi + 0x18]
// 008cd76d  50                   push eax
// 008cd76e  8bf1                 mov esi, ecx
// 008cd770  e8bb8c0500           call 0x926430
// 008cd775  8d4f1c               lea ecx, [edi + 0x1c]
// 008cd778  51                   push ecx
// 008cd779  8d542410             lea edx, [esp + 0x10]
// 008cd77d  52                   push edx
// 008cd77e  8bd8                 mov ebx, eax
// 008cd780  ff1564cc9800         call dword ptr [0x98cc64]
// 008cd786  8b4708               mov eax, dword ptr [edi + 8]
// 008cd789  6a00                 push 0
// 008cd78b  50                   push eax
// 008cd78c  8b4620               mov eax, dword ptr [esi + 0x20]
// 008cd78f  6899010000           push 0x199
// 008cd794  50                   push eax
// 008cd795  ff15c4cb9800         call dword ptr [0x98cbc4]
// 008cd79b  837e5400             cmp dword ptr [esi + 0x54], 0
// 008cd79f  7433                 je 0x8cd7d4
// 008cd7a1  8b5710               mov edx, dword ptr [edi + 0x10]
// 008cd7a4  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008cd7a8  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 008cd7ab  8b31                 mov esi, dword ptr [ecx]
// 008cd7ad  83e201               and edx, 1
// 008cd7b0  52                   push edx
// 008cd7b1  83ec10               sub esp, 0x10
// 008cd7b4  8bd4                 mov edx, esp
// 008cd7b6  893a                 mov dword ptr [edx], edi
// 008cd7b8  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 008cd7bc  897a04               mov dword ptr [edx + 4], edi
// 008cd7bf  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 008cd7c3  897a08               mov dword ptr [edx + 8], edi
// 008cd7c6  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 008cd7ca  50                   push eax
// 008cd7cb  8b466c               mov eax, dword ptr [esi + 0x6c]
// 008cd7ce  53                   push ebx
// 008cd7cf  897a0c               mov dword ptr [edx + 0xc], edi
// 008cd7d2  ffd0                 call eax
// 008cd7d4  5f                   pop edi
// 008cd7d5  5e                   pop esi
// 008cd7d6  5b                   pop ebx
// 008cd7d7  83c410               add esp, 0x10
// 008cd7da  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?DrawItem@CXTPPropertyGridInplaceList@@MAEXPAUtagDRAWITEMSTRUCT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
