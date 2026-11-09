// from server: 100% by auto
// roc 2010-06 00403010  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00403010
//
// 00403010  8b4108               mov eax, dword ptr [ecx + 8]
// 00403013  50                   push eax
// 00403014  ff15d8d09e00         call dword ptr [0x9ed0d8]
// 0040301a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcaptionbar.cpp (function ?GetTextColor@CDC@@QBEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcaptionbar.cpp
