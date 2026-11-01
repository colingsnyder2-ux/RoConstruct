// from server: 100% by auto
// roc 2009-12 008b3ad0  unit: CXTPDockingPaneTabbedContainer  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b3ad0
//
// 008b3ad0  51                   push ecx
// 008b3ad1  53                   push ebx
// 008b3ad2  56                   push esi
// 008b3ad3  8d7120               lea esi, [ecx + 0x20]
// 008b3ad6  57                   push edi
// 008b3ad7  8bce                 mov ecx, esi
// 008b3ad9  e8b26cfaff           call 0x85a790
// 008b3ade  8944240c             mov dword ptr [esp + 0xc], eax
// 008b3ae2  85c0                 test eax, eax
// 008b3ae4  7426                 je 0x8b3b0c
// 008b3ae6  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 008b3aea  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 008b3aee  8bff                 mov edi, edi
// 008b3af0  3bc7                 cmp eax, edi
// 008b3af2  7418                 je 0x8b3b0c
// 008b3af4  8d44240c             lea eax, [esp + 0xc]
// 008b3af8  50                   push eax
// 008b3af9  8bce                 mov ecx, esi
// 008b3afb  e810f40300           call 0x8f2f10
// 008b3b00  3bc3                 cmp eax, ebx
// 008b3b02  7411                 je 0x8b3b15
// 008b3b04  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008b3b08  85c0                 test eax, eax
// 008b3b0a  75e4                 jne 0x8b3af0
// 008b3b0c  5f                   pop edi
// 008b3b0d  5e                   pop esi
// 008b3b0e  33c0                 xor eax, eax
// 008b3b10  5b                   pop ebx
// 008b3b11  59                   pop ecx
// 008b3b12  c20800               ret 8
// 008b3b15  5f                   pop edi
// 008b3b16  5e                   pop esi
// 008b3b17  b801000000           mov eax, 1
// 008b3b1c  5b                   pop ebx
// 008b3b1d  59                   pop ecx
// 008b3b1e  c20800               ret 8
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?_Before@CXTPDockingPaneSplitterContainer@@ABEHPBVCXTPDockingPaneBase@@PAU__POSITION@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
