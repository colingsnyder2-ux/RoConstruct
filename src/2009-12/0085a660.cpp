// from server: 100% by auto
// roc 2009-12 0085a660  unit: CXTThemeManager  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085a660
//
// 0085a660  56                   push esi
// 0085a661  57                   push edi
// 0085a662  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0085a666  8bf1                 mov esi, ecx
// 0085a668  85ff                 test edi, edi
// 0085a66a  742c                 je 0x85a698
// 0085a66c  8b4610               mov eax, dword ptr [esi + 0x10]
// 0085a66f  85c0                 test eax, eax
// 0085a671  7409                 je 0x85a67c
// 0085a673  56                   push esi
// 0085a674  8d4808               lea ecx, [eax + 8]
// 0085a677  e862c40c00           call 0x926ade
// 0085a67c  57                   push edi
// 0085a67d  897e08               mov dword ptr [esi + 8], edi
// 0085a680  e8fbfeffff           call 0x85a580
// 0085a685  8bc8                 mov ecx, eax
// 0085a687  e854fcffff           call 0x85a2e0
// 0085a68c  56                   push esi
// 0085a68d  8d4808               lea ecx, [eax + 8]
// 0085a690  894610               mov dword ptr [esi + 0x10], eax
// 0085a693  e840c40c00           call 0x926ad8
// 0085a698  5f                   pop edi
// 0085a699  5e                   pop esi
// 0085a69a  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTThemeManager.cpp (function ?InitStyleHost@CXTThemeManagerStyleHost@@IAEXPAUCRuntimeClass@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTThemeManager.cpp
