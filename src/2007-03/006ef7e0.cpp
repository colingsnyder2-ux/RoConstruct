// from server: 100% by auto
// roc 2007-03 006ef7e0  unit: seg_006e0000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006ef7e0
//
// 006ef7e0  51                   push ecx
// 006ef7e1  dd442410             fld qword ptr [esp + 0x10]
// 006ef7e5  83ec18               sub esp, 0x18
// 006ef7e8  dd5c2410             fstp qword ptr [esp + 0x10]
// 006ef7ec  8d442418             lea eax, [esp + 0x18]
// 006ef7f0  dd442430             fld qword ptr [esp + 0x30]
// 006ef7f4  dd5c2408             fstp qword ptr [esp + 8]
// 006ef7f8  dd442420             fld qword ptr [esp + 0x20]
// 006ef7fc  dd1c24               fstp qword ptr [esp]
// 006ef7ff  50                   push eax
// 006ef800  e8eb5e0200           call 0x7156f0
// 006ef805  8b00                 mov eax, dword ptr [eax]
// 006ef807  83c420               add esp, 0x20
// 006ef80a  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?HLStoRGB@CXTColorBase@@SAKNNN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
