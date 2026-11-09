// from server: 100% by auto
// roc 2010-06 00808fb0  unit: CXTPTabClientWnd  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00808fb0
//
// 00808fb0  56                   push esi
// 00808fb1  8bf1                 mov esi, ecx
// 00808fb3  8b8e98000000         mov ecx, dword ptr [esi + 0x98]
// 00808fb9  57                   push edi
// 00808fba  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00808fbe  3bcf                 cmp ecx, edi
// 00808fc0  741a                 je 0x808fdc
// 00808fc2  85c9                 test ecx, ecx
// 00808fc4  7407                 je 0x808fcd
// 00808fc6  6a00                 push 0
// 00808fc8  e863940700           call 0x882430
// 00808fcd  6a01                 push 1
// 00808fcf  8bcf                 mov ecx, edi
// 00808fd1  89be98000000         mov dword ptr [esi + 0x98], edi
// 00808fd7  e854940700           call 0x882430
// 00808fdc  5f                   pop edi
// 00808fdd  5e                   pop esi
// 00808fde  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?SetActiveWorkspace@CXTPTabClientWnd@@IAEXPAVCWorkspace@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
