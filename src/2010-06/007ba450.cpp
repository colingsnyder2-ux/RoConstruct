// from server: 100% by auto
// roc 2010-06 007ba450  unit: CRgn  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ba450
//
// 007ba450  8b4138               mov eax, dword ptr [ecx + 0x38]
// 007ba453  85c0                 test eax, eax
// 007ba455  750a                 jne 0x7ba461
// 007ba457  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007ba45a  50                   push eax
// 007ba45b  ff154cba9e00         call dword ptr [0x9eba4c]
// 007ba461  50                   push eax
// 007ba462  e803d8feff           call 0x7a7c6a
// 007ba467  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetOwner@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
