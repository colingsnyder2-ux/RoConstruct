// from server: 100% by auto
// roc 2007-03 00672520  unit: seg_00670000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00672520
//
// 00672520  56                   push esi
// 00672521  8b742408             mov esi, dword ptr [esp + 8]
// 00672525  8b4604               mov eax, dword ptr [esi + 4]
// 00672528  57                   push edi
// 00672529  8b3e                 mov edi, dword ptr [esi]
// 0067252b  6a00                 push 0
// 0067252d  50                   push eax
// 0067252e  e80df7ffff           call 0x671c40
// 00672533  8b17                 mov edx, dword ptr [edi]
// 00672535  50                   push eax
// 00672536  8bce                 mov ecx, esi
// 00672538  ffd2                 call edx
// 0067253a  5f                   pop edi
// 0067253b  5e                   pop esi
// 0067253c  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnUpdateWorkspaceCommand@CXTPTabClientWnd@@IAEXPAVCCmdUI@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
