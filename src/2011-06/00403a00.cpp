// from server: 100% by auto
// roc 2011-06 00403a00  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403a00
//
// 00403a00  8b4108               mov eax, dword ptr [ecx + 8]
// 00403a03  50                   push eax
// 00403a04  ff157c30a400         call dword ptr [0xa4307c]
// 00403a0a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcaptionbar.cpp (function ?GetTextColor@CDC@@QBEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcaptionbar.cpp
