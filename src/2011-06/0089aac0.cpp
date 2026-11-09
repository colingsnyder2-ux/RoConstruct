// from server: 100% by auto
// roc 2011-06 0089aac0  unit: XTPPaintThemes::CXTPOfficeTheme  size: 337 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0089aac0
//
// 0089aac0  83ec10               sub esp, 0x10
// 0089aac3  837c243000           cmp dword ptr [esp + 0x30], 0
// 0089aac8  53                   push ebx
// 0089aac9  55                   push ebp
// 0089aaca  56                   push esi
// 0089aacb  57                   push edi
// 0089aacc  8bd9                 mov ebx, ecx
// 0089aace  0f8422010000         je 0x89abf6
// 0089aad4  8b542438             mov edx, dword ptr [esp + 0x38]
// 0089aad8  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0089aadc  2b542430             sub edx, dword ptr [esp + 0x30]
// 0089aae0  b801000000           mov eax, 1
// 0089aae5  41                   inc ecx
// 0089aae6  894c2418             mov dword ptr [esp + 0x18], ecx
// 0089aaea  03d0                 add edx, eax
// 0089aaec  6a29                 push 0x29
// 0089aaee  8bcb                 mov ecx, ebx
// 0089aaf0  89442414             mov dword ptr [esp + 0x14], eax
// 0089aaf4  89442418             mov dword ptr [esp + 0x18], eax
// 0089aaf8  89542420             mov dword ptr [esp + 0x20], edx
// 0089aafc  e8af4af7ff           call 0x80f5b0
// 0089ab01  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0089ab05  50                   push eax
// 0089ab06  8d442414             lea eax, [esp + 0x14]
// 0089ab0a  50                   push eax
// 0089ab0b  8bcd                 mov ecx, ebp
// 0089ab0d  e80e03f7ff           call 0x80ae20
// 0089ab12  6aff                 push -1
// 0089ab14  6aff                 push -1
// 0089ab16  8d4c2418             lea ecx, [esp + 0x18]
// 0089ab1a  51                   push ecx
// 0089ab1b  ff15e41ba400         call dword ptr [0xa41be4]
// 0089ab21  8b442434             mov eax, dword ptr [esp + 0x34]
// 0089ab25  2b44242c             sub eax, dword ptr [esp + 0x2c]
// 0089ab29  b910000000           mov ecx, 0x10
// 0089ab2e  99                   cdq 
// 0089ab2f  2bc2                 sub eax, edx
// 0089ab31  d1f8                 sar eax, 1
// 0089ab33  8d78f6               lea edi, [eax - 0xa]
// 0089ab36  83ff10               cmp edi, 0x10
// 0089ab39  7f02                 jg 0x89ab3d
// 0089ab3b  8bcf                 mov ecx, edi
// 0089ab3d  8b542418             mov edx, dword ptr [esp + 0x18]
// 0089ab41  8b442410             mov eax, dword ptr [esp + 0x10]
// 0089ab45  03c2                 add eax, edx
// 0089ab47  99                   cdq 
// 0089ab48  2bc2                 sub eax, edx
// 0089ab4a  d1f8                 sar eax, 1
// 0089ab4c  8bf0                 mov esi, eax
// 0089ab4e  2bf1                 sub esi, ecx
// 0089ab50  83ff10               cmp edi, 0x10
// 0089ab53  7e05                 jle 0x89ab5a
// 0089ab55  bf10000000           mov edi, 0x10
// 0089ab5a  03f8                 add edi, eax
// 0089ab5c  837c243c00           cmp dword ptr [esp + 0x3c], 0
// 0089ab61  7449                 je 0x89abac
// 0089ab63  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0089ab67  8b542414             mov edx, dword ptr [esp + 0x14]
// 0089ab6b  6a1f                 push 0x1f
// 0089ab6d  6a20                 push 0x20
// 0089ab6f  83ec10               sub esp, 0x10
// 0089ab72  8bc4                 mov eax, esp
// 0089ab74  8908                 mov dword ptr [eax], ecx
// 0089ab76  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0089ab7a  895004               mov dword ptr [eax + 4], edx
// 0089ab7d  8b542434             mov edx, dword ptr [esp + 0x34]
// 0089ab81  894808               mov dword ptr [eax + 8], ecx
// 0089ab84  55                   push ebp
// 0089ab85  8bcb                 mov ecx, ebx
// 0089ab87  89500c               mov dword ptr [eax + 0xc], edx
// 0089ab8a  e8f15af7ff           call 0x810680
// 0089ab8f  3bf7                 cmp esi, edi
// 0089ab91  7d63                 jge 0x89abf6
// 0089ab93  6a2d                 push 0x2d
// 0089ab95  6a04                 push 4
// 0089ab97  57                   push edi
// 0089ab98  6a04                 push 4
// 0089ab9a  56                   push esi
// 0089ab9b  55                   push ebp
// 0089ab9c  8bcb                 mov ecx, ebx
// 0089ab9e  e81d5ff7ff           call 0x810ac0
// 0089aba3  6a2d                 push 0x2d
// 0089aba5  6a06                 push 6
// 0089aba7  57                   push edi
// 0089aba8  6a06                 push 6
// 0089abaa  eb41                 jmp 0x89abed
// 0089abac  6a1e                 push 0x1e
// 0089abae  8bcb                 mov ecx, ebx
// 0089abb0  e8fb49f7ff           call 0x80f5b0
// 0089abb5  50                   push eax
// 0089abb6  8d442414             lea eax, [esp + 0x14]
// 0089abba  50                   push eax
// 0089abbb  8bcd                 mov ecx, ebp
// 0089abbd  e85e02f7ff           call 0x80ae20
// 0089abc2  3bf7                 cmp esi, edi
// 0089abc4  7d30                 jge 0x89abf6
// 0089abc6  6a26                 push 0x26
// 0089abc8  6a03                 push 3
// 0089abca  57                   push edi
// 0089abcb  6a03                 push 3
// 0089abcd  56                   push esi
// 0089abce  55                   push ebp
// 0089abcf  8bcb                 mov ecx, ebx
// 0089abd1  e8ea5ef7ff           call 0x810ac0
// 0089abd6  6a26                 push 0x26
// 0089abd8  6a05                 push 5
// 0089abda  57                   push edi
// 0089abdb  6a05                 push 5
// 0089abdd  56                   push esi
// 0089abde  55                   push ebp
// 0089abdf  8bcb                 mov ecx, ebx
// 0089abe1  e8da5ef7ff           call 0x810ac0
// 0089abe6  6a26                 push 0x26
// 0089abe8  6a07                 push 7
// 0089abea  57                   push edi
// 0089abeb  6a07                 push 7
// 0089abed  56                   push esi
// 0089abee  55                   push ebp
// 0089abef  8bcb                 mov ecx, ebx
// 0089abf1  e8ca5ef7ff           call 0x810ac0
// 0089abf6  8b442424             mov eax, dword ptr [esp + 0x24]
// 0089abfa  5f                   pop edi
// 0089abfb  5e                   pop esi
// 0089abfc  5d                   pop ebp
// 0089abfd  c70000000000         mov dword ptr [eax], 0
// 0089ac03  c7400409000000       mov dword ptr [eax + 4], 9
// 0089ac0a  5b                   pop ebx
// 0089ac0b  83c410               add esp, 0x10
// 0089ac0e  c22000               ret 0x20
// library xtp-13.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawTearOffGripper@CXTPOfficeTheme@@UAE?AVCSize@@PAVCDC@@VCRect@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOfficeTheme.cpp
