// from server: 100% by auto
// roc 2007-03 0067bda0  unit: seg_00670000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067bda0
//
// 0067bda0  56                   push esi
// 0067bda1  8bf1                 mov esi, ecx
// 0067bda3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0067bda7  57                   push edi
// 0067bda8  8bbe80000000         mov edi, dword ptr [esi + 0x80]
// 0067bdae  8bc7                 mov eax, edi
// 0067bdb0  25fff0ffff           and eax, 0xfffff0ff
// 0067bdb5  51                   push ecx
// 0067bdb6  8bce                 mov ecx, esi
// 0067bdb8  898680000000         mov dword ptr [esi + 0x80], eax
// 0067bdbe  e8d3f40b00           call 0x73b296
// 0067bdc3  89be80000000         mov dword ptr [esi + 0x80], edi
// 0067bdc9  5f                   pop edi
// 0067bdca  5e                   pop esi
// 0067bdcb  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\bardock.cpp (function ?OnWindowPosChanging@CDockBar@@IAEXPAUtagWINDOWPOS@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/bardock.cpp
