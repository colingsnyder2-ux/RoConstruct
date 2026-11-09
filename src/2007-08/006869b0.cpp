// from server: 100% by auto
// roc 2007-08 006869b0  unit: CXTPPropExchangeArchive  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006869b0
//
// 006869b0  8b01                 mov eax, dword ptr [ecx]
// 006869b2  85c0                 test eax, eax
// 006869b4  7408                 je 0x6869be
// 006869b6  8b08                 mov ecx, dword ptr [eax]
// 006869b8  8b5108               mov edx, dword ptr [ecx + 8]
// 006869bb  50                   push eax
// 006869bc  ffd2                 call edx
// 006869be  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1?$CComPtrBase@UIDispatch@@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
