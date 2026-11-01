// from server: 100% by auto
// roc 2009-06 007a39f0  unit: XTPPaintThemes::CXTPDefaultTheme  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007a39f0
//
// 007a39f0  83ec10               sub esp, 0x10
// 007a39f3  837c243000           cmp dword ptr [esp + 0x30], 0
// 007a39f8  7440                 je 0x7a3a3a
// 007a39fa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007a39fe  8b542420             mov edx, dword ptr [esp + 0x20]
// 007a3a02  890424               mov dword ptr [esp], eax
// 007a3a05  8b442424             mov eax, dword ptr [esp + 0x24]
// 007a3a09  89442408             mov dword ptr [esp + 8], eax
// 007a3a0d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007a3a11  89542404             mov dword ptr [esp + 4], edx
// 007a3a15  8b542428             mov edx, dword ptr [esp + 0x28]
// 007a3a19  4a                   dec edx
// 007a3a1a  f7d8                 neg eax
// 007a3a1c  1bc0                 sbb eax, eax
// 007a3a1e  83c003               add eax, 3
// 007a3a21  50                   push eax
// 007a3a22  89542410             mov dword ptr [esp + 0x10], edx
// 007a3a26  e855edf7ff           call 0x722780
// 007a3a2b  50                   push eax
// 007a3a2c  8d4c2404             lea ecx, [esp + 4]
// 007a3a30  51                   push ecx
// 007a3a31  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007a3a35  e8965df7ff           call 0x7197d0
// 007a3a3a  8b442414             mov eax, dword ptr [esp + 0x14]
// 007a3a3e  c70000000000         mov dword ptr [eax], 0
// 007a3a44  c7400408000000       mov dword ptr [eax + 4], 8
// 007a3a4b  83c410               add esp, 0x10
// 007a3a4e  c22000               ret 0x20
// library xtp-15.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?DrawTearOffGripper@CXTPDefaultTheme@@UAE?AVCSize@@PAVCDC@@VCRect@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDefaultTheme.cpp
