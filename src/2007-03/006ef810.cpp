// from server: 100% by auto
// roc 2007-03 006ef810  unit: seg_006e0000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006ef810
//
// 006ef810  8b442404             mov eax, dword ptr [esp + 4]
// 006ef814  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006ef818  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006ef81c  51                   push ecx
// 006ef81d  89442408             mov dword ptr [esp + 8], eax
// 006ef821  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006ef825  52                   push edx
// 006ef826  50                   push eax
// 006ef827  8d4c2410             lea ecx, [esp + 0x10]
// 006ef82b  e8205b0200           call 0x715350
// 006ef830  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?RGBtoHSL@CXTColorBase@@SAXKPAN00@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
