// from server: 100% by auto
// roc 2010-06 0040d3d0  unit: CDeclarationView  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040d3d0
//
// 0040d3d0  e82fab3900           call 0x7a7f04
// 0040d3d5  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0040d3d9  8901                 mov dword ptr [ecx], eax
// 0040d3db  33c0                 xor eax, eax
// 0040d3dd  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\viewform.cpp (function ?get_accChildCount@CFormView@@UAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewform.cpp
