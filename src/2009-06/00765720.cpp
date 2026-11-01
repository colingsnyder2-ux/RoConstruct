// from server: 100% by auto
// roc 2009-06 00765720  unit: CXTPCustomizeOptionsPage  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00765720
//
// 00765720  56                   push esi
// 00765721  57                   push edi
// 00765722  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00765726  8bf1                 mov esi, ecx
// 00765728  8d869c000000         lea eax, [esi + 0x9c]
// 0076572e  50                   push eax
// 0076572f  6a6a                 push 0x6a
// 00765731  57                   push edi
// 00765732  e84f3cfbff           call 0x719386
// 00765737  8d8ef0000000         lea ecx, [esi + 0xf0]
// 0076573d  51                   push ecx
// 0076573e  6a6a                 push 0x6a
// 00765740  57                   push edi
// 00765741  e8466c0e00           call 0x84c38c
// 00765746  8d9688000000         lea edx, [esi + 0x88]
// 0076574c  52                   push edx
// 0076574d  6a64                 push 0x64
// 0076574f  57                   push edi
// 00765750  e8316c0e00           call 0x84c386
// 00765755  8d868c000000         lea eax, [esi + 0x8c]
// 0076575b  50                   push eax
// 0076575c  6a65                 push 0x65
// 0076575e  57                   push edi
// 0076575f  e8226c0e00           call 0x84c386
// 00765764  8d8e90000000         lea ecx, [esi + 0x90]
// 0076576a  51                   push ecx
// 0076576b  6a67                 push 0x67
// 0076576d  57                   push edi
// 0076576e  e8136c0e00           call 0x84c386
// 00765773  8d9694000000         lea edx, [esi + 0x94]
// 00765779  52                   push edx
// 0076577a  6a68                 push 0x68
// 0076577c  57                   push edi
// 0076577d  e8046c0e00           call 0x84c386
// 00765782  81c698000000         add esi, 0x98
// 00765788  56                   push esi
// 00765789  6a69                 push 0x69
// 0076578b  57                   push edi
// 0076578c  e8f56b0e00           call 0x84c386
// 00765791  5f                   pop edi
// 00765792  5e                   pop esi
// 00765793  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeOptionsPage.cpp (function ?DoDataExchange@CXTPCustomizeOptionsPage@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeOptionsPage.cpp
