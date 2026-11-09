// from server: 100% by auto
// roc 2011-06 00463040  unit: CRobloxApp  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00463040
//
// 00463040  8b01                 mov eax, dword ptr [ecx]
// 00463042  85c0                 test eax, eax
// 00463044  7408                 je 0x46304e
// 00463046  8b08                 mov ecx, dword ptr [eax]
// 00463048  8b5108               mov edx, dword ptr [ecx + 8]
// 0046304b  50                   push eax
// 0046304c  ffd2                 call edx
// 0046304e  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1?$CComPtrBase@UIDispatch@@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
