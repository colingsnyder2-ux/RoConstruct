// from server: 100% by auto
// roc 2007-08 00692380  unit: CXTPStatusBar  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00692380
//
// 00692380  56                   push esi
// 00692381  8bf1                 mov esi, ecx
// 00692383  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00692387  57                   push edi
// 00692388  8bbe80000000         mov edi, dword ptr [esi + 0x80]
// 0069238e  8bc7                 mov eax, edi
// 00692390  25fff0ffff           and eax, 0xfffff0ff
// 00692395  51                   push ecx
// 00692396  8bce                 mov ecx, esi
// 00692398  898680000000         mov dword ptr [esi + 0x80], eax
// 0069239e  e8b9670a00           call 0x738b5c
// 006923a3  89be80000000         mov dword ptr [esi + 0x80], edi
// 006923a9  5f                   pop edi
// 006923aa  5e                   pop esi
// 006923ab  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\bardock.cpp (function ?OnWindowPosChanging@CDockBar@@IAEXPAUtagWINDOWPOS@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/bardock.cpp
