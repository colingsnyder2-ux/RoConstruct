// from server: 100% by auto
// roc 2010-06 00891670  unit: CXTColorBase  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00891670
//
// 00891670  51                   push ecx
// 00891671  dd442410             fld qword ptr [esp + 0x10]
// 00891675  83ec18               sub esp, 0x18
// 00891678  dd5c2410             fstp qword ptr [esp + 0x10]
// 0089167c  8d442418             lea eax, [esp + 0x18]
// 00891680  dd442430             fld qword ptr [esp + 0x30]
// 00891684  dd5c2408             fstp qword ptr [esp + 8]
// 00891688  dd442420             fld qword ptr [esp + 0x20]
// 0089168c  dd1c24               fstp qword ptr [esp]
// 0089168f  50                   push eax
// 00891690  e83b5d0100           call 0x8a73d0
// 00891695  8b00                 mov eax, dword ptr [eax]
// 00891697  83c420               add esp, 0x20
// 0089169a  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?HLStoRGB@CXTColorBase@@SAKNNN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
