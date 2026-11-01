// from server: 100% by auto
// roc 2009-06 00811d20  unit: CXTPRibbonGroup  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00811d20
//
// 00811d20  56                   push esi
// 00811d21  8b7128               mov esi, dword ptr [ecx + 0x28]
// 00811d24  33c0                 xor eax, eax
// 00811d26  33d2                 xor edx, edx
// 00811d28  85f6                 test esi, esi
// 00811d2a  7e20                 jle 0x811d4c
// 00811d2c  53                   push ebx
// 00811d2d  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00811d31  57                   push edi
// 00811d32  8d7eff               lea edi, [esi - 1]
// 00811d35  8b0c93               mov ecx, dword ptr [ebx + edx*4]
// 00811d38  03c1                 add eax, ecx
// 00811d3a  3bd7                 cmp edx, edi
// 00811d3c  7407                 je 0x811d45
// 00811d3e  85c9                 test ecx, ecx
// 00811d40  7403                 je 0x811d45
// 00811d42  83c007               add eax, 7
// 00811d45  42                   inc edx
// 00811d46  3bd6                 cmp edx, esi
// 00811d48  7ceb                 jl 0x811d35
// 00811d4a  5f                   pop edi
// 00811d4b  5b                   pop ebx
// 00811d4c  5e                   pop esi
// 00811d4d  c20400               ret 4
// library xtp-15.2.1/Source\Ribbon\XTPRibbonGroups.cpp (function ?_CalcSmartLayoutToolBar@CXTPRibbonGroups@@IAEHPAH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonGroups.cpp
