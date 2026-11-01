// from server: 100% by EspClaude
// from server: 96% by EspClaude
// roc 2008-06 004f4e60  unit: RBX::ViewNew::PBBBuilder  size: 820 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004f4e60
//
// 004f4e60  83ec6c               sub esp, 0x6c
// 004f4e63  53                   push ebx
// 004f4e64  55                   push ebp
// 004f4e65  8be9                 mov ebp, ecx
// 004f4e67  56                   push esi
// 004f4e68  57                   push edi
// 004f4e69  8d4504               lea eax, [ebp + 4]
// 004f4e6c  50                   push eax
// 004f4e6d  8d4c2474             lea ecx, [esp + 0x74]
// 004f4e71  51                   push ecx
// 004f4e72  896c242c             mov dword ptr [esp + 0x2c], ebp
// 004f4e76  e825730f00           call 0x5ec1a0
// 004f4e7b  0fbf8424b8000000     movsx eax, word ptr [esp + 0xb8]
// 004f4e83  89442424             mov dword ptr [esp + 0x24], eax
// 004f4e87  0fbf8c24ba000000     movsx ecx, word ptr [esp + 0xba]
// 004f4e8f  db442424             fild dword ptr [esp + 0x24]
// 004f4e93  d9842498000000       fld dword ptr [esp + 0x98]
// 004f4e9a  894c2424             mov dword ptr [esp + 0x24], ecx
// 004f4e9e  d8a42490000000       fsub dword ptr [esp + 0x90]
// 004f4ea5  40                   inc eax
// 004f4ea6  41                   inc ecx
// 004f4ea7  0fafc8               imul ecx, eax
// 004f4eaa  d8f1                 fdiv st(1)
// 004f4eac  33db                 xor ebx, ebx
// 004f4eae  8bc1                 mov eax, ecx
// 004f4eb0  ba04000000           mov edx, 4
// 004f4eb5  894c2430             mov dword ptr [esp + 0x30], ecx
// 004f4eb9  d95c243c             fstp dword ptr [esp + 0x3c]
// 004f4ebd  f7e2                 mul edx
// 004f4ebf  db442424             fild dword ptr [esp + 0x24]
// 004f4ec3  d984249c000000       fld dword ptr [esp + 0x9c]
// 004f4eca  d8a42494000000       fsub dword ptr [esp + 0x94]
// 004f4ed1  d8f1                 fdiv st(1)
// 004f4ed3  0f90c3               seto bl
// 004f4ed6  f7db                 neg ebx
// 004f4ed8  0bd8                 or ebx, eax
// 004f4eda  53                   push ebx
// 004f4edb  d95c2444             fstp dword ptr [esp + 0x44]
// 004f4edf  d98424b0000000       fld dword ptr [esp + 0xb0]
// 004f4ee6  def2                 fdivrp st(2)
// 004f4ee8  d9c9                 fxch st(1)
// 004f4eea  d95c2448             fstp dword ptr [esp + 0x48]
// 004f4eee  d8bc24b4000000       fdivr dword ptr [esp + 0xb4]
// 004f4ef5  d95c244c             fstp dword ptr [esp + 0x4c]
// 004f4ef9  e858ba1a00           call 0x6a0956
// 004f4efe  d9842494000000       fld dword ptr [esp + 0x94]
// 004f4f05  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 004f4f0c  d954241c             fst dword ptr [esp + 0x1c]
// 004f4f10  d98424a8000000       fld dword ptr [esp + 0xa8]
// 004f4f17  8bf0                 mov esi, eax
// 004f4f19  33c0                 xor eax, eax
// 004f4f1b  d95c2420             fstp dword ptr [esp + 0x20]
// 004f4f1f  83c40c               add esp, 0xc
// 004f4f22  33db                 xor ebx, ebx
// 004f4f24  663bc2               cmp ax, dx
// 004f4f27  668b8424b2000000     mov ax, word ptr [esp + 0xb2]
// 004f4f2f  0f8fdd010000         jg 0x4f5112
// 004f4f35  d9ee                 fldz 
// 004f4f37  eb02                 jmp 0x4f4f3b
// 004f4f39  d9c9                 fxch st(1)
// 004f4f3b  d984248c000000       fld dword ptr [esp + 0x8c]
// 004f4f42  33c9                 xor ecx, ecx
// 004f4f44  d9542418             fst dword ptr [esp + 0x18]
// 004f4f48  33ff                 xor edi, edi
// 004f4f4a  663bc8               cmp cx, ax
// 004f4f4d  d98424a0000000       fld dword ptr [esp + 0xa0]
// 004f4f54  d954241c             fst dword ptr [esp + 0x1c]
// 004f4f58  0f8f8a010000         jg 0x4f50e8
// 004f4f5e  8b8424ac000000       mov eax, dword ptr [esp + 0xac]
// 004f4f65  03c0                 add eax, eax
// 004f4f67  03c0                 add eax, eax
// 004f4f69  8d6c2430             lea ebp, [esp + 0x30]
// 004f4f6d  8d54042c             lea edx, [esp + eax + 0x2c]
// 004f4f71  2be8                 sub ebp, eax
// 004f4f73  89542420             mov dword ptr [esp + 0x20], edx
// 004f4f77  eb0c                 jmp 0x4f4f85
// 004f4f79  d9ee                 fldz 
// 004f4f7b  d9442410             fld dword ptr [esp + 0x10]
// 004f4f7f  d9cb                 fxch st(3)
// 004f4f81  d9c9                 fxch st(1)
// 004f4f83  d9ca                 fxch st(2)
// 004f4f85  d9842498000000       fld dword ptr [esp + 0x98]
// 004f4f8c  8b442420             mov eax, dword ptr [esp + 0x20]
// 004f4f90  d95c2454             fstp dword ptr [esp + 0x54]
// 004f4f94  d9ca                 fxch st(2)
// 004f4f96  d954242c             fst dword ptr [esp + 0x2c]
// 004f4f9a  d9542430             fst dword ptr [esp + 0x30]
// 004f4f9e  d9442414             fld dword ptr [esp + 0x14]
// 004f4fa2  d95d00               fstp dword ptr [ebp]
// 004f4fa5  d9ca                 fxch st(2)
// 004f4fa7  d918                 fstp dword ptr [eax]
// 004f4fa9  d9c9                 fxch st(1)
// 004f4fab  d9542458             fst dword ptr [esp + 0x58]
// 004f4faf  d954245c             fst dword ptr [esp + 0x5c]
// 004f4fb3  d9e8                 fld1 
// 004f4fb5  d95c2460             fstp dword ptr [esp + 0x60]
// 004f4fb9  d8d1                 fcom st(1)
// 004f4fbb  dfe0                 fnstsw ax
// 004f4fbd  f6c405               test ah, 5
// 004f4fc0  7a20                 jp 0x4f4fe2
// 004f4fc2  ddd8                 fstp st(0)
// 004f4fc4  d9842480000000       fld dword ptr [esp + 0x80]
// 004f4fcb  dce9                 fsub st(1), st(0)
// 004f4fcd  d9c9                 fxch st(1)
// 004f4fcf  d95c2450             fstp dword ptr [esp + 0x50]
// 004f4fd3  d9c9                 fxch st(1)
// 004f4fd5  d9e1                 fabs 
// 004f4fd7  dee1                 fsubrp st(1)
// 004f4fd9  d88c2484000000       fmul dword ptr [esp + 0x84]
// 004f4fe0  eb20                 jmp 0x4f5002
// 004f4fe2  d9842480000000       fld dword ptr [esp + 0x80]
// 004f4fe9  d9c0                 fld st(0)
// 004f4feb  dec3                 faddp st(3)
// 004f4fed  d9ca                 fxch st(2)
// 004f4fef  d95c2450             fstp dword ptr [esp + 0x50]
// 004f4ff3  d8da                 fcomp st(2)
// 004f4ff5  dfe0                 fnstsw ax
// 004f4ff7  f6c405               test ah, 5
// 004f4ffa  7a04                 jp 0x4f5000
// 004f4ffc  dee9                 fsubp st(1)
// 004f4ffe  eb02                 jmp 0x4f5002
// 004f5000  dec1                 faddp st(1)
// 004f5002  d95c244c             fstp dword ptr [esp + 0x4c]
// 004f5006  e8954b0100           call 0x509ba0
// 004f500b  8bc8                 mov ecx, eax
// 004f500d  d901                 fld dword ptr [ecx]
// 004f500f  d89c24a4000000       fcomp dword ptr [esp + 0xa4]
// 004f5016  dfe0                 fnstsw ax
// 004f5018  f6c444               test ah, 0x44
// 004f501b  7a21                 jp 0x4f503e
// 004f501d  d94104               fld dword ptr [ecx + 4]
// 004f5020  d89c24a8000000       fcomp dword ptr [esp + 0xa8]
// 004f5027  dfe0                 fnstsw ax
// 004f5029  f6c444               test ah, 0x44
// 004f502c  7a10                 jp 0x4f503e
// 004f502e  d984249c000000       fld dword ptr [esp + 0x9c]
// 004f5035  d98424a0000000       fld dword ptr [esp + 0xa0]
// 004f503c  eb08                 jmp 0x4f5046
// 004f503e  d944242c             fld dword ptr [esp + 0x2c]
// 004f5042  d9442430             fld dword ptr [esp + 0x30]
// 004f5046  d905ac9b8100         fld dword ptr [0x819bac]
// 004f504c  8d4c2458             lea ecx, [esp + 0x58]
// 004f5050  dcca                 fmul st(2), st(0)
// 004f5052  51                   push ecx
// 004f5053  d9ca                 fxch st(2)
// 004f5055  8d542468             lea edx, [esp + 0x68]
// 004f5059  52                   push edx
// 004f505a  d95c244c             fstp dword ptr [esp + 0x4c]
// 004f505e  dec9                 fmulp st(1)
// 004f5060  d95c2450             fstp dword ptr [esp + 0x50]
// 004f5064  e837710f00           call 0x5ec1a0
// 004f5069  8d442454             lea eax, [esp + 0x54]
// 004f506d  50                   push eax
// 004f506e  8d4c247c             lea ecx, [esp + 0x7c]
// 004f5072  51                   push ecx
// 004f5073  e828710f00           call 0x5ec1a0
// 004f5078  6a01                 push 1
// 004f507a  8d542458             lea edx, [esp + 0x58]
// 004f507e  52                   push edx
// 004f507f  8d44247c             lea eax, [esp + 0x7c]
// 004f5083  50                   push eax
// 004f5084  8d8c248c000000       lea ecx, [esp + 0x8c]
// 004f508b  51                   push ecx
// 004f508c  e86f2f0500           call 0x548000
// 004f5091  d9442458             fld dword ptr [esp + 0x58]
// 004f5095  0fbf9424d2000000     movsx edx, word ptr [esp + 0xd2]
// 004f509d  d8442438             fadd dword ptr [esp + 0x38]
// 004f50a1  42                   inc edx
// 004f50a2  0fafd3               imul edx, ebx
// 004f50a5  d9542438             fst dword ptr [esp + 0x38]
// 004f50a9  d9442460             fld dword ptr [esp + 0x60]
// 004f50ad  d844243c             fadd dword ptr [esp + 0x3c]
// 004f50b1  d954243c             fst dword ptr [esp + 0x3c]
// 004f50b5  03d7                 add edx, edi
// 004f50b7  890496               mov dword ptr [esi + edx*4], eax
// 004f50ba  668b8424d2000000     mov ax, word ptr [esp + 0xd2]
// 004f50c2  0fbfc8               movsx ecx, ax
// 004f50c5  47                   inc edi
// 004f50c6  83c420               add esp, 0x20
// 004f50c9  3bf9                 cmp edi, ecx
// 004f50cb  0f8ea8feffff         jle 0x4f4f79
// 004f50d1  8b9424b0000000       mov edx, dword ptr [esp + 0xb0]
// 004f50d8  ddd9                 fstp st(1)
// 004f50da  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 004f50de  ddd8                 fstp st(0)
// 004f50e0  d9442410             fld dword ptr [esp + 0x10]
// 004f50e4  d9ee                 fldz 
// 004f50e6  eb04                 jmp 0x4f50ec
// 004f50e8  ddd9                 fstp st(1)
// 004f50ea  ddd8                 fstp st(0)
// 004f50ec  d9442434             fld dword ptr [esp + 0x34]
// 004f50f0  0fbfca               movsx ecx, dx
// 004f50f3  dec2                 faddp st(2)
// 004f50f5  43                   inc ebx
// 004f50f6  3bd9                 cmp ebx, ecx
// 004f50f8  d9c9                 fxch st(1)
// 004f50fa  d9542410             fst dword ptr [esp + 0x10]
// 004f50fe  d944243c             fld dword ptr [esp + 0x3c]
// 004f5102  d8442414             fadd dword ptr [esp + 0x14]
// 004f5106  d95c2414             fstp dword ptr [esp + 0x14]
// 004f510a  0f8e29feffff         jle 0x4f4f39
// 004f5110  ddd9                 fstp st(1)
// 004f5112  33c9                 xor ecx, ecx
// 004f5114  ddd8                 fstp st(0)
// 004f5116  33db                 xor ebx, ebx
// 004f5118  663bca               cmp cx, dx
// 004f511b  7d49                 jge 0x4f5166
// 004f511d  0fbfc8               movsx ecx, ax
// 004f5120  33ff                 xor edi, edi
// 004f5122  85c9                 test ecx, ecx
// 004f5124  7e38                 jle 0x4f515e
// 004f5126  8d4101               lea eax, [ecx + 1]
// 004f5129  0fafc3               imul eax, ebx
// 004f512c  03c7                 add eax, edi
// 004f512e  03c8                 add ecx, eax
// 004f5130  8b548e08             mov edx, dword ptr [esi + ecx*4 + 8]
// 004f5134  8b4c8e04             mov ecx, dword ptr [esi + ecx*4 + 4]
// 004f5138  52                   push edx
// 004f5139  8b1486               mov edx, dword ptr [esi + eax*4]
// 004f513c  8b448604             mov eax, dword ptr [esi + eax*4 + 4]
// 004f5140  51                   push ecx
// 004f5141  52                   push edx
// 004f5142  50                   push eax
// 004f5143  8bcd                 mov ecx, ebp
// 004f5145  e866bd0000           call 0x500eb0
// 004f514a  0fbf8c24b2000000     movsx ecx, word ptr [esp + 0xb2]
// 004f5152  47                   inc edi
// 004f5153  3bf9                 cmp edi, ecx
// 004f5155  7ccf                 jl 0x4f5126
// 004f5157  8b9424b0000000       mov edx, dword ptr [esp + 0xb0]
// 004f515e  0fbfc2               movsx eax, dx
// 004f5161  43                   inc ebx
// 004f5162  3bd8                 cmp ebx, eax
// 004f5164  7cba                 jl 0x4f5120
// 004f5166  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 004f516a  33ff                 xor edi, edi
// 004f516c  85db                 test ebx, ebx
// 004f516e  7611                 jbe 0x4f5181
// 004f5170  8b0cbe               mov ecx, dword ptr [esi + edi*4]
// 004f5173  51                   push ecx
// 004f5174  e8c7340500           call 0x548640
// 004f5179  47                   inc edi
// 004f517a  83c404               add esp, 4
// 004f517d  3bfb                 cmp edi, ebx
// 004f517f  72ef                 jb 0x4f5170
// 004f5181  56                   push esi
// 004f5182  e8c3b71a00           call 0x6a094a
// 004f5187  83c404               add esp, 4
// 004f518a  5f                   pop edi
// 004f518b  5e                   pop esi
// 004f518c  5d                   pop ebp
// 004f518d  5b                   pop ebx
// 004f518e  83c46c               add esp, 0x6c
// 004f5191  c23400               ret 0x34

