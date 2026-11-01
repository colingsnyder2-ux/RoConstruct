// from server: 100% by auto
// roc 2007-03 00662320  unit: seg_00660000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00662320
//
// 00662320  56                   push esi
// 00662321  57                   push edi
// 00662322  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00662326  8bf1                 mov esi, ecx
// 00662328  8d8688000000         lea eax, [esi + 0x88]
// 0066232e  50                   push eax
// 0066232f  6a65                 push 0x65
// 00662331  57                   push edi
// 00662332  e8b38c0d00           call 0x73afea
// 00662337  81c6e4000000         add esi, 0xe4
// 0066233d  56                   push esi
// 0066233e  6a64                 push 0x64
// 00662340  57                   push edi
// 00662341  e8a48c0d00           call 0x73afea
// 00662346  5f                   pop edi
// 00662347  5e                   pop esi
// 00662348  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeCommandsPage.cpp (function ?DoDataExchange@CXTPCustomizeCommandsPage@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeCommandsPage.cpp
