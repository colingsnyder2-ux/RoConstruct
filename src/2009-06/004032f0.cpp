// from server: 100% by auto
// roc 2009-06 004032f0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004032f0
//
// 004032f0  8b4108               mov eax, dword ptr [ecx + 8]
// 004032f3  50                   push eax
// 004032f4  ff1504038a00         call dword ptr [0x8a0304]
// 004032fa  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcaptionbar.cpp (function ?GetTextColor@CDC@@QBEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcaptionbar.cpp
