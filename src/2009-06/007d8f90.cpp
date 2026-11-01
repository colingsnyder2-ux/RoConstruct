// from server: 100% by auto
// roc 2009-06 007d8f90  unit: CXTPDockingPaneTabbedContainer  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d8f90
//
// 007d8f90  51                   push ecx
// 007d8f91  53                   push ebx
// 007d8f92  56                   push esi
// 007d8f93  8d7120               lea esi, [ecx + 0x20]
// 007d8f96  57                   push edi
// 007d8f97  8bce                 mov ecx, esi
// 007d8f99  e802c2faff           call 0x7851a0
// 007d8f9e  8944240c             mov dword ptr [esp + 0xc], eax
// 007d8fa2  85c0                 test eax, eax
// 007d8fa4  7426                 je 0x7d8fcc
// 007d8fa6  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 007d8faa  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 007d8fae  8bff                 mov edi, edi
// 007d8fb0  3bc7                 cmp eax, edi
// 007d8fb2  7418                 je 0x7d8fcc
// 007d8fb4  8d44240c             lea eax, [esp + 0xc]
// 007d8fb8  50                   push eax
// 007d8fb9  8bce                 mov ecx, esi
// 007d8fbb  e8b0f20300           call 0x818270
// 007d8fc0  3bc3                 cmp eax, ebx
// 007d8fc2  7411                 je 0x7d8fd5
// 007d8fc4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007d8fc8  85c0                 test eax, eax
// 007d8fca  75e4                 jne 0x7d8fb0
// 007d8fcc  5f                   pop edi
// 007d8fcd  5e                   pop esi
// 007d8fce  33c0                 xor eax, eax
// 007d8fd0  5b                   pop ebx
// 007d8fd1  59                   pop ecx
// 007d8fd2  c20800               ret 8
// 007d8fd5  5f                   pop edi
// 007d8fd6  5e                   pop esi
// 007d8fd7  b801000000           mov eax, 1
// 007d8fdc  5b                   pop ebx
// 007d8fdd  59                   pop ecx
// 007d8fde  c20800               ret 8
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?_Before@CXTPDockingPaneSplitterContainer@@ABEHPBVCXTPDockingPaneBase@@PAU__POSITION@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
