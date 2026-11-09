// from server: 100% by auto
// roc 2010-06 0085bfc0  unit: CXTPDockingPaneBase  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085bfc0
//
// 0085bfc0  56                   push esi
// 0085bfc1  57                   push edi
// 0085bfc2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0085bfc6  8bf1                 mov esi, ecx
// 0085bfc8  6a00                 push 0
// 0085bfca  8d4604               lea eax, [esi + 4]
// 0085bfcd  50                   push eax
// 0085bfce  68d4a5a600           push 0xa6a5d4
// 0085bfd3  57                   push edi
// 0085bfd4  e8678afaff           call 0x804a40
// 0085bfd9  6a00                 push 0
// 0085bfdb  83c608               add esi, 8
// 0085bfde  56                   push esi
// 0085bfdf  68c8a5a600           push 0xa6a5c8
// 0085bfe4  57                   push edi
// 0085bfe5  e8568afaff           call 0x804a40
// 0085bfea  83c420               add esp, 0x20
// 0085bfed  5f                   pop edi
// 0085bfee  b801000000           mov eax, 1
// 0085bff3  5e                   pop esi
// 0085bff4  c20400               ret 4
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneLayout.cpp (function ?DoPropExchange@CXTPDockingPaneBase@@MAEHPAVCXTPPropExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneLayout.cpp
