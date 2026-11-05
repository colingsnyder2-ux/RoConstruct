// from server: 100% by auto
// roc 2010-06 00892090  unit: CXTColorLum  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00892090
//
// 00892090  dd442404             fld qword ptr [esp + 4]
// 00892094  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00892097  6a00                 push 0
// 00892099  dd5968               fstp qword ptr [ecx + 0x68]
// 0089209c  dd442410             fld qword ptr [esp + 0x10]
// 008920a0  6a00                 push 0
// 008920a2  50                   push eax
// 008920a3  dd5960               fstp qword ptr [ecx + 0x60]
// 008920a6  ff1578ba9e00         call dword ptr [0x9eba78]
// 008920ac  c21000               ret 0x10
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?SetColor@CXTColorLum@@UAEXNN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
