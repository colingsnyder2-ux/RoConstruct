// from server: 100% by auto
// roc 2009-06 0077edc0  unit: CXTPTabClientWnd  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077edc0
//
// 0077edc0  56                   push esi
// 0077edc1  8b742408             mov esi, dword ptr [esp + 8]
// 0077edc5  8b4604               mov eax, dword ptr [esi + 4]
// 0077edc8  57                   push edi
// 0077edc9  8b3e                 mov edi, dword ptr [esi]
// 0077edcb  6a00                 push 0
// 0077edcd  50                   push eax
// 0077edce  e8ddf6ffff           call 0x77e4b0
// 0077edd3  8b17                 mov edx, dword ptr [edi]
// 0077edd5  50                   push eax
// 0077edd6  8bce                 mov ecx, esi
// 0077edd8  ffd2                 call edx
// 0077edda  5f                   pop edi
// 0077eddb  5e                   pop esi
// 0077eddc  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnUpdateWorkspaceCommand@CXTPTabClientWnd@@IAEXPAVCCmdUI@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
