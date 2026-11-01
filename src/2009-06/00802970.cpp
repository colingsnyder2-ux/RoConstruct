// from server: 100% by auto
// roc 2009-06 00802970  unit: CXTColorBase  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00802970
//
// 00802970  8b442404             mov eax, dword ptr [esp + 4]
// 00802974  0fb6d0               movzx edx, al
// 00802977  899168070000         mov dword ptr [ecx + 0x768], edx
// 0080297d  8bd0                 mov edx, eax
// 0080297f  c1ea08               shr edx, 8
// 00802982  c1e810               shr eax, 0x10
// 00802985  0fb6d2               movzx edx, dl
// 00802988  0fb6c0               movzx eax, al
// 0080298b  899170070000         mov dword ptr [ecx + 0x770], edx
// 00802991  89816c070000         mov dword ptr [ecx + 0x76c], eax
// 00802997  c744240400000000     mov dword ptr [esp + 4], 0
// 0080299f  e91c63f1ff           jmp 0x718cc0
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?UpdateRGB@CXTPColorPageCustom@@IAEXK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
