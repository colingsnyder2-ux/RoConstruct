// from server: 100% by auto
// roc 2007-03 006c4c60  unit: seg_006c0000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c4c60
//
// 006c4c60  56                   push esi
// 006c4c61  57                   push edi
// 006c4c62  8bf9                 mov edi, ecx
// 006c4c64  be60000000           mov esi, 0x60
// 006c4c69  8da42400000000       lea esp, [esp]
// 006c4c70  8b4760               mov eax, dword ptr [edi + 0x60]
// 006c4c73  03c6                 add eax, esi
// 006c4c75  833800               cmp dword ptr [eax], 0
// 006c4c78  7409                 je 0x6c4c83
// 006c4c7a  8b08                 mov ecx, dword ptr [eax]
// 006c4c7c  6a00                 push 0
// 006c4c7e  e83df3ffff           call 0x6c3fc0
// 006c4c83  83c604               add esi, 4
// 006c4c86  83fe70               cmp esi, 0x70
// 006c4c89  7ce5                 jl 0x6c4c70
// 006c4c8b  5f                   pop edi
// 006c4c8c  5e                   pop esi
// 006c4c8d  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneAutoHidePanel.cpp (function ?CloseActiveWindows@CXTPDockingPaneAutoHidePanel@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneAutoHidePanel.cpp
