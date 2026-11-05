// from server: 100% by auto
// roc 2009-12 00840b10  unit: CXTPCustomizeCommandsPage  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00840b10
//
// 00840b10  56                   push esi
// 00840b11  57                   push edi
// 00840b12  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00840b16  8bf1                 mov esi, ecx
// 00840b18  8d8688000000         lea eax, [esi + 0x88]
// 00840b1e  50                   push eax
// 00840b1f  6a65                 push 0x65
// 00840b21  57                   push edi
// 00840b22  e88736fbff           call 0x7f41ae
// 00840b27  81c6e4000000         add esi, 0xe4
// 00840b2d  56                   push esi
// 00840b2e  6a64                 push 0x64
// 00840b30  57                   push edi
// 00840b31  e87836fbff           call 0x7f41ae
// 00840b36  5f                   pop edi
// 00840b37  5e                   pop esi
// 00840b38  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeCommandsPage.cpp (function ?DoDataExchange@CXTPCustomizeCommandsPage@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeCommandsPage.cpp
