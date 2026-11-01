// from server: 100% by auto
// roc 2009-12 004335b0  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004335b0
//
// 004335b0  8b442404             mov eax, dword ptr [esp + 4]
// 004335b4  56                   push esi
// 004335b5  8bf1                 mov esi, ecx
// 004335b7  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004335ba  8908                 mov dword ptr [eax], ecx
// 004335bc  83460cff             add dword ptr [esi + 0xc], -1
// 004335c0  894610               mov dword ptr [esi + 0x10], eax
// 004335c3  7529                 jne 0x4335ee
// 004335c5  8b4604               mov eax, dword ptr [esi + 4]
// 004335c8  57                   push edi
// 004335c9  33ff                 xor edi, edi
// 004335cb  3bc7                 cmp eax, edi
// 004335cd  7407                 je 0x4335d6
// 004335cf  90                   nop 
// 004335d0  8b00                 mov eax, dword ptr [eax]
// 004335d2  3bc7                 cmp eax, edi
// 004335d4  75fa                 jne 0x4335d0
// 004335d6  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004335d9  897e0c               mov dword ptr [esi + 0xc], edi
// 004335dc  897e10               mov dword ptr [esi + 0x10], edi
// 004335df  897e08               mov dword ptr [esi + 8], edi
// 004335e2  897e04               mov dword ptr [esi + 4], edi
// 004335e5  e8da0d3c00           call 0x7f43c4
// 004335ea  897e14               mov dword ptr [esi + 0x14], edi
// 004335ed  5f                   pop edi
// 004335ee  5e                   pop esi
// 004335ef  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\occmgr.cpp (function ?FreeNode@?$CList@PAVIControlSiteFactory@@PAV1@@@IAEXPAUCNode@1@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/occmgr.cpp
