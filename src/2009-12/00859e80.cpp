// from server: 100% by auto
// roc 2009-12 00859e80  unit: CXTPTabClientWnd  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00859e80
//
// 00859e80  56                   push esi
// 00859e81  8b742408             mov esi, dword ptr [esp + 8]
// 00859e85  8b4604               mov eax, dword ptr [esi + 4]
// 00859e88  57                   push edi
// 00859e89  8b3e                 mov edi, dword ptr [esi]
// 00859e8b  6a00                 push 0
// 00859e8d  50                   push eax
// 00859e8e  e8ddf6ffff           call 0x859570
// 00859e93  8b17                 mov edx, dword ptr [edi]
// 00859e95  50                   push eax
// 00859e96  8bce                 mov ecx, esi
// 00859e98  ffd2                 call edx
// 00859e9a  5f                   pop edi
// 00859e9b  5e                   pop esi
// 00859e9c  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnUpdateWorkspaceCommand@CXTPTabClientWnd@@IAEXPAVCCmdUI@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
