// from server: 100% by auto
// roc 2007-03 00707600  unit: seg_00700000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00707600
//
// 00707600  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 00707603  8b442404             mov eax, dword ptr [esp + 4]
// 00707607  8b5140               mov edx, dword ptr [ecx + 0x40]
// 0070760a  83c140               add ecx, 0x40
// 0070760d  8910                 mov dword ptr [eax], edx
// 0070760f  8b5104               mov edx, dword ptr [ecx + 4]
// 00707612  895004               mov dword ptr [eax + 4], edx
// 00707615  8b5108               mov edx, dword ptr [ecx + 8]
// 00707618  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0070761b  895008               mov dword ptr [eax + 8], edx
// 0070761e  89480c               mov dword ptr [eax + 0xc], ecx
// 00707621  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?GetClientMargin@CXTPTabPaintManagerAppearanceSet@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
