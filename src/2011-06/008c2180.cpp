// from server: 100% by auto
// roc 2011-06 008c2180  unit: CXTPDockingPaneAutoHidePanel  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008c2180
//
// 008c2180  83ec20               sub esp, 0x20
// 008c2183  8b442424             mov eax, dword ptr [esp + 0x24]
// 008c2187  53                   push ebx
// 008c2188  55                   push ebp
// 008c2189  56                   push esi
// 008c218a  57                   push edi
// 008c218b  50                   push eax
// 008c218c  8bf1                 mov esi, ecx
// 008c218e  e825a41000           call 0x9cc5b8
// 008c2193  89442434             mov dword ptr [esp + 0x34], eax
// 008c2197  85c0                 test eax, eax
// 008c2199  7449                 je 0x8c21e4
// 008c219b  56                   push esi
// 008c219c  8d4c2414             lea ecx, [esp + 0x14]
// 008c21a0  e8ebabf9ff           call 0x85cd90
// 008c21a5  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 008c21a9  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008c21ad  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 008c21b1  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 008c21b5  894c242c             mov dword ptr [esp + 0x2c], ecx
// 008c21b9  8d4e54               lea ecx, [esi + 0x54]
// 008c21bc  e8affbffff           call 0x8c1d70
// 008c21c1  83ec10               sub esp, 0x10
// 008c21c4  8bd4                 mov edx, esp
// 008c21c6  893a                 mov dword ptr [edx], edi
// 008c21c8  8b7c243c             mov edi, dword ptr [esp + 0x3c]
// 008c21cc  895a04               mov dword ptr [edx + 4], ebx
// 008c21cf  896a08               mov dword ptr [edx + 8], ebp
// 008c21d2  8bc8                 mov ecx, eax
// 008c21d4  8b00                 mov eax, dword ptr [eax]
// 008c21d6  8b4058               mov eax, dword ptr [eax + 0x58]
// 008c21d9  897a0c               mov dword ptr [edx + 0xc], edi
// 008c21dc  8b542444             mov edx, dword ptr [esp + 0x44]
// 008c21e0  56                   push esi
// 008c21e1  52                   push edx
// 008c21e2  ffd0                 call eax
// 008c21e4  5f                   pop edi
// 008c21e5  5e                   pop esi
// 008c21e6  5d                   pop ebp
// 008c21e7  b801000000           mov eax, 1
// 008c21ec  5b                   pop ebx
// 008c21ed  83c420               add esp, 0x20
// 008c21f0  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?OnPrintClient@CXTPDockingPaneTabbedContainer@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
