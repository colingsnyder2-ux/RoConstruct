// from server: 100% by auto
// roc 2009-06 007e2600  unit: CXTPDockingPaneContext  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e2600
//
// 007e2600  83ec10               sub esp, 0x10
// 007e2603  56                   push esi
// 007e2604  8b742418             mov esi, dword ptr [esp + 0x18]
// 007e2608  57                   push edi
// 007e2609  8d442408             lea eax, [esp + 8]
// 007e260d  56                   push esi
// 007e260e  50                   push eax
// 007e260f  e88cf3f7ff           call 0x7619a0
// 007e2614  8bc8                 mov ecx, eax
// 007e2616  e8e5eef7ff           call 0x761500
// 007e261b  8b442414             mov eax, dword ptr [esp + 0x14]
// 007e261f  2b4604               sub eax, dword ptr [esi + 4]
// 007e2622  8b3df8ed8900         mov edi, dword ptr [0x89edf8]
// 007e2628  83f80a               cmp eax, 0xa
// 007e262b  7d09                 jge 0x7e2636
// 007e262d  83c0f6               add eax, -0xa
// 007e2630  50                   push eax
// 007e2631  6a00                 push 0
// 007e2633  56                   push esi
// 007e2634  ffd7                 call edi
// 007e2636  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007e2639  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e263d  8bd1                 mov edx, ecx
// 007e263f  2bd0                 sub edx, eax
// 007e2641  83fa0a               cmp edx, 0xa
// 007e2644  7d0b                 jge 0x7e2651
// 007e2646  2bc1                 sub eax, ecx
// 007e2648  83c00a               add eax, 0xa
// 007e264b  50                   push eax
// 007e264c  6a00                 push 0
// 007e264e  56                   push esi
// 007e264f  ffd7                 call edi
// 007e2651  8b442410             mov eax, dword ptr [esp + 0x10]
// 007e2655  2b06                 sub eax, dword ptr [esi]
// 007e2657  83f80a               cmp eax, 0xa
// 007e265a  7d09                 jge 0x7e2665
// 007e265c  6a00                 push 0
// 007e265e  83c0f6               add eax, -0xa
// 007e2661  50                   push eax
// 007e2662  56                   push esi
// 007e2663  ffd7                 call edi
// 007e2665  8b4e08               mov ecx, dword ptr [esi + 8]
// 007e2668  8b442408             mov eax, dword ptr [esp + 8]
// 007e266c  8bd1                 mov edx, ecx
// 007e266e  2bd0                 sub edx, eax
// 007e2670  83fa0a               cmp edx, 0xa
// 007e2673  7d0b                 jge 0x7e2680
// 007e2675  2bc1                 sub eax, ecx
// 007e2677  6a00                 push 0
// 007e2679  83c00a               add eax, 0xa
// 007e267c  50                   push eax
// 007e267d  56                   push esi
// 007e267e  ffd7                 call edi
// 007e2680  5f                   pop edi
// 007e2681  5e                   pop esi
// 007e2682  83c410               add esp, 0x10
// 007e2685  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ?EnsureVisible@CXTPDockingPaneContext@@SAXAAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneContext.cpp
