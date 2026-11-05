// from server: 100% by auto
// roc 2007-08 006d2910  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d2910
//
// 006d2910  56                   push esi
// 006d2911  57                   push edi
// 006d2912  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006d2916  85ff                 test edi, edi
// 006d2918  8bf1                 mov esi, ecx
// 006d291a  7d05                 jge 0x6d2921
// 006d291c  e8ffd5f5ff           call 0x62ff20
// 006d2921  3b7e08               cmp edi, dword ptr [esi + 8]
// 006d2924  7c0b                 jl 0x6d2931
// 006d2926  6aff                 push -1
// 006d2928  8d4701               lea eax, [edi + 1]
// 006d292b  50                   push eax
// 006d292c  e87fd10200           call 0x6ffab0
// 006d2931  8b4e04               mov ecx, dword ptr [esi + 4]
// 006d2934  8b542410             mov edx, dword ptr [esp + 0x10]
// 006d2938  8914b9               mov dword ptr [ecx + edi*4], edx
// 006d293b  5f                   pop edi
// 006d293c  5e                   pop esi
// 006d293d  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\array_d.cpp (function ?SetAtGrow@CDWordArray@@QAEXHK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_d.cpp
