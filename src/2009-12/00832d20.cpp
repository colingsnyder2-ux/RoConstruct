// from server: 100% by auto
// roc 2009-12 00832d20  unit: CRobloxTreeCtrl  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00832d20
//
// 00832d20  53                   push ebx
// 00832d21  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00832d25  56                   push esi
// 00832d26  57                   push edi
// 00832d27  8bf9                 mov edi, ecx
// 00832d29  8bcb                 mov ecx, ebx
// 00832d2b  e80c3a0f00           call 0x92673c
// 00832d30  8bcf                 mov ecx, edi
// 00832d32  e829f8ffff           call 0x832560
// 00832d37  8bf0                 mov esi, eax
// 00832d39  85f6                 test esi, esi
// 00832d3b  7419                 je 0x832d56
// 00832d3d  8d4900               lea ecx, [ecx]
// 00832d40  56                   push esi
// 00832d41  8bcb                 mov ecx, ebx
// 00832d43  e8ca390f00           call 0x926712
// 00832d48  56                   push esi
// 00832d49  8bcf                 mov ecx, edi
// 00832d4b  e860f8ffff           call 0x8325b0
// 00832d50  8bf0                 mov esi, eax
// 00832d52  85f6                 test esi, esi
// 00832d54  75ea                 jne 0x832d40
// 00832d56  5f                   pop edi
// 00832d57  5e                   pop esi
// 00832d58  5b                   pop ebx
// 00832d59  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetSelectedList@CXTPTreeBase@@QBEXAAV?$CTypedPtrList@VCPtrList@@PAU_TREEITEM@@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
