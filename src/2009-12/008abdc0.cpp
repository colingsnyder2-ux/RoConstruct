// from server: 100% by auto
// roc 2009-12 008abdc0  unit: CXTPDockingPaneAutoHidePanel  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008abdc0
//
// 008abdc0  56                   push esi
// 008abdc1  57                   push edi
// 008abdc2  8bf9                 mov edi, ecx
// 008abdc4  be60000000           mov esi, 0x60
// 008abdc9  8da42400000000       lea esp, [esp]
// 008abdd0  8b4760               mov eax, dword ptr [edi + 0x60]
// 008abdd3  03c6                 add eax, esi
// 008abdd5  833800               cmp dword ptr [eax], 0
// 008abdd8  7409                 je 0x8abde3
// 008abdda  8b08                 mov ecx, dword ptr [eax]
// 008abddc  6a00                 push 0
// 008abdde  e83df2ffff           call 0x8ab020
// 008abde3  83c604               add esi, 4
// 008abde6  83fe70               cmp esi, 0x70
// 008abde9  7ce5                 jl 0x8abdd0
// 008abdeb  5f                   pop edi
// 008abdec  5e                   pop esi
// 008abded  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneAutoHidePanel.cpp (function ?CloseActiveWindows@CXTPDockingPaneAutoHidePanel@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneAutoHidePanel.cpp
