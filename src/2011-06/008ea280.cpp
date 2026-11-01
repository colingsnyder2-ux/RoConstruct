// from server: 100% by auto
// roc 2011-06 008ea280  unit: CXTColorBase  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ea280
//
// 008ea280  51                   push ecx
// 008ea281  dd442410             fld qword ptr [esp + 0x10]
// 008ea285  83ec18               sub esp, 0x18
// 008ea288  dd5c2410             fstp qword ptr [esp + 0x10]
// 008ea28c  8d442418             lea eax, [esp + 0x18]
// 008ea290  dd442430             fld qword ptr [esp + 0x30]
// 008ea294  dd5c2408             fstp qword ptr [esp + 8]
// 008ea298  dd442420             fld qword ptr [esp + 0x20]
// 008ea29c  dd1c24               fstp qword ptr [esp]
// 008ea29f  50                   push eax
// 008ea2a0  e8fb670100           call 0x900aa0
// 008ea2a5  8b00                 mov eax, dword ptr [eax]
// 008ea2a7  83c420               add esp, 0x20
// 008ea2aa  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?HLStoRGB@CXTColorBase@@SAKNNN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
