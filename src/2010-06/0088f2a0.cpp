// from server: 100% by auto
// roc 2010-06 0088f2a0  unit: CXTColorPageStandard  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0088f2a0
//
// 0088f2a0  56                   push esi
// 0088f2a1  8bf1                 mov esi, ecx
// 0088f2a3  8b4608               mov eax, dword ptr [esi + 8]
// 0088f2a6  6a00                 push 0
// 0088f2a8  50                   push eax
// 0088f2a9  e8c2f8ffff           call 0x88eb70
// 0088f2ae  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0088f2b2  894808               mov dword ptr [eax + 8], ecx
// 0088f2b5  8b4e08               mov ecx, dword ptr [esi + 8]
// 0088f2b8  85c9                 test ecx, ecx
// 0088f2ba  7409                 je 0x88f2c5
// 0088f2bc  8901                 mov dword ptr [ecx], eax
// 0088f2be  894608               mov dword ptr [esi + 8], eax
// 0088f2c1  5e                   pop esi
// 0088f2c2  c20400               ret 4
// 0088f2c5  894604               mov dword ptr [esi + 4], eax
// 0088f2c8  894608               mov dword ptr [esi + 8], eax
// 0088f2cb  5e                   pop esi
// 0088f2cc  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?AddTail@?$CList@II@@QAEPAU__POSITION@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
