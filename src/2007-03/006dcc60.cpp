// from server: 100% by auto
// roc 2007-03 006dcc60  unit: seg_006d0000  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006dcc60
//
// 006dcc60  83ec10               sub esp, 0x10
// 006dcc63  53                   push ebx
// 006dcc64  56                   push esi
// 006dcc65  57                   push edi
// 006dcc66  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006dcc6a  8b4718               mov eax, dword ptr [edi + 0x18]
// 006dcc6d  50                   push eax
// 006dcc6e  8bf1                 mov esi, ecx
// 006dcc70  e819df0500           call 0x73ab8e
// 006dcc75  8d4f1c               lea ecx, [edi + 0x1c]
// 006dcc78  51                   push ecx
// 006dcc79  8d542410             lea edx, [esp + 0x10]
// 006dcc7d  52                   push edx
// 006dcc7e  8bd8                 mov ebx, eax
// 006dcc80  ff1550ed7700         call dword ptr [0x77ed50]
// 006dcc86  8b4708               mov eax, dword ptr [edi + 8]
// 006dcc89  6a00                 push 0
// 006dcc8b  50                   push eax
// 006dcc8c  8b4620               mov eax, dword ptr [esi + 0x20]
// 006dcc8f  6899010000           push 0x199
// 006dcc94  50                   push eax
// 006dcc95  ff1550ee7700         call dword ptr [0x77ee50]
// 006dcc9b  837e5400             cmp dword ptr [esi + 0x54], 0
// 006dcc9f  7433                 je 0x6dccd4
// 006dcca1  8b5710               mov edx, dword ptr [edi + 0x10]
// 006dcca4  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006dcca8  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 006dccab  8b31                 mov esi, dword ptr [ecx]
// 006dccad  83e201               and edx, 1
// 006dccb0  52                   push edx
// 006dccb1  83ec10               sub esp, 0x10
// 006dccb4  8bd4                 mov edx, esp
// 006dccb6  893a                 mov dword ptr [edx], edi
// 006dccb8  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 006dccbc  897a04               mov dword ptr [edx + 4], edi
// 006dccbf  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006dccc3  897a08               mov dword ptr [edx + 8], edi
// 006dccc6  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006dccca  50                   push eax
// 006dcccb  8b466c               mov eax, dword ptr [esi + 0x6c]
// 006dccce  53                   push ebx
// 006dcccf  897a0c               mov dword ptr [edx + 0xc], edi
// 006dccd2  ffd0                 call eax
// 006dccd4  5f                   pop edi
// 006dccd5  5e                   pop esi
// 006dccd6  5b                   pop ebx
// 006dccd7  83c410               add esp, 0x10
// 006dccda  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?DrawItem@CXTPPropertyGridInplaceList@@MAEXPAUtagDRAWITEMSTRUCT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
