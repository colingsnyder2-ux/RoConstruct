// from server: 100% by auto
// roc 2009-06 00735f90  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00735f90
//
// 00735f90  83ec08               sub esp, 8
// 00735f93  56                   push esi
// 00735f94  8bf1                 mov esi, ecx
// 00735f96  8b4608               mov eax, dword ptr [esi + 8]
// 00735f99  85c0                 test eax, eax
// 00735f9b  756d                 jne 0x73600a
// 00735f9d  8b4604               mov eax, dword ptr [esi + 4]
// 00735fa0  85c0                 test eax, eax
// 00735fa2  7505                 jne 0x735fa9
// 00735fa4  5e                   pop esi
// 00735fa5  83c408               add esp, 8
// 00735fa8  c3                   ret 
// 00735fa9  53                   push ebx
// 00735faa  57                   push edi
// 00735fab  8d4c240c             lea ecx, [esp + 0xc]
// 00735faf  51                   push ecx
// 00735fb0  6a00                 push 0
// 00735fb2  50                   push eax
// 00735fb3  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00735fbb  e8b0f3ffff           call 0x735370
// 00735fc0  8bf8                 mov edi, eax
// 00735fc2  83c40c               add esp, 0xc
// 00735fc5  85ff                 test edi, edi
// 00735fc7  743d                 je 0x736006
// 00735fc9  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00735fcd  85db                 test ebx, ebx
// 00735fcf  7435                 je 0x736006
// 00735fd1  8bce                 mov ecx, esi
// 00735fd3  e838f1ffff           call 0x735110
// 00735fd8  8d54240c             lea edx, [esp + 0xc]
// 00735fdc  52                   push edx
// 00735fdd  8bce                 mov ecx, esi
// 00735fdf  897e04               mov dword ptr [esi + 4], edi
// 00735fe2  895e08               mov dword ptr [esi + 8], ebx
// 00735fe5  c7460c01000000       mov dword ptr [esi + 0xc], 1
// 00735fec  e86ff1ffff           call 0x735160
// 00735ff1  8b08                 mov ecx, dword ptr [eax]
// 00735ff3  894e18               mov dword ptr [esi + 0x18], ecx
// 00735ff6  8b5004               mov edx, dword ptr [eax + 4]
// 00735ff9  8b4608               mov eax, dword ptr [esi + 8]
// 00735ffc  5f                   pop edi
// 00735ffd  5b                   pop ebx
// 00735ffe  89561c               mov dword ptr [esi + 0x1c], edx
// 00736001  5e                   pop esi
// 00736002  83c408               add esp, 8
// 00736005  c3                   ret 
// 00736006  5f                   pop edi
// 00736007  33c0                 xor eax, eax
// 00736009  5b                   pop ebx
// 0073600a  5e                   pop esi
// 0073600b  83c408               add esp, 8
// 0073600e  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?PreMultiply@CXTPImageManagerIconHandle@@QAEPAEXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
