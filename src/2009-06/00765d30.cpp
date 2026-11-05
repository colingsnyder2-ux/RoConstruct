// from server: 100% by auto
// roc 2009-06 00765d30  unit: CXTPCustomizeCommandsPage  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00765d30
//
// 00765d30  56                   push esi
// 00765d31  57                   push edi
// 00765d32  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00765d36  8bf1                 mov esi, ecx
// 00765d38  8d8688000000         lea eax, [esi + 0x88]
// 00765d3e  50                   push eax
// 00765d3f  6a65                 push 0x65
// 00765d41  57                   push edi
// 00765d42  e83f36fbff           call 0x719386
// 00765d47  81c6e4000000         add esi, 0xe4
// 00765d4d  56                   push esi
// 00765d4e  6a64                 push 0x64
// 00765d50  57                   push edi
// 00765d51  e83036fbff           call 0x719386
// 00765d56  5f                   pop edi
// 00765d57  5e                   pop esi
// 00765d58  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeCommandsPage.cpp (function ?DoDataExchange@CXTPCustomizeCommandsPage@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeCommandsPage.cpp
