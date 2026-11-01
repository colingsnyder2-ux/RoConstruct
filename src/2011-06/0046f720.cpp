// from server: 100% by auto
// roc 2011-06 0046f720  unit: VCWorkspace::?$CComObject  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0046f720
//
// 0046f720  8b442408             mov eax, dword ptr [esp + 8]
// 0046f724  8b08                 mov ecx, dword ptr [eax]
// 0046f726  3b0da4daa600         cmp ecx, dword ptr [0xa6daa4]
// 0046f72c  7532                 jne 0x46f760
// 0046f72e  8b5004               mov edx, dword ptr [eax + 4]
// 0046f731  3b15a8daa600         cmp edx, dword ptr [0xa6daa8]
// 0046f737  7527                 jne 0x46f760
// 0046f739  8b4808               mov ecx, dword ptr [eax + 8]
// 0046f73c  3b0dacdaa600         cmp ecx, dword ptr [0xa6daac]
// 0046f742  751c                 jne 0x46f760
// 0046f744  8b500c               mov edx, dword ptr [eax + 0xc]
// 0046f747  3b15b0daa600         cmp edx, dword ptr [0xa6dab0]
// 0046f74d  7511                 jne 0x46f760
// 0046f74f  b801000000           mov eax, 1
// 0046f754  33c9                 xor ecx, ecx
// 0046f756  85c0                 test eax, eax
// 0046f758  0f94c1               sete cl
// 0046f75b  8bc1                 mov eax, ecx
// 0046f75d  c20800               ret 8
// 0046f760  33c0                 xor eax, eax
// 0046f762  33c9                 xor ecx, ecx
// 0046f764  85c0                 test eax, eax
// 0046f766  0f94c1               sete cl
// 0046f769  8bc1                 mov eax, ecx
// 0046f76b  c20800               ret 8
// copied from an identical function in another client (function ?f@S_func_0040b570@ns_ROCX000002@ns_ROCX0000ed@@QAEHHPBH@Z)

namespace ns_ROCX000002 {
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/IPipelined.cpp
}
