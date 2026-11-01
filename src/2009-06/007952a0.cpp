// from server: 100% by auto
// roc 2009-06 007952a0  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007952a0
//
// 007952a0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007952a4  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 007952a7  83ec10               sub esp, 0x10
// 007952aa  8bc4                 mov eax, esp
// 007952ac  8910                 mov dword ptr [eax], edx
// 007952ae  8b542420             mov edx, dword ptr [esp + 0x20]
// 007952b2  895004               mov dword ptr [eax + 4], edx
// 007952b5  8b542424             mov edx, dword ptr [esp + 0x24]
// 007952b9  895008               mov dword ptr [eax + 8], edx
// 007952bc  8b542428             mov edx, dword ptr [esp + 0x28]
// 007952c0  89500c               mov dword ptr [eax + 0xc], edx
// 007952c3  8b442418             mov eax, dword ptr [esp + 0x18]
// 007952c7  8b542414             mov edx, dword ptr [esp + 0x14]
// 007952cb  50                   push eax
// 007952cc  52                   push edx
// 007952cd  e83e370600           call 0x7f8a10
// 007952d2  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?DrawTabControl@CXTPTabPaintManagerAppearanceSet@@UAEXPAVCXTPTabManager@@PAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
