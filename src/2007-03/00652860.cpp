// from server: 100% by auto
// roc 2007-03 00652860  unit: seg_00650000  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00652860
//
// 00652860  53                   push ebx
// 00652861  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00652865  56                   push esi
// 00652866  57                   push edi
// 00652867  8bf9                 mov edi, ecx
// 00652869  8bcb                 mov ecx, ebx
// 0065286b  e84c850e00           call 0x73adbc
// 00652870  8bcf                 mov ecx, edi
// 00652872  e839f8ffff           call 0x6520b0
// 00652877  8bf0                 mov esi, eax
// 00652879  85f6                 test esi, esi
// 0065287b  7419                 je 0x652896
// 0065287d  8d4900               lea ecx, [ecx]
// 00652880  56                   push esi
// 00652881  8bcb                 mov ecx, ebx
// 00652883  e80a850e00           call 0x73ad92
// 00652888  56                   push esi
// 00652889  8bcf                 mov ecx, edi
// 0065288b  e870f8ffff           call 0x652100
// 00652890  8bf0                 mov esi, eax
// 00652892  85f6                 test esi, esi
// 00652894  75ea                 jne 0x652880
// 00652896  5f                   pop edi
// 00652897  5e                   pop esi
// 00652898  5b                   pop ebx
// 00652899  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetSelectedList@CXTPTreeBase@@QBEXAAV?$CTypedPtrList@VCPtrList@@PAU_TREEITEM@@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
