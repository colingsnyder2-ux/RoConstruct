// from server: 100% by auto
// roc 2010-06 008a1b10  unit: CXTPRibbonGroup  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a1b10
//
// 008a1b10  56                   push esi
// 008a1b11  8b7128               mov esi, dword ptr [ecx + 0x28]
// 008a1b14  33c0                 xor eax, eax
// 008a1b16  33d2                 xor edx, edx
// 008a1b18  85f6                 test esi, esi
// 008a1b1a  7e20                 jle 0x8a1b3c
// 008a1b1c  53                   push ebx
// 008a1b1d  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 008a1b21  57                   push edi
// 008a1b22  8d7eff               lea edi, [esi - 1]
// 008a1b25  8b0c93               mov ecx, dword ptr [ebx + edx*4]
// 008a1b28  03c1                 add eax, ecx
// 008a1b2a  3bd7                 cmp edx, edi
// 008a1b2c  7407                 je 0x8a1b35
// 008a1b2e  85c9                 test ecx, ecx
// 008a1b30  7403                 je 0x8a1b35
// 008a1b32  83c007               add eax, 7
// 008a1b35  42                   inc edx
// 008a1b36  3bd6                 cmp edx, esi
// 008a1b38  7ceb                 jl 0x8a1b25
// 008a1b3a  5f                   pop edi
// 008a1b3b  5b                   pop ebx
// 008a1b3c  5e                   pop esi
// 008a1b3d  c20400               ret 4
// library xtp-13.2.1/Source\Ribbon\XTPRibbonGroups.cpp (function ?_CalcSmartLayoutToolBar@CXTPRibbonGroups@@IAEHPAH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonGroups.cpp
