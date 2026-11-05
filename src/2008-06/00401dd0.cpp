// from server: 100% by auto
// roc 2008-06 00401dd0  unit: VCWorkspace::?$CComObject  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401dd0
//
// 00401dd0  8b4108               mov eax, dword ptr [ecx + 8]
// 00401dd3  50                   push eax
// 00401dd4  ff1514418000         call dword ptr [0x804114]
// 00401dda  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcaptionbar.cpp (function ?GetTextColor@CDC@@QBEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcaptionbar.cpp
