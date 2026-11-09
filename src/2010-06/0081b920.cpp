// from server: 100% by auto
// roc 2010-06 0081b920  unit: CXTPPropertyGridView  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081b920
//
// 0081b920  837c2408fc           cmp dword ptr [esp + 8], -4
// 0081b925  56                   push esi
// 0081b926  8bf1                 mov esi, ecx
// 0081b928  7409                 je 0x81b933
// 0081b92a  e841c6f8ff           call 0x7a7f70
// 0081b92f  5e                   pop esi
// 0081b930  c20800               ret 8
// 0081b933  68085aa500           push 0xa55a08
// 0081b938  e8b9141600           call 0x97cdf6
// 0081b93d  85c0                 test eax, eax
// 0081b93f  7509                 jne 0x81b94a
// 0081b941  b805400080           mov eax, 0x80004005
// 0081b946  5e                   pop esi
// 0081b947  c20800               ret 8
// 0081b94a  50                   push eax
// 0081b94b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0081b94f  50                   push eax
// 0081b950  68085aa500           push 0xa55a08
// 0081b955  8d4e54               lea ecx, [esi + 0x54]
// 0081b958  e8c34cfdff           call 0x7f0620
// 0081b95d  5e                   pop esi
// 0081b95e  c20800               ret 8
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?OnGetObject@CXTPDockingPaneManager@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
