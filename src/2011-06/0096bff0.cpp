// from server: 100% by auto
// roc 2011-06 0096bff0  unit: Ogre::istreamDataStream  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0096bff0
//
// 0096bff0  33c0                 xor eax, eax
// 0096bff2  3981e0010000         cmp dword ptr [ecx + 0x1e0], eax
// 0096bff8  0f95c0               setne al
// 0096bffb  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertwnd.cpp (function ?IsWindowsLayerSupportAvailable@AFX_GLOBAL_DATA@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertwnd.cpp
