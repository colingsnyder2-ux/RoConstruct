// from server: 100% by auto
// roc 2010-06 007f4f70  unit: PAUXTP_COMMANDBARS_CATEGORYINFO::?$CArray  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f4f70
//
// 007f4f70  8b442404             mov eax, dword ptr [esp + 4]
// 007f4f74  85c0                 test eax, eax
// 007f4f76  7c14                 jl 0x7f4f8c
// 007f4f78  3b8144010000         cmp eax, dword ptr [ecx + 0x144]
// 007f4f7e  7d0c                 jge 0x7f4f8c
// 007f4f80  8b8940010000         mov ecx, dword ptr [ecx + 0x140]
// 007f4f86  8b0481               mov eax, dword ptr [ecx + eax*4]
// 007f4f89  c20400               ret 4
// 007f4f8c  33c0                 xor eax, eax
// 007f4f8e  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeCommandsPage.cpp (function ?GetCategoryInfo@CXTPCustomizeCommandsPage@@QBEPAUXTP_COMMANDBARS_CATEGORYINFO@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeCommandsPage.cpp
