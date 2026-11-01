// from server: 100% by EspClaude
// from server: 99% by EspClaude
// roc 2008-06 004fe350  unit: RBX::ViewNew::CylinderBuilder  size: 739 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004fe350
//
// 004fe350  55                   push ebp
// 004fe351  8bec                 mov ebp, esp
// 004fe353  83e4f8               and esp, 0xfffffff8
// 004fe356  81ec84000000         sub esp, 0x84
// 004fe35c  53                   push ebx
// 004fe35d  56                   push esi
// 004fe35e  894c242c             mov dword ptr [esp + 0x2c], ecx
// 004fe362  57                   push edi
// 004fe363  83c104               add ecx, 4
// 004fe366  51                   push ecx
// 004fe367  8d442464             lea eax, [esp + 0x64]
// 004fe36b  50                   push eax
// 004fe36c  e86fde0e00           call 0x5ec1e0
// 004fe371  d9442468             fld dword ptr [esp + 0x68]
// 004fe375  0fbf4538             movsx eax, word ptr [ebp + 0x38]
// 004fe379  d9e1                 fabs 
// 004fe37b  d95c2474             fstp dword ptr [esp + 0x74]
// 004fe37f  8944242c             mov dword ptr [esp + 0x2c], eax
// 004fe383  d944246c             fld dword ptr [esp + 0x6c]
// 004fe387  0fbf7d3a             movsx edi, word ptr [ebp + 0x3a]
// 004fe38b  d9e1                 fabs 
// 004fe38d  d95c2478             fstp dword ptr [esp + 0x78]
// 004fe391  d9442470             fld dword ptr [esp + 0x70]
// 004fe395  40                   inc eax
// 004fe396  d9e1                 fabs 
// 004fe398  33c9                 xor ecx, ecx
// 004fe39a  d95c247c             fstp dword ptr [esp + 0x7c]
// 004fe39e  ba04000000           mov edx, 4
// 004fe3a3  db44242c             fild dword ptr [esp + 0x2c]
// 004fe3a7  897c242c             mov dword ptr [esp + 0x2c], edi
// 004fe3ab  d94518               fld dword ptr [ebp + 0x18]
// 004fe3ae  47                   inc edi
// 004fe3af  d86510               fsub dword ptr [ebp + 0x10]
// 004fe3b2  0faff8               imul edi, eax
// 004fe3b5  d8f1                 fdiv st(1)
// 004fe3b7  8bc7                 mov eax, edi
// 004fe3b9  d95c2444             fstp dword ptr [esp + 0x44]
// 004fe3bd  f7e2                 mul edx
// 004fe3bf  db44242c             fild dword ptr [esp + 0x2c]
// 004fe3c3  d9451c               fld dword ptr [ebp + 0x1c]
// 004fe3c6  d86514               fsub dword ptr [ebp + 0x14]
// 004fe3c9  d8f1                 fdiv st(1)
// 004fe3cb  0f90c1               seto cl
// 004fe3ce  897c242c             mov dword ptr [esp + 0x2c], edi
// 004fe3d2  f7d9                 neg ecx
// 004fe3d4  0bc8                 or ecx, eax
// 004fe3d6  51                   push ecx
// 004fe3d7  d95c244c             fstp dword ptr [esp + 0x4c]
// 004fe3db  d9452c               fld dword ptr [ebp + 0x2c]
// 004fe3de  def2                 fdivrp st(2)
// 004fe3e0  d9c9                 fxch st(1)
// 004fe3e2  d95c2450             fstp dword ptr [esp + 0x50]
// 004fe3e6  d87d30               fdivr dword ptr [ebp + 0x30]
// 004fe3e9  d95c2454             fstp dword ptr [esp + 0x54]
// 004fe3ed  e864251a00           call 0x6a0956
// 004fe3f2  d94510               fld dword ptr [ebp + 0x10]
// 004fe3f5  8b5538               mov edx, dword ptr [ebp + 0x38]
// 004fe3f8  d95c241c             fstp dword ptr [esp + 0x1c]
// 004fe3fc  d94524               fld dword ptr [ebp + 0x24]
// 004fe3ff  8bf0                 mov esi, eax
// 004fe401  33c0                 xor eax, eax
// 004fe403  d95c2420             fstp dword ptr [esp + 0x20]
// 004fe407  83c40c               add esp, 0xc
// 004fe40a  33db                 xor ebx, ebx
// 004fe40c  663bc2               cmp ax, dx
// 004fe40f  668b453a             mov ax, word ptr [ebp + 0x3a]
// 004fe413  0f8f9a010000         jg 0x4fe5b3
// 004fe419  d9ee                 fldz 
// 004fe41b  d94514               fld dword ptr [ebp + 0x14]
// 004fe41e  33c9                 xor ecx, ecx
// 004fe420  d954241c             fst dword ptr [esp + 0x1c]
// 004fe424  33ff                 xor edi, edi
// 004fe426  663bc8               cmp cx, ax
// 004fe429  d94528               fld dword ptr [ebp + 0x28]
// 004fe42c  d9542420             fst dword ptr [esp + 0x20]
// 004fe430  0f8f4f010000         jg 0x4fe585
// 004fe436  8b4d34               mov ecx, dword ptr [ebp + 0x34]
// 004fe439  03c9                 add ecx, ecx
// 004fe43b  03c9                 add ecx, ecx
// 004fe43d  8d442438             lea eax, [esp + 0x38]
// 004fe441  2bc1                 sub eax, ecx
// 004fe443  8d540c34             lea edx, [esp + ecx + 0x34]
// 004fe447  89442428             mov dword ptr [esp + 0x28], eax
// 004fe44b  8954242c             mov dword ptr [esp + 0x2c], edx
// 004fe44f  66895c2418           mov word ptr [esp + 0x18], bx
// 004fe454  eb0a                 jmp 0x4fe460
// 004fe456  d9ee                 fldz 
// 004fe458  8b442428             mov eax, dword ptr [esp + 0x28]
// 004fe45c  d9ca                 fxch st(2)
// 004fe45e  d9c9                 fxch st(1)
// 004fe460  d9442410             fld dword ptr [esp + 0x10]
// 004fe464  8d4c2418             lea ecx, [esp + 0x18]
// 004fe468  d95c2460             fstp dword ptr [esp + 0x60]
// 004fe46c  51                   push ecx
// 004fe46d  d9c9                 fxch st(1)
// 004fe46f  8d542470             lea edx, [esp + 0x70]
// 004fe473  d95c2468             fstp dword ptr [esp + 0x68]
// 004fe477  52                   push edx
// 004fe478  d94520               fld dword ptr [ebp + 0x20]
// 004fe47b  8d4c245c             lea ecx, [esp + 0x5c]
// 004fe47f  d95c2470             fstp dword ptr [esp + 0x70]
// 004fe483  8d542468             lea edx, [esp + 0x68]
// 004fe487  d9c9                 fxch st(1)
// 004fe489  66897c2422           mov word ptr [esp + 0x22], di
// 004fe48e  d954243c             fst dword ptr [esp + 0x3c]
// 004fe492  d9542440             fst dword ptr [esp + 0x40]
// 004fe496  d944241c             fld dword ptr [esp + 0x1c]
// 004fe49a  d918                 fstp dword ptr [eax]
// 004fe49c  8b442434             mov eax, dword ptr [esp + 0x34]
// 004fe4a0  d9c9                 fxch st(1)
// 004fe4a2  d918                 fstp dword ptr [eax]
// 004fe4a4  8d44243c             lea eax, [esp + 0x3c]
// 004fe4a8  50                   push eax
// 004fe4a9  d9542460             fst dword ptr [esp + 0x60]
// 004fe4ad  51                   push ecx
// 004fe4ae  d95c2468             fstp dword ptr [esp + 0x68]
// 004fe4b2  52                   push edx
// 004fe4b3  d9e8                 fld1 
// 004fe4b5  8d4d08               lea ecx, [ebp + 8]
// 004fe4b8  d95c2470             fstp dword ptr [esp + 0x70]
// 004fe4bc  e80ff7ffff           call 0x4fdbd0
// 004fe4c1  e8dab60000           call 0x509ba0
// 004fe4c6  8bc8                 mov ecx, eax
// 004fe4c8  d901                 fld dword ptr [ecx]
// 004fe4ca  d85d2c               fcomp dword ptr [ebp + 0x2c]
// 004fe4cd  dfe0                 fnstsw ax
// 004fe4cf  f6c444               test ah, 0x44
// 004fe4d2  7a15                 jp 0x4fe4e9
// 004fe4d4  d94104               fld dword ptr [ecx + 4]
// 004fe4d7  d85d30               fcomp dword ptr [ebp + 0x30]
// 004fe4da  dfe0                 fnstsw ax
// 004fe4dc  f6c444               test ah, 0x44
// 004fe4df  7a08                 jp 0x4fe4e9
// 004fe4e1  d94524               fld dword ptr [ebp + 0x24]
// 004fe4e4  d94528               fld dword ptr [ebp + 0x28]
// 004fe4e7  eb08                 jmp 0x4fe4f1
// 004fe4e9  d9442434             fld dword ptr [esp + 0x34]
// 004fe4ed  d9442438             fld dword ptr [esp + 0x38]
// 004fe4f1  d905ac9b8100         fld dword ptr [0x819bac]
// 004fe4f7  8d442454             lea eax, [esp + 0x54]
// 004fe4fb  dcca                 fmul st(2), st(0)
// 004fe4fd  50                   push eax
// 004fe4fe  d9ca                 fxch st(2)
// 004fe500  8d4c247c             lea ecx, [esp + 0x7c]
// 004fe504  51                   push ecx
// 004fe505  d95c2454             fstp dword ptr [esp + 0x54]
// 004fe509  dec9                 fmulp st(1)
// 004fe50b  d95c2458             fstp dword ptr [esp + 0x58]
// 004fe50f  e8ccdc0e00           call 0x5ec1e0
// 004fe514  8d542468             lea edx, [esp + 0x68]
// 004fe518  52                   push edx
// 004fe519  8d842490000000       lea eax, [esp + 0x90]
// 004fe520  50                   push eax
// 004fe521  e8badc0e00           call 0x5ec1e0
// 004fe526  6a01                 push 1
// 004fe528  8d4c2460             lea ecx, [esp + 0x60]
// 004fe52c  51                   push ecx
// 004fe52d  8d942490000000       lea edx, [esp + 0x90]
// 004fe534  52                   push edx
// 004fe535  8d8424a0000000       lea eax, [esp + 0xa0]
// 004fe53c  50                   push eax
// 004fe53d  e8be9a0400           call 0x548000
// 004fe542  d9442460             fld dword ptr [esp + 0x60]
// 004fe546  0fbf4d3a             movsx ecx, word ptr [ebp + 0x3a]
// 004fe54a  d844243c             fadd dword ptr [esp + 0x3c]
// 004fe54e  41                   inc ecx
// 004fe54f  0fafcb               imul ecx, ebx
// 004fe552  d954243c             fst dword ptr [esp + 0x3c]
// 004fe556  d9442468             fld dword ptr [esp + 0x68]
// 004fe55a  d8442440             fadd dword ptr [esp + 0x40]
// 004fe55e  d9542440             fst dword ptr [esp + 0x40]
// 004fe562  03cf                 add ecx, edi
// 004fe564  89048e               mov dword ptr [esi + ecx*4], eax
// 004fe567  668b453a             mov ax, word ptr [ebp + 0x3a]
// 004fe56b  0fbfd0               movsx edx, ax
// 004fe56e  47                   inc edi
// 004fe56f  83c420               add esp, 0x20
// 004fe572  3bfa                 cmp edi, edx
// 004fe574  0f8edcfeffff         jle 0x4fe456
// 004fe57a  8b5538               mov edx, dword ptr [ebp + 0x38]
// 004fe57d  ddd9                 fstp st(1)
// 004fe57f  ddd8                 fstp st(0)
// 004fe581  d9ee                 fldz 
// 004fe583  eb04                 jmp 0x4fe589
// 004fe585  ddd9                 fstp st(1)
// 004fe587  ddd8                 fstp st(0)
// 004fe589  d944243c             fld dword ptr [esp + 0x3c]
// 004fe58d  0fbfca               movsx ecx, dx
// 004fe590  d8442410             fadd dword ptr [esp + 0x10]
// 004fe594  43                   inc ebx
// 004fe595  3bd9                 cmp ebx, ecx
// 004fe597  d95c2410             fstp dword ptr [esp + 0x10]
// 004fe59b  d9442444             fld dword ptr [esp + 0x44]
// 004fe59f  d8442414             fadd dword ptr [esp + 0x14]
// 004fe5a3  d95c2414             fstp dword ptr [esp + 0x14]
// 004fe5a7  0f8e6efeffff         jle 0x4fe41b
// 004fe5ad  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004fe5b1  ddd8                 fstp st(0)
// 004fe5b3  33c9                 xor ecx, ecx
// 004fe5b5  33db                 xor ebx, ebx
// 004fe5b7  663bca               cmp cx, dx
// 004fe5ba  7d48                 jge 0x4fe604
// 004fe5bc  0fbfc8               movsx ecx, ax
// 004fe5bf  90                   nop 
// 004fe5c0  33ff                 xor edi, edi
// 004fe5c2  85c9                 test ecx, ecx
// 004fe5c4  7e32                 jle 0x4fe5f8
// 004fe5c6  8d4101               lea eax, [ecx + 1]
// 004fe5c9  0fafc3               imul eax, ebx
// 004fe5cc  03c7                 add eax, edi
// 004fe5ce  03c8                 add ecx, eax
// 004fe5d0  8b548e08             mov edx, dword ptr [esi + ecx*4 + 8]
// 004fe5d4  8b4c8e04             mov ecx, dword ptr [esi + ecx*4 + 4]
// 004fe5d8  52                   push edx
// 004fe5d9  8b1486               mov edx, dword ptr [esi + eax*4]
// 004fe5dc  8b448604             mov eax, dword ptr [esi + eax*4 + 4]
// 004fe5e0  51                   push ecx
// 004fe5e1  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 004fe5e5  52                   push edx
// 004fe5e6  50                   push eax
// 004fe5e7  e8c4280000           call 0x500eb0
// 004fe5ec  0fbf4d3a             movsx ecx, word ptr [ebp + 0x3a]
// 004fe5f0  47                   inc edi
// 004fe5f1  3bf9                 cmp edi, ecx
// 004fe5f3  7cd1                 jl 0x4fe5c6
// 004fe5f5  8b5538               mov edx, dword ptr [ebp + 0x38]
// 004fe5f8  0fbfc2               movsx eax, dx
// 004fe5fb  43                   inc ebx
// 004fe5fc  3bd8                 cmp ebx, eax
// 004fe5fe  7cc0                 jl 0x4fe5c0
// 004fe600  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004fe604  33db                 xor ebx, ebx
// 004fe606  85ff                 test edi, edi
// 004fe608  7617                 jbe 0x4fe621
// 004fe60a  8d9b00000000         lea ebx, [ebx]
// 004fe610  8b0c9e               mov ecx, dword ptr [esi + ebx*4]
// 004fe613  51                   push ecx
// 004fe614  e827a00400           call 0x548640
// 004fe619  43                   inc ebx
// 004fe61a  83c404               add esp, 4
// 004fe61d  3bdf                 cmp ebx, edi
// 004fe61f  72ef                 jb 0x4fe610
// 004fe621  56                   push esi
// 004fe622  e823231a00           call 0x6a094a
// 004fe627  83c404               add esp, 4
// 004fe62a  5f                   pop edi
// 004fe62b  5e                   pop esi
// 004fe62c  5b                   pop ebx
// 004fe62d  8be5                 mov esp, ebp
// 004fe62f  5d                   pop ebp
// 004fe630  c23400               ret 0x34

