// from server: 100% by auto
// roc 2009-12 0085a950  unit: CXTPStatusBar  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085a950
//
// 0085a950  56                   push esi
// 0085a951  8bf1                 mov esi, ecx
// 0085a953  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0085a957  57                   push edi
// 0085a958  8bbe84000000         mov edi, dword ptr [esi + 0x84]
// 0085a95e  8bc7                 mov eax, edi
// 0085a960  25fff0ffff           and eax, 0xfffff0ff
// 0085a965  51                   push ecx
// 0085a966  8bce                 mov ecx, esi
// 0085a968  898684000000         mov dword ptr [esi + 0x84], eax
// 0085a96e  e89bc10c00           call 0x926b0e
// 0085a973  89be84000000         mov dword ptr [esi + 0x84], edi
// 0085a979  5f                   pop edi
// 0085a97a  5e                   pop esi
// 0085a97b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\bardock.cpp (function ?OnWindowPosChanging@CDockBar@@IAEXPAUtagWINDOWPOS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/bardock.cpp
