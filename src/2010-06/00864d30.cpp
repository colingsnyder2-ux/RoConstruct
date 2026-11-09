// from server: 100% by auto
// roc 2010-06 00864d30  unit: CXTPDockingPaneAutoHidePanel  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00864d30
//
// 00864d30  83ec20               sub esp, 0x20
// 00864d33  8b442424             mov eax, dword ptr [esp + 0x24]
// 00864d37  53                   push ebx
// 00864d38  55                   push ebp
// 00864d39  56                   push esi
// 00864d3a  57                   push edi
// 00864d3b  50                   push eax
// 00864d3c  8bf1                 mov esi, ecx
// 00864d3e  e829801100           call 0x97cd6c
// 00864d43  89442434             mov dword ptr [esp + 0x34], eax
// 00864d47  85c0                 test eax, eax
// 00864d49  7449                 je 0x864d94
// 00864d4b  56                   push esi
// 00864d4c  8d4c2414             lea ecx, [esp + 0x14]
// 00864d50  e8bba5f9ff           call 0x7ff310
// 00864d55  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00864d59  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00864d5d  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00864d61  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00864d65  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00864d69  8d4e54               lea ecx, [esi + 0x54]
// 00864d6c  e8affbffff           call 0x864920
// 00864d71  83ec10               sub esp, 0x10
// 00864d74  8bd4                 mov edx, esp
// 00864d76  893a                 mov dword ptr [edx], edi
// 00864d78  8b7c243c             mov edi, dword ptr [esp + 0x3c]
// 00864d7c  895a04               mov dword ptr [edx + 4], ebx
// 00864d7f  896a08               mov dword ptr [edx + 8], ebp
// 00864d82  8bc8                 mov ecx, eax
// 00864d84  8b00                 mov eax, dword ptr [eax]
// 00864d86  8b4058               mov eax, dword ptr [eax + 0x58]
// 00864d89  897a0c               mov dword ptr [edx + 0xc], edi
// 00864d8c  8b542444             mov edx, dword ptr [esp + 0x44]
// 00864d90  56                   push esi
// 00864d91  52                   push edx
// 00864d92  ffd0                 call eax
// 00864d94  5f                   pop edi
// 00864d95  5e                   pop esi
// 00864d96  5d                   pop ebp
// 00864d97  b801000000           mov eax, 1
// 00864d9c  5b                   pop ebx
// 00864d9d  83c420               add esp, 0x20
// 00864da0  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?OnPrintClient@CXTPDockingPaneTabbedContainer@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
