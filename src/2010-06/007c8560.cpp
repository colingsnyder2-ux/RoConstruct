// from server: 100% by auto
// roc 2010-06 007c8560  unit: MyXTPCommandBars  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c8560
//
// 007c8560  56                   push esi
// 007c8561  51                   push ecx
// 007c8562  e8c9d40200           call 0x7f5a30
// 007c8567  6a00                 push 0
// 007c8569  6a01                 push 1
// 007c856b  6800e80000           push 0xe800
// 007c8570  8bf0                 mov esi, eax
// 007c8572  6a00                 push 0
// 007c8574  56                   push esi
// 007c8575  e8e6480300           call 0x7fce60
// 007c857a  83c418               add esp, 0x18
// 007c857d  8bc6                 mov eax, esi
// 007c857f  5e                   pop esi
// 007c8580  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetToolbarsPopup@CXTPCommandBars@@UAEPAVCXTPPopupBar@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
