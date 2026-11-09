// from server: 100% by auto
// roc 2010-06 0082cb70  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0082cb70
//
// 0082cb70  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0082cb74  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 0082cb77  83ec10               sub esp, 0x10
// 0082cb7a  8bc4                 mov eax, esp
// 0082cb7c  8910                 mov dword ptr [eax], edx
// 0082cb7e  8b542420             mov edx, dword ptr [esp + 0x20]
// 0082cb82  895004               mov dword ptr [eax + 4], edx
// 0082cb85  8b542424             mov edx, dword ptr [esp + 0x24]
// 0082cb89  895008               mov dword ptr [eax + 8], edx
// 0082cb8c  8b542428             mov edx, dword ptr [esp + 0x28]
// 0082cb90  89500c               mov dword ptr [eax + 0xc], edx
// 0082cb93  8b442418             mov eax, dword ptr [esp + 0x18]
// 0082cb97  8b542414             mov edx, dword ptr [esp + 0x14]
// 0082cb9b  50                   push eax
// 0082cb9c  52                   push edx
// 0082cb9d  e8beab0500           call 0x887760
// 0082cba2  c21800               ret 0x18
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?DrawTabControl@CAppearanceSet@CXTPTabPaintManager@@UAEXPAVCXTPTabManager@@PAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
