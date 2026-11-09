// from server: 100% by auto
// roc 2009-06 0072f180  unit: CRgn  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0072f180
//
// 0072f180  8b4138               mov eax, dword ptr [ecx + 0x38]
// 0072f183  85c0                 test eax, eax
// 0072f185  750a                 jne 0x72f191
// 0072f187  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0072f18a  50                   push eax
// 0072f18b  ff1598ee8900         call dword ptr [0x89ee98]
// 0072f191  50                   push eax
// 0072f192  e86b9bfeff           call 0x718d02
// 0072f197  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetOwner@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
