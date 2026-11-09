// from server: 100% by auto
// roc 2011-06 0081c8c0  unit: CRgn  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0081c8c0
//
// 0081c8c0  8b4138               mov eax, dword ptr [ecx + 0x38]
// 0081c8c3  85c0                 test eax, eax
// 0081c8c5  750a                 jne 0x81c8d1
// 0081c8c7  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0081c8ca  50                   push eax
// 0081c8cb  ff15b819a400         call dword ptr [0xa419b8]
// 0081c8d1  50                   push eax
// 0081c8d2  e851dafeff           call 0x80a328
// 0081c8d7  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetOwner@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
