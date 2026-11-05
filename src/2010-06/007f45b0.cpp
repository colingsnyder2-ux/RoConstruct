// from server: 100% by auto
// roc 2010-06 007f45b0  unit: CXTPCustomizeOptionsPage  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f45b0
//
// 007f45b0  56                   push esi
// 007f45b1  57                   push edi
// 007f45b2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007f45b6  8bf1                 mov esi, ecx
// 007f45b8  8d869c000000         lea eax, [esi + 0x9c]
// 007f45be  50                   push eax
// 007f45bf  6a6a                 push 0x6a
// 007f45c1  57                   push edi
// 007f45c2  e8273dfbff           call 0x7a82ee
// 007f45c7  8d8ef0000000         lea ecx, [esi + 0xf0]
// 007f45cd  51                   push ecx
// 007f45ce  6a6a                 push 0x6a
// 007f45d0  57                   push edi
// 007f45d1  e85e8c1800           call 0x97d234
// 007f45d6  8d9688000000         lea edx, [esi + 0x88]
// 007f45dc  52                   push edx
// 007f45dd  6a64                 push 0x64
// 007f45df  57                   push edi
// 007f45e0  e8498c1800           call 0x97d22e
// 007f45e5  8d868c000000         lea eax, [esi + 0x8c]
// 007f45eb  50                   push eax
// 007f45ec  6a65                 push 0x65
// 007f45ee  57                   push edi
// 007f45ef  e83a8c1800           call 0x97d22e
// 007f45f4  8d8e90000000         lea ecx, [esi + 0x90]
// 007f45fa  51                   push ecx
// 007f45fb  6a67                 push 0x67
// 007f45fd  57                   push edi
// 007f45fe  e82b8c1800           call 0x97d22e
// 007f4603  8d9694000000         lea edx, [esi + 0x94]
// 007f4609  52                   push edx
// 007f460a  6a68                 push 0x68
// 007f460c  57                   push edi
// 007f460d  e81c8c1800           call 0x97d22e
// 007f4612  81c698000000         add esi, 0x98
// 007f4618  56                   push esi
// 007f4619  6a69                 push 0x69
// 007f461b  57                   push edi
// 007f461c  e80d8c1800           call 0x97d22e
// 007f4621  5f                   pop edi
// 007f4622  5e                   pop esi
// 007f4623  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeOptionsPage.cpp (function ?DoDataExchange@CXTPCustomizeOptionsPage@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeOptionsPage.cpp
