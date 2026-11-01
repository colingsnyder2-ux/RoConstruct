// from server: 100% by auto
// roc 2009-12 008d4080  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d4080
//
// 008d4080  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 008d4083  8b442404             mov eax, dword ptr [esp + 4]
// 008d4087  8b5140               mov edx, dword ptr [ecx + 0x40]
// 008d408a  83c140               add ecx, 0x40
// 008d408d  8910                 mov dword ptr [eax], edx
// 008d408f  8b5104               mov edx, dword ptr [ecx + 4]
// 008d4092  895004               mov dword ptr [eax + 4], edx
// 008d4095  8b5108               mov edx, dword ptr [ecx + 8]
// 008d4098  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 008d409b  895008               mov dword ptr [eax + 8], edx
// 008d409e  89480c               mov dword ptr [eax + 0xc], ecx
// 008d40a1  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?GetClientMargin@CXTPTabPaintManagerAppearanceSet@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
