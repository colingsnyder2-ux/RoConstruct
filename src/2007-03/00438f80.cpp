// from server: 100% by auto
// roc 2007-03 00438f80  unit: seg_00430000  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00438f80
//
// 00438f80  8b442404             mov eax, dword ptr [esp + 4]
// 00438f84  56                   push esi
// 00438f85  8bf1                 mov esi, ecx
// 00438f87  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00438f8a  8908                 mov dword ptr [eax], ecx
// 00438f8c  83460cff             add dword ptr [esi + 0xc], -1
// 00438f90  894610               mov dword ptr [esi + 0x10], eax
// 00438f93  7529                 jne 0x438fbe
// 00438f95  8b4604               mov eax, dword ptr [esi + 4]
// 00438f98  57                   push edi
// 00438f99  33ff                 xor edi, edi
// 00438f9b  3bc7                 cmp eax, edi
// 00438f9d  7407                 je 0x438fa6
// 00438f9f  90                   nop 
// 00438fa0  8b00                 mov eax, dword ptr [eax]
// 00438fa2  3bc7                 cmp eax, edi
// 00438fa4  75fa                 jne 0x438fa0
// 00438fa6  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00438fa9  897e0c               mov dword ptr [esi + 0xc], edi
// 00438fac  897e10               mov dword ptr [esi + 0x10], edi
// 00438faf  897e08               mov dword ptr [esi + 8], edi
// 00438fb2  897e04               mov dword ptr [esi + 4], edi
// 00438fb5  e8505b1e00           call 0x61eb0a
// 00438fba  897e14               mov dword ptr [esi + 0x14], edi
// 00438fbd  5f                   pop edi
// 00438fbe  5e                   pop esi
// 00438fbf  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\occmgr.cpp (function ?FreeNode@?$CList@PAVIControlSiteFactory@@PAV1@@@IAEXPAUCNode@1@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/occmgr.cpp
