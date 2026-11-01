// from server: 100% by auto
// roc 2009-06 00757ea0  unit: CRobloxTreeCtrl  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00757ea0
//
// 00757ea0  53                   push ebx
// 00757ea1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00757ea5  56                   push esi
// 00757ea6  57                   push edi
// 00757ea7  8bf9                 mov edi, ecx
// 00757ea9  8bcb                 mov ecx, ebx
// 00757eab  e820430f00           call 0x84c1d0
// 00757eb0  8bcf                 mov ecx, edi
// 00757eb2  e829f8ffff           call 0x7576e0
// 00757eb7  8bf0                 mov esi, eax
// 00757eb9  85f6                 test esi, esi
// 00757ebb  7419                 je 0x757ed6
// 00757ebd  8d4900               lea ecx, [ecx]
// 00757ec0  56                   push esi
// 00757ec1  8bcb                 mov ecx, ebx
// 00757ec3  e8de420f00           call 0x84c1a6
// 00757ec8  56                   push esi
// 00757ec9  8bcf                 mov ecx, edi
// 00757ecb  e860f8ffff           call 0x757730
// 00757ed0  8bf0                 mov esi, eax
// 00757ed2  85f6                 test esi, esi
// 00757ed4  75ea                 jne 0x757ec0
// 00757ed6  5f                   pop edi
// 00757ed7  5e                   pop esi
// 00757ed8  5b                   pop ebx
// 00757ed9  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetSelectedList@CXTPTreeBase@@QBEXAAV?$CTypedPtrList@VCPtrList@@PAU_TREEITEM@@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
