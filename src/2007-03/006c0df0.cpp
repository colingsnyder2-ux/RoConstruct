// from server: 100% by auto
// roc 2007-03 006c0df0  unit: seg_006c0000  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c0df0
//
// 006c0df0  56                   push esi
// 006c0df1  57                   push edi
// 006c0df2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006c0df6  8bf1                 mov esi, ecx
// 006c0df8  6a00                 push 0
// 006c0dfa  8d4604               lea eax, [esi + 4]
// 006c0dfd  50                   push eax
// 006c0dfe  6868597d00           push 0x7d5968
// 006c0e03  57                   push edi
// 006c0e04  e8375ffaff           call 0x666d40
// 006c0e09  6a00                 push 0
// 006c0e0b  83c608               add esi, 8
// 006c0e0e  56                   push esi
// 006c0e0f  685c597d00           push 0x7d595c
// 006c0e14  57                   push edi
// 006c0e15  e8265ffaff           call 0x666d40
// 006c0e1a  83c420               add esp, 0x20
// 006c0e1d  5f                   pop edi
// 006c0e1e  b801000000           mov eax, 1
// 006c0e23  5e                   pop esi
// 006c0e24  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneLayout.cpp (function ?DoPropExchange@CXTPDockingPaneBase@@MAEHPAVCXTPPropExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneLayout.cpp
