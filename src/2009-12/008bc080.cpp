// from server: 100% by auto
// roc 2009-12 008bc080  unit: XTPDockingPanePaintThemes::CXTPDockingPaneNativeXPTheme  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008bc080
//
// 008bc080  83ec10               sub esp, 0x10
// 008bc083  56                   push esi
// 008bc084  8b742418             mov esi, dword ptr [esp + 0x18]
// 008bc088  8d442404             lea eax, [esp + 4]
// 008bc08c  56                   push esi
// 008bc08d  50                   push eax
// 008bc08e  e8dd06f8ff           call 0x83c770
// 008bc093  8bc8                 mov ecx, eax
// 008bc095  e8e601f8ff           call 0x83c280
// 008bc09a  8b442404             mov eax, dword ptr [esp + 4]
// 008bc09e  3906                 cmp dword ptr [esi], eax
// 008bc0a0  7d02                 jge 0x8bc0a4
// 008bc0a2  8906                 mov dword ptr [esi], eax
// 008bc0a4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008bc0a8  3906                 cmp dword ptr [esi], eax
// 008bc0aa  7e02                 jle 0x8bc0ae
// 008bc0ac  8906                 mov dword ptr [esi], eax
// 008bc0ae  8b442408             mov eax, dword ptr [esp + 8]
// 008bc0b2  394604               cmp dword ptr [esi + 4], eax
// 008bc0b5  7d03                 jge 0x8bc0ba
// 008bc0b7  894604               mov dword ptr [esi + 4], eax
// 008bc0ba  8b442410             mov eax, dword ptr [esp + 0x10]
// 008bc0be  394604               cmp dword ptr [esi + 4], eax
// 008bc0c1  7e03                 jle 0x8bc0c6
// 008bc0c3  894604               mov dword ptr [esi + 4], eax
// 008bc0c6  5e                   pop esi
// 008bc0c7  83c410               add esp, 0x10
// 008bc0ca  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ?AdjustCursor@CXTPDockingPaneContext@@KAXAAVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneContext.cpp
