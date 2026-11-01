// from server: 100% by auto
// roc 2009-06 0077a1b0  unit: CXTPTabClientWnd  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077a1b0
//
// 0077a1b0  56                   push esi
// 0077a1b1  8bf1                 mov esi, ecx
// 0077a1b3  8b8e98000000         mov ecx, dword ptr [esi + 0x98]
// 0077a1b9  57                   push edi
// 0077a1ba  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0077a1be  3bcf                 cmp ecx, edi
// 0077a1c0  741a                 je 0x77a1dc
// 0077a1c2  85c9                 test ecx, ecx
// 0077a1c4  7407                 je 0x77a1cd
// 0077a1c6  6a00                 push 0
// 0077a1c8  e8d3940700           call 0x7f36a0
// 0077a1cd  6a01                 push 1
// 0077a1cf  8bcf                 mov ecx, edi
// 0077a1d1  89be98000000         mov dword ptr [esi + 0x98], edi
// 0077a1d7  e8c4940700           call 0x7f36a0
// 0077a1dc  5f                   pop edi
// 0077a1dd  5e                   pop esi
// 0077a1de  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?SetActiveWorkspace@CXTPTabClientWnd@@IAEXPAVCWorkspace@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
