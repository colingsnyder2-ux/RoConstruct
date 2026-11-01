// from server: 100% by auto
// roc 2009-06 00795260  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00795260
//
// 00795260  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00795264  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 00795267  83ec10               sub esp, 0x10
// 0079526a  8bc4                 mov eax, esp
// 0079526c  8910                 mov dword ptr [eax], edx
// 0079526e  8b542420             mov edx, dword ptr [esp + 0x20]
// 00795272  895004               mov dword ptr [eax + 4], edx
// 00795275  8b542424             mov edx, dword ptr [esp + 0x24]
// 00795279  895008               mov dword ptr [eax + 8], edx
// 0079527c  8b542428             mov edx, dword ptr [esp + 0x28]
// 00795280  89500c               mov dword ptr [eax + 0xc], edx
// 00795283  8b442418             mov eax, dword ptr [esp + 0x18]
// 00795287  8b542414             mov edx, dword ptr [esp + 0x14]
// 0079528b  50                   push eax
// 0079528c  52                   push edx
// 0079528d  e89e1c0600           call 0x7f6f30
// 00795292  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?DrawTabControl@CXTPTabPaintManagerAppearanceSet@@UAEXPAVCXTPTabManager@@PAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
