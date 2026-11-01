// from server: 100% by auto
// roc 2009-06 00728fa0  unit: CXTPPaintManager  size: 355 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00728fa0
//
// 00728fa0  55                   push ebp
// 00728fa1  8bec                 mov ebp, esp
// 00728fa3  83e4c0               and esp, 0xffffffc0
// 00728fa6  83ec34               sub esp, 0x34
// 00728fa9  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00728fac  8b5518               mov edx, dword ptr [ebp + 0x18]
// 00728faf  53                   push ebx
// 00728fb0  56                   push esi
// 00728fb1  8b7510               mov esi, dword ptr [ebp + 0x10]
// 00728fb4  57                   push edi
// 00728fb5  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 00728fb8  8d4c38ff             lea ecx, [eax + edi - 1]
// 00728fbc  894c2418             mov dword ptr [esp + 0x18], ecx
// 00728fc0  db442418             fild dword ptr [esp + 0x18]
// 00728fc4  8d4c32ff             lea ecx, [edx + esi - 1]
// 00728fc8  dd05f8018c00         fld qword ptr [0x8c01f8]
// 00728fce  894c2418             mov dword ptr [esp + 0x18], ecx
// 00728fd2  8bd0                 mov edx, eax
// 00728fd4  dcc9                 fmul st(1), st(0)
// 00728fd6  2bd7                 sub edx, edi
// 00728fd8  d9c9                 fxch st(1)
// 00728fda  4a                   dec edx
// 00728fdb  3bf8                 cmp edi, eax
// 00728fdd  dd5c2428             fstp qword ptr [esp + 0x28]
// 00728fe1  db442418             fild dword ptr [esp + 0x18]
// 00728fe5  89542418             mov dword ptr [esp + 0x18], edx
// 00728fe9  d8c9                 fmul st(1)
// 00728feb  dd5c2430             fstp qword ptr [esp + 0x30]
// 00728fef  db442418             fild dword ptr [esp + 0x18]
// 00728ff3  897c2418             mov dword ptr [esp + 0x18], edi
// 00728ff7  dec9                 fmulp st(1)
// 00728ff9  dc25e87d8c00         fsub qword ptr [0x8c7de8]
// 00728fff  dd5c2420             fstp qword ptr [esp + 0x20]
// 00729003  0f8df1000000         jge 0x7290fa
// 00729009  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0072900c  d9e8                 fld1 
// 0072900e  3b7518               cmp esi, dword ptr [ebp + 0x18]
// 00729011  89742414             mov dword ptr [esp + 0x14], esi
// 00729015  0f8dd0000000         jge 0x7290eb
// 0072901b  db442418             fild dword ptr [esp + 0x18]
// 0072901f  dc6c2428             fsubr qword ptr [esp + 0x28]
// 00729023  dd5c2418             fstp qword ptr [esp + 0x18]
// 00729027  dd442420             fld qword ptr [esp + 0x20]
// 0072902b  d8e1                 fsub st(1)
// 0072902d  dd5c2438             fstp qword ptr [esp + 0x38]
// 00729031  dd442418             fld qword ptr [esp + 0x18]
// 00729035  b802000000           mov eax, 2
// 0072903a  d9c1                 fld st(1)
// 0072903c  a801                 test al, 1
// 0072903e  7402                 je 0x729042
// 00729040  d8c9                 fmul st(1)
// 00729042  d1e8                 shr eax, 1
// 00729044  7406                 je 0x72904c
// 00729046  d9c1                 fld st(1)
// 00729048  deca                 fmulp st(2)
// 0072904a  ebf0                 jmp 0x72903c
// 0072904c  ddd9                 fstp st(1)
// 0072904e  b802000000           mov eax, 2
// 00729053  db442414             fild dword ptr [esp + 0x14]
// 00729057  dc6c2430             fsubr qword ptr [esp + 0x30]
// 0072905b  a801                 test al, 1
// 0072905d  7402                 je 0x729061
// 0072905f  dcca                 fmul st(2), st(0)
// 00729061  d1e8                 shr eax, 1
// 00729063  7404                 je 0x729069
// 00729065  dcc8                 fmul st(0), st(0)
// 00729067  ebf2                 jmp 0x72905b
// 00729069  ddd8                 fstp st(0)
// 0072906b  dec1                 faddp st(1)
// 0072906d  e81815ffff           call 0x71a58a
// 00729072  dd442438             fld qword ptr [esp + 0x38]
// 00729076  d8d1                 fcom st(1)
// 00729078  dfe0                 fnstsw ax
// 0072907a  f6c441               test ah, 0x41
// 0072907d  7a3d                 jp 0x7290bc
// 0072907f  dd442420             fld qword ptr [esp + 0x20]
// 00729083  dd05c0178b00         fld qword ptr [0x8b17c0]
// 00729089  d8c1                 fadd st(1)
// 0072908b  d8db                 fcomp st(3)
// 0072908d  dfe0                 fnstsw ax
// 0072908f  f6c401               test ah, 1
// 00729092  7526                 jne 0x7290ba
// 00729094  8b4520               mov eax, dword ptr [ebp + 0x20]
// 00729097  ddd9                 fstp st(1)
// 00729099  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 0072909c  dee9                 fsubp st(1)
// 0072909e  83ec08               sub esp, 8
// 007290a1  dd1c24               fstp qword ptr [esp]
// 007290a4  50                   push eax
// 007290a5  51                   push ecx
// 007290a6  56                   push esi
// 007290a7  57                   push edi
// 007290a8  53                   push ebx
// 007290a9  e802a9ffff           call 0x7239b0
// 007290ae  8b5304               mov edx, dword ptr [ebx + 4]
// 007290b1  83c41c               add esp, 0x1c
// 007290b4  50                   push eax
// 007290b5  56                   push esi
// 007290b6  57                   push edi
// 007290b7  52                   push edx
// 007290b8  eb15                 jmp 0x7290cf
// 007290ba  ddd8                 fstp st(0)
// 007290bc  ded9                 fcompp 
// 007290be  dfe0                 fnstsw ax
// 007290c0  f6c441               test ah, 0x41
// 007290c3  7510                 jne 0x7290d5
// 007290c5  8b4520               mov eax, dword ptr [ebp + 0x20]
// 007290c8  8b4b04               mov ecx, dword ptr [ebx + 4]
// 007290cb  50                   push eax
// 007290cc  56                   push esi
// 007290cd  57                   push edi
// 007290ce  51                   push ecx
// 007290cf  ff15d4e08900         call dword ptr [0x89e0d4]
// 007290d5  d9e8                 fld1 
// 007290d7  46                   inc esi
// 007290d8  3b7518               cmp esi, dword ptr [ebp + 0x18]
// 007290db  89742414             mov dword ptr [esp + 0x14], esi
// 007290df  0f8c4cffffff         jl 0x729031
// 007290e5  8b4514               mov eax, dword ptr [ebp + 0x14]
// 007290e8  8b7510               mov esi, dword ptr [ebp + 0x10]
// 007290eb  47                   inc edi
// 007290ec  3bf8                 cmp edi, eax
// 007290ee  897c2418             mov dword ptr [esp + 0x18], edi
// 007290f2  0f8c16ffffff         jl 0x72900e
// 007290f8  ddd8                 fstp st(0)
// 007290fa  5f                   pop edi
// 007290fb  5e                   pop esi
// 007290fc  5b                   pop ebx
// 007290fd  8be5                 mov esp, ebp
// 007290ff  5d                   pop ebp
// 00729100  c21c00               ret 0x1c
// library xtp-15.2.1/Source\Controls\Button\XTPButtonTheme.cpp (function ?AlphaEllipse@CXTPButtonTheme@@QAEXPAVCDC@@VCRect@@KK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Button/XTPButtonTheme.cpp
