// from server: 100% by auto
// roc 2009-06 007f94e0  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f94e0
//
// 007f94e0  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 007f94e3  8b442404             mov eax, dword ptr [esp + 4]
// 007f94e7  8b5140               mov edx, dword ptr [ecx + 0x40]
// 007f94ea  83c140               add ecx, 0x40
// 007f94ed  8910                 mov dword ptr [eax], edx
// 007f94ef  8b5104               mov edx, dword ptr [ecx + 4]
// 007f94f2  895004               mov dword ptr [eax + 4], edx
// 007f94f5  8b5108               mov edx, dword ptr [ecx + 8]
// 007f94f8  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 007f94fb  895008               mov dword ptr [eax + 8], edx
// 007f94fe  89480c               mov dword ptr [eax + 0xc], ecx
// 007f9501  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?GetClientMargin@CXTPTabPaintManagerAppearanceSet@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
