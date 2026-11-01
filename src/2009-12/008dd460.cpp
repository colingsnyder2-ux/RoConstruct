// from server: 100% by auto
// roc 2009-12 008dd460  unit: CXTColorBase  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008dd460
//
// 008dd460  8b442404             mov eax, dword ptr [esp + 4]
// 008dd464  0fb6d0               movzx edx, al
// 008dd467  899168070000         mov dword ptr [ecx + 0x768], edx
// 008dd46d  8bd0                 mov edx, eax
// 008dd46f  c1ea08               shr edx, 8
// 008dd472  c1e810               shr eax, 0x10
// 008dd475  0fb6d2               movzx edx, dl
// 008dd478  0fb6c0               movzx eax, al
// 008dd47b  899170070000         mov dword ptr [ecx + 0x770], edx
// 008dd481  89816c070000         mov dword ptr [ecx + 0x76c], eax
// 008dd487  c744240400000000     mov dword ptr [esp + 4], 0
// 008dd48f  e95466f1ff           jmp 0x7f3ae8
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?UpdateRGB@CXTPColorPageCustom@@IAEXK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
