// from server: 100% by auto
// roc 2009-12 00814480  unit: MyXTPCommandBars  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00814480
//
// 00814480  56                   push esi
// 00814481  51                   push ecx
// 00814482  e809d50200           call 0x841990
// 00814487  6a00                 push 0
// 00814489  6a01                 push 1
// 0081448b  6800e80000           push 0xe800
// 00814490  8bf0                 mov esi, eax
// 00814492  6a00                 push 0
// 00814494  56                   push esi
// 00814495  e826490300           call 0x848dc0
// 0081449a  83c418               add esp, 0x18
// 0081449d  8bc6                 mov eax, esi
// 0081449f  5e                   pop esi
// 008144a0  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetToolbarsPopup@CXTPCommandBars@@UAEPAVCXTPPopupBar@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
