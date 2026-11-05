// from server: 100% by auto
// roc 2010-06 00803080  unit: CXTPPropertyGrid  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00803080
//
// 00803080  e85beaffff           call 0x801ae0
// 00803085  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00803089  8b5020               mov edx, dword ptr [eax + 0x20]
// 0080308c  6a00                 push 0
// 0080308e  51                   push ecx
// 0080308f  6897010000           push 0x197
// 00803094  52                   push edx
// 00803095  ff1554ba9e00         call dword ptr [0x9eba54]
// 0080309b  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBoxExt.cpp (function ?SetTopIndex@CXTPControlComboBoxList@@MAEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBoxExt.cpp
