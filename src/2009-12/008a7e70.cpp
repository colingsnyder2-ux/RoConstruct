// from server: 100% by auto
// roc 2009-12 008a7e70  unit: CXTPDockingPaneBase  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a7e70
//
// 008a7e70  56                   push esi
// 008a7e71  57                   push edi
// 008a7e72  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008a7e76  8bf1                 mov esi, ecx
// 008a7e78  6a00                 push 0
// 008a7e7a  8d4604               lea eax, [esi + 4]
// 008a7e7d  50                   push eax
// 008a7e7e  68ec62a000           push 0xa062ec
// 008a7e83  57                   push edi
// 008a7e84  e8778bfaff           call 0x850a00
// 008a7e89  6a00                 push 0
// 008a7e8b  83c608               add esi, 8
// 008a7e8e  56                   push esi
// 008a7e8f  68e062a000           push 0xa062e0
// 008a7e94  57                   push edi
// 008a7e95  e8668bfaff           call 0x850a00
// 008a7e9a  83c420               add esp, 0x20
// 008a7e9d  5f                   pop edi
// 008a7e9e  b801000000           mov eax, 1
// 008a7ea3  5e                   pop esi
// 008a7ea4  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneLayout.cpp (function ?DoPropExchange@CXTPDockingPaneBase@@MAEHPAVCXTPPropExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneLayout.cpp
