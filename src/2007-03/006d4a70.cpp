// from server: 100% by auto
// roc 2007-03 006d4a70  unit: seg_006d0000  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006d4a70
//
// 006d4a70  83ec10               sub esp, 0x10
// 006d4a73  56                   push esi
// 006d4a74  8b742418             mov esi, dword ptr [esp + 0x18]
// 006d4a78  8d442404             lea eax, [esp + 4]
// 006d4a7c  56                   push esi
// 006d4a7d  50                   push eax
// 006d4a7e  e86d22fbff           call 0x686cf0
// 006d4a83  8bc8                 mov ecx, eax
// 006d4a85  e8761dfbff           call 0x686800
// 006d4a8a  8b442404             mov eax, dword ptr [esp + 4]
// 006d4a8e  3906                 cmp dword ptr [esi], eax
// 006d4a90  7d02                 jge 0x6d4a94
// 006d4a92  8906                 mov dword ptr [esi], eax
// 006d4a94  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006d4a98  3906                 cmp dword ptr [esi], eax
// 006d4a9a  7e02                 jle 0x6d4a9e
// 006d4a9c  8906                 mov dword ptr [esi], eax
// 006d4a9e  8b442408             mov eax, dword ptr [esp + 8]
// 006d4aa2  394604               cmp dword ptr [esi + 4], eax
// 006d4aa5  7d03                 jge 0x6d4aaa
// 006d4aa7  894604               mov dword ptr [esi + 4], eax
// 006d4aaa  8b442410             mov eax, dword ptr [esp + 0x10]
// 006d4aae  394604               cmp dword ptr [esi + 4], eax
// 006d4ab1  7e03                 jle 0x6d4ab6
// 006d4ab3  894604               mov dword ptr [esi + 4], eax
// 006d4ab6  5e                   pop esi
// 006d4ab7  83c410               add esp, 0x10
// 006d4aba  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ?AdjustCursor@CXTPDockingPaneContext@@KAXAAVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneContext.cpp
