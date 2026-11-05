// from server: 100% by auto
// roc 2009-06 007ad3f0  unit: XTPPaintThemes::CXTPOfficeTheme  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ad3f0
//
// 007ad3f0  8b542408             mov edx, dword ptr [esp + 8]
// 007ad3f4  6a10                 push 0x10
// 007ad3f6  6a10                 push 0x10
// 007ad3f8  83ec10               sub esp, 0x10
// 007ad3fb  8bc4                 mov eax, esp
// 007ad3fd  8910                 mov dword ptr [eax], edx
// 007ad3ff  8b542424             mov edx, dword ptr [esp + 0x24]
// 007ad403  895004               mov dword ptr [eax + 4], edx
// 007ad406  8b542428             mov edx, dword ptr [esp + 0x28]
// 007ad40a  895008               mov dword ptr [eax + 8], edx
// 007ad40d  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007ad411  89500c               mov dword ptr [eax + 0xc], edx
// 007ad414  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007ad418  50                   push eax
// 007ad419  e86255f7ff           call 0x722980
// 007ad41e  c21c00               ret 0x1c
// library xtp-13.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawStatusBarPaneBorder@CXTPOfficeTheme@@MAEXPAVCDC@@VCRect@@PAVCXTPStatusBarPane@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOfficeTheme.cpp
