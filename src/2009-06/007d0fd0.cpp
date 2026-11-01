// from server: 100% by auto
// roc 2009-06 007d0fd0  unit: CXTPDockingPaneAutoHidePanel  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d0fd0
//
// 007d0fd0  56                   push esi
// 007d0fd1  57                   push edi
// 007d0fd2  8bf9                 mov edi, ecx
// 007d0fd4  be60000000           mov esi, 0x60
// 007d0fd9  8da42400000000       lea esp, [esp]
// 007d0fe0  8b4760               mov eax, dword ptr [edi + 0x60]
// 007d0fe3  03c6                 add eax, esi
// 007d0fe5  833800               cmp dword ptr [eax], 0
// 007d0fe8  7409                 je 0x7d0ff3
// 007d0fea  8b08                 mov ecx, dword ptr [eax]
// 007d0fec  6a00                 push 0
// 007d0fee  e80df2ffff           call 0x7d0200
// 007d0ff3  83c604               add esi, 4
// 007d0ff6  83fe70               cmp esi, 0x70
// 007d0ff9  7ce5                 jl 0x7d0fe0
// 007d0ffb  5f                   pop edi
// 007d0ffc  5e                   pop esi
// 007d0ffd  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneAutoHidePanel.cpp (function ?CloseActiveWindows@CXTPDockingPaneAutoHidePanel@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneAutoHidePanel.cpp
