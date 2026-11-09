// from server: 100% by auto
// roc 2010-06 007e6ee0  unit: CRobloxTreeCtrl  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e6ee0
//
// 007e6ee0  53                   push ebx
// 007e6ee1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 007e6ee5  56                   push esi
// 007e6ee6  57                   push edi
// 007e6ee7  8bf9                 mov edi, ecx
// 007e6ee9  8bcb                 mov ecx, ebx
// 007e6eeb  e888611900           call 0x97d078
// 007e6ef0  8bcf                 mov ecx, edi
// 007e6ef2  e829f8ffff           call 0x7e6720
// 007e6ef7  8bf0                 mov esi, eax
// 007e6ef9  85f6                 test esi, esi
// 007e6efb  7419                 je 0x7e6f16
// 007e6efd  8d4900               lea ecx, [ecx]
// 007e6f00  56                   push esi
// 007e6f01  8bcb                 mov ecx, ebx
// 007e6f03  e846611900           call 0x97d04e
// 007e6f08  56                   push esi
// 007e6f09  8bcf                 mov ecx, edi
// 007e6f0b  e860f8ffff           call 0x7e6770
// 007e6f10  8bf0                 mov esi, eax
// 007e6f12  85f6                 test esi, esi
// 007e6f14  75ea                 jne 0x7e6f00
// 007e6f16  5f                   pop edi
// 007e6f17  5e                   pop esi
// 007e6f18  5b                   pop ebx
// 007e6f19  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?GetSelectedList@CXTTreeBase@@QBEXAAV?$CTypedPtrList@VCPtrList@@PAU_TREEITEM@@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
