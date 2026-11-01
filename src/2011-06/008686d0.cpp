// from server: 100% by auto
// roc 2011-06 008686d0  unit: CXTPTabClientWnd  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008686d0
//
// 008686d0  56                   push esi
// 008686d1  8bf1                 mov esi, ecx
// 008686d3  83bed800000000       cmp dword ptr [esi + 0xd8], 0
// 008686da  57                   push edi
// 008686db  7512                 jne 0x8686ef
// 008686dd  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008686e1  50                   push eax
// 008686e2  e8e9f8ffff           call 0x867fd0
// 008686e7  50                   push eax
// 008686e8  8bce                 mov ecx, esi
// 008686ea  e811e1ffff           call 0x866800
// 008686ef  8bce                 mov ecx, esi
// 008686f1  e8381ffaff           call 0x80a62e
// 008686f6  8b16                 mov edx, dword ptr [esi]
// 008686f8  8bf8                 mov edi, eax
// 008686fa  8b8244010000         mov eax, dword ptr [edx + 0x144]
// 00868700  8bce                 mov ecx, esi
// 00868702  ffd0                 call eax
// 00868704  8bc7                 mov eax, edi
// 00868706  5f                   pop edi
// 00868707  5e                   pop esi
// 00868708  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnMDIDestroy@CXTPTabClientWnd@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPTabClientWnd.cpp
