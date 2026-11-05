// from server: 100% by auto
// roc 2009-06 007af670  unit: XTPPaintThemes::CXTPOfficeTheme  size: 337 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007af670
//
// 007af670  83ec10               sub esp, 0x10
// 007af673  837c243000           cmp dword ptr [esp + 0x30], 0
// 007af678  53                   push ebx
// 007af679  55                   push ebp
// 007af67a  56                   push esi
// 007af67b  57                   push edi
// 007af67c  8bd9                 mov ebx, ecx
// 007af67e  0f8422010000         je 0x7af7a6
// 007af684  8b542438             mov edx, dword ptr [esp + 0x38]
// 007af688  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 007af68c  2b542430             sub edx, dword ptr [esp + 0x30]
// 007af690  b801000000           mov eax, 1
// 007af695  41                   inc ecx
// 007af696  894c2418             mov dword ptr [esp + 0x18], ecx
// 007af69a  03d0                 add edx, eax
// 007af69c  6a29                 push 0x29
// 007af69e  8bcb                 mov ecx, ebx
// 007af6a0  89442414             mov dword ptr [esp + 0x14], eax
// 007af6a4  89442418             mov dword ptr [esp + 0x18], eax
// 007af6a8  89542420             mov dword ptr [esp + 0x20], edx
// 007af6ac  e8cf30f7ff           call 0x722780
// 007af6b1  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 007af6b5  50                   push eax
// 007af6b6  8d442414             lea eax, [esp + 0x14]
// 007af6ba  50                   push eax
// 007af6bb  8bcd                 mov ecx, ebp
// 007af6bd  e80ea1f6ff           call 0x7197d0
// 007af6c2  6aff                 push -1
// 007af6c4  6aff                 push -1
// 007af6c6  8d4c2418             lea ecx, [esp + 0x18]
// 007af6ca  51                   push ecx
// 007af6cb  ff15bced8900         call dword ptr [0x89edbc]
// 007af6d1  8b442434             mov eax, dword ptr [esp + 0x34]
// 007af6d5  2b44242c             sub eax, dword ptr [esp + 0x2c]
// 007af6d9  b910000000           mov ecx, 0x10
// 007af6de  99                   cdq 
// 007af6df  2bc2                 sub eax, edx
// 007af6e1  d1f8                 sar eax, 1
// 007af6e3  8d78f6               lea edi, [eax - 0xa]
// 007af6e6  83ff10               cmp edi, 0x10
// 007af6e9  7f02                 jg 0x7af6ed
// 007af6eb  8bcf                 mov ecx, edi
// 007af6ed  8b542418             mov edx, dword ptr [esp + 0x18]
// 007af6f1  8b442410             mov eax, dword ptr [esp + 0x10]
// 007af6f5  03c2                 add eax, edx
// 007af6f7  99                   cdq 
// 007af6f8  2bc2                 sub eax, edx
// 007af6fa  d1f8                 sar eax, 1
// 007af6fc  8bf0                 mov esi, eax
// 007af6fe  2bf1                 sub esi, ecx
// 007af700  83ff10               cmp edi, 0x10
// 007af703  7e05                 jle 0x7af70a
// 007af705  bf10000000           mov edi, 0x10
// 007af70a  03f8                 add edi, eax
// 007af70c  837c243c00           cmp dword ptr [esp + 0x3c], 0
// 007af711  7449                 je 0x7af75c
// 007af713  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007af717  8b542414             mov edx, dword ptr [esp + 0x14]
// 007af71b  6a1f                 push 0x1f
// 007af71d  6a20                 push 0x20
// 007af71f  83ec10               sub esp, 0x10
// 007af722  8bc4                 mov eax, esp
// 007af724  8908                 mov dword ptr [eax], ecx
// 007af726  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007af72a  895004               mov dword ptr [eax + 4], edx
// 007af72d  8b542434             mov edx, dword ptr [esp + 0x34]
// 007af731  894808               mov dword ptr [eax + 8], ecx
// 007af734  55                   push ebp
// 007af735  8bcb                 mov ecx, ebx
// 007af737  89500c               mov dword ptr [eax + 0xc], edx
// 007af73a  e8b140f7ff           call 0x7237f0
// 007af73f  3bf7                 cmp esi, edi
// 007af741  7d63                 jge 0x7af7a6
// 007af743  6a2d                 push 0x2d
// 007af745  6a04                 push 4
// 007af747  57                   push edi
// 007af748  6a04                 push 4
// 007af74a  56                   push esi
// 007af74b  55                   push ebp
// 007af74c  8bcb                 mov ecx, ebx
// 007af74e  e8dd44f7ff           call 0x723c30
// 007af753  6a2d                 push 0x2d
// 007af755  6a06                 push 6
// 007af757  57                   push edi
// 007af758  6a06                 push 6
// 007af75a  eb41                 jmp 0x7af79d
// 007af75c  6a1e                 push 0x1e
// 007af75e  8bcb                 mov ecx, ebx
// 007af760  e81b30f7ff           call 0x722780
// 007af765  50                   push eax
// 007af766  8d442414             lea eax, [esp + 0x14]
// 007af76a  50                   push eax
// 007af76b  8bcd                 mov ecx, ebp
// 007af76d  e85ea0f6ff           call 0x7197d0
// 007af772  3bf7                 cmp esi, edi
// 007af774  7d30                 jge 0x7af7a6
// 007af776  6a26                 push 0x26
// 007af778  6a03                 push 3
// 007af77a  57                   push edi
// 007af77b  6a03                 push 3
// 007af77d  56                   push esi
// 007af77e  55                   push ebp
// 007af77f  8bcb                 mov ecx, ebx
// 007af781  e8aa44f7ff           call 0x723c30
// 007af786  6a26                 push 0x26
// 007af788  6a05                 push 5
// 007af78a  57                   push edi
// 007af78b  6a05                 push 5
// 007af78d  56                   push esi
// 007af78e  55                   push ebp
// 007af78f  8bcb                 mov ecx, ebx
// 007af791  e89a44f7ff           call 0x723c30
// 007af796  6a26                 push 0x26
// 007af798  6a07                 push 7
// 007af79a  57                   push edi
// 007af79b  6a07                 push 7
// 007af79d  56                   push esi
// 007af79e  55                   push ebp
// 007af79f  8bcb                 mov ecx, ebx
// 007af7a1  e88a44f7ff           call 0x723c30
// 007af7a6  8b442424             mov eax, dword ptr [esp + 0x24]
// 007af7aa  5f                   pop edi
// 007af7ab  5e                   pop esi
// 007af7ac  5d                   pop ebp
// 007af7ad  c70000000000         mov dword ptr [eax], 0
// 007af7b3  c7400409000000       mov dword ptr [eax + 4], 9
// 007af7ba  5b                   pop ebx
// 007af7bb  83c410               add esp, 0x10
// 007af7be  c22000               ret 0x20
// library xtp-13.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawTearOffGripper@CXTPOfficeTheme@@UAE?AVCSize@@PAVCDC@@VCRect@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOfficeTheme.cpp
