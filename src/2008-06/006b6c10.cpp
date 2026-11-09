// from server: 100% by auto
// roc 2008-06 006b6c10  unit: CRgn  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006b6c10
//
// 006b6c10  8b4138               mov eax, dword ptr [ecx + 0x38]
// 006b6c13  85c0                 test eax, eax
// 006b6c15  750a                 jne 0x6b6c21
// 006b6c17  8b4120               mov eax, dword ptr [ecx + 0x20]
// 006b6c1a  50                   push eax
// 006b6c1b  ff15f82d8000         call dword ptr [0x802df8]
// 006b6c21  50                   push eax
// 006b6c22  e8b79ffeff           call 0x6a0bde
// 006b6c27  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetOwner@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
