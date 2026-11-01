// from server: 100% by auto
// roc 2009-12 008140e0  unit: CXTPCommandBars  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008140e0
//
// 008140e0  83ec24               sub esp, 0x24
// 008140e3  53                   push ebx
// 008140e4  55                   push ebp
// 008140e5  8be9                 mov ebp, ecx
// 008140e7  8b85a0000000         mov eax, dword ptr [ebp + 0xa0]
// 008140ed  56                   push esi
// 008140ee  57                   push edi
// 008140ef  c74424141be80000     mov dword ptr [esp + 0x14], 0xe81b
// 008140f7  c744241800280000     mov dword ptr [esp + 0x18], 0x2800
// 008140ff  c744241c1ee80000     mov dword ptr [esp + 0x1c], 0xe81e
// 00814107  c744242000820000     mov dword ptr [esp + 0x20], 0x8200
// 0081410f  c74424241ce80000     mov dword ptr [esp + 0x24], 0xe81c
// 00814117  c744242800140000     mov dword ptr [esp + 0x28], 0x1400
// 0081411f  c744242c1de80000     mov dword ptr [esp + 0x2c], 0xe81d
// 00814127  c744243000410000     mov dword ptr [esp + 0x30], 0x4100
// 0081412f  89442410             mov dword ptr [esp + 0x10], eax
// 00814133  33f6                 xor esi, esi
// 00814135  8d9d90000000         lea ebx, [ebp + 0x90]
// 0081413b  eb03                 jmp 0x814140
// 0081413d  8d4900               lea ecx, [ecx]
// 00814140  8b0d4caeb900         mov ecx, dword ptr [0xb9ae4c]
// 00814146  e81701feff           call 0x7f4262
// 0081414b  8b4cf414             mov ecx, dword ptr [esp + esi*8 + 0x14]
// 0081414f  8b54f418             mov edx, dword ptr [esp + esi*8 + 0x18]
// 00814153  51                   push ecx
// 00814154  8bf8                 mov edi, eax
// 00814156  8b442414             mov eax, dword ptr [esp + 0x14]
// 0081415a  81ca00000056         or edx, 0x56000000
// 00814160  52                   push edx
// 00814161  50                   push eax
// 00814162  8bcf                 mov ecx, edi
// 00814164  896f6c               mov dword ptr [edi + 0x6c], ebp
// 00814167  e854ce0700           call 0x890fc0
// 0081416c  85c0                 test eax, eax
// 0081416e  7505                 jne 0x814175
// 00814170  e859241100           call 0x9265ce
// 00814175  893b                 mov dword ptr [ebx], edi
// 00814177  46                   inc esi
// 00814178  83c304               add ebx, 4
// 0081417b  83fe04               cmp esi, 4
// 0081417e  7cc0                 jl 0x814140
// 00814180  5f                   pop edi
// 00814181  5e                   pop esi
// 00814182  5d                   pop ebp
// 00814183  5b                   pop ebx
// 00814184  83c424               add esp, 0x24
// 00814187  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?EnableDocking@CXTPCommandBars@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
