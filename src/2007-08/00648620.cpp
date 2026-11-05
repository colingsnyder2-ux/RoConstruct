// from server: 100% by auto
// roc 2007-08 00648620  unit: CXTPCommandBar  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00648620
//
// 00648620  33c0                 xor eax, eax
// 00648622  394104               cmp dword ptr [ecx + 4], eax
// 00648625  0f95c0               setne al
// 00648628  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dbcore.cpp (function ?IsOpen@CDatabase@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dbcore.cpp
