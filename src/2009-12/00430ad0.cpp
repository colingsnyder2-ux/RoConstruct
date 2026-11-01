// from server: 100% by auto
// roc 2009-12 00430ad0  unit: COutputView  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00430ad0
//
// 00430ad0  8b01                 mov eax, dword ptr [ecx]
// 00430ad2  85c0                 test eax, eax
// 00430ad4  7408                 je 0x430ade
// 00430ad6  8b08                 mov ecx, dword ptr [eax]
// 00430ad8  8b5108               mov edx, dword ptr [ecx + 8]
// 00430adb  50                   push eax
// 00430adc  ffd2                 call edx
// 00430ade  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1?$CComPtrBase@UIDispatch@@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
