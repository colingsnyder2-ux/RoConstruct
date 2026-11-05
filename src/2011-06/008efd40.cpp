// from server: 100% by auto
// roc 2011-06 008efd40  unit: CXTShadowHook  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008efd40
//
// 008efd40  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008efd44  85c9                 test ecx, ecx
// 008efd46  7408                 je 0x8efd50
// 008efd48  8b442408             mov eax, dword ptr [esp + 8]
// 008efd4c  85c0                 test eax, eax
// 008efd4e  7505                 jne 0x8efd55
// 008efd50  e8b5a5f1ff           call 0x80a30a
// 008efd55  8b09                 mov ecx, dword ptr [ecx]
// 008efd57  33d2                 xor edx, edx
// 008efd59  3b08                 cmp ecx, dword ptr [eax]
// 008efd5b  0f94c2               sete dl
// 008efd5e  8bc2                 mov eax, edx
// 008efd60  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ??$CompareElements@II@@YGHPBI0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
