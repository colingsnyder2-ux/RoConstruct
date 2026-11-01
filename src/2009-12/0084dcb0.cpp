// from server: 100% by auto
// roc 2009-12 0084dcb0  unit: CXTPPropertyGridToolBar  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084dcb0
//
// 0084dcb0  8b442408             mov eax, dword ptr [esp + 8]
// 0084dcb4  53                   push ebx
// 0084dcb5  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0084dcb9  c70000000000         mov dword ptr [eax], 0
// 0084dcbf  8b430c               mov eax, dword ptr [ebx + 0xc]
// 0084dcc2  83e801               sub eax, 1
// 0084dcc5  7556                 jne 0x84dd1d
// 0084dcc7  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0084dcca  56                   push esi
// 0084dccb  57                   push edi
// 0084dccc  8b3dbccb9800         mov edi, dword ptr [0x98cbbc]
// 0084dcd2  51                   push ecx
// 0084dcd3  ffd7                 call edi
// 0084dcd5  50                   push eax
// 0084dcd6  e84f5efaff           call 0x7f3b2a
// 0084dcdb  8bf0                 mov esi, eax
// 0084dcdd  8b5620               mov edx, dword ptr [esi + 0x20]
// 0084dce0  52                   push edx
// 0084dce1  ffd7                 call edi
// 0084dce3  50                   push eax
// 0084dce4  e8415efaff           call 0x7f3b2a
// 0084dce9  8b7620               mov esi, dword ptr [esi + 0x20]
// 0084dcec  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0084dcef  8b4020               mov eax, dword ptr [eax + 0x20]
// 0084dcf2  56                   push esi
// 0084dcf3  51                   push ecx
// 0084dcf4  6838010000           push 0x138
// 0084dcf9  50                   push eax
// 0084dcfa  ff15c4cb9800         call dword ptr [0x98cbc4]
// 0084dd00  5f                   pop edi
// 0084dd01  5e                   pop esi
// 0084dd02  85c0                 test eax, eax
// 0084dd04  7508                 jne 0x84dd0e
// 0084dd06  6a0f                 push 0xf
// 0084dd08  ff1564cb9800         call dword ptr [0x98cb64]
// 0084dd0e  8b5310               mov edx, dword ptr [ebx + 0x10]
// 0084dd11  50                   push eax
// 0084dd12  8d4b14               lea ecx, [ebx + 0x14]
// 0084dd15  51                   push ecx
// 0084dd16  52                   push edx
// 0084dd17  ff1560cb9800         call dword ptr [0x98cb60]
// 0084dd1d  5b                   pop ebx
// 0084dd1e  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?OnCustomDraw@CXTPPropertyGridToolBar@@IAEXPAUtagNMHDR@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
