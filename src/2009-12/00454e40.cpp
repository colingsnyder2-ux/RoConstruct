// from server: 100% by auto
// roc 2009-12 00454e40  unit: VCWorkspace::?$CComObject  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00454e40
//
// 00454e40  8b442408             mov eax, dword ptr [esp + 8]
// 00454e44  8b08                 mov ecx, dword ptr [eax]
// 00454e46  3b0d18ac9a00         cmp ecx, dword ptr [0x9aac18]
// 00454e4c  7532                 jne 0x454e80
// 00454e4e  8b5004               mov edx, dword ptr [eax + 4]
// 00454e51  3b151cac9a00         cmp edx, dword ptr [0x9aac1c]
// 00454e57  7527                 jne 0x454e80
// 00454e59  8b4808               mov ecx, dword ptr [eax + 8]
// 00454e5c  3b0d20ac9a00         cmp ecx, dword ptr [0x9aac20]
// 00454e62  751c                 jne 0x454e80
// 00454e64  8b500c               mov edx, dword ptr [eax + 0xc]
// 00454e67  3b1524ac9a00         cmp edx, dword ptr [0x9aac24]
// 00454e6d  7511                 jne 0x454e80
// 00454e6f  b801000000           mov eax, 1
// 00454e74  33c9                 xor ecx, ecx
// 00454e76  85c0                 test eax, eax
// 00454e78  0f94c1               sete cl
// 00454e7b  8bc1                 mov eax, ecx
// 00454e7d  c20800               ret 8
// 00454e80  33c0                 xor eax, eax
// 00454e82  33c9                 xor ecx, ecx
// 00454e84  85c0                 test eax, eax
// 00454e86  0f94c1               sete cl
// 00454e89  8bc1                 mov eax, ecx
// 00454e8b  c20800               ret 8
// copied from an identical function in another client (function ?f@S_func_0040b570@ns_ROCX00001c@ns_ROCX000003@@QAEHHPBH@Z)

namespace ns_ROCX00001c {
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs gui/GUI.cpp
}
