// from server: 100% by auto
// roc 2009-12 00871c40  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00871c40
//
// 00871c40  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00871c44  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 00871c47  83ec10               sub esp, 0x10
// 00871c4a  8bc4                 mov eax, esp
// 00871c4c  8910                 mov dword ptr [eax], edx
// 00871c4e  8b542420             mov edx, dword ptr [esp + 0x20]
// 00871c52  895004               mov dword ptr [eax + 4], edx
// 00871c55  8b542424             mov edx, dword ptr [esp + 0x24]
// 00871c59  895008               mov dword ptr [eax + 8], edx
// 00871c5c  8b542428             mov edx, dword ptr [esp + 0x28]
// 00871c60  89500c               mov dword ptr [eax + 0xc], edx
// 00871c63  8b442418             mov eax, dword ptr [esp + 0x18]
// 00871c67  8b542414             mov edx, dword ptr [esp + 0x14]
// 00871c6b  50                   push eax
// 00871c6c  52                   push edx
// 00871c6d  e83e190600           call 0x8d35b0
// 00871c72  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?DrawTabControl@CXTPTabPaintManagerAppearanceSet@@UAEXPAVCXTPTabManager@@PAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
