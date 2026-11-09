// from server: 100% by auto
// roc 2009-12 0040cea0  unit: CDeclarationView  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0040cea0
//
// 0040cea0  e81f6f3e00           call 0x7f3dc4
// 0040cea5  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0040cea9  8901                 mov dword ptr [ecx], eax
// 0040ceab  33c0                 xor eax, eax
// 0040cead  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\viewform.cpp (function ?get_accChildCount@CFormView@@UAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewform.cpp
