// from server: 100% by auto
// roc 2009-06 007742c0  unit: CXTPPropertyGrid  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007742c0
//
// 007742c0  e88beaffff           call 0x772d50
// 007742c5  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007742c9  8b5020               mov edx, dword ptr [eax + 0x20]
// 007742cc  6a00                 push 0
// 007742ce  51                   push ecx
// 007742cf  6897010000           push 0x197
// 007742d4  52                   push edx
// 007742d5  ff1590ee8900         call dword ptr [0x89ee90]
// 007742db  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBoxExt.cpp (function ?SetTopIndex@CXTPControlComboBoxList@@MAEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBoxExt.cpp
