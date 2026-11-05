// from server: 100% by auto
// roc 2007-08 006b3960  unit: CXTPControlComboBoxGalleryPopupBar  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006b3960
//
// 006b3960  6a00                 push 0
// 006b3962  e8b90df9ff           call 0x644720
// 006b3967  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\olepset.cpp (function ?Get@CProperty@@QAEPAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/olepset.cpp
