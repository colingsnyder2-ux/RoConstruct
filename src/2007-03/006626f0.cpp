// from server: 100% by auto
// roc 2007-03 006626f0  unit: seg_00660000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006626f0
//
// 006626f0  8b442404             mov eax, dword ptr [esp + 4]
// 006626f4  85c0                 test eax, eax
// 006626f6  7c14                 jl 0x66270c
// 006626f8  3b8144010000         cmp eax, dword ptr [ecx + 0x144]
// 006626fe  7d0c                 jge 0x66270c
// 00662700  8b8940010000         mov ecx, dword ptr [ecx + 0x140]
// 00662706  8b0481               mov eax, dword ptr [ecx + eax*4]
// 00662709  c20400               ret 4
// 0066270c  33c0                 xor eax, eax
// 0066270e  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeCommandsPage.cpp (function ?GetCategoryInfo@CXTPCustomizeCommandsPage@@QBEPAUXTP_COMMANDBARS_CATEGORYINFO@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeCommandsPage.cpp
