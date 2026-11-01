// from server: 100% by auto
// roc 2007-08 006fc8f0  unit: CXTPPropertyGridInplaceList  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006fc8f0
//
// 006fc8f0  83ec10               sub esp, 0x10
// 006fc8f3  53                   push ebx
// 006fc8f4  56                   push esi
// 006fc8f5  57                   push edi
// 006fc8f6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006fc8fa  8b4718               mov eax, dword ptr [edi + 0x18]
// 006fc8fd  50                   push eax
// 006fc8fe  8bf1                 mov esi, ecx
// 006fc900  e8b9ba0300           call 0x7383be
// 006fc905  8d4f1c               lea ecx, [edi + 0x1c]
// 006fc908  51                   push ecx
// 006fc909  8d542410             lea edx, [esp + 0x10]
// 006fc90d  52                   push edx
// 006fc90e  8bd8                 mov ebx, eax
// 006fc910  ff15e0ed7700         call dword ptr [0x77ede0]
// 006fc916  8b4708               mov eax, dword ptr [edi + 8]
// 006fc919  6a00                 push 0
// 006fc91b  50                   push eax
// 006fc91c  8b4620               mov eax, dword ptr [esi + 0x20]
// 006fc91f  6899010000           push 0x199
// 006fc924  50                   push eax
// 006fc925  ff15d8ec7700         call dword ptr [0x77ecd8]
// 006fc92b  837e5400             cmp dword ptr [esi + 0x54], 0
// 006fc92f  7433                 je 0x6fc964
// 006fc931  8b5710               mov edx, dword ptr [edi + 0x10]
// 006fc934  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006fc938  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 006fc93b  8b31                 mov esi, dword ptr [ecx]
// 006fc93d  83e201               and edx, 1
// 006fc940  52                   push edx
// 006fc941  83ec10               sub esp, 0x10
// 006fc944  8bd4                 mov edx, esp
// 006fc946  893a                 mov dword ptr [edx], edi
// 006fc948  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 006fc94c  897a04               mov dword ptr [edx + 4], edi
// 006fc94f  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006fc953  897a08               mov dword ptr [edx + 8], edi
// 006fc956  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006fc95a  50                   push eax
// 006fc95b  8b466c               mov eax, dword ptr [esi + 0x6c]
// 006fc95e  53                   push ebx
// 006fc95f  897a0c               mov dword ptr [edx + 0xc], edi
// 006fc962  ffd0                 call eax
// 006fc964  5f                   pop edi
// 006fc965  5e                   pop esi
// 006fc966  5b                   pop ebx
// 006fc967  83c410               add esp, 0x10
// 006fc96a  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?DrawItem@CXTPPropertyGridInplaceList@@MAEXPAUtagDRAWITEMSTRUCT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
