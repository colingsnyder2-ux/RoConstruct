// from server: 100% by auto
// roc 2009-12 00840ee0  unit: PAUXTP_COMMANDBARS_CATEGORYINFO::?$CArray  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00840ee0
//
// 00840ee0  8b442404             mov eax, dword ptr [esp + 4]
// 00840ee4  85c0                 test eax, eax
// 00840ee6  7c14                 jl 0x840efc
// 00840ee8  3b8144010000         cmp eax, dword ptr [ecx + 0x144]
// 00840eee  7d0c                 jge 0x840efc
// 00840ef0  8b8940010000         mov ecx, dword ptr [ecx + 0x140]
// 00840ef6  8b0481               mov eax, dword ptr [ecx + eax*4]
// 00840ef9  c20400               ret 4
// 00840efc  33c0                 xor eax, eax
// 00840efe  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeCommandsPage.cpp (function ?GetCategoryInfo@CXTPCustomizeCommandsPage@@QBEPAUXTP_COMMANDBARS_CATEGORYINFO@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeCommandsPage.cpp
