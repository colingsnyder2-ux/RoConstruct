// from server: 100% by auto
// roc 2009-06 007293f0  unit: CXTPCommandBars  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007293f0
//
// 007293f0  83ec24               sub esp, 0x24
// 007293f3  53                   push ebx
// 007293f4  55                   push ebp
// 007293f5  8be9                 mov ebp, ecx
// 007293f7  8b85a0000000         mov eax, dword ptr [ebp + 0xa0]
// 007293fd  56                   push esi
// 007293fe  57                   push edi
// 007293ff  c74424141be80000     mov dword ptr [esp + 0x14], 0xe81b
// 00729407  c744241800280000     mov dword ptr [esp + 0x18], 0x2800
// 0072940f  c744241c1ee80000     mov dword ptr [esp + 0x1c], 0xe81e
// 00729417  c744242000820000     mov dword ptr [esp + 0x20], 0x8200
// 0072941f  c74424241ce80000     mov dword ptr [esp + 0x24], 0xe81c
// 00729427  c744242800140000     mov dword ptr [esp + 0x28], 0x1400
// 0072942f  c744242c1de80000     mov dword ptr [esp + 0x2c], 0xe81d
// 00729437  c744243000410000     mov dword ptr [esp + 0x30], 0x4100
// 0072943f  89442410             mov dword ptr [esp + 0x10], eax
// 00729443  33f6                 xor esi, esi
// 00729445  8d9d90000000         lea ebx, [ebp + 0x90]
// 0072944b  eb03                 jmp 0x729450
// 0072944d  8d4900               lea ecx, [ecx]
// 00729450  8b0d5c19a500         mov ecx, dword ptr [0xa5195c]
// 00729456  e8d9fffeff           call 0x719434
// 0072945b  8b4cf414             mov ecx, dword ptr [esp + esi*8 + 0x14]
// 0072945f  8b54f418             mov edx, dword ptr [esp + esi*8 + 0x18]
// 00729463  51                   push ecx
// 00729464  8bf8                 mov edi, eax
// 00729466  8b442414             mov eax, dword ptr [esp + 0x14]
// 0072946a  81ca00000056         or edx, 0x56000000
// 00729470  52                   push edx
// 00729471  50                   push eax
// 00729472  8bcf                 mov ecx, edi
// 00729474  896f6c               mov dword ptr [edi + 0x6c], ebp
// 00729477  e834910800           call 0x7b25b0
// 0072947c  85c0                 test eax, eax
// 0072947e  7505                 jne 0x729485
// 00729480  e8cf2a1200           call 0x84bf54
// 00729485  893b                 mov dword ptr [ebx], edi
// 00729487  46                   inc esi
// 00729488  83c304               add ebx, 4
// 0072948b  83fe04               cmp esi, 4
// 0072948e  7cc0                 jl 0x729450
// 00729490  5f                   pop edi
// 00729491  5e                   pop esi
// 00729492  5d                   pop ebp
// 00729493  5b                   pop ebx
// 00729494  83c424               add esp, 0x24
// 00729497  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?EnableDocking@CXTPCommandBars@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
