// from server: 100% by auto
// roc 2009-12 008dde70  unit: CXTColorLum  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008dde70
//
// 008dde70  dd442404             fld qword ptr [esp + 4]
// 008dde74  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008dde77  6a00                 push 0
// 008dde79  dd5968               fstp qword ptr [ecx + 0x68]
// 008dde7c  dd442410             fld qword ptr [esp + 0x10]
// 008dde80  6a00                 push 0
// 008dde82  50                   push eax
// 008dde83  dd5960               fstp qword ptr [ecx + 0x60]
// 008dde86  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008dde8c  c21000               ret 0x10
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?SetColor@CXTPColorLum@@UAEXNN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
