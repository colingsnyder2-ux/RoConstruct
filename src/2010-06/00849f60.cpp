// from server: 100% by auto
// roc 2010-06 00849f60  unit: CXTPRibbonBar  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00849f60
//
// 00849f60  8b442404             mov eax, dword ptr [esp + 4]
// 00849f64  8b5128               mov edx, dword ptr [ecx + 0x28]
// 00849f67  8910                 mov dword ptr [eax], edx
// 00849f69  8b512c               mov edx, dword ptr [ecx + 0x2c]
// 00849f6c  895004               mov dword ptr [eax + 4], edx
// 00849f6f  8b5130               mov edx, dword ptr [ecx + 0x30]
// 00849f72  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 00849f75  895008               mov dword ptr [eax + 8], edx
// 00849f78  89480c               mov dword ptr [eax + 0xc], ecx
// 00849f7b  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTPPopupControl.cpp (function ?GetRect@CXTPPopupItem@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTPPopupControl.cpp
