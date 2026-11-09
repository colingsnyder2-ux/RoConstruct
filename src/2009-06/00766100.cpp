// from server: 100% by auto
// roc 2009-06 00766100  unit: PAUXTP_COMMANDBARS_CATEGORYINFO::?$CArray  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00766100
//
// 00766100  8b442404             mov eax, dword ptr [esp + 4]
// 00766104  85c0                 test eax, eax
// 00766106  7c14                 jl 0x76611c
// 00766108  3b8144010000         cmp eax, dword ptr [ecx + 0x144]
// 0076610e  7d0c                 jge 0x76611c
// 00766110  8b8940010000         mov ecx, dword ptr [ecx + 0x140]
// 00766116  8b0481               mov eax, dword ptr [ecx + eax*4]
// 00766119  c20400               ret 4
// 0076611c  33c0                 xor eax, eax
// 0076611e  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeCommandsPage.cpp (function ?GetCategoryInfo@CXTPCustomizeCommandsPage@@QBEPAUXTP_COMMANDBARS_CATEGORYINFO@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeCommandsPage.cpp