// from server: 98% by EspClaude
// roc 2008-06 004fe350  unit: RBX::ViewNew::CylinderBuilder  size: 739 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004fe350
//
// 004fe350  55                   push ebp
// 004fe351  8bec                 mov ebp, esp
// 004fe353  83e4f8               and esp, 0xfffffff8
// 004fe356  81ec84000000         sub esp, 0x84
// 004fe35c  53                   push ebx
// 004fe35d  56                   push esi
// 004fe35e  894c242c             mov dword ptr [esp + 0x2c], ecx
// 004fe362  57                   push edi
// 004fe363  83c104               add ecx, 4
// 004fe366  51                   push ecx
// 004fe367  8d442464             lea eax, [esp + 0x64]
// 004fe36b  50                   push eax
// 004fe36c  e86fde0e00           call 0x5ec1e0
// 004fe371  d9442468             fld dword ptr [esp + 0x68]
// 004fe375  0fbf4538             movsx eax, word ptr [ebp + 0x38]
// 004fe379  d9e1                 fabs 
// 004fe37b  d95c2474             fstp dword ptr [esp + 0x74]
// 004fe37f  8944242c             mov dword ptr [esp + 0x2c], eax
// 004fe383  d944246c             fld dword ptr [esp + 0x6c]
// 004fe387  0fbf7d3a             movsx edi, word ptr [ebp + 0x3a]
// 004fe38b  d9e1                 fabs 
// 004fe38d  d95c2478             fstp dword ptr [esp + 0x78]
// 004fe391  d9442470             fld dword ptr [esp + 0x70]
// 004fe395  40                   inc eax
// 004fe396  d9e1                 fabs 
// 004fe398  33c9                 xor ecx, ecx
// 004fe39a  d95c247c             fstp dword ptr [esp + 0x7c]
// 004fe39e  ba04000000           mov edx, 4
// 004fe3a3  db44242c             fild dword ptr [esp + 0x2c]
// 004fe3a7  897c242c             mov dword ptr [esp + 0x2c], edi
// 004fe3ab  d94518               fld dword ptr [ebp + 0x18]
// 004fe3ae  47                   inc edi
// 004fe3af  d86510               fsub dword ptr [ebp + 0x10]
// 004fe3b2  0faff8               imul edi, eax
// 004fe3b5  d8f1                 fdiv st(1)
// 004fe3b7  8bc7                 mov eax, edi
// 004fe3b9  d95c2444             fstp dword ptr [esp + 0x44]
// 004fe3bd  f7e2                 mul edx
// 004fe3bf  db44242c             fild dword ptr [esp + 0x2c]
// 004fe3c3  d9451c               fld dword ptr [ebp + 0x1c]
// 004fe3c6  d86514               fsub dword ptr [ebp + 0x14]
// 004fe3c9  d8f1                 fdiv st(1)
// 004fe3cb  0f90c1               seto cl
// 004fe3ce  897c242c             mov dword ptr [esp + 0x2c], edi
// 004fe3d2  f7d9                 neg ecx
// 004fe3d4  0bc8                 or ecx, eax
// 004fe3d6  51                   push ecx
// 004fe3d7  d95c244c             fstp dword ptr [esp + 0x4c]
// 004fe3db  d9452c               fld dword ptr [ebp + 0x2c]
// 004fe3de  def2                 fdivrp st(2)
// 004fe3e0  d9c9                 fxch st(1)
// 004fe3e2  d95c2450             fstp dword ptr [esp + 0x50]
// 004fe3e6  d87d30               fdivr dword ptr [ebp + 0x30]
// 004fe3e9  d95c2454             fstp dword ptr [esp + 0x54]
// 004fe3ed  e864251a00           call 0x6a0956
// 004fe3f2  d94510               fld dword ptr [ebp + 0x10]
// 004fe3f5  8b5538               mov edx, dword ptr [ebp + 0x38]
// 004fe3f8  d95c241c             fstp dword ptr [esp + 0x1c]
// 004fe3fc  d94524               fld dword ptr [ebp + 0x24]
// 004fe3ff  8bf0                 mov esi, eax
// 004fe401  33c0                 xor eax, eax
// 004fe403  d95c2420             fstp dword ptr [esp + 0x20]
// 004fe407  83c40c               add esp, 0xc
// 004fe40a  33db                 xor ebx, ebx
// 004fe40c  663bc2               cmp ax, dx
// 004fe40f  668b453a             mov ax, word ptr [ebp + 0x3a]
// 004fe413  0f8f9a010000         jg 0x4fe5b3
// 004fe419  d9ee                 fldz 
// 004fe41b  d94514               fld dword ptr [ebp + 0x14]
// 004fe41e  33c9                 xor ecx, ecx
// 004fe420  d954241c             fst dword ptr [esp + 0x1c]
// 004fe424  33ff                 xor edi, edi
// 004fe426  663bc8               cmp cx, ax
// 004fe429  d94528               fld dword ptr [ebp + 0x28]
// 004fe42c  d9542420             fst dword ptr [esp + 0x20]
// 004fe430  0f8f4f010000         jg 0x4fe585
// 004fe436  8b4d34               mov ecx, dword ptr [ebp + 0x34]
// 004fe439  03c9                 add ecx, ecx
// 004fe43b  03c9                 add ecx, ecx
// 004fe43d  8d442438             lea eax, [esp + 0x38]
// 004fe441  2bc1                 sub eax, ecx
// 004fe443  8d540c34             lea edx, [esp + ecx + 0x34]
// 004fe447  89442428             mov dword ptr [esp + 0x28], eax
// 004fe44b  8954242c             mov dword ptr [esp + 0x2c], edx
// 004fe44f  66895c2418           mov word ptr [esp + 0x18], bx
// 004fe454  eb0a                 jmp 0x4fe460
// 004fe456  d9ee                 fldz 
// 004fe458  8b442428             mov eax, dword ptr [esp + 0x28]
// 004fe45c  d9ca                 fxch st(2)
// 004fe45e  d9c9                 fxch st(1)
// 004fe460  d9442410             fld dword ptr [esp + 0x10]
// 004fe464  8d4c2418             lea ecx, [esp + 0x18]
// 004fe468  d95c2460             fstp dword ptr [esp + 0x60]
// 004fe46c  51                   push ecx
// 004fe46d  d9c9                 fxch st(1)
// 004fe46f  8d542470             lea edx, [esp + 0x70]
// 004fe473  d95c2468             fstp dword ptr [esp + 0x68]
// 004fe477  52                   push edx
// 004fe478  d94520               fld dword ptr [ebp + 0x20]
// 004fe47b  8d4c245c             lea ecx, [esp + 0x5c]
// 004fe47f  d95c2470             fstp dword ptr [esp + 0x70]
// 004fe483  8d542468             lea edx, [esp + 0x68]
// 004fe487  d9c9                 fxch st(1)
// 004fe489  66897c2422           mov word ptr [esp + 0x22], di
// 004fe48e  d954243c             fst dword ptr [esp + 0x3c]
// 004fe492  d9542440             fst dword ptr [esp + 0x40]
// 004fe496  d944241c             fld dword ptr [esp + 0x1c]
// 004fe49a  d918                 fstp dword ptr [eax]
// 004fe49c  8b442434             mov eax, dword ptr [esp + 0x34]
// 004fe4a0  d9c9                 fxch st(1)
// 004fe4a2  d918                 fstp dword ptr [eax]
// 004fe4a4  8d44243c             lea eax, [esp + 0x3c]
// 004fe4a8  50                   push eax
// 004fe4a9  d9542460             fst dword ptr [esp + 0x60]
// 004fe4ad  51                   push ecx
// 004fe4ae  d95c2468             fstp dword ptr [esp + 0x68]
// 004fe4b2  52                   push edx
// 004fe4b3  d9e8                 fld1 
// 004fe4b5  8d4d08               lea ecx, [ebp + 8]
// 004fe4b8  d95c2470             fstp dword ptr [esp + 0x70]
// 004fe4bc  e80ff7ffff           call 0x4fdbd0
// 004fe4c1  e8dab60000           call 0x509ba0
// 004fe4c6  8bc8                 mov ecx, eax
// 004fe4c8  d901                 fld dword ptr [ecx]
// 004fe4ca  d85d2c               fcomp dword ptr [ebp + 0x2c]
// 004fe4cd  dfe0                 fnstsw ax
// 004fe4cf  f6c444               test ah, 0x44
// 004fe4d2  7a15                 jp 0x4fe4e9
// 004fe4d4  d94104               fld dword ptr [ecx + 4]
// 004fe4d7  d85d30               fcomp dword ptr [ebp + 0x30]
// 004fe4da  dfe0                 fnstsw ax
// 004fe4dc  f6c444               test ah, 0x44
// 004fe4df  7a08                 jp 0x4fe4e9
// 004fe4e1  d94524               fld dword ptr [ebp + 0x24]
// 004fe4e4  d94528               fld dword ptr [ebp + 0x28]
// 004fe4e7  eb08                 jmp 0x4fe4f1
// 004fe4e9  d9442434             fld dword ptr [esp + 0x34]
// 004fe4ed  d9442438             fld dword ptr [esp + 0x38]
// 004fe4f1  d905ac9b8100         fld dword ptr [0x819bac]
// 004fe4f7  8d442454             lea eax, [esp + 0x54]
// 004fe4fb  dcca                 fmul st(2), st(0)
// 004fe4fd  50                   push eax
// 004fe4fe  d9ca                 fxch st(2)
// 004fe500  8d4c247c             lea ecx, [esp + 0x7c]
// 004fe504  51                   push ecx
// 004fe505  d95c2454             fstp dword ptr [esp + 0x54]
// 004fe509  dec9                 fmulp st(1)
// 004fe50b  d95c2458             fstp dword ptr [esp + 0x58]
// 004fe50f  e8ccdc0e00           call 0x5ec1e0
// 004fe514  8d542468             lea edx, [esp + 0x68]
// 004fe518  52                   push edx
// 004fe519  8d842490000000       lea eax, [esp + 0x90]
// 004fe520  50                   push eax
// 004fe521  e8badc0e00           call 0x5ec1e0
// 004fe526  6a01                 push 1
// 004fe528  8d4c2460             lea ecx, [esp + 0x60]
// 004fe52c  51                   push ecx
// 004fe52d  8d942490000000       lea edx, [esp + 0x90]
// 004fe534  52                   push edx
// 004fe535  8d8424a0000000       lea eax, [esp + 0xa0]
// 004fe53c  50                   push eax
// 004fe53d  e8be9a0400           call 0x548000
// 004fe542  d9442460             fld dword ptr [esp + 0x60]
// 004fe546  0fbf4d3a             movsx ecx, word ptr [ebp + 0x3a]
// 004fe54a  d844243c             fadd dword ptr [esp + 0x3c]
// 004fe54e  41                   inc ecx
// 004fe54f  0fafcb               imul ecx, ebx
// 004fe552  d954243c             fst dword ptr [esp + 0x3c]
// 004fe556  d9442468             fld dword ptr [esp + 0x68]
// 004fe55a  d8442440             fadd dword ptr [esp + 0x40]
// 004fe55e  d9542440             fst dword ptr [esp + 0x40]
// 004fe562  03cf                 add ecx, edi
// 004fe564  89048e               mov dword ptr [esi + ecx*4], eax
// 004fe567  668b453a             mov ax, word ptr [ebp + 0x3a]
// 004fe56b  0fbfd0               movsx edx, ax
// 004fe56e  47                   inc edi
// 004fe56f  83c420               add esp, 0x20
// 004fe572  3bfa                 cmp edi, edx
// 004fe574  0f8edcfeffff         jle 0x4fe456
// 004fe57a  8b5538               mov edx, dword ptr [ebp + 0x38]
// 004fe57d  ddd9                 fstp st(1)
// 004fe57f  ddd8                 fstp st(0)
// 004fe581  d9ee                 fldz 
// 004fe583  eb04                 jmp 0x4fe589
// 004fe585  ddd9                 fstp st(1)
// 004fe587  ddd8                 fstp st(0)
// 004fe589  d944243c             fld dword ptr [esp + 0x3c]
// 004fe58d  0fbfca               movsx ecx, dx
// 004fe590  d8442410             fadd dword ptr [esp + 0x10]
// 004fe594  43                   inc ebx
// 004fe595  3bd9                 cmp ebx, ecx
// 004fe597  d95c2410             fstp dword ptr [esp + 0x10]
// 004fe59b  d9442444             fld dword ptr [esp + 0x44]
// 004fe59f  d8442414             fadd dword ptr [esp + 0x14]
// 004fe5a3  d95c2414             fstp dword ptr [esp + 0x14]
// 004fe5a7  0f8e6efeffff         jle 0x4fe41b
// 004fe5ad  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004fe5b1  ddd8                 fstp st(0)
// 004fe5b3  33c9                 xor ecx, ecx
// 004fe5b5  33db                 xor ebx, ebx
// 004fe5b7  663bca               cmp cx, dx
// 004fe5ba  7d48                 jge 0x4fe604
// 004fe5bc  0fbfc8               movsx ecx, ax
// 004fe5bf  90                   nop 
// 004fe5c0  33ff                 xor edi, edi
// 004fe5c2  85c9                 test ecx, ecx
// 004fe5c4  7e32                 jle 0x4fe5f8
// 004fe5c6  8d4101               lea eax, [ecx + 1]
// 004fe5c9  0fafc3               imul eax, ebx
// 004fe5cc  03c7                 add eax, edi
// 004fe5ce  03c8                 add ecx, eax
// 004fe5d0  8b548e08             mov edx, dword ptr [esi + ecx*4 + 8]
// 004fe5d4  8b4c8e04             mov ecx, dword ptr [esi + ecx*4 + 4]
// 004fe5d8  52                   push edx
// 004fe5d9  8b1486               mov edx, dword ptr [esi + eax*4]
// 004fe5dc  8b448604             mov eax, dword ptr [esi + eax*4 + 4]
// 004fe5e0  51                   push ecx
// 004fe5e1  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 004fe5e5  52                   push edx
// 004fe5e6  50                   push eax
// 004fe5e7  e8c4280000           call 0x500eb0
// 004fe5ec  0fbf4d3a             movsx ecx, word ptr [ebp + 0x3a]
// 004fe5f0  47                   inc edi
// 004fe5f1  3bf9                 cmp edi, ecx
// 004fe5f3  7cd1                 jl 0x4fe5c6
// 004fe5f5  8b5538               mov edx, dword ptr [ebp + 0x38]
// 004fe5f8  0fbfc2               movsx eax, dx
// 004fe5fb  43                   inc ebx
// 004fe5fc  3bd8                 cmp ebx, eax
// 004fe5fe  7cc0                 jl 0x4fe5c0
// 004fe600  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004fe604  33db                 xor ebx, ebx
// 004fe606  85ff                 test edi, edi
// 004fe608  7617                 jbe 0x4fe621
// 004fe60a  8d9b00000000         lea ebx, [ebx]
// 004fe610  8b0c9e               mov ecx, dword ptr [esi + ebx*4]
// 004fe613  51                   push ecx
// 004fe614  e827a00400           call 0x548640
// 004fe619  43                   inc ebx
// 004fe61a  83c404               add esp, 4
// 004fe61d  3bdf                 cmp ebx, edi
// 004fe61f  72ef                 jb 0x4fe610
// 004fe621  56                   push esi
// 004fe622  e823231a00           call 0x6a094a
// 004fe627  83c404               add esp, 4
// 004fe62a  5f                   pop edi
// 004fe62b  5e                   pop esi
// 004fe62c  5b                   pop ebx
// 004fe62d  8be5                 mov esp, ebp
// 004fe62f  5d                   pop ebp
// 004fe630  c23400               ret 0x34

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

extern "C" double __cdecl fabs(double);

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
    char data[8];
    void operator()(Vec3*, Vec3*, Vec2*, const Vec3*, const GridSize*);
};

struct TorsoBuilder {
    char prefix[4];
    Vec3 dimensions;

    void build(VertexCallback, Vec2, Vec2, float, Vec2, Vec2, int, GridSize);
    void quad(int, int, int, int);
};

#pragma float_control(precise, off, push)

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
    GridSize index;
    Vec2 texture;
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
        int j = 0;
        if (j <= divisions.y) {
        float* pu = &texture.y - axis;
        float* pv = &texture.x + axis;
        index.x = (short)i;
        do {
            Vec3 position;
            position.x = x;
            position.y = y;
            position.z = depth;

            texture.x = 0.0f;
            texture.y = 0.0f;
            *pu = u;
            *pv = v;

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
            ++j;
        } while (j <= divisions.y);
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

#pragma float_control(pop)
