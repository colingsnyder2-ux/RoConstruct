// from server: 100% by auto
// roc 2009-06 0077f670  unit: CXTThemeManager  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077f670
//
// 0077f670  33c0                 xor eax, eax
// 0077f672  56                   push esi
// 0077f673  8bf1                 mov esi, ecx
// 0077f675  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0077f679  c70610cd8f00         mov dword ptr [esi], 0x8fcd10
// 0077f67f  894604               mov dword ptr [esi + 4], eax
// 0077f682  894610               mov dword ptr [esi + 0x10], eax
// 0077f685  89460c               mov dword ptr [esi + 0xc], eax
// 0077f688  894614               mov dword ptr [esi + 0x14], eax
// 0077f68b  894608               mov dword ptr [esi + 8], eax
// 0077f68e  3bc8                 cmp ecx, eax
// 0077f690  7408                 je 0x77f69a
// 0077f692  51                   push ecx
// 0077f693  8bce                 mov ecx, esi
// 0077f695  e806ffffff           call 0x77f5a0
// 0077f69a  8bc6                 mov eax, esi
// 0077f69c  5e                   pop esi
// 0077f69d  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTThemeManager.cpp (function ??0CXTThemeManagerStyleHost@@IAE@PAUCRuntimeClass@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTThemeManager.cpp
