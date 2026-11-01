// from server: 100% by auto
// roc 2007-03 0040bc70  unit: seg_00400000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0040bc70
//
// 0040bc70  85c9                 test ecx, ecx
// 0040bc72  7503                 jne 0x40bc77
// 0040bc74  33c0                 xor eax, eax
// 0040bc76  c3                   ret 
// 0040bc77  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040bc7a  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appui1.cpp (function ?GetSafeHwnd@CWnd@@QBEPAUHWND__@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appui1.cpp
