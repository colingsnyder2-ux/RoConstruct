// from server: 100% by auto
// roc 2007-03 00401df0  unit: seg_00400000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401df0
//
// 00401df0  8b4108               mov eax, dword ptr [ecx + 8]
// 00401df3  50                   push eax
// 00401df4  ff1534f17700         call dword ptr [0x77f134]
// 00401dfa  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcore.cpp (function ?GetBkColor@CDC@@QBEKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcore.cpp
