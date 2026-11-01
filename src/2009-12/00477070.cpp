// from server: 100% by auto
// roc 2009-12 00477070  unit: VCContent::?$CComObject  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00477070
//
// 00477070  8b442408             mov eax, dword ptr [esp + 8]
// 00477074  8b08                 mov ecx, dword ptr [eax]
// 00477076  3b0df8ab9a00         cmp ecx, dword ptr [0x9aabf8]
// 0047707c  7532                 jne 0x4770b0
// 0047707e  8b5004               mov edx, dword ptr [eax + 4]
// 00477081  3b15fcab9a00         cmp edx, dword ptr [0x9aabfc]
// 00477087  7527                 jne 0x4770b0
// 00477089  8b4808               mov ecx, dword ptr [eax + 8]
// 0047708c  3b0d00ac9a00         cmp ecx, dword ptr [0x9aac00]
// 00477092  751c                 jne 0x4770b0
// 00477094  8b500c               mov edx, dword ptr [eax + 0xc]
// 00477097  3b1504ac9a00         cmp edx, dword ptr [0x9aac04]
// 0047709d  7511                 jne 0x4770b0
// 0047709f  b801000000           mov eax, 1
// 004770a4  33c9                 xor ecx, ecx
// 004770a6  85c0                 test eax, eax
// 004770a8  0f94c1               sete cl
// 004770ab  8bc1                 mov eax, ecx
// 004770ad  c20800               ret 8
// 004770b0  33c0                 xor eax, eax
// 004770b2  33c9                 xor ecx, ecx
// 004770b4  85c0                 test eax, eax
// 004770b6  0f94c1               sete cl
// 004770b9  8bc1                 mov eax, ecx
// 004770bb  c20800               ret 8
// copied from an identical function in another client (function ?f@S_func_0040b570@ns_ROCX00001c@ns_ROCX000003@@QAEHHPBH@Z)

namespace ns_ROCX00001c {
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs gui/GUI.cpp
}
