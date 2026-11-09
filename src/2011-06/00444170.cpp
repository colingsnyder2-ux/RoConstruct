// from server: 100% by auto
// roc 2011-06 00444170  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00444170
//
// 00444170  8b442404             mov eax, dword ptr [esp + 4]
// 00444174  56                   push esi
// 00444175  8bf1                 mov esi, ecx
// 00444177  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0044417a  8908                 mov dword ptr [eax], ecx
// 0044417c  83460cff             add dword ptr [esi + 0xc], -1
// 00444180  894610               mov dword ptr [esi + 0x10], eax
// 00444183  7529                 jne 0x4441ae
// 00444185  8b4604               mov eax, dword ptr [esi + 4]
// 00444188  57                   push edi
// 00444189  33ff                 xor edi, edi
// 0044418b  3bc7                 cmp eax, edi
// 0044418d  7407                 je 0x444196
// 0044418f  90                   nop 
// 00444190  8b00                 mov eax, dword ptr [eax]
// 00444192  3bc7                 cmp eax, edi
// 00444194  75fa                 jne 0x444190
// 00444196  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00444199  897e0c               mov dword ptr [esi + 0xc], edi
// 0044419c  897e10               mov dword ptr [esi + 0x10], edi
// 0044419f  897e08               mov dword ptr [esi + 8], edi
// 004441a2  897e04               mov dword ptr [esi + 4], edi
// 004441a5  e81e6a3c00           call 0x80abc8
// 004441aa  897e14               mov dword ptr [esi + 0x14], edi
// 004441ad  5f                   pop edi
// 004441ae  5e                   pop esi
// 004441af  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcommandmanager.cpp (function ?FreeNode@?$CList@II@@IAEXPAUCNode@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcommandmanager.cpp
