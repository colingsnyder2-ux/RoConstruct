// from server: 100% by auto
// roc 2009-12 0040c880  unit: CNullDoc  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0040c880
//
// 0040c880  85c9                 test ecx, ecx
// 0040c882  7503                 jne 0x40c887
// 0040c884  33c0                 xor eax, eax
// 0040c886  c3                   ret 
// 0040c887  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040c88a  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appui1.cpp (function ?GetSafeHwnd@CWnd@@QBEPAUHWND__@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appui1.cpp
