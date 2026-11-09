// from server: 100% by auto
// roc 2009-06 0077f8f0  unit: CXTPStatusBar  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077f8f0
//
// 0077f8f0  56                   push esi
// 0077f8f1  8bf1                 mov esi, ecx
// 0077f8f3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0077f8f7  57                   push edi
// 0077f8f8  8bbe84000000         mov edi, dword ptr [esi + 0x84]
// 0077f8fe  8bc7                 mov eax, edi
// 0077f900  25fff0ffff           and eax, 0xfffff0ff
// 0077f905  51                   push ecx
// 0077f906  8bce                 mov ecx, esi
// 0077f908  898684000000         mov dword ptr [esi + 0x84], eax
// 0077f90e  e88fcc0c00           call 0x84c5a2
// 0077f913  89be84000000         mov dword ptr [esi + 0x84], edi
// 0077f919  5f                   pop edi
// 0077f91a  5e                   pop esi
// 0077f91b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\bardock.cpp (function ?OnWindowPosChanging@CDockBar@@IAEXPAUtagWINDOWPOS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/bardock.cpp
