// from server: 100% by auto
// roc 2011-06 004070b0  unit: VCApp::?$CComObject  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004070b0
//
// 004070b0  8b442408             mov eax, dword ptr [esp + 8]
// 004070b4  8b08                 mov ecx, dword ptr [eax]
// 004070b6  3b0db4daa600         cmp ecx, dword ptr [0xa6dab4]
// 004070bc  7532                 jne 0x4070f0
// 004070be  8b5004               mov edx, dword ptr [eax + 4]
// 004070c1  3b15b8daa600         cmp edx, dword ptr [0xa6dab8]
// 004070c7  7527                 jne 0x4070f0
// 004070c9  8b4808               mov ecx, dword ptr [eax + 8]
// 004070cc  3b0dbcdaa600         cmp ecx, dword ptr [0xa6dabc]
// 004070d2  751c                 jne 0x4070f0
// 004070d4  8b500c               mov edx, dword ptr [eax + 0xc]
// 004070d7  3b15c0daa600         cmp edx, dword ptr [0xa6dac0]
// 004070dd  7511                 jne 0x4070f0
// 004070df  b801000000           mov eax, 1
// 004070e4  33c9                 xor ecx, ecx
// 004070e6  85c0                 test eax, eax
// 004070e8  0f94c1               sete cl
// 004070eb  8bc1                 mov eax, ecx
// 004070ed  c20800               ret 8
// 004070f0  33c0                 xor eax, eax
// 004070f2  33c9                 xor ecx, ecx
// 004070f4  85c0                 test eax, eax
// 004070f6  0f94c1               sete cl
// 004070f9  8bc1                 mov eax, ecx
// 004070fb  c20800               ret 8
// copied from an identical function in another client (function ?f@S_func_0040b570@ns_ROCX000002@ns_ROCX0000ed@@QAEHHPBH@Z)

namespace ns_ROCX000002 {
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/IPipelined.cpp
}
