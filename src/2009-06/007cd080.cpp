// from server: 100% by auto
// roc 2009-06 007cd080  unit: CXTPDockingPaneBase  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cd080
//
// 007cd080  56                   push esi
// 007cd081  57                   push edi
// 007cd082  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007cd086  8bf1                 mov esi, ecx
// 007cd088  6a00                 push 0
// 007cd08a  8d4604               lea eax, [esi + 4]
// 007cd08d  50                   push eax
// 007cd08e  686c5e9000           push 0x905e6c
// 007cd093  57                   push edi
// 007cd094  e8078cfaff           call 0x775ca0
// 007cd099  6a00                 push 0
// 007cd09b  83c608               add esi, 8
// 007cd09e  56                   push esi
// 007cd09f  68605e9000           push 0x905e60
// 007cd0a4  57                   push edi
// 007cd0a5  e8f68bfaff           call 0x775ca0
// 007cd0aa  83c420               add esp, 0x20
// 007cd0ad  5f                   pop edi
// 007cd0ae  b801000000           mov eax, 1
// 007cd0b3  5e                   pop esi
// 007cd0b4  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneLayout.cpp (function ?DoPropExchange@CXTPDockingPaneBase@@MAEHPAVCXTPPropExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneLayout.cpp
