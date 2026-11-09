// from server: 100% by auto
// roc 2009-06 00802930  unit: CXTColorBase  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00802930
//
// 00802930  51                   push ecx
// 00802931  dd442410             fld qword ptr [esp + 0x10]
// 00802935  83ec18               sub esp, 0x18
// 00802938  dd5c2410             fstp qword ptr [esp + 0x10]
// 0080293c  8d442418             lea eax, [esp + 0x18]
// 00802940  dd442430             fld qword ptr [esp + 0x30]
// 00802944  dd5c2408             fstp qword ptr [esp + 8]
// 00802948  dd442420             fld qword ptr [esp + 0x20]
// 0080294c  dd1c24               fstp qword ptr [esp]
// 0080294f  50                   push eax
// 00802950  e88b5c0100           call 0x8185e0
// 00802955  8b00                 mov eax, dword ptr [eax]
// 00802957  83c420               add esp, 0x20
// 0080295a  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?HLStoRGB@CXTColorBase@@SAKNNN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
