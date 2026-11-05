// from server: 100% by auto
// roc 2010-06 00896240  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00896240
//
// 00896240  53                   push ebx
// 00896241  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00896245  56                   push esi
// 00896246  8bf1                 mov esi, ecx
// 00896248  3bf3                 cmp esi, ebx
// 0089624a  7505                 jne 0x896251
// 0089624c  e8fb19f1ff           call 0x7a7c4c
// 00896251  8b4308               mov eax, dword ptr [ebx + 8]
// 00896254  57                   push edi
// 00896255  8b7e08               mov edi, dword ptr [esi + 8]
// 00896258  6aff                 push -1
// 0089625a  03c7                 add eax, edi
// 0089625c  50                   push eax
// 0089625d  e89eb0f4ff           call 0x7e1300
// 00896262  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00896265  8b5304               mov edx, dword ptr [ebx + 4]
// 00896268  8b4604               mov eax, dword ptr [esi + 4]
// 0089626b  51                   push ecx
// 0089626c  52                   push edx
// 0089626d  8d0cb8               lea ecx, [eax + edi*4]
// 00896270  51                   push ecx
// 00896271  e82a0efcff           call 0x8570a0
// 00896276  8bc7                 mov eax, edi
// 00896278  5f                   pop edi
// 00896279  5e                   pop esi
// 0089627a  5b                   pop ebx
// 0089627b  c20400               ret 4
// library xtp-13.2.1/Source\Calendar\XTPCalendarEventLabel.cpp (function ?Append@?$CArray@II@@QAEHABV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarEventLabel.cpp
