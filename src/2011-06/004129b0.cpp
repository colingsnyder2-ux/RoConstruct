// from server: 100% by auto
// roc 2011-06 004129b0  unit: CDeclarationView  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004129b0
//
// 004129b0  e80d7c3f00           call 0x80a5c2
// 004129b5  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004129b9  8901                 mov dword ptr [ecx], eax
// 004129bb  33c0                 xor eax, eax
// 004129bd  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\viewform.cpp (function ?get_accChildCount@CFormView@@UAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewform.cpp
