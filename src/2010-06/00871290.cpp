// from server: 100% by auto
// roc 2010-06 00871290  unit: CXTPDockingPaneContext  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00871290
//
// 00871290  83ec10               sub esp, 0x10
// 00871293  56                   push esi
// 00871294  8b742418             mov esi, dword ptr [esp + 0x18]
// 00871298  57                   push edi
// 00871299  8d442408             lea eax, [esp + 8]
// 0087129d  56                   push esi
// 0087129e  50                   push eax
// 0087129f  e82cf6f7ff           call 0x7f08d0
// 008712a4  8bc8                 mov ecx, eax
// 008712a6  e885f1f7ff           call 0x7f0430
// 008712ab  8b442414             mov eax, dword ptr [esp + 0x14]
// 008712af  2b4604               sub eax, dword ptr [esi + 4]
// 008712b2  8b3d40bc9e00         mov edi, dword ptr [0x9ebc40]
// 008712b8  83f80a               cmp eax, 0xa
// 008712bb  7d09                 jge 0x8712c6
// 008712bd  83c0f6               add eax, -0xa
// 008712c0  50                   push eax
// 008712c1  6a00                 push 0
// 008712c3  56                   push esi
// 008712c4  ffd7                 call edi
// 008712c6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 008712c9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008712cd  8bd1                 mov edx, ecx
// 008712cf  2bd0                 sub edx, eax
// 008712d1  83fa0a               cmp edx, 0xa
// 008712d4  7d0b                 jge 0x8712e1
// 008712d6  2bc1                 sub eax, ecx
// 008712d8  83c00a               add eax, 0xa
// 008712db  50                   push eax
// 008712dc  6a00                 push 0
// 008712de  56                   push esi
// 008712df  ffd7                 call edi
// 008712e1  8b442410             mov eax, dword ptr [esp + 0x10]
// 008712e5  2b06                 sub eax, dword ptr [esi]
// 008712e7  83f80a               cmp eax, 0xa
// 008712ea  7d09                 jge 0x8712f5
// 008712ec  6a00                 push 0
// 008712ee  83c0f6               add eax, -0xa
// 008712f1  50                   push eax
// 008712f2  56                   push esi
// 008712f3  ffd7                 call edi
// 008712f5  8b4e08               mov ecx, dword ptr [esi + 8]
// 008712f8  8b442408             mov eax, dword ptr [esp + 8]
// 008712fc  8bd1                 mov edx, ecx
// 008712fe  2bd0                 sub edx, eax
// 00871300  83fa0a               cmp edx, 0xa
// 00871303  7d0b                 jge 0x871310
// 00871305  2bc1                 sub eax, ecx
// 00871307  6a00                 push 0
// 00871309  83c00a               add eax, 0xa
// 0087130c  50                   push eax
// 0087130d  56                   push esi
// 0087130e  ffd7                 call edi
// 00871310  5f                   pop edi
// 00871311  5e                   pop esi
// 00871312  83c410               add esp, 0x10
// 00871315  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ?EnsureVisible@CXTPDockingPaneContext@@SAXAAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneContext.cpp
