// from server: 100% by auto
// roc 2007-03 006e7da0  unit: seg_006e0000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e7da0
//
// 006e7da0  8b5118               mov edx, dword ptr [ecx + 0x18]
// 006e7da3  035104               add edx, dword ptr [ecx + 4]
// 006e7da6  8b442404             mov eax, dword ptr [esp + 4]
// 006e7daa  8910                 mov dword ptr [eax], edx
// 006e7dac  8b5108               mov edx, dword ptr [ecx + 8]
// 006e7daf  895004               mov dword ptr [eax + 4], edx
// 006e7db2  8b510c               mov edx, dword ptr [ecx + 0xc]
// 006e7db5  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 006e7db8  895008               mov dword ptr [eax + 8], edx
// 006e7dbb  89480c               mov dword ptr [eax + 0xc], ecx
// 006e7dbe  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?GetHeaderMargin@CAppearanceSetPropertyPage2003@CXTPTabPaintManager@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
