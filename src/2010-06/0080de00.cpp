// from server: 100% by auto
// roc 2010-06 0080de00  unit: CXTPTabClientWnd  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080de00
//
// 0080de00  56                   push esi
// 0080de01  8b742408             mov esi, dword ptr [esp + 8]
// 0080de05  8b4604               mov eax, dword ptr [esi + 4]
// 0080de08  57                   push edi
// 0080de09  8b3e                 mov edi, dword ptr [esi]
// 0080de0b  6a00                 push 0
// 0080de0d  50                   push eax
// 0080de0e  e8ddf6ffff           call 0x80d4f0
// 0080de13  8b17                 mov edx, dword ptr [edi]
// 0080de15  50                   push eax
// 0080de16  8bce                 mov ecx, esi
// 0080de18  ffd2                 call edx
// 0080de1a  5f                   pop edi
// 0080de1b  5e                   pop esi
// 0080de1c  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnUpdateWorkspaceCommand@CXTPTabClientWnd@@IAEXPAVCCmdUI@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
