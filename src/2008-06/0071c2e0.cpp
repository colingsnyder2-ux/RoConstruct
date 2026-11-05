// from server: 100% by auto
// roc 2008-06 0071c2e0  unit: CXTPDockBar  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0071c2e0
//
// 0071c2e0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0071c2e4  85c9                 test ecx, ecx
// 0071c2e6  7408                 je 0x71c2f0
// 0071c2e8  8b442408             mov eax, dword ptr [esp + 8]
// 0071c2ec  85c0                 test eax, eax
// 0071c2ee  7505                 jne 0x71c2f5
// 0071c2f0  e84f46f8ff           call 0x6a0944
// 0071c2f5  8b09                 mov ecx, dword ptr [ecx]
// 0071c2f7  33d2                 xor edx, edx
// 0071c2f9  3b08                 cmp ecx, dword ptr [eax]
// 0071c2fb  0f94c2               sete dl
// 0071c2fe  8bc2                 mov eax, edx
// 0071c300  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ??$CompareElements@II@@YGHPBI0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
