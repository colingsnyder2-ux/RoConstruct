// from server: 100% by auto
// roc 2010-06 00870290  unit: ATL::CRegObject  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00870290
//
// 00870290  53                   push ebx
// 00870291  8b5904               mov ebx, dword ptr [ecx + 4]
// 00870294  85db                 test ebx, ebx
// 00870296  7505                 jne 0x87029d
// 00870298  e8af79f3ff           call 0x7a7c4c
// 0087029d  55                   push ebp
// 0087029e  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 008702a2  56                   push esi
// 008702a3  8b7500               mov esi, dword ptr [ebp]
// 008702a6  85f6                 test esi, esi
// 008702a8  7505                 jne 0x8702af
// 008702aa  e89d79f3ff           call 0x7a7c4c
// 008702af  57                   push edi
// 008702b0  83feff               cmp esi, -1
// 008702b3  751e                 jne 0x8702d3
// 008702b5  8b7908               mov edi, dword ptr [ecx + 8]
// 008702b8  33c0                 xor eax, eax
// 008702ba  85ff                 test edi, edi
// 008702bc  7615                 jbe 0x8702d3
// 008702be  8bd3                 mov edx, ebx
// 008702c0  8b32                 mov esi, dword ptr [edx]
// 008702c2  85f6                 test esi, esi
// 008702c4  750d                 jne 0x8702d3
// 008702c6  40                   inc eax
// 008702c7  83c204               add edx, 4
// 008702ca  3bc7                 cmp eax, edi
// 008702cc  72f2                 jb 0x8702c0
// 008702ce  e87979f3ff           call 0x7a7c4c
// 008702d3  8b7e08               mov edi, dword ptr [esi + 8]
// 008702d6  85ff                 test edi, edi
// 008702d8  7524                 jne 0x8702fe
// 008702da  8b4908               mov ecx, dword ptr [ecx + 8]
// 008702dd  8b460c               mov eax, dword ptr [esi + 0xc]
// 008702e0  33d2                 xor edx, edx
// 008702e2  f7f1                 div ecx
// 008702e4  42                   inc edx
// 008702e5  3bd1                 cmp edx, ecx
// 008702e7  7315                 jae 0x8702fe
// 008702e9  8d0493               lea eax, [ebx + edx*4]
// 008702ec  8d642400             lea esp, [esp]
// 008702f0  8b38                 mov edi, dword ptr [eax]
// 008702f2  85ff                 test edi, edi
// 008702f4  7508                 jne 0x8702fe
// 008702f6  42                   inc edx
// 008702f7  83c004               add eax, 4
// 008702fa  3bd1                 cmp edx, ecx
// 008702fc  72f2                 jb 0x8702f0
// 008702fe  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00870302  897d00               mov dword ptr [ebp], edi
// 00870305  8b06                 mov eax, dword ptr [esi]
// 00870307  8901                 mov dword ptr [ecx], eax
// 00870309  8b5604               mov edx, dword ptr [esi + 4]
// 0087030c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00870310  5f                   pop edi
// 00870311  5e                   pop esi
// 00870312  5d                   pop ebp
// 00870313  8910                 mov dword ptr [eax], edx
// 00870315  5b                   pop ebx
// 00870316  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcontextmenumanager.cpp (function ?GetNextAssoc@?$CMap@IIPAUHMENU__@@PAU1@@@QBEXAAPAU__POSITION@@AAIAAPAUHMENU__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcontextmenumanager.cpp
