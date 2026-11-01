// from server: 100% by auto
// roc 2009-06 007c8290  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c8290
//
// 007c8290  53                   push ebx
// 007c8291  8b5c2408             mov ebx, dword ptr [esp + 8]
// 007c8295  56                   push esi
// 007c8296  8bf1                 mov esi, ecx
// 007c8298  3bf3                 cmp esi, ebx
// 007c829a  7505                 jne 0x7c82a1
// 007c829c  e8430af5ff           call 0x718ce4
// 007c82a1  8b4308               mov eax, dword ptr [ebx + 8]
// 007c82a4  57                   push edi
// 007c82a5  8b7e08               mov edi, dword ptr [esi + 8]
// 007c82a8  6aff                 push -1
// 007c82aa  03c7                 add eax, edi
// 007c82ac  50                   push eax
// 007c82ad  e85ea2f8ff           call 0x752510
// 007c82b2  8b4b08               mov ecx, dword ptr [ebx + 8]
// 007c82b5  8b5304               mov edx, dword ptr [ebx + 4]
// 007c82b8  8b4604               mov eax, dword ptr [esi + 4]
// 007c82bb  51                   push ecx
// 007c82bc  52                   push edx
// 007c82bd  8d0cb8               lea ecx, [eax + edi*4]
// 007c82c0  51                   push ecx
// 007c82c1  e84afeffff           call 0x7c8110
// 007c82c6  8bc7                 mov eax, edi
// 007c82c8  5f                   pop edi
// 007c82c9  5e                   pop esi
// 007c82ca  5b                   pop ebx
// 007c82cb  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPCalendarEventLabel.cpp (function ?Append@?$CArray@II@@QAEHABV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarEventLabel.cpp
