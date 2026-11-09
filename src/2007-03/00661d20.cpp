// from server: 100% by auto
// roc 2007-03 00661d20  unit: seg_00660000  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00661d20
//
// 00661d20  56                   push esi
// 00661d21  57                   push edi
// 00661d22  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00661d26  8bf1                 mov esi, ecx
// 00661d28  8d869c000000         lea eax, [esi + 0x9c]
// 00661d2e  50                   push eax
// 00661d2f  6a6a                 push 0x6a
// 00661d31  57                   push edi
// 00661d32  e8b3920d00           call 0x73afea
// 00661d37  8d8ef0000000         lea ecx, [esi + 0xf0]
// 00661d3d  51                   push ecx
// 00661d3e  6a6a                 push 0x6a
// 00661d40  57                   push edi
// 00661d41  e89e920d00           call 0x73afe4
// 00661d46  8d9688000000         lea edx, [esi + 0x88]
// 00661d4c  52                   push edx
// 00661d4d  6a64                 push 0x64
// 00661d4f  57                   push edi
// 00661d50  e889920d00           call 0x73afde
// 00661d55  8d868c000000         lea eax, [esi + 0x8c]
// 00661d5b  50                   push eax
// 00661d5c  6a65                 push 0x65
// 00661d5e  57                   push edi
// 00661d5f  e87a920d00           call 0x73afde
// 00661d64  8d8e90000000         lea ecx, [esi + 0x90]
// 00661d6a  51                   push ecx
// 00661d6b  6a67                 push 0x67
// 00661d6d  57                   push edi
// 00661d6e  e86b920d00           call 0x73afde
// 00661d73  8d9694000000         lea edx, [esi + 0x94]
// 00661d79  52                   push edx
// 00661d7a  6a68                 push 0x68
// 00661d7c  57                   push edi
// 00661d7d  e85c920d00           call 0x73afde
// 00661d82  81c698000000         add esi, 0x98
// 00661d88  56                   push esi
// 00661d89  6a69                 push 0x69
// 00661d8b  57                   push edi
// 00661d8c  e84d920d00           call 0x73afde
// 00661d91  5f                   pop edi
// 00661d92  5e                   pop esi
// 00661d93  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeOptionsPage.cpp (function ?DoDataExchange@CXTPCustomizeOptionsPage@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeOptionsPage.cpp
