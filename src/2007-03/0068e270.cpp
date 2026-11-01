// from server: 100% by auto
// roc 2007-03 0068e270  unit: seg_00680000  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068e270
//
// 0068e270  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0068e274  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 0068e277  83ec10               sub esp, 0x10
// 0068e27a  8bc4                 mov eax, esp
// 0068e27c  8910                 mov dword ptr [eax], edx
// 0068e27e  8b542420             mov edx, dword ptr [esp + 0x20]
// 0068e282  895004               mov dword ptr [eax + 4], edx
// 0068e285  8b542424             mov edx, dword ptr [esp + 0x24]
// 0068e289  895008               mov dword ptr [eax + 8], edx
// 0068e28c  8b542428             mov edx, dword ptr [esp + 0x28]
// 0068e290  89500c               mov dword ptr [eax + 0xc], edx
// 0068e293  8b442418             mov eax, dword ptr [esp + 0x18]
// 0068e297  8b542414             mov edx, dword ptr [esp + 0x14]
// 0068e29b  50                   push eax
// 0068e29c  52                   push edx
// 0068e29d  e8ceaa0500           call 0x6e8d70
// 0068e2a2  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?DrawTabControl@CXTPTabPaintManagerAppearanceSet@@UAEXPAVCXTPTabManager@@PAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
