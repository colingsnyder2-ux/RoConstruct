// from server: 100% by auto
// roc 2008-06 004029c0  unit: VCWorkspace::?$CComContainedObject  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004029c0
//
// 004029c0  8b01                 mov eax, dword ptr [ecx]
// 004029c2  85c0                 test eax, eax
// 004029c4  7408                 je 0x4029ce
// 004029c6  8b08                 mov ecx, dword ptr [eax]
// 004029c8  8b5108               mov edx, dword ptr [ecx + 8]
// 004029cb  50                   push eax
// 004029cc  ffd2                 call edx
// 004029ce  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??1?$CComPtrBase@UIDispatch@@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
