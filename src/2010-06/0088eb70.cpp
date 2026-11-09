// from server: 100% by auto
// roc 2010-06 0088eb70  unit: CXTColorHex::PAUHEXCOLOR_CELL::?$CList  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0088eb70
//
// 0088eb70  56                   push esi
// 0088eb71  8bf1                 mov esi, ecx
// 0088eb73  837e1000             cmp dword ptr [esi + 0x10], 0
// 0088eb77  7537                 jne 0x88ebb0
// 0088eb79  8b4618               mov eax, dword ptr [esi + 0x18]
// 0088eb7c  6a0c                 push 0xc
// 0088eb7e  50                   push eax
// 0088eb7f  8d4e14               lea ecx, [esi + 0x14]
// 0088eb82  51                   push ecx
// 0088eb83  e8a099f1ff           call 0x7a8528
// 0088eb88  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0088eb8b  83c004               add eax, 4
// 0088eb8e  8d1449               lea edx, [ecx + ecx*2]
// 0088eb91  83c1ff               add ecx, -1
// 0088eb94  8d4490f4             lea eax, [eax + edx*4 - 0xc]
// 0088eb98  7816                 js 0x88ebb0
// 0088eb9a  8d9b00000000         lea ebx, [ebx]
// 0088eba0  8b5610               mov edx, dword ptr [esi + 0x10]
// 0088eba3  8910                 mov dword ptr [eax], edx
// 0088eba5  894610               mov dword ptr [esi + 0x10], eax
// 0088eba8  49                   dec ecx
// 0088eba9  83e80c               sub eax, 0xc
// 0088ebac  85c9                 test ecx, ecx
// 0088ebae  7df0                 jge 0x88eba0
// 0088ebb0  8b4610               mov eax, dword ptr [esi + 0x10]
// 0088ebb3  85c0                 test eax, eax
// 0088ebb5  7505                 jne 0x88ebbc
// 0088ebb7  e89090f1ff           call 0x7a7c4c
// 0088ebbc  8b08                 mov ecx, dword ptr [eax]
// 0088ebbe  8b542408             mov edx, dword ptr [esp + 8]
// 0088ebc2  894e10               mov dword ptr [esi + 0x10], ecx
// 0088ebc5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0088ebc9  895004               mov dword ptr [eax + 4], edx
// 0088ebcc  8908                 mov dword ptr [eax], ecx
// 0088ebce  ff460c               inc dword ptr [esi + 0xc]
// 0088ebd1  5e                   pop esi
// 0088ebd2  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?NewNode@?$CList@II@@IAEPAUCNode@1@PAU21@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
