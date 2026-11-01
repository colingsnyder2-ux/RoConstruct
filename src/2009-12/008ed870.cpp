// from server: 100% by auto
// roc 2009-12 008ed870  unit: CXTPRibbonGroup  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ed870
//
// 008ed870  56                   push esi
// 008ed871  8b7128               mov esi, dword ptr [ecx + 0x28]
// 008ed874  33c0                 xor eax, eax
// 008ed876  33d2                 xor edx, edx
// 008ed878  85f6                 test esi, esi
// 008ed87a  7e20                 jle 0x8ed89c
// 008ed87c  53                   push ebx
// 008ed87d  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 008ed881  57                   push edi
// 008ed882  8d7eff               lea edi, [esi - 1]
// 008ed885  8b0c93               mov ecx, dword ptr [ebx + edx*4]
// 008ed888  03c1                 add eax, ecx
// 008ed88a  3bd7                 cmp edx, edi
// 008ed88c  7407                 je 0x8ed895
// 008ed88e  85c9                 test ecx, ecx
// 008ed890  7403                 je 0x8ed895
// 008ed892  83c007               add eax, 7
// 008ed895  42                   inc edx
// 008ed896  3bd6                 cmp edx, esi
// 008ed898  7ceb                 jl 0x8ed885
// 008ed89a  5f                   pop edi
// 008ed89b  5b                   pop ebx
// 008ed89c  5e                   pop esi
// 008ed89d  c20400               ret 4
// library xtp-15.2.1/Source\Ribbon\XTPRibbonGroups.cpp (function ?_CalcSmartLayoutToolBar@CXTPRibbonGroups@@IAEHPAH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonGroups.cpp
