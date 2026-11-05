// from server: 100% by auto
// roc 2007-08 00401e00  unit: VCWorkspace::?$CComObject  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401e00
//
// 00401e00  8b4108               mov eax, dword ptr [ecx + 8]
// 00401e03  50                   push eax
// 00401e04  ff151cf07700         call dword ptr [0x77f01c]
// 00401e0a  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcore.cpp (function ?GetBkColor@CDC@@QBEKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcore.cpp
