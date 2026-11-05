// from server: 100% by auto
// roc 2009-12 004526b0  unit: CRobloxControlColorSelector  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004526b0
//
// 004526b0  8b442408             mov eax, dword ptr [esp + 8]
// 004526b4  8b542404             mov edx, dword ptr [esp + 4]
// 004526b8  50                   push eax
// 004526b9  52                   push edx
// 004526ba  51                   push ecx
// 004526bb  ff155cca9800         call dword ptr [0x98ca5c]
// 004526c1  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\barcore.cpp (function ?OffsetRect@CRect@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcore.cpp
