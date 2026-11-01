// from server: 100% by auto
// roc 2009-06 007e1570  unit: XTPDockingPanePaintThemes::CXTPDockingPaneNativeXPTheme  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e1570
//
// 007e1570  83ec10               sub esp, 0x10
// 007e1573  56                   push esi
// 007e1574  8b742418             mov esi, dword ptr [esp + 0x18]
// 007e1578  8d442404             lea eax, [esp + 4]
// 007e157c  56                   push esi
// 007e157d  50                   push eax
// 007e157e  e81d04f8ff           call 0x7619a0
// 007e1583  8bc8                 mov ecx, eax
// 007e1585  e826fff7ff           call 0x7614b0
// 007e158a  8b442404             mov eax, dword ptr [esp + 4]
// 007e158e  3906                 cmp dword ptr [esi], eax
// 007e1590  7d02                 jge 0x7e1594
// 007e1592  8906                 mov dword ptr [esi], eax
// 007e1594  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e1598  3906                 cmp dword ptr [esi], eax
// 007e159a  7e02                 jle 0x7e159e
// 007e159c  8906                 mov dword ptr [esi], eax
// 007e159e  8b442408             mov eax, dword ptr [esp + 8]
// 007e15a2  394604               cmp dword ptr [esi + 4], eax
// 007e15a5  7d03                 jge 0x7e15aa
// 007e15a7  894604               mov dword ptr [esi + 4], eax
// 007e15aa  8b442410             mov eax, dword ptr [esp + 0x10]
// 007e15ae  394604               cmp dword ptr [esi + 4], eax
// 007e15b1  7e03                 jle 0x7e15b6
// 007e15b3  894604               mov dword ptr [esi + 4], eax
// 007e15b6  5e                   pop esi
// 007e15b7  83c410               add esp, 0x10
// 007e15ba  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ?AdjustCursor@CXTPDockingPaneContext@@KAXAAVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneContext.cpp
