// from server: 100% by auto
// roc 2009-06 007f2be0  unit: CXTPPropertyGridInplaceList  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f2be0
//
// 007f2be0  83ec10               sub esp, 0x10
// 007f2be3  53                   push ebx
// 007f2be4  56                   push esi
// 007f2be5  57                   push edi
// 007f2be6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007f2bea  8b4718               mov eax, dword ptr [edi + 0x18]
// 007f2bed  50                   push eax
// 007f2bee  8bf1                 mov esi, ecx
// 007f2bf0  e817930500           call 0x84bf0c
// 007f2bf5  8d4f1c               lea ecx, [edi + 0x1c]
// 007f2bf8  51                   push ecx
// 007f2bf9  8d542410             lea edx, [esp + 0x10]
// 007f2bfd  52                   push edx
// 007f2bfe  8bd8                 mov ebx, eax
// 007f2c00  ff1500ee8900         call dword ptr [0x89ee00]
// 007f2c06  8b4708               mov eax, dword ptr [edi + 8]
// 007f2c09  6a00                 push 0
// 007f2c0b  50                   push eax
// 007f2c0c  8b4620               mov eax, dword ptr [esi + 0x20]
// 007f2c0f  6899010000           push 0x199
// 007f2c14  50                   push eax
// 007f2c15  ff1590ee8900         call dword ptr [0x89ee90]
// 007f2c1b  837e5400             cmp dword ptr [esi + 0x54], 0
// 007f2c1f  7433                 je 0x7f2c54
// 007f2c21  8b5710               mov edx, dword ptr [edi + 0x10]
// 007f2c24  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007f2c28  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 007f2c2b  8b31                 mov esi, dword ptr [ecx]
// 007f2c2d  83e201               and edx, 1
// 007f2c30  52                   push edx
// 007f2c31  83ec10               sub esp, 0x10
// 007f2c34  8bd4                 mov edx, esp
// 007f2c36  893a                 mov dword ptr [edx], edi
// 007f2c38  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 007f2c3c  897a04               mov dword ptr [edx + 4], edi
// 007f2c3f  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007f2c43  897a08               mov dword ptr [edx + 8], edi
// 007f2c46  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 007f2c4a  50                   push eax
// 007f2c4b  8b466c               mov eax, dword ptr [esi + 0x6c]
// 007f2c4e  53                   push ebx
// 007f2c4f  897a0c               mov dword ptr [edx + 0xc], edi
// 007f2c52  ffd0                 call eax
// 007f2c54  5f                   pop edi
// 007f2c55  5e                   pop esi
// 007f2c56  5b                   pop ebx
// 007f2c57  83c410               add esp, 0x10
// 007f2c5a  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?DrawItem@CXTPPropertyGridInplaceList@@MAEXPAUtagDRAWITEMSTRUCT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