extern "C" double __cdecl fabs(double);
#pragma intrinsic(fabs)
// roc-flags: /O2 /fp:fast /GS- /EHsc /MD
// from server: 98% by coldek
// roc 2008-06 004fac10  unit: RBX::ViewNew::TorsoBuilder  size: 739 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004fac10
//
// 004fac10  55                   push ebp
// 004fac11  8bec                 mov ebp, esp
// 004fac13  83e4f8               and esp, 0xfffffff8
// 004fac16  81ec84000000         sub esp, 0x84
// 004fac1c  53                   push ebx
// 004fac1d  56                   push esi
// 004fac1e  894c242c             mov dword ptr [esp + 0x2c], ecx
// 004fac22  57                   push edi
// 004fac23  83c104               add ecx, 4
// 004fac26  51                   push ecx
// 004fac27  8d442464             lea eax, [esp + 0x64]
// 004fac2b  50                   push eax
// 004fac2c  e86f150f00           call 0x5ec1a0
// 004fac31  d9442468             fld dword ptr [esp + 0x68]
// 004fac35  0fbf4534             movsx eax, word ptr [ebp + 0x34]
// 004fac39  d9e1                 fabs 
// 004fac3b  d95c2474             fstp dword ptr [esp + 0x74]
// 004fac3f  8944242c             mov dword ptr [esp + 0x2c], eax
// 004fac43  d944246c             fld dword ptr [esp + 0x6c]
// 004fac47  0fbf7d36             movsx edi, word ptr [ebp + 0x36]
// 004fac4b  d9e1                 fabs 
// 004fac4d  d95c2478             fstp dword ptr [esp + 0x78]
// 004fac51  d9442470             fld dword ptr [esp + 0x70]
// 004fac55  40                   inc eax
// 004fac56  d9e1                 fabs 
// 004fac58  33c9                 xor ecx, ecx
// 004fac5a  d95c247c             fstp dword ptr [esp + 0x7c]
// 004fac5e  ba04000000           mov edx, 4
// 004fac63  db44242c             fild dword ptr [esp + 0x2c]
// 004fac67  897c242c             mov dword ptr [esp + 0x2c], edi
// 004fac6b  d94514               fld dword ptr [ebp + 0x14]
// 004fac6e  47                   inc edi
// 004fac6f  d8650c               fsub dword ptr [ebp + 0xc]
// 004fac72  0faff8               imul edi, eax
// 004fac75  d8f1                 fdiv st(1)
// 004fac77  8bc7                 mov eax, edi
// 004fac79  d95c2444             fstp dword ptr [esp + 0x44]
// 004fac7d  f7e2                 mul edx
// 004fac7f  db44242c             fild dword ptr [esp + 0x2c]
// 004fac83  d94518               fld dword ptr [ebp + 0x18]
// 004fac86  d86510               fsub dword ptr [ebp + 0x10]
// 004fac89  d8f1                 fdiv st(1)
// 004fac8b  0f90c1               seto cl
// 004fac8e  897c242c             mov dword ptr [esp + 0x2c], edi
// 004fac92  f7d9                 neg ecx
// 004fac94  0bc8                 or ecx, eax
// 004fac96  51                   push ecx
// 004fac97  d95c244c             fstp dword ptr [esp + 0x4c]
// 004fac9b  d94528               fld dword ptr [ebp + 0x28]
// 004fac9e  def2                 fdivrp st(2)
// 004faca0  d9c9                 fxch st(1)
// 004faca2  d95c2450             fstp dword ptr [esp + 0x50]
// 004faca6  d87d2c               fdivr dword ptr [ebp + 0x2c]
// 004faca9  d95c2454             fstp dword ptr [esp + 0x54]
// 004facad  e8a45c1a00           call 0x6a0956
// 004facb2  d9450c               fld dword ptr [ebp + 0xc]
// 004facb5  8b5534               mov edx, dword ptr [ebp + 0x34]
// 004facb8  d95c241c             fstp dword ptr [esp + 0x1c]
// 004facbc  d94520               fld dword ptr [ebp + 0x20]
// 004facbf  8bf0                 mov esi, eax
// 004facc1  33c0                 xor eax, eax
// 004facc3  d95c2420             fstp dword ptr [esp + 0x20]
// 004facc7  83c40c               add esp, 0xc
// 004facca  33db                 xor ebx, ebx
// 004faccc  663bc2               cmp ax, dx
// 004faccf  668b4536             mov ax, word ptr [ebp + 0x36]
// 004facd3  0f8f9c010000         jg 0x4fae75
// 004facd9  d9ee                 fldz 
// 004facdb  d94510               fld dword ptr [ebp + 0x10]
// 004facde  33c9                 xor ecx, ecx
// 004face0  d954241c             fst dword ptr [esp + 0x1c]
// 004face4  33ff                 xor edi, edi
// 004face6  663bc8               cmp cx, ax
// 004face9  d94524               fld dword ptr [ebp + 0x24]
// 004facec  d9542420             fst dword ptr [esp + 0x20]
// 004facf0  0f8f51010000         jg 0x4fae47
// 004facf6  8b4d30               mov ecx, dword ptr [ebp + 0x30]
// 004facf9  03c9                 add ecx, ecx
// 004facfb  03c9                 add ecx, ecx
// 004facfd  8d442438             lea eax, [esp + 0x38]
// 004fad01  2bc1                 sub eax, ecx
// 004fad03  8d540c34             lea edx, [esp + ecx + 0x34]
// 004fad07  89442428             mov dword ptr [esp + 0x28], eax
// 004fad0b  8954242c             mov dword ptr [esp + 0x2c], edx
// 004fad0f  eb0a                 jmp 0x4fad1b
// 004fad11  d9ee                 fldz 
// 004fad13  8b442428             mov eax, dword ptr [esp + 0x28]
// 004fad17  d9ca                 fxch st(2)
// 004fad19  d9c9                 fxch st(1)
// 004fad1b  d9442410             fld dword ptr [esp + 0x10]
// 004fad1f  8d4c2418             lea ecx, [esp + 0x18]
// 004fad23  d95c2460             fstp dword ptr [esp + 0x60]
// 004fad27  51                   push ecx
// 004fad28  d9c9                 fxch st(1)
// 004fad2a  8d542470             lea edx, [esp + 0x70]
// 004fad2e  d95c2468             fstp dword ptr [esp + 0x68]
// 004fad32  52                   push edx
// 004fad33  d9451c               fld dword ptr [ebp + 0x1c]
// 004fad36  8d4c245c             lea ecx, [esp + 0x5c]
// 004fad3a  d95c2470             fstp dword ptr [esp + 0x70]
// 004fad3e  8d542468             lea edx, [esp + 0x68]
// 004fad42  d9c9                 fxch st(1)
// 004fad44  66895c2420           mov word ptr [esp + 0x20], bx
// 004fad49  d954243c             fst dword ptr [esp + 0x3c]
// 004fad4d  66897c2422           mov word ptr [esp + 0x22], di
// 004fad52  d9542440             fst dword ptr [esp + 0x40]
// 004fad56  d944241c             fld dword ptr [esp + 0x1c]
// 004fad5a  d918                 fstp dword ptr [eax]
// 004fad5c  8b442434             mov eax, dword ptr [esp + 0x34]
// 004fad60  d9c9                 fxch st(1)
// 004fad62  d918                 fstp dword ptr [eax]
// 004fad64  8d44243c             lea eax, [esp + 0x3c]
// 004fad68  50                   push eax
// 004fad69  d9542460             fst dword ptr [esp + 0x60]
// 004fad6d  51                   push ecx
// 004fad6e  d95c2468             fstp dword ptr [esp + 0x68]
// 004fad72  52                   push edx
// 004fad73  d9e8                 fld1 
// 004fad75  d95c2470             fstp dword ptr [esp + 0x70]
// 004fad79  ff5508               call dword ptr [ebp + 8]
// 004fad7c  83c414               add esp, 0x14
// 004fad7f  e81cee0000           call 0x509ba0
// 004fad84  8bc8                 mov ecx, eax
// 004fad86  d901                 fld dword ptr [ecx]
// 004fad88  d85d28               fcomp dword ptr [ebp + 0x28]
// 004fad8b  dfe0                 fnstsw ax
// 004fad8d  f6c444               test ah, 0x44
// 004fad90  7a1b                 jp 0x4fadad
// 004fad92  d94104               fld dword ptr [ecx + 4]
// 004fad95  d85d2c               fcomp dword ptr [ebp + 0x2c]
// 004fad98  dfe0                 fnstsw ax
// 004fad9a  f6c444               test ah, 0x44
// 004fad9d  7a0e                 jp 0x4fadad
// 004fad9f  d94520               fld dword ptr [ebp + 0x20]
// 004fada2  d95c2434             fstp dword ptr [esp + 0x34]
// 004fada6  d94524               fld dword ptr [ebp + 0x24]
// 004fada9  d95c2438             fstp dword ptr [esp + 0x38]
// 004fadad  d9442434             fld dword ptr [esp + 0x34]
// 004fadb1  8d442454             lea eax, [esp + 0x54]
// 004fadb5  d905ac9b8100         fld dword ptr [0x819bac]
// 004fadbb  50                   push eax
// 004fadbc  dcc9                 fmul st(1), st(0)
// 004fadbe  8d4c247c             lea ecx, [esp + 0x7c]
// 004fadc2  d9c9                 fxch st(1)
// 004fadc4  51                   push ecx
// 004fadc5  d95c2454             fstp dword ptr [esp + 0x54]
// 004fadc9  d84c2440             fmul dword ptr [esp + 0x40]
// 004fadcd  d95c2458             fstp dword ptr [esp + 0x58]
// 004fadd1  e8ca130f00           call 0x5ec1a0
// 004fadd6  8d542468             lea edx, [esp + 0x68]
// 004fadda  52                   push edx
// 004faddb  8d842490000000       lea eax, [esp + 0x90]
// 004fade2  50                   push eax
// 004fade3  e8b8130f00           call 0x5ec1a0
// 004fade8  6a01                 push 1
// 004fadea  8d4c2460             lea ecx, [esp + 0x60]
// 004fadee  51                   push ecx
// 004fadef  8d942490000000       lea edx, [esp + 0x90]
// 004fadf6  52                   push edx
// 004fadf7  8d8424a0000000       lea eax, [esp + 0xa0]
// 004fadfe  50                   push eax
// 004fadff  e8fcd10400           call 0x548000
// 004fae04  d9442460             fld dword ptr [esp + 0x60]
// 004fae08  0fbf4d36             movsx ecx, word ptr [ebp + 0x36]
// 004fae0c  d844243c             fadd dword ptr [esp + 0x3c]
// 004fae10  41                   inc ecx
// 004fae11  0fafcb               imul ecx, ebx
// 004fae14  d954243c             fst dword ptr [esp + 0x3c]
// 004fae18  d9442468             fld dword ptr [esp + 0x68]
// 004fae1c  d8442440             fadd dword ptr [esp + 0x40]
// 004fae20  d9542440             fst dword ptr [esp + 0x40]
// 004fae24  03cf                 add ecx, edi
// 004fae26  89048e               mov dword ptr [esi + ecx*4], eax
// 004fae29  668b4536             mov ax, word ptr [ebp + 0x36]
// 004fae2d  0fbfd0               movsx edx, ax
// 004fae30  47                   inc edi
// 004fae31  83c420               add esp, 0x20
// 004fae34  3bfa                 cmp edi, edx
// 004fae36  0f8ed5feffff         jle 0x4fad11
// 004fae3c  8b5534               mov edx, dword ptr [ebp + 0x34]
// 004fae3f  ddd9                 fstp st(1)
// 004fae41  ddd8                 fstp st(0)
// 004fae43  d9ee                 fldz 
// 004fae45  eb04                 jmp 0x4fae4b
// 004fae47  ddd9                 fstp st(1)
// 004fae49  ddd8                 fstp st(0)
// 004fae4b  d944243c             fld dword ptr [esp + 0x3c]
// 004fae4f  0fbfca               movsx ecx, dx
// 004fae52  d8442410             fadd dword ptr [esp + 0x10]
// 004fae56  43                   inc ebx
// 004fae57  3bd9                 cmp ebx, ecx
// 004fae59  d95c2410             fstp dword ptr [esp + 0x10]
// 004fae5d  d9442444             fld dword ptr [esp + 0x44]
// 004fae61  d8442414             fadd dword ptr [esp + 0x14]
// 004fae65  d95c2414             fstp dword ptr [esp + 0x14]
// 004fae69  0f8e6cfeffff         jle 0x4facdb
// 004fae6f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004fae73  ddd8                 fstp st(0)
// 004fae75  33c9                 xor ecx, ecx
// 004fae77  33db                 xor ebx, ebx
// 004fae79  663bca               cmp cx, dx
// 004fae7c  7d47                 jge 0x4faec5
// 004fae7e  0fbfc8               movsx ecx, ax
// 004fae81  33ff                 xor edi, edi
// 004fae83  85c9                 test ecx, ecx
// 004fae85  7e32                 jle 0x4faeb9
// 004fae87  8d4101               lea eax, [ecx + 1]
// 004fae8a  0fafc3               imul eax, ebx
// 004fae8d  03c7                 add eax, edi
// 004fae8f  03c8                 add ecx, eax
// 004fae91  8b548e08             mov edx, dword ptr [esi + ecx*4 + 8]
// 004fae95  8b4c8e04             mov ecx, dword ptr [esi + ecx*4 + 4]
// 004fae99  52                   push edx
// 004fae9a  8b1486               mov edx, dword ptr [esi + eax*4]
// 004fae9d  8b448604             mov eax, dword ptr [esi + eax*4 + 4]
// 004faea1  51                   push ecx
// 004faea2  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 004faea6  52                   push edx
// 004faea7  50                   push eax
// 004faea8  e803600000           call 0x500eb0
// 004faead  0fbf4d36             movsx ecx, word ptr [ebp + 0x36]
// 004faeb1  47                   inc edi
// 004faeb2  3bf9                 cmp edi, ecx
// 004faeb4  7cd1                 jl 0x4fae87
// 004faeb6  8b5534               mov edx, dword ptr [ebp + 0x34]
// 004faeb9  0fbfc2               movsx eax, dx
// 004faebc  43                   inc ebx
// 004faebd  3bd8                 cmp ebx, eax
// 004faebf  7cc0                 jl 0x4fae81
// 004faec1  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004faec5  33db                 xor ebx, ebx
// 004faec7  85ff                 test edi, edi
// 004faec9  7616                 jbe 0x4faee1
// 004faecb  eb03                 jmp 0x4faed0
// 004faecd  8d4900               lea ecx, [ecx]
// 004faed0  8b0c9e               mov ecx, dword ptr [esi + ebx*4]
// 004faed3  51                   push ecx
// 004faed4  e867d70400           call 0x548640
// 004faed9  43                   inc ebx
// 004faeda  83c404               add esp, 4
// 004faedd  3bdf                 cmp ebx, edi
// 004faedf  72ef                 jb 0x4faed0
// 004faee1  56                   push esi
// 004faee2  e8635a1a00           call 0x6a094a
// 004faee7  83c404               add esp, 4
// 004faeea  5f                   pop edi
// 004faeeb  5e                   pop esi
// 004faeec  5b                   pop ebx
// 004faeed  8be5                 mov esp, ebp
// 004faeef  5d                   pop ebp
// 004faef0  c23000               ret 0x30


struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;
};

struct GridSize {
    short x, y;
};

extern void __cdecl copyVector(Vec3*, const Vec3*);
extern const Vec2& __cdecl currentTextureSize();
extern int __cdecl allocateVertex(const Vec3*, const Vec3*, const Vec2*, int);
extern void __cdecl releaseVertex(int);
extern const float textureScale;

struct VertexCallback {
    float inset;
    float bevel;
    void operator()(Vec3* p, Vec3* n, Vec2* t, const Vec3* dims, const GridSize* idx)
    {
        if (p->y > 0) {
            p->y -= inset;
            p->x = ((float)fabs(p->x) - inset) * bevel;
        } else {
            p->y += inset;
            if (p->x > 0)
                p->x -= inset;
            else
                p->x += inset;
        }
    }
};

struct TorsoBuilder {
    char prefix[4];
    Vec3 dimensions;

    void build(VertexCallback, Vec2, Vec2, float, Vec2, Vec2, int, GridSize);
    void quad(int, int, int, int);
};

//#pragma float_control(precise, off, push)

void TorsoBuilder::build(
    VertexCallback callback,
    Vec2 minimum,
    Vec2 maximum,
    float depth,
    Vec2 textureOrigin,
    Vec2 textureExtent,
    int axis,
    GridSize divisions)
{
    Vec3 absoluteDimensions;
    {
        Vec3 copiedDimensions;
        copyVector(&copiedDimensions, &dimensions);
        absoluteDimensions.x = (float)fabs(copiedDimensions.x);
        absoluteDimensions.y = (float)fabs(copiedDimensions.y);
        absoluteDimensions.z = (float)fabs(copiedDimensions.z);
    }

    float x = 0, u = 0, y = 0, v = 0;

    Vec2 positionStep;
    positionStep.x = (maximum.x - minimum.x) / divisions.x;
    positionStep.y = (maximum.y - minimum.y) / divisions.y;

    Vec2 textureStep;
    textureStep.x = textureExtent.x / divisions.x;
    textureStep.y = textureExtent.y / divisions.y;

    unsigned count = (divisions.x + 1) * (divisions.y + 1);
    int* vertices = new int[count];

    x = minimum.x;
    u = textureOrigin.x;

    for (int i = 0; i <= divisions.x; ++i) {
        y = minimum.y;
        v = textureOrigin.y;
        GridSize index;
        index.x = (short)i;

        for (int j = 0; j <= divisions.y; ++j) {
            Vec3 position;
            position.x = x;
            position.y = y;
            position.z = depth;

            Vec2 texture;
            texture.x = 0.0f;
            texture.y = 0.0f;
            (&texture.y)[-axis] = u;
            (&texture.x)[axis] = v;

            Vec3 normal;
            normal.x = 0.0f;
            normal.y = 0.0f;
            normal.z = 1.0f;

            index.y = (short)j;

            callback(&position, &normal, &texture, &absoluteDimensions, &index);

            const Vec2& size = currentTextureSize();
            float tx, ty;
            if (textureExtent.x == size.x && textureExtent.y == size.y) {
                tx = textureOrigin.x;
                ty = textureOrigin.y;
            } else {
                tx = texture.x;
                ty = texture.y;
            }

            Vec2 scaledTexture;
            scaledTexture.x = tx * textureScale;
            scaledTexture.y = ty * textureScale;

            Vec3 copiedNormal;
            Vec3 copiedPosition;
            copyVector(&copiedNormal, &normal);
            copyVector(&copiedPosition, &position);

            vertices[i * (divisions.y + 1) + j] =
                allocateVertex(&copiedPosition, &copiedNormal, &scaledTexture, 1);

            y += positionStep.y;
            v += textureStep.y;
        }

        x += positionStep.x;
        u += textureStep.x;
    }

    for (int i = 0; i < divisions.x; ++i) {
        for (int j = 0; j < divisions.y; ++j) {
            int index = (divisions.y + 1) * i + j;
            int next = index + divisions.y;
            quad(vertices[index + 1], vertices[index],
                 vertices[next + 1], vertices[next + 2]);
        }
    }

    for (unsigned i = 0; i < count; ++i)
        releaseVertex(vertices[i]);

    delete[] vertices;
}

//#pragma float_control(pop)
