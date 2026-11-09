// from server: 100% by auto
// roc 2010-06 0082cb30  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0082cb30
//
// 0082cb30  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0082cb34  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 0082cb37  83ec10               sub esp, 0x10
// 0082cb3a  8bc4                 mov eax, esp
// 0082cb3c  8910                 mov dword ptr [eax], edx
// 0082cb3e  8b542420             mov edx, dword ptr [esp + 0x20]
// 0082cb42  895004               mov dword ptr [eax + 4], edx
// 0082cb45  8b542424             mov edx, dword ptr [esp + 0x24]
// 0082cb49  895008               mov dword ptr [eax + 8], edx
// 0082cb4c  8b542428             mov edx, dword ptr [esp + 0x28]
// 0082cb50  89500c               mov dword ptr [eax + 0xc], edx
// 0082cb53  8b442418             mov eax, dword ptr [esp + 0x18]
// 0082cb57  8b542414             mov edx, dword ptr [esp + 0x14]
// 0082cb5b  50                   push eax
// 0082cb5c  52                   push edx
// 0082cb5d  e81e910500           call 0x885c80
// 0082cb62  c21800               ret 0x18
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?DrawTabControl@CAppearanceSet@CXTPTabPaintManager@@UAEXPAVCXTPTabManager@@PAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
