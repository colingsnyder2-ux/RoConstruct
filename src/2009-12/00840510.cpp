// from server: 100% by auto
// roc 2009-12 00840510  unit: CXTPCustomizeOptionsPage  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00840510
//
// 00840510  56                   push esi
// 00840511  57                   push edi
// 00840512  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00840516  8bf1                 mov esi, ecx
// 00840518  8d869c000000         lea eax, [esi + 0x9c]
// 0084051e  50                   push eax
// 0084051f  6a6a                 push 0x6a
// 00840521  57                   push edi
// 00840522  e8873cfbff           call 0x7f41ae
// 00840527  8d8ef0000000         lea ecx, [esi + 0xf0]
// 0084052d  51                   push ecx
// 0084052e  6a6a                 push 0x6a
// 00840530  57                   push edi
// 00840531  e8c2630e00           call 0x9268f8
// 00840536  8d9688000000         lea edx, [esi + 0x88]
// 0084053c  52                   push edx
// 0084053d  6a64                 push 0x64
// 0084053f  57                   push edi
// 00840540  e8ad630e00           call 0x9268f2
// 00840545  8d868c000000         lea eax, [esi + 0x8c]
// 0084054b  50                   push eax
// 0084054c  6a65                 push 0x65
// 0084054e  57                   push edi
// 0084054f  e89e630e00           call 0x9268f2
// 00840554  8d8e90000000         lea ecx, [esi + 0x90]
// 0084055a  51                   push ecx
// 0084055b  6a67                 push 0x67
// 0084055d  57                   push edi
// 0084055e  e88f630e00           call 0x9268f2
// 00840563  8d9694000000         lea edx, [esi + 0x94]
// 00840569  52                   push edx
// 0084056a  6a68                 push 0x68
// 0084056c  57                   push edi
// 0084056d  e880630e00           call 0x9268f2
// 00840572  81c698000000         add esi, 0x98
// 00840578  56                   push esi
// 00840579  6a69                 push 0x69
// 0084057b  57                   push edi
// 0084057c  e871630e00           call 0x9268f2
// 00840581  5f                   pop edi
// 00840582  5e                   pop esi
// 00840583  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeOptionsPage.cpp (function ?DoDataExchange@CXTPCustomizeOptionsPage@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeOptionsPage.cpp
