// from server: 100% by auto
// roc 2011-06 0049c540  unit: VCContent::?$CComObject  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0049c540
//
// 0049c540  8b442408             mov eax, dword ptr [esp + 8]
// 0049c544  8b08                 mov ecx, dword ptr [eax]
// 0049c546  3b0d64daa600         cmp ecx, dword ptr [0xa6da64]
// 0049c54c  7532                 jne 0x49c580
// 0049c54e  8b5004               mov edx, dword ptr [eax + 4]
// 0049c551  3b1568daa600         cmp edx, dword ptr [0xa6da68]
// 0049c557  7527                 jne 0x49c580
// 0049c559  8b4808               mov ecx, dword ptr [eax + 8]
// 0049c55c  3b0d6cdaa600         cmp ecx, dword ptr [0xa6da6c]
// 0049c562  751c                 jne 0x49c580
// 0049c564  8b500c               mov edx, dword ptr [eax + 0xc]
// 0049c567  3b1570daa600         cmp edx, dword ptr [0xa6da70]
// 0049c56d  7511                 jne 0x49c580
// 0049c56f  b801000000           mov eax, 1
// 0049c574  33c9                 xor ecx, ecx
// 0049c576  85c0                 test eax, eax
// 0049c578  0f94c1               sete cl
// 0049c57b  8bc1                 mov eax, ecx
// 0049c57d  c20800               ret 8
// 0049c580  33c0                 xor eax, eax
// 0049c582  33c9                 xor ecx, ecx
// 0049c584  85c0                 test eax, eax
// 0049c586  0f94c1               sete cl
// 0049c589  8bc1                 mov eax, ecx
// 0049c58b  c20800               ret 8
// copied from an identical function in another client (function ?f@S_func_0040b570@ns_ROCX000002@ns_ROCX0000ed@@QAEHHPBH@Z)

namespace ns_ROCX000002 {
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/IPipelined.cpp
}
