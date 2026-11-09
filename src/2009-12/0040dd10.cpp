// from server: 100% by auto
// roc 2009-12 0040dd10  unit: VCBrowserViewExternal::?$CComObjectNoLock  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0040dd10
//
// 0040dd10  8b442408             mov eax, dword ptr [esp + 8]
// 0040dd14  8b08                 mov ecx, dword ptr [eax]
// 0040dd16  3b0d38ac9a00         cmp ecx, dword ptr [0x9aac38]
// 0040dd1c  7532                 jne 0x40dd50
// 0040dd1e  8b5004               mov edx, dword ptr [eax + 4]
// 0040dd21  3b153cac9a00         cmp edx, dword ptr [0x9aac3c]
// 0040dd27  7527                 jne 0x40dd50
// 0040dd29  8b4808               mov ecx, dword ptr [eax + 8]
// 0040dd2c  3b0d40ac9a00         cmp ecx, dword ptr [0x9aac40]
// 0040dd32  751c                 jne 0x40dd50
// 0040dd34  8b500c               mov edx, dword ptr [eax + 0xc]
// 0040dd37  3b1544ac9a00         cmp edx, dword ptr [0x9aac44]
// 0040dd3d  7511                 jne 0x40dd50
// 0040dd3f  b801000000           mov eax, 1
// 0040dd44  33c9                 xor ecx, ecx
// 0040dd46  85c0                 test eax, eax
// 0040dd48  0f94c1               sete cl
// 0040dd4b  8bc1                 mov eax, ecx
// 0040dd4d  c20800               ret 8
// 0040dd50  33c0                 xor eax, eax
// 0040dd52  33c9                 xor ecx, ecx
// 0040dd54  85c0                 test eax, eax
// 0040dd56  0f94c1               sete cl
// 0040dd59  8bc1                 mov eax, ecx
// 0040dd5b  c20800               ret 8
// copied from an identical function in another client (function ?f@S_func_0040b570@ns_ROCX00001c@ns_ROCX000003@@QAEHHPBH@Z)

namespace ns_ROCX00001c {
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs gui/GUI.cpp
}
