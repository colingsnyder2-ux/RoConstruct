// from server: 100% by auto
// roc 2010-06 00874250  unit: CXTPDockingPaneContext  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00874250
//
// 00874250  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00874254  85c9                 test ecx, ecx
// 00874256  7408                 je 0x874260
// 00874258  8b442408             mov eax, dword ptr [esp + 8]
// 0087425c  85c0                 test eax, eax
// 0087425e  7505                 jne 0x874265
// 00874260  e8e739f3ff           call 0x7a7c4c
// 00874265  8b09                 mov ecx, dword ptr [ecx]
// 00874267  33d2                 xor edx, edx
// 00874269  3b08                 cmp ecx, dword ptr [eax]
// 0087426b  0f94c2               sete dl
// 0087426e  8bc2                 mov eax, edx
// 00874270  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ??$CompareElements@II@@YGHPBI0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
