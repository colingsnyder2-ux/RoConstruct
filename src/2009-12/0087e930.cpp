// from server: 100% by auto
// roc 2009-12 0087e930  unit: XTPPaintThemes::CXTPDefaultTheme  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0087e930
//
// 0087e930  83ec10               sub esp, 0x10
// 0087e933  837c243000           cmp dword ptr [esp + 0x30], 0
// 0087e938  7440                 je 0x87e97a
// 0087e93a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0087e93e  8b542420             mov edx, dword ptr [esp + 0x20]
// 0087e942  890424               mov dword ptr [esp], eax
// 0087e945  8b442424             mov eax, dword ptr [esp + 0x24]
// 0087e949  89442408             mov dword ptr [esp + 8], eax
// 0087e94d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0087e951  89542404             mov dword ptr [esp + 4], edx
// 0087e955  8b542428             mov edx, dword ptr [esp + 0x28]
// 0087e959  4a                   dec edx
// 0087e95a  f7d8                 neg eax
// 0087e95c  1bc0                 sbb eax, eax
// 0087e95e  83c003               add eax, 3
// 0087e961  50                   push eax
// 0087e962  89542410             mov dword ptr [esp + 0x10], edx
// 0087e966  e8d5ecf7ff           call 0x7fd640
// 0087e96b  50                   push eax
// 0087e96c  8d4c2404             lea ecx, [esp + 4]
// 0087e970  51                   push ecx
// 0087e971  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0087e975  e8845cf7ff           call 0x7f45fe
// 0087e97a  8b442414             mov eax, dword ptr [esp + 0x14]
// 0087e97e  c70000000000         mov dword ptr [eax], 0
// 0087e984  c7400408000000       mov dword ptr [eax + 4], 8
// 0087e98b  83c410               add esp, 0x10
// 0087e98e  c22000               ret 0x20
// library xtp-15.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?DrawTearOffGripper@CXTPDefaultTheme@@UAE?AVCSize@@PAVCDC@@VCRect@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDefaultTheme.cpp
