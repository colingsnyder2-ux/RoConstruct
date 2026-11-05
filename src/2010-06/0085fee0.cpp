// from server: 100% by auto
// roc 2010-06 0085fee0  unit: CXTPDockingPaneAutoHidePanel  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085fee0
//
// 0085fee0  56                   push esi
// 0085fee1  57                   push edi
// 0085fee2  8bf9                 mov edi, ecx
// 0085fee4  be60000000           mov esi, 0x60
// 0085fee9  8da42400000000       lea esp, [esp]
// 0085fef0  8b4760               mov eax, dword ptr [edi + 0x60]
// 0085fef3  03c6                 add eax, esi
// 0085fef5  833800               cmp dword ptr [eax], 0
// 0085fef8  7409                 je 0x85ff03
// 0085fefa  8b08                 mov ecx, dword ptr [eax]
// 0085fefc  6a00                 push 0
// 0085fefe  e84df2ffff           call 0x85f150
// 0085ff03  83c604               add esi, 4
// 0085ff06  83fe70               cmp esi, 0x70
// 0085ff09  7ce5                 jl 0x85fef0
// 0085ff0b  5f                   pop edi
// 0085ff0c  5e                   pop esi
// 0085ff0d  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneAutoHidePanel.cpp (function ?CloseActiveWindows@CXTPDockingPaneAutoHidePanel@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneAutoHidePanel.cpp
