// from server: 100% by auto
// roc 2009-12 0084f020  unit: CXTPPropertyGrid  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084f020
//
// 0084f020  e85beaffff           call 0x84da80
// 0084f025  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0084f029  8b5020               mov edx, dword ptr [eax + 0x20]
// 0084f02c  6a00                 push 0
// 0084f02e  51                   push ecx
// 0084f02f  6897010000           push 0x197
// 0084f034  52                   push edx
// 0084f035  ff15c4cb9800         call dword ptr [0x98cbc4]
// 0084f03b  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBoxExt.cpp (function ?SetTopIndex@CXTPControlComboBoxList@@MAEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBoxExt.cpp
