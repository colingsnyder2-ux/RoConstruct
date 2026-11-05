// from server: 100% by auto
// roc 2007-08 006457a0  unit: CRgn  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006457a0
//
// 006457a0  8b4138               mov eax, dword ptr [ecx + 0x38]
// 006457a3  85c0                 test eax, eax
// 006457a5  750a                 jne 0x6457b1
// 006457a7  8b4120               mov eax, dword ptr [ecx + 0x20]
// 006457aa  50                   push eax
// 006457ab  ff15f8eb7700         call dword ptr [0x77ebf8]
// 006457b1  50                   push eax
// 006457b2  e809aafeff           call 0x6301c0
// 006457b7  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?GetOwner@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
