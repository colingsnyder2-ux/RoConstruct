// from server: 100% by auto
// roc 2007-03 006e17c0  unit: seg_006e0000  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e17c0
//
// 006e17c0  56                   push esi
// 006e17c1  8bf1                 mov esi, ecx
// 006e17c3  837e1000             cmp dword ptr [esi + 0x10], 0
// 006e17c7  7539                 jne 0x6e1802
// 006e17c9  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e17cc  6a0c                 push 0xc
// 006e17ce  50                   push eax
// 006e17cf  8d4e14               lea ecx, [esi + 0x14]
// 006e17d2  51                   push ecx
// 006e17d3  e820930500           call 0x73aaf8
// 006e17d8  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006e17db  83c004               add eax, 4
// 006e17de  8d1449               lea edx, [ecx + ecx*2]
// 006e17e1  83c1ff               add ecx, -1
// 006e17e4  8d4490f4             lea eax, [eax + edx*4 - 0xc]
// 006e17e8  7818                 js 0x6e1802
// 006e17ea  8d9b00000000         lea ebx, [ebx]
// 006e17f0  8b5610               mov edx, dword ptr [esi + 0x10]
// 006e17f3  8910                 mov dword ptr [eax], edx
// 006e17f5  894610               mov dword ptr [esi + 0x10], eax
// 006e17f8  83e901               sub ecx, 1
// 006e17fb  83e80c               sub eax, 0xc
// 006e17fe  85c9                 test ecx, ecx
// 006e1800  7dee                 jge 0x6e17f0
// 006e1802  8b4610               mov eax, dword ptr [esi + 0x10]
// 006e1805  85c0                 test eax, eax
// 006e1807  7505                 jne 0x6e180e
// 006e1809  e8a0cbf3ff           call 0x61e3ae
// 006e180e  8b08                 mov ecx, dword ptr [eax]
// 006e1810  8b542408             mov edx, dword ptr [esp + 8]
// 006e1814  894e10               mov dword ptr [esi + 0x10], ecx
// 006e1817  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006e181b  895004               mov dword ptr [eax + 4], edx
// 006e181e  8908                 mov dword ptr [eax], ecx
// 006e1820  83460c01             add dword ptr [esi + 0xc], 1
// 006e1824  5e                   pop esi
// 006e1825  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\occmgr.cpp (function ?NewNode@?$CList@PAVIControlSiteFactory@@PAV1@@@IAEPAUCNode@1@PAU21@0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/occmgr.cpp
