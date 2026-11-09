// from server: 100% by auto
// roc 2010-06 0040d950  unit: CIDEBrowserView  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040d950
//
// 0040d950  8b01                 mov eax, dword ptr [ecx]
// 0040d952  85c0                 test eax, eax
// 0040d954  7408                 je 0x40d95e
// 0040d956  8b08                 mov ecx, dword ptr [eax]
// 0040d958  8b5108               mov edx, dword ptr [ecx + 8]
// 0040d95b  50                   push eax
// 0040d95c  ffd2                 call edx
// 0040d95e  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1?$CComPtrBase@UIDispatch@@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
