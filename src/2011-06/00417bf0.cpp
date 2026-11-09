// from server: 100% by auto
// roc 2011-06 00417bf0  unit: VCRbxObject::?$CComObjectNoLock  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00417bf0
//
// 00417bf0  8b442408             mov eax, dword ptr [esp + 8]
// 00417bf4  8b08                 mov ecx, dword ptr [eax]
// 00417bf6  3b0d84daa600         cmp ecx, dword ptr [0xa6da84]
// 00417bfc  7532                 jne 0x417c30
// 00417bfe  8b5004               mov edx, dword ptr [eax + 4]
// 00417c01  3b1588daa600         cmp edx, dword ptr [0xa6da88]
// 00417c07  7527                 jne 0x417c30
// 00417c09  8b4808               mov ecx, dword ptr [eax + 8]
// 00417c0c  3b0d8cdaa600         cmp ecx, dword ptr [0xa6da8c]
// 00417c12  751c                 jne 0x417c30
// 00417c14  8b500c               mov edx, dword ptr [eax + 0xc]
// 00417c17  3b1590daa600         cmp edx, dword ptr [0xa6da90]
// 00417c1d  7511                 jne 0x417c30
// 00417c1f  b801000000           mov eax, 1
// 00417c24  33c9                 xor ecx, ecx
// 00417c26  85c0                 test eax, eax
// 00417c28  0f94c1               sete cl
// 00417c2b  8bc1                 mov eax, ecx
// 00417c2d  c20800               ret 8
// 00417c30  33c0                 xor eax, eax
// 00417c32  33c9                 xor ecx, ecx
// 00417c34  85c0                 test eax, eax
// 00417c36  0f94c1               sete cl
// 00417c39  8bc1                 mov eax, ecx
// 00417c3b  c20800               ret 8
// copied from an identical function in another client (function ?f@S_func_0040b570@ns_ROCX000002@ns_ROCX0000ed@@QAEHHPBH@Z)

namespace ns_ROCX000002 {
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/IPipelined.cpp
}
