// from server: 100% by auto
// roc 2007-03 006e7e60  unit: seg_006e0000  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e7e60
//
// 006e7e60  8b4118               mov eax, dword ptr [ecx + 0x18]
// 006e7e63  99                   cdq 
// 006e7e64  2bc2                 sub eax, edx
// 006e7e66  8bd0                 mov edx, eax
// 006e7e68  8b442404             mov eax, dword ptr [esp + 4]
// 006e7e6c  d1fa                 sar edx, 1
// 006e7e6e  035104               add edx, dword ptr [ecx + 4]
// 006e7e71  8910                 mov dword ptr [eax], edx
// 006e7e73  8b5108               mov edx, dword ptr [ecx + 8]
// 006e7e76  895004               mov dword ptr [eax + 4], edx
// 006e7e79  8b510c               mov edx, dword ptr [ecx + 0xc]
// 006e7e7c  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 006e7e7f  895008               mov dword ptr [eax + 8], edx
// 006e7e82  89480c               mov dword ptr [eax + 0xc], ecx
// 006e7e85  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?GetHeaderMargin@CAppearanceSetVisualStudio2005@CXTPTabPaintManager@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
