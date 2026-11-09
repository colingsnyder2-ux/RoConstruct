// from server: 100% by auto
// roc 2007-08 00439020  unit: CXTPPropertyGridItem  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00439020
//
// 00439020  8b442404             mov eax, dword ptr [esp + 4]
// 00439024  56                   push esi
// 00439025  8bf1                 mov esi, ecx
// 00439027  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0043902a  8908                 mov dword ptr [eax], ecx
// 0043902c  83460cff             add dword ptr [esi + 0xc], -1
// 00439030  894610               mov dword ptr [esi + 0x10], eax
// 00439033  7529                 jne 0x43905e
// 00439035  8b4604               mov eax, dword ptr [esi + 4]
// 00439038  57                   push edi
// 00439039  33ff                 xor edi, edi
// 0043903b  3bc7                 cmp eax, edi
// 0043903d  7407                 je 0x439046
// 0043903f  90                   nop 
// 00439040  8b00                 mov eax, dword ptr [eax]
// 00439042  3bc7                 cmp eax, edi
// 00439044  75fa                 jne 0x439040
// 00439046  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00439049  897e0c               mov dword ptr [esi + 0xc], edi
// 0043904c  897e10               mov dword ptr [esi + 0x10], edi
// 0043904f  897e08               mov dword ptr [esi + 8], edi
// 00439052  897e04               mov dword ptr [esi + 4], edi
// 00439055  e822761f00           call 0x63067c
// 0043905a  897e14               mov dword ptr [esi + 0x14], edi
// 0043905d  5f                   pop edi
// 0043905e  5e                   pop esi
// 0043905f  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\occmgr.cpp (function ?FreeNode@?$CList@PAVIControlSiteFactory@@PAV1@@@IAEXPAUCNode@1@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/occmgr.cpp
