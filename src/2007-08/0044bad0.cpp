// from server: 100% by auto
// roc 2007-08 0044bad0  unit: CRobloxControlColorSelector  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044bad0
//
// 0044bad0  8b442408             mov eax, dword ptr [esp + 8]
// 0044bad4  8b542404             mov edx, dword ptr [esp + 4]
// 0044bad8  50                   push eax
// 0044bad9  52                   push edx
// 0044bada  51                   push ecx
// 0044badb  ff1594ed7700         call dword ptr [0x77ed94]
// 0044bae1  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\barcore.cpp (function ?OffsetRect@CRect@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcore.cpp
