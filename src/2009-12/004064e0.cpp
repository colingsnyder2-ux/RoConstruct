// from server: 100% by auto
// roc 2009-12 004064e0  unit: VCApp::?$CComObject  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004064e0
//
// 004064e0  8b442408             mov eax, dword ptr [esp + 8]
// 004064e4  8b08                 mov ecx, dword ptr [eax]
// 004064e6  3b0d28ac9a00         cmp ecx, dword ptr [0x9aac28]
// 004064ec  7532                 jne 0x406520
// 004064ee  8b5004               mov edx, dword ptr [eax + 4]
// 004064f1  3b152cac9a00         cmp edx, dword ptr [0x9aac2c]
// 004064f7  7527                 jne 0x406520
// 004064f9  8b4808               mov ecx, dword ptr [eax + 8]
// 004064fc  3b0d30ac9a00         cmp ecx, dword ptr [0x9aac30]
// 00406502  751c                 jne 0x406520
// 00406504  8b500c               mov edx, dword ptr [eax + 0xc]
// 00406507  3b1534ac9a00         cmp edx, dword ptr [0x9aac34]
// 0040650d  7511                 jne 0x406520
// 0040650f  b801000000           mov eax, 1
// 00406514  33c9                 xor ecx, ecx
// 00406516  85c0                 test eax, eax
// 00406518  0f94c1               sete cl
// 0040651b  8bc1                 mov eax, ecx
// 0040651d  c20800               ret 8
// 00406520  33c0                 xor eax, eax
// 00406522  33c9                 xor ecx, ecx
// 00406524  85c0                 test eax, eax
// 00406526  0f94c1               sete cl
// 00406529  8bc1                 mov eax, ecx
// 0040652b  c20800               ret 8
// copied from an identical function in another client (function ?f@S_func_0040b570@ns_ROCX00001c@ns_ROCX000003@@QAEHHPBH@Z)

namespace ns_ROCX00001c {
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs gui/GUI.cpp
}
