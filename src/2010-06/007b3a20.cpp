// from server: 100% by auto
// roc 2010-06 007b3a20  unit: CXTPPaintManager  size: 355 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b3a20
//
// 007b3a20  55                   push ebp
// 007b3a21  8bec                 mov ebp, esp
// 007b3a23  83e4c0               and esp, 0xffffffc0
// 007b3a26  83ec34               sub esp, 0x34
// 007b3a29  8b4514               mov eax, dword ptr [ebp + 0x14]
// 007b3a2c  8b5518               mov edx, dword ptr [ebp + 0x18]
// 007b3a2f  53                   push ebx
// 007b3a30  56                   push esi
// 007b3a31  8b7510               mov esi, dword ptr [ebp + 0x10]
// 007b3a34  57                   push edi
// 007b3a35  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 007b3a38  8d4c38ff             lea ecx, [eax + edi - 1]
// 007b3a3c  894c2418             mov dword ptr [esp + 0x18], ecx
// 007b3a40  db442418             fild dword ptr [esp + 0x18]
// 007b3a44  8d4c32ff             lea ecx, [edx + esi - 1]
// 007b3a48  dd057850a100         fld qword ptr [0xa15078]
// 007b3a4e  894c2418             mov dword ptr [esp + 0x18], ecx
// 007b3a52  8bd0                 mov edx, eax
// 007b3a54  dcc9                 fmul st(1), st(0)
// 007b3a56  2bd7                 sub edx, edi
// 007b3a58  d9c9                 fxch st(1)
// 007b3a5a  4a                   dec edx
// 007b3a5b  3bf8                 cmp edi, eax
// 007b3a5d  dd5c2428             fstp qword ptr [esp + 0x28]
// 007b3a61  db442418             fild dword ptr [esp + 0x18]
// 007b3a65  89542418             mov dword ptr [esp + 0x18], edx
// 007b3a69  d8c9                 fmul st(1)
// 007b3a6b  dd5c2430             fstp qword ptr [esp + 0x30]
// 007b3a6f  db442418             fild dword ptr [esp + 0x18]
// 007b3a73  897c2418             mov dword ptr [esp + 0x18], edi
// 007b3a77  dec9                 fmulp st(1)
// 007b3a79  dc25b0c2a100         fsub qword ptr [0xa1c2b0]
// 007b3a7f  dd5c2420             fstp qword ptr [esp + 0x20]
// 007b3a83  0f8df1000000         jge 0x7b3b7a
// 007b3a89  8b5d08               mov ebx, dword ptr [ebp + 8]
// 007b3a8c  d9e8                 fld1 
// 007b3a8e  3b7518               cmp esi, dword ptr [ebp + 0x18]
// 007b3a91  89742414             mov dword ptr [esp + 0x14], esi
// 007b3a95  0f8dd0000000         jge 0x7b3b6b
// 007b3a9b  db442418             fild dword ptr [esp + 0x18]
// 007b3a9f  dc6c2428             fsubr qword ptr [esp + 0x28]
// 007b3aa3  dd5c2418             fstp qword ptr [esp + 0x18]
// 007b3aa7  dd442420             fld qword ptr [esp + 0x20]
// 007b3aab  d8e1                 fsub st(1)
// 007b3aad  dd5c2438             fstp qword ptr [esp + 0x38]
// 007b3ab1  dd442418             fld qword ptr [esp + 0x18]
// 007b3ab5  b802000000           mov eax, 2
// 007b3aba  d9c1                 fld st(1)
// 007b3abc  a801                 test al, 1
// 007b3abe  7402                 je 0x7b3ac2
// 007b3ac0  d8c9                 fmul st(1)
// 007b3ac2  d1e8                 shr eax, 1
// 007b3ac4  7406                 je 0x7b3acc
// 007b3ac6  d9c1                 fld st(1)
// 007b3ac8  deca                 fmulp st(2)
// 007b3aca  ebf0                 jmp 0x7b3abc
// 007b3acc  ddd9                 fstp st(1)
// 007b3ace  b802000000           mov eax, 2
// 007b3ad3  db442414             fild dword ptr [esp + 0x14]
// 007b3ad7  dc6c2430             fsubr qword ptr [esp + 0x30]
// 007b3adb  a801                 test al, 1
// 007b3add  7402                 je 0x7b3ae1
// 007b3adf  dcca                 fmul st(2), st(0)
// 007b3ae1  d1e8                 shr eax, 1
// 007b3ae3  7404                 je 0x7b3ae9
// 007b3ae5  dcc8                 fmul st(0), st(0)
// 007b3ae7  ebf2                 jmp 0x7b3adb
// 007b3ae9  ddd8                 fstp st(0)
// 007b3aeb  dec1                 faddp st(1)
// 007b3aed  e87457ffff           call 0x7a9266
// 007b3af2  dd442438             fld qword ptr [esp + 0x38]
// 007b3af6  d8d1                 fcom st(1)
// 007b3af8  dfe0                 fnstsw ax
// 007b3afa  f6c441               test ah, 0x41
// 007b3afd  7a3d                 jp 0x7b3b3c
// 007b3aff  dd442420             fld qword ptr [esp + 0x20]
// 007b3b03  dd054052a000         fld qword ptr [0xa05240]
// 007b3b09  d8c1                 fadd st(1)
// 007b3b0b  d8db                 fcomp st(3)
// 007b3b0d  dfe0                 fnstsw ax
// 007b3b0f  f6c401               test ah, 1
// 007b3b12  7526                 jne 0x7b3b3a
// 007b3b14  8b4520               mov eax, dword ptr [ebp + 0x20]
// 007b3b17  ddd9                 fstp st(1)
// 007b3b19  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 007b3b1c  dee9                 fsubp st(1)
// 007b3b1e  83ec08               sub esp, 8
// 007b3b21  dd1c24               fstp qword ptr [esp]
// 007b3b24  50                   push eax
// 007b3b25  51                   push ecx
// 007b3b26  56                   push esi
// 007b3b27  57                   push edi
// 007b3b28  53                   push ebx
// 007b3b29  e802a9ffff           call 0x7ae430
// 007b3b2e  8b5304               mov edx, dword ptr [ebx + 4]
// 007b3b31  83c41c               add esp, 0x1c
// 007b3b34  50                   push eax
// 007b3b35  56                   push esi
// 007b3b36  57                   push edi
// 007b3b37  52                   push edx
// 007b3b38  eb15                 jmp 0x7b3b4f
// 007b3b3a  ddd8                 fstp st(0)
// 007b3b3c  ded9                 fcompp 
// 007b3b3e  dfe0                 fnstsw ax
// 007b3b40  f6c441               test ah, 0x41
// 007b3b43  7510                 jne 0x7b3b55
// 007b3b45  8b4520               mov eax, dword ptr [ebp + 0x20]
// 007b3b48  8b4b04               mov ecx, dword ptr [ebx + 4]
// 007b3b4b  50                   push eax
// 007b3b4c  56                   push esi
// 007b3b4d  57                   push edi
// 007b3b4e  51                   push ecx
// 007b3b4f  ff155ca19e00         call dword ptr [0x9ea15c]
// 007b3b55  d9e8                 fld1 
// 007b3b57  46                   inc esi
// 007b3b58  3b7518               cmp esi, dword ptr [ebp + 0x18]
// 007b3b5b  89742414             mov dword ptr [esp + 0x14], esi
// 007b3b5f  0f8c4cffffff         jl 0x7b3ab1
// 007b3b65  8b4514               mov eax, dword ptr [ebp + 0x14]
// 007b3b68  8b7510               mov esi, dword ptr [ebp + 0x10]
// 007b3b6b  47                   inc edi
// 007b3b6c  3bf8                 cmp edi, eax
// 007b3b6e  897c2418             mov dword ptr [esp + 0x18], edi
// 007b3b72  0f8c16ffffff         jl 0x7b3a8e
// 007b3b78  ddd8                 fstp st(0)
// 007b3b7a  5f                   pop edi
// 007b3b7b  5e                   pop esi
// 007b3b7c  5b                   pop ebx
// 007b3b7d  8be5                 mov esp, ebp
// 007b3b7f  5d                   pop ebp
// 007b3b80  c21c00               ret 0x1c
// library xtp-13.2.1/Source\Controls\XTPButton.cpp (function ?AlphaEllipse@CXTPButtonTheme@@QAEXPAVCDC@@VCRect@@KK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTPButton.cpp
