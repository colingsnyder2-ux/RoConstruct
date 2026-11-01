// from server: 100% by auto
// roc 2011-06 00412f40  unit: VCBrowserViewExternal::?$CComObjectNoLock  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00412f40
//
// 00412f40  8b442408             mov eax, dword ptr [esp + 8]
// 00412f44  8b08                 mov ecx, dword ptr [eax]
// 00412f46  3b0dc4daa600         cmp ecx, dword ptr [0xa6dac4]
// 00412f4c  7532                 jne 0x412f80
// 00412f4e  8b5004               mov edx, dword ptr [eax + 4]
// 00412f51  3b15c8daa600         cmp edx, dword ptr [0xa6dac8]
// 00412f57  7527                 jne 0x412f80
// 00412f59  8b4808               mov ecx, dword ptr [eax + 8]
// 00412f5c  3b0dccdaa600         cmp ecx, dword ptr [0xa6dacc]
// 00412f62  751c                 jne 0x412f80
// 00412f64  8b500c               mov edx, dword ptr [eax + 0xc]
// 00412f67  3b15d0daa600         cmp edx, dword ptr [0xa6dad0]
// 00412f6d  7511                 jne 0x412f80
// 00412f6f  b801000000           mov eax, 1
// 00412f74  33c9                 xor ecx, ecx
// 00412f76  85c0                 test eax, eax
// 00412f78  0f94c1               sete cl
// 00412f7b  8bc1                 mov eax, ecx
// 00412f7d  c20800               ret 8
// 00412f80  33c0                 xor eax, eax
// 00412f82  33c9                 xor ecx, ecx
// 00412f84  85c0                 test eax, eax
// 00412f86  0f94c1               sete cl
// 00412f89  8bc1                 mov eax, ecx
// 00412f8b  c20800               ret 8
// copied from an identical function in another client (function ?f@S_func_0040b570@ns_ROCX000002@ns_ROCX0000ed@@QAEHHPBH@Z)

namespace ns_ROCX000002 {
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/IPipelined.cpp
}
