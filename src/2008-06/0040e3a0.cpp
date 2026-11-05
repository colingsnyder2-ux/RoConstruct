// from server: 100% by auto
// roc 2008-06 0040e3a0  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040e3a0
//
// 0040e3a0  e857282900           call 0x6a0bfc
// 0040e3a5  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0040e3a9  8901                 mov dword ptr [ecx], eax
// 0040e3ab  33c0                 xor eax, eax
// 0040e3ad  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\viewform.cpp (function ?get_accChildCount@CFormView@@UAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewform.cpp
