// from server: 100% by auto
// roc 2009-12 008bd0c0  unit: CXTPDockingPaneContext  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008bd0c0
//
// 008bd0c0  83ec10               sub esp, 0x10
// 008bd0c3  56                   push esi
// 008bd0c4  8b742418             mov esi, dword ptr [esp + 0x18]
// 008bd0c8  57                   push edi
// 008bd0c9  8d442408             lea eax, [esp + 8]
// 008bd0cd  56                   push esi
// 008bd0ce  50                   push eax
// 008bd0cf  e89cf6f7ff           call 0x83c770
// 008bd0d4  8bc8                 mov ecx, eax
// 008bd0d6  e8f5f1f7ff           call 0x83c2d0
// 008bd0db  8b442414             mov eax, dword ptr [esp + 0x14]
// 008bd0df  2b4604               sub eax, dword ptr [esi + 4]
// 008bd0e2  8b3d6ccc9800         mov edi, dword ptr [0x98cc6c]
// 008bd0e8  83f80a               cmp eax, 0xa
// 008bd0eb  7d09                 jge 0x8bd0f6
// 008bd0ed  83c0f6               add eax, -0xa
// 008bd0f0  50                   push eax
// 008bd0f1  6a00                 push 0
// 008bd0f3  56                   push esi
// 008bd0f4  ffd7                 call edi
// 008bd0f6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 008bd0f9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008bd0fd  8bd1                 mov edx, ecx
// 008bd0ff  2bd0                 sub edx, eax
// 008bd101  83fa0a               cmp edx, 0xa
// 008bd104  7d0b                 jge 0x8bd111
// 008bd106  2bc1                 sub eax, ecx
// 008bd108  83c00a               add eax, 0xa
// 008bd10b  50                   push eax
// 008bd10c  6a00                 push 0
// 008bd10e  56                   push esi
// 008bd10f  ffd7                 call edi
// 008bd111  8b442410             mov eax, dword ptr [esp + 0x10]
// 008bd115  2b06                 sub eax, dword ptr [esi]
// 008bd117  83f80a               cmp eax, 0xa
// 008bd11a  7d09                 jge 0x8bd125
// 008bd11c  6a00                 push 0
// 008bd11e  83c0f6               add eax, -0xa
// 008bd121  50                   push eax
// 008bd122  56                   push esi
// 008bd123  ffd7                 call edi
// 008bd125  8b4e08               mov ecx, dword ptr [esi + 8]
// 008bd128  8b442408             mov eax, dword ptr [esp + 8]
// 008bd12c  8bd1                 mov edx, ecx
// 008bd12e  2bd0                 sub edx, eax
// 008bd130  83fa0a               cmp edx, 0xa
// 008bd133  7d0b                 jge 0x8bd140
// 008bd135  2bc1                 sub eax, ecx
// 008bd137  6a00                 push 0
// 008bd139  83c00a               add eax, 0xa
// 008bd13c  50                   push eax
// 008bd13d  56                   push esi
// 008bd13e  ffd7                 call edi
// 008bd140  5f                   pop edi
// 008bd141  5e                   pop esi
// 008bd142  83c410               add esp, 0x10
// 008bd145  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ?EnsureVisible@CXTPDockingPaneContext@@SAXAAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneContext.cpp
