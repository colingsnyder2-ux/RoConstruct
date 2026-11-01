// from server: 100% by auto
// roc 2009-12 008dd420  unit: CXTColorBase  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008dd420
//
// 008dd420  51                   push ecx
// 008dd421  dd442410             fld qword ptr [esp + 0x10]
// 008dd425  83ec18               sub esp, 0x18
// 008dd428  dd5c2410             fstp qword ptr [esp + 0x10]
// 008dd42c  8d442418             lea eax, [esp + 0x18]
// 008dd430  dd442430             fld qword ptr [esp + 0x30]
// 008dd434  dd5c2408             fstp qword ptr [esp + 8]
// 008dd438  dd442420             fld qword ptr [esp + 0x20]
// 008dd43c  dd1c24               fstp qword ptr [esp]
// 008dd43f  50                   push eax
// 008dd440  e83b5e0100           call 0x8f3280
// 008dd445  8b00                 mov eax, dword ptr [eax]
// 008dd447  83c420               add esp, 0x20
// 008dd44a  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?HLStoRGB@CXTColorBase@@SAKNNN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
