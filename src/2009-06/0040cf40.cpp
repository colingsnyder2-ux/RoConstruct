// from server: 100% by auto
// roc 2009-06 0040cf40  unit: CDeclarationView  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040cf40
//
// 0040cf40  e84bc03000           call 0x718f90
// 0040cf45  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0040cf49  8901                 mov dword ptr [ecx], eax
// 0040cf4b  33c0                 xor eax, eax
// 0040cf4d  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\viewform.cpp (function ?get_accChildCount@CFormView@@UAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewform.cpp
