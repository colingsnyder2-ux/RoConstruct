// from server: 100% by auto
// roc 2009-12 00803f40  unit: CFont  size: 355 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00803f40
//
// 00803f40  55                   push ebp
// 00803f41  8bec                 mov ebp, esp
// 00803f43  83e4c0               and esp, 0xffffffc0
// 00803f46  83ec34               sub esp, 0x34
// 00803f49  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00803f4c  8b5518               mov edx, dword ptr [ebp + 0x18]
// 00803f4f  53                   push ebx
// 00803f50  56                   push esi
// 00803f51  8b7510               mov esi, dword ptr [ebp + 0x10]
// 00803f54  57                   push edi
// 00803f55  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 00803f58  8d4c38ff             lea ecx, [eax + edi - 1]
// 00803f5c  894c2418             mov dword ptr [esp + 0x18], ecx
// 00803f60  db442418             fild dword ptr [esp + 0x18]
// 00803f64  8d4c32ff             lea ecx, [edx + esi - 1]
// 00803f68  dd0510329b00         fld qword ptr [0x9b3210]
// 00803f6e  894c2418             mov dword ptr [esp + 0x18], ecx
// 00803f72  8bd0                 mov edx, eax
// 00803f74  dcc9                 fmul st(1), st(0)
// 00803f76  2bd7                 sub edx, edi
// 00803f78  d9c9                 fxch st(1)
// 00803f7a  4a                   dec edx
// 00803f7b  3bf8                 cmp edi, eax
// 00803f7d  dd5c2428             fstp qword ptr [esp + 0x28]
// 00803f81  db442418             fild dword ptr [esp + 0x18]
// 00803f85  89542418             mov dword ptr [esp + 0x18], edx
// 00803f89  d8c9                 fmul st(1)
// 00803f8b  dd5c2430             fstp qword ptr [esp + 0x30]
// 00803f8f  db442418             fild dword ptr [esp + 0x18]
// 00803f93  897c2418             mov dword ptr [esp + 0x18], edi
// 00803f97  dec9                 fmulp st(1)
// 00803f99  dc2530e39b00         fsub qword ptr [0x9be330]
// 00803f9f  dd5c2420             fstp qword ptr [esp + 0x20]
// 00803fa3  0f8df1000000         jge 0x80409a
// 00803fa9  8b5d08               mov ebx, dword ptr [ebp + 8]
// 00803fac  d9e8                 fld1 
// 00803fae  3b7518               cmp esi, dword ptr [ebp + 0x18]
// 00803fb1  89742414             mov dword ptr [esp + 0x14], esi
// 00803fb5  0f8dd0000000         jge 0x80408b
// 00803fbb  db442418             fild dword ptr [esp + 0x18]
// 00803fbf  dc6c2428             fsubr qword ptr [esp + 0x28]
// 00803fc3  dd5c2418             fstp qword ptr [esp + 0x18]
// 00803fc7  dd442420             fld qword ptr [esp + 0x20]
// 00803fcb  d8e1                 fsub st(1)
// 00803fcd  dd5c2438             fstp qword ptr [esp + 0x38]
// 00803fd1  dd442418             fld qword ptr [esp + 0x18]
// 00803fd5  b802000000           mov eax, 2
// 00803fda  d9c1                 fld st(1)
// 00803fdc  a801                 test al, 1
// 00803fde  7402                 je 0x803fe2
// 00803fe0  d8c9                 fmul st(1)
// 00803fe2  d1e8                 shr eax, 1
// 00803fe4  7406                 je 0x803fec
// 00803fe6  d9c1                 fld st(1)
// 00803fe8  deca                 fmulp st(2)
// 00803fea  ebf0                 jmp 0x803fdc
// 00803fec  ddd9                 fstp st(1)
// 00803fee  b802000000           mov eax, 2
// 00803ff3  db442414             fild dword ptr [esp + 0x14]
// 00803ff7  dc6c2430             fsubr qword ptr [esp + 0x30]
// 00803ffb  a801                 test al, 1
// 00803ffd  7402                 je 0x804001
// 00803fff  dcca                 fmul st(2), st(0)
// 00804001  d1e8                 shr eax, 1
// 00804003  7404                 je 0x804009
// 00804005  dcc8                 fmul st(0), st(0)
// 00804007  ebf2                 jmp 0x803ffb
// 00804009  ddd8                 fstp st(0)
// 0080400b  dec1                 faddp st(1)
// 0080400d  e81411ffff           call 0x7f5126
// 00804012  dd442438             fld qword ptr [esp + 0x38]
// 00804016  d8d1                 fcom st(1)
// 00804018  dfe0                 fnstsw ax
// 0080401a  f6c441               test ah, 0x41
// 0080401d  7a3d                 jp 0x80405c
// 0080401f  dd442420             fld qword ptr [esp + 0x20]
// 00804023  dd05c8449a00         fld qword ptr [0x9a44c8]
// 00804029  d8c1                 fadd st(1)
// 0080402b  d8db                 fcomp st(3)
// 0080402d  dfe0                 fnstsw ax
// 0080402f  f6c401               test ah, 1
// 00804032  7526                 jne 0x80405a
// 00804034  8b4520               mov eax, dword ptr [ebp + 0x20]
// 00804037  ddd9                 fstp st(1)
// 00804039  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 0080403c  dee9                 fsubp st(1)
// 0080403e  83ec08               sub esp, 8
// 00804041  dd1c24               fstp qword ptr [esp]
// 00804044  50                   push eax
// 00804045  51                   push ecx
// 00804046  56                   push esi
// 00804047  57                   push edi
// 00804048  53                   push ebx
// 00804049  e8d2a8ffff           call 0x7fe920
// 0080404e  8b5304               mov edx, dword ptr [ebx + 4]
// 00804051  83c41c               add esp, 0x1c
// 00804054  50                   push eax
// 00804055  56                   push esi
// 00804056  57                   push edi
// 00804057  52                   push edx
// 00804058  eb15                 jmp 0x80406f
// 0080405a  ddd8                 fstp st(0)
// 0080405c  ded9                 fcompp 
// 0080405e  dfe0                 fnstsw ax
// 00804060  f6c441               test ah, 0x41
// 00804063  7510                 jne 0x804075
// 00804065  8b4520               mov eax, dword ptr [ebp + 0x20]
// 00804068  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0080406b  50                   push eax
// 0080406c  56                   push esi
// 0080406d  57                   push edi
// 0080406e  51                   push ecx
// 0080406f  ff1514b19800         call dword ptr [0x98b114]
// 00804075  d9e8                 fld1 
// 00804077  46                   inc esi
// 00804078  3b7518               cmp esi, dword ptr [ebp + 0x18]
// 0080407b  89742414             mov dword ptr [esp + 0x14], esi
// 0080407f  0f8c4cffffff         jl 0x803fd1
// 00804085  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00804088  8b7510               mov esi, dword ptr [ebp + 0x10]
// 0080408b  47                   inc edi
// 0080408c  3bf8                 cmp edi, eax
// 0080408e  897c2418             mov dword ptr [esp + 0x18], edi
// 00804092  0f8c16ffffff         jl 0x803fae
// 00804098  ddd8                 fstp st(0)
// 0080409a  5f                   pop edi
// 0080409b  5e                   pop esi
// 0080409c  5b                   pop ebx
// 0080409d  8be5                 mov esp, ebp
// 0080409f  5d                   pop ebp
// 008040a0  c21c00               ret 0x1c
// library xtp-15.2.1/Source\Controls\Button\XTPButtonTheme.cpp (function ?AlphaEllipse@CXTPButtonTheme@@QAEXPAVCDC@@VCRect@@KK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Button/XTPButtonTheme.cpp
