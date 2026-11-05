// from server: 100% by auto
// roc 2010-06 0080e920  unit: CXTPStatusBar  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080e920
//
// 0080e920  56                   push esi
// 0080e921  8bf1                 mov esi, ecx
// 0080e923  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0080e927  57                   push edi
// 0080e928  8bbe84000000         mov edi, dword ptr [esi + 0x84]
// 0080e92e  8bc7                 mov eax, edi
// 0080e930  25fff0ffff           and eax, 0xfffff0ff
// 0080e935  51                   push ecx
// 0080e936  8bce                 mov ecx, esi
// 0080e938  898684000000         mov dword ptr [esi + 0x84], eax
// 0080e93e  e80deb1600           call 0x97d450
// 0080e943  89be84000000         mov dword ptr [esi + 0x84], edi
// 0080e949  5f                   pop edi
// 0080e94a  5e                   pop esi
// 0080e94b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\bardock.cpp (function ?OnWindowPosChanging@CDockBar@@IAEXPAUtagWINDOWPOS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/bardock.cpp
