// from server: 100% by auto
// roc 2010-06 007f4ba0  unit: CXTPCustomizeCommandsPage  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f4ba0
//
// 007f4ba0  56                   push esi
// 007f4ba1  57                   push edi
// 007f4ba2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007f4ba6  8bf1                 mov esi, ecx
// 007f4ba8  8d8688000000         lea eax, [esi + 0x88]
// 007f4bae  50                   push eax
// 007f4baf  6a65                 push 0x65
// 007f4bb1  57                   push edi
// 007f4bb2  e83737fbff           call 0x7a82ee
// 007f4bb7  81c6e4000000         add esi, 0xe4
// 007f4bbd  56                   push esi
// 007f4bbe  6a64                 push 0x64
// 007f4bc0  57                   push edi
// 007f4bc1  e82837fbff           call 0x7a82ee
// 007f4bc6  5f                   pop edi
// 007f4bc7  5e                   pop esi
// 007f4bc8  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeCommandsPage.cpp (function ?DoDataExchange@CXTPCustomizeCommandsPage@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeCommandsPage.cpp
