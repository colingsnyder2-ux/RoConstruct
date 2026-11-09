// from server: 100% by auto
// roc 2007-08 0040aac0  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040aac0
//
// 0040aac0  e807572200           call 0x6301cc
// 0040aac5  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0040aac9  8901                 mov dword ptr [ecx], eax
// 0040aacb  33c0                 xor eax, eax
// 0040aacd  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\viewform.cpp (function ?get_accChildCount@CFormView@@UAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewform.cpp
