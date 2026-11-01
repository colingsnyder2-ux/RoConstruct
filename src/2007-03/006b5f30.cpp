// from server: 100% by auto
// roc 2007-03 006b5f30  unit: seg_006b0000  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b5f30
//
// 006b5f30  53                   push ebx
// 006b5f31  8b5c2408             mov ebx, dword ptr [esp + 8]
// 006b5f35  56                   push esi
// 006b5f36  8bf1                 mov esi, ecx
// 006b5f38  3bf3                 cmp esi, ebx
// 006b5f3a  7505                 jne 0x6b5f41
// 006b5f3c  e86d84f6ff           call 0x61e3ae
// 006b5f41  8b4308               mov eax, dword ptr [ebx + 8]
// 006b5f44  57                   push edi
// 006b5f45  8b7e08               mov edi, dword ptr [esi + 8]
// 006b5f48  6aff                 push -1
// 006b5f4a  03c7                 add eax, edi
// 006b5f4c  50                   push eax
// 006b5f4d  e8ce52daff           call 0x45b220
// 006b5f52  8b4b08               mov ecx, dword ptr [ebx + 8]
// 006b5f55  8b5304               mov edx, dword ptr [ebx + 4]
// 006b5f58  8b4604               mov eax, dword ptr [esi + 4]
// 006b5f5b  51                   push ecx
// 006b5f5c  52                   push edx
// 006b5f5d  8d0cb8               lea ecx, [eax + edi*4]
// 006b5f60  51                   push ecx
// 006b5f61  e8bae9fdff           call 0x694920
// 006b5f66  8bc7                 mov eax, edi
// 006b5f68  5f                   pop edi
// 006b5f69  5e                   pop esi
// 006b5f6a  5b                   pop ebx
// 006b5f6b  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPCalendarEventLabel.cpp (function ?Append@?$CArray@II@@QAEHABV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarEventLabel.cpp
