// from server: 100% by auto
// roc 2009-06 0077f5a0  unit: CXTThemeManager  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077f5a0
//
// 0077f5a0  56                   push esi
// 0077f5a1  57                   push edi
// 0077f5a2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0077f5a6  8bf1                 mov esi, ecx
// 0077f5a8  85ff                 test edi, edi
// 0077f5aa  742c                 je 0x77f5d8
// 0077f5ac  8b4610               mov eax, dword ptr [esi + 0x10]
// 0077f5af  85c0                 test eax, eax
// 0077f5b1  7409                 je 0x77f5bc
// 0077f5b3  56                   push esi
// 0077f5b4  8d4808               lea ecx, [eax + 8]
// 0077f5b7  e8b6cf0c00           call 0x84c572
// 0077f5bc  57                   push edi
// 0077f5bd  897e08               mov dword ptr [esi + 8], edi
// 0077f5c0  e8fbfeffff           call 0x77f4c0
// 0077f5c5  8bc8                 mov ecx, eax
// 0077f5c7  e854fcffff           call 0x77f220
// 0077f5cc  56                   push esi
// 0077f5cd  8d4808               lea ecx, [eax + 8]
// 0077f5d0  894610               mov dword ptr [esi + 0x10], eax
// 0077f5d3  e894cf0c00           call 0x84c56c
// 0077f5d8  5f                   pop edi
// 0077f5d9  5e                   pop esi
// 0077f5da  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTThemeManager.cpp (function ?InitStyleHost@CXTThemeManagerStyleHost@@IAEXPAUCRuntimeClass@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTThemeManager.cpp
