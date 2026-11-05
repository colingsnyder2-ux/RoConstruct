// from server: 100% by auto
// roc 2009-12 0086bda0  unit: CXTPPropertyGridItemEnum  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086bda0
//
// 0086bda0  33c0                 xor eax, eax
// 0086bda2  394104               cmp dword ptr [ecx + 4], eax
// 0086bda5  0f95c0               setne al
// 0086bda8  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dbcore.cpp (function ?IsOpen@CDatabase@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dbcore.cpp
