// from server: 100% by auto
// roc 2009-12 00854f30  unit: CXTPTabClientWnd  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00854f30
//
// 00854f30  56                   push esi
// 00854f31  8bf1                 mov esi, ecx
// 00854f33  8b8e98000000         mov ecx, dword ptr [esi + 0x98]
// 00854f39  57                   push edi
// 00854f3a  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00854f3e  3bcf                 cmp ecx, edi
// 00854f40  741a                 je 0x854f5c
// 00854f42  85c9                 test ecx, ecx
// 00854f44  7407                 je 0x854f4d
// 00854f46  6a00                 push 0
// 00854f48  e803930700           call 0x8ce250
// 00854f4d  6a01                 push 1
// 00854f4f  8bcf                 mov ecx, edi
// 00854f51  89be98000000         mov dword ptr [esi + 0x98], edi
// 00854f57  e8f4920700           call 0x8ce250
// 00854f5c  5f                   pop edi
// 00854f5d  5e                   pop esi
// 00854f5e  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?SetActiveWorkspace@CXTPTabClientWnd@@IAEXPAVCWorkspace@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
