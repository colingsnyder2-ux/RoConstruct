// from server: 100% by auto
// roc 2010-06 0083dab0  unit: XTPPaintThemes::CXTPOfficeTheme  size: 337 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0083dab0
//
// 0083dab0  83ec10               sub esp, 0x10
// 0083dab3  837c243000           cmp dword ptr [esp + 0x30], 0
// 0083dab8  53                   push ebx
// 0083dab9  55                   push ebp
// 0083daba  56                   push esi
// 0083dabb  57                   push edi
// 0083dabc  8bd9                 mov ebx, ecx
// 0083dabe  0f8422010000         je 0x83dbe6
// 0083dac4  8b542438             mov edx, dword ptr [esp + 0x38]
// 0083dac8  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0083dacc  2b542430             sub edx, dword ptr [esp + 0x30]
// 0083dad0  b801000000           mov eax, 1
// 0083dad5  41                   inc ecx
// 0083dad6  894c2418             mov dword ptr [esp + 0x18], ecx
// 0083dada  03d0                 add edx, eax
// 0083dadc  6a29                 push 0x29
// 0083dade  8bcb                 mov ecx, ebx
// 0083dae0  89442414             mov dword ptr [esp + 0x14], eax
// 0083dae4  89442418             mov dword ptr [esp + 0x18], eax
// 0083dae8  89542420             mov dword ptr [esp + 0x20], edx
// 0083daec  e81ff6f6ff           call 0x7ad110
// 0083daf1  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0083daf5  50                   push eax
// 0083daf6  8d442414             lea eax, [esp + 0x14]
// 0083dafa  50                   push eax
// 0083dafb  8bcd                 mov ecx, ebp
// 0083dafd  e83cacf6ff           call 0x7a873e
// 0083db02  6aff                 push -1
// 0083db04  6aff                 push -1
// 0083db06  8d4c2418             lea ecx, [esp + 0x18]
// 0083db0a  51                   push ecx
// 0083db0b  ff15dcbb9e00         call dword ptr [0x9ebbdc]
// 0083db11  8b442434             mov eax, dword ptr [esp + 0x34]
// 0083db15  2b44242c             sub eax, dword ptr [esp + 0x2c]
// 0083db19  b910000000           mov ecx, 0x10
// 0083db1e  99                   cdq 
// 0083db1f  2bc2                 sub eax, edx
// 0083db21  d1f8                 sar eax, 1
// 0083db23  8d78f6               lea edi, [eax - 0xa]
// 0083db26  83ff10               cmp edi, 0x10
// 0083db29  7f02                 jg 0x83db2d
// 0083db2b  8bcf                 mov ecx, edi
// 0083db2d  8b542418             mov edx, dword ptr [esp + 0x18]
// 0083db31  8b442410             mov eax, dword ptr [esp + 0x10]
// 0083db35  03c2                 add eax, edx
// 0083db37  99                   cdq 
// 0083db38  2bc2                 sub eax, edx
// 0083db3a  d1f8                 sar eax, 1
// 0083db3c  8bf0                 mov esi, eax
// 0083db3e  2bf1                 sub esi, ecx
// 0083db40  83ff10               cmp edi, 0x10
// 0083db43  7e05                 jle 0x83db4a
// 0083db45  bf10000000           mov edi, 0x10
// 0083db4a  03f8                 add edi, eax
// 0083db4c  837c243c00           cmp dword ptr [esp + 0x3c], 0
// 0083db51  7449                 je 0x83db9c
// 0083db53  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0083db57  8b542414             mov edx, dword ptr [esp + 0x14]
// 0083db5b  6a1f                 push 0x1f
// 0083db5d  6a20                 push 0x20
// 0083db5f  83ec10               sub esp, 0x10
// 0083db62  8bc4                 mov eax, esp
// 0083db64  8908                 mov dword ptr [eax], ecx
// 0083db66  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0083db6a  895004               mov dword ptr [eax + 4], edx
// 0083db6d  8b542434             mov edx, dword ptr [esp + 0x34]
// 0083db71  894808               mov dword ptr [eax + 8], ecx
// 0083db74  55                   push ebp
// 0083db75  8bcb                 mov ecx, ebx
// 0083db77  89500c               mov dword ptr [eax + 0xc], edx
// 0083db7a  e8f106f7ff           call 0x7ae270
// 0083db7f  3bf7                 cmp esi, edi
// 0083db81  7d63                 jge 0x83dbe6
// 0083db83  6a2d                 push 0x2d
// 0083db85  6a04                 push 4
// 0083db87  57                   push edi
// 0083db88  6a04                 push 4
// 0083db8a  56                   push esi
// 0083db8b  55                   push ebp
// 0083db8c  8bcb                 mov ecx, ebx
// 0083db8e  e81d0bf7ff           call 0x7ae6b0
// 0083db93  6a2d                 push 0x2d
// 0083db95  6a06                 push 6
// 0083db97  57                   push edi
// 0083db98  6a06                 push 6
// 0083db9a  eb41                 jmp 0x83dbdd
// 0083db9c  6a1e                 push 0x1e
// 0083db9e  8bcb                 mov ecx, ebx
// 0083dba0  e86bf5f6ff           call 0x7ad110
// 0083dba5  50                   push eax
// 0083dba6  8d442414             lea eax, [esp + 0x14]
// 0083dbaa  50                   push eax
// 0083dbab  8bcd                 mov ecx, ebp
// 0083dbad  e88cabf6ff           call 0x7a873e
// 0083dbb2  3bf7                 cmp esi, edi
// 0083dbb4  7d30                 jge 0x83dbe6
// 0083dbb6  6a26                 push 0x26
// 0083dbb8  6a03                 push 3
// 0083dbba  57                   push edi
// 0083dbbb  6a03                 push 3
// 0083dbbd  56                   push esi
// 0083dbbe  55                   push ebp
// 0083dbbf  8bcb                 mov ecx, ebx
// 0083dbc1  e8ea0af7ff           call 0x7ae6b0
// 0083dbc6  6a26                 push 0x26
// 0083dbc8  6a05                 push 5
// 0083dbca  57                   push edi
// 0083dbcb  6a05                 push 5
// 0083dbcd  56                   push esi
// 0083dbce  55                   push ebp
// 0083dbcf  8bcb                 mov ecx, ebx
// 0083dbd1  e8da0af7ff           call 0x7ae6b0
// 0083dbd6  6a26                 push 0x26
// 0083dbd8  6a07                 push 7
// 0083dbda  57                   push edi
// 0083dbdb  6a07                 push 7
// 0083dbdd  56                   push esi
// 0083dbde  55                   push ebp
// 0083dbdf  8bcb                 mov ecx, ebx
// 0083dbe1  e8ca0af7ff           call 0x7ae6b0
// 0083dbe6  8b442424             mov eax, dword ptr [esp + 0x24]
// 0083dbea  5f                   pop edi
// 0083dbeb  5e                   pop esi
// 0083dbec  5d                   pop ebp
// 0083dbed  c70000000000         mov dword ptr [eax], 0
// 0083dbf3  c7400409000000       mov dword ptr [eax + 4], 9
// 0083dbfa  5b                   pop ebx
// 0083dbfb  83c410               add esp, 0x10
// 0083dbfe  c22000               ret 0x20
// library xtp-13.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawTearOffGripper@CXTPOfficeTheme@@UAE?AVCSize@@PAVCDC@@VCRect@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOfficeTheme.cpp
