// from server: 100% by auto
// roc 2010-06 00867bc0  unit: CInstanceRecord::CNameItem  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00867bc0
//
// 00867bc0  51                   push ecx
// 00867bc1  53                   push ebx
// 00867bc2  56                   push esi
// 00867bc3  8d7120               lea esi, [ecx + 0x20]
// 00867bc6  57                   push edi
// 00867bc7  8bce                 mov ecx, esi
// 00867bc9  e8f275f9ff           call 0x7ff1c0
// 00867bce  8944240c             mov dword ptr [esp + 0xc], eax
// 00867bd2  85c0                 test eax, eax
// 00867bd4  7426                 je 0x867bfc
// 00867bd6  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00867bda  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00867bde  8bff                 mov edi, edi
// 00867be0  3bc7                 cmp eax, edi
// 00867be2  7418                 je 0x867bfc
// 00867be4  8d44240c             lea eax, [esp + 0xc]
// 00867be8  50                   push eax
// 00867be9  8bce                 mov ecx, esi
// 00867beb  e870f40300           call 0x8a7060
// 00867bf0  3bc3                 cmp eax, ebx
// 00867bf2  7411                 je 0x867c05
// 00867bf4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00867bf8  85c0                 test eax, eax
// 00867bfa  75e4                 jne 0x867be0
// 00867bfc  5f                   pop edi
// 00867bfd  5e                   pop esi
// 00867bfe  33c0                 xor eax, eax
// 00867c00  5b                   pop ebx
// 00867c01  59                   pop ecx
// 00867c02  c20800               ret 8
// 00867c05  5f                   pop edi
// 00867c06  5e                   pop esi
// 00867c07  b801000000           mov eax, 1
// 00867c0c  5b                   pop ebx
// 00867c0d  59                   pop ecx
// 00867c0e  c20800               ret 8
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?_Before@CXTPDockingPaneSplitterContainer@@ABEHPBVCXTPDockingPaneBase@@PAU__POSITION@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
