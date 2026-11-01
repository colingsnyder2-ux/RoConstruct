// from server: 100% by auto
// roc 2010-06 0080d4b0  unit: CXTPTabClientWnd  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080d4b0
//
// 0080d4b0  56                   push esi
// 0080d4b1  8bf1                 mov esi, ecx
// 0080d4b3  83bed800000000       cmp dword ptr [esi + 0xd8], 0
// 0080d4ba  57                   push edi
// 0080d4bb  7512                 jne 0x80d4cf
// 0080d4bd  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0080d4c1  50                   push eax
// 0080d4c2  e8e9f8ffff           call 0x80cdb0
// 0080d4c7  50                   push eax
// 0080d4c8  8bce                 mov ecx, esi
// 0080d4ca  e811e1ffff           call 0x80b5e0
// 0080d4cf  8bce                 mov ecx, esi
// 0080d4d1  e89aaaf9ff           call 0x7a7f70
// 0080d4d6  8b16                 mov edx, dword ptr [esi]
// 0080d4d8  8bf8                 mov edi, eax
// 0080d4da  8b8244010000         mov eax, dword ptr [edx + 0x144]
// 0080d4e0  8bce                 mov ecx, esi
// 0080d4e2  ffd0                 call eax
// 0080d4e4  8bc7                 mov eax, edi
// 0080d4e6  5f                   pop edi
// 0080d4e7  5e                   pop esi
// 0080d4e8  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnMDIDestroy@CXTPTabClientWnd@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPTabClientWnd.cpp
