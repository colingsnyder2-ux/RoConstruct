// from server: 100% by auto
// roc 2009-06 00803380  unit: CXTColorLum  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00803380
//
// 00803380  dd442404             fld qword ptr [esp + 4]
// 00803384  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00803387  6a00                 push 0
// 00803389  dd5968               fstp qword ptr [ecx + 0x68]
// 0080338c  dd442410             fld qword ptr [esp + 0x10]
// 00803390  6a00                 push 0
// 00803392  50                   push eax
// 00803393  dd5960               fstp qword ptr [ecx + 0x60]
// 00803396  ff157cee8900         call dword ptr [0x89ee7c]
// 0080339c  c21000               ret 0x10
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?SetColor@CXTPColorLum@@UAEXNN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
