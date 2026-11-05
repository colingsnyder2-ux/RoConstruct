// from server: 100% by auto
// roc 2009-06 00756a00  unit: CXTTreeBase  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00756a00
//
// 00756a00  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00756a04  85c9                 test ecx, ecx
// 00756a06  7408                 je 0x756a10
// 00756a08  8b442408             mov eax, dword ptr [esp + 8]
// 00756a0c  85c0                 test eax, eax
// 00756a0e  7505                 jne 0x756a15
// 00756a10  e8cf22fcff           call 0x718ce4
// 00756a15  8b09                 mov ecx, dword ptr [ecx]
// 00756a17  33d2                 xor edx, edx
// 00756a19  3b08                 cmp ecx, dword ptr [eax]
// 00756a1b  0f94c2               sete dl
// 00756a1e  8bc2                 mov eax, edx
// 00756a20  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ??$CompareElements@II@@YGHPBI0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
