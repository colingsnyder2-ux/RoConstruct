// from server: 100% by EspClaude
// from server: 99% by EspClaude
// roc 2008-06 004fe640  unit: RBX::ViewNew::CylinderBuilder  size: 739 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004fe640
//
// 004fe640  55                   push ebp
// 004fe641  8bec                 mov ebp, esp
// 004fe643  83e4f8               and esp, 0xfffffff8
// 004fe646  81ec84000000         sub esp, 0x84
// 004fe64c  53                   push ebx
// 004fe64d  56                   push esi
// 004fe64e  894c242c             mov dword ptr [esp + 0x2c], ecx
// 004fe652  57                   push edi
// 004fe653  83c104               add ecx, 4
// 004fe656  51                   push ecx
// 004fe657  8d442464             lea eax, [esp + 0x64]
// 004fe65b  50                   push eax
// 004fe65c  e83fdb0e00           call 0x5ec1a0
// 004fe661  d9442468             fld dword ptr [esp + 0x68]
// 004fe665  0fbf4538             movsx eax, word ptr [ebp + 0x38]
// 004fe669  d9e1                 fabs 
// 004fe66b  d95c2474             fstp dword ptr [esp + 0x74]
// 004fe66f  8944242c             mov dword ptr [esp + 0x2c], eax
// 004fe673  d944246c             fld dword ptr [esp + 0x6c]
// 004fe677  0fbf7d3a             movsx edi, word ptr [ebp + 0x3a]
// 004fe67b  d9e1                 fabs 
// 004fe67d  d95c2478             fstp dword ptr [esp + 0x78]
// 004fe681  d9442470             fld dword ptr [esp + 0x70]
// 004fe685  40                   inc eax
// 004fe686  d9e1                 fabs 
// 004fe688  33c9                 xor ecx, ecx
// 004fe68a  d95c247c             fstp dword ptr [esp + 0x7c]
// 004fe68e  ba04000000           mov edx, 4
// 004fe693  db44242c             fild dword ptr [esp + 0x2c]
// 004fe697  897c242c             mov dword ptr [esp + 0x2c], edi
// 004fe69b  d94518               fld dword ptr [ebp + 0x18]
// 004fe69e  47                   inc edi
// 004fe69f  d86510               fsub dword ptr [ebp + 0x10]
// 004fe6a2  0faff8               imul edi, eax
// 004fe6a5  d8f1                 fdiv st(1)
// 004fe6a7  8bc7                 mov eax, edi
// 004fe6a9  d95c2444             fstp dword ptr [esp + 0x44]
// 004fe6ad  f7e2                 mul edx
// 004fe6af  db44242c             fild dword ptr [esp + 0x2c]
// 004fe6b3  d9451c               fld dword ptr [ebp + 0x1c]
// 004fe6b6  d86514               fsub dword ptr [ebp + 0x14]
// 004fe6b9  d8f1                 fdiv st(1)
// 004fe6bb  0f90c1               seto cl
// 004fe6be  897c242c             mov dword ptr [esp + 0x2c], edi
// 004fe6c2  f7d9                 neg ecx
// 004fe6c4  0bc8                 or ecx, eax
// 004fe6c6  51                   push ecx
// 004fe6c7  d95c244c             fstp dword ptr [esp + 0x4c]
// 004fe6cb  d9452c               fld dword ptr [ebp + 0x2c]
// 004fe6ce  def2                 fdivrp st(2)
// 004fe6d0  d9c9                 fxch st(1)
// 004fe6d2  d95c2450             fstp dword ptr [esp + 0x50]
// 004fe6d6  d87d30               fdivr dword ptr [ebp + 0x30]
// 004fe6d9  d95c2454             fstp dword ptr [esp + 0x54]
// 004fe6dd  e874221a00           call 0x6a0956
// 004fe6e2  d94510               fld dword ptr [ebp + 0x10]
// 004fe6e5  8b5538               mov edx, dword ptr [ebp + 0x38]
// 004fe6e8  d95c241c             fstp dword ptr [esp + 0x1c]
// 004fe6ec  d94524               fld dword ptr [ebp + 0x24]
// 004fe6ef  8bf0                 mov esi, eax
// 004fe6f1  33c0                 xor eax, eax
// 004fe6f3  d95c2420             fstp dword ptr [esp + 0x20]
// 004fe6f7  83c40c               add esp, 0xc
// 004fe6fa  33db                 xor ebx, ebx
// 004fe6fc  663bc2               cmp ax, dx
// 004fe6ff  668b453a             mov ax, word ptr [ebp + 0x3a]
// 004fe703  0f8f9a010000         jg 0x4fe8a3
// 004fe709  d9ee                 fldz 
// 004fe70b  d94514               fld dword ptr [ebp + 0x14]
// 004fe70e  33c9                 xor ecx, ecx
// 004fe710  d954241c             fst dword ptr [esp + 0x1c]
// 004fe714  33ff                 xor edi, edi
// 004fe716  663bc8               cmp cx, ax
// 004fe719  d94528               fld dword ptr [ebp + 0x28]
// 004fe71c  d9542420             fst dword ptr [esp + 0x20]
// 004fe720  0f8f4f010000         jg 0x4fe875
// 004fe726  8b4d34               mov ecx, dword ptr [ebp + 0x34]
// 004fe729  03c9                 add ecx, ecx
// 004fe72b  03c9                 add ecx, ecx
// 004fe72d  8d442438             lea eax, [esp + 0x38]
// 004fe731  2bc1                 sub eax, ecx
// 004fe733  8d540c34             lea edx, [esp + ecx + 0x34]
// 004fe737  89442428             mov dword ptr [esp + 0x28], eax
// 004fe73b  8954242c             mov dword ptr [esp + 0x2c], edx
// 004fe73f  66895c2418           mov word ptr [esp + 0x18], bx
// 004fe744  eb0a                 jmp 0x4fe750
// 004fe746  d9ee                 fldz 
// 004fe748  8b442428             mov eax, dword ptr [esp + 0x28]
// 004fe74c  d9ca                 fxch st(2)
// 004fe74e  d9c9                 fxch st(1)
// 004fe750  d9442410             fld dword ptr [esp + 0x10]
// 004fe754  8d4c2418             lea ecx, [esp + 0x18]
// 004fe758  d95c2460             fstp dword ptr [esp + 0x60]
// 004fe75c  51                   push ecx
// 004fe75d  d9c9                 fxch st(1)
// 004fe75f  8d542470             lea edx, [esp + 0x70]
// 004fe763  d95c2468             fstp dword ptr [esp + 0x68]
// 004fe767  52                   push edx
// 004fe768  d94520               fld dword ptr [ebp + 0x20]
// 004fe76b  8d4c245c             lea ecx, [esp + 0x5c]
// 004fe76f  d95c2470             fstp dword ptr [esp + 0x70]
// 004fe773  8d542468             lea edx, [esp + 0x68]
// 004fe777  d9c9                 fxch st(1)
// 004fe779  66897c2422           mov word ptr [esp + 0x22], di
// 004fe77e  d954243c             fst dword ptr [esp + 0x3c]
// 004fe782  d9542440             fst dword ptr [esp + 0x40]
// 004fe786  d944241c             fld dword ptr [esp + 0x1c]
// 004fe78a  d918                 fstp dword ptr [eax]
// 004fe78c  8b442434             mov eax, dword ptr [esp + 0x34]
// 004fe790  d9c9                 fxch st(1)
// 004fe792  d918                 fstp dword ptr [eax]
// 004fe794  8d44243c             lea eax, [esp + 0x3c]
// 004fe798  50                   push eax
// 004fe799  d9542460             fst dword ptr [esp + 0x60]
// 004fe79d  51                   push ecx
// 004fe79e  d95c2468             fstp dword ptr [esp + 0x68]
// 004fe7a2  52                   push edx
// 004fe7a3  d9e8                 fld1 
// 004fe7a5  8d4d08               lea ecx, [ebp + 8]
// 004fe7a8  d95c2470             fstp dword ptr [esp + 0x70]
// 004fe7ac  e81ff4ffff           call 0x4fdbd0
// 004fe7b1  e8eab30000           call 0x509ba0
// 004fe7b6  8bc8                 mov ecx, eax
// 004fe7b8  d901                 fld dword ptr [ecx]
// 004fe7ba  d85d2c               fcomp dword ptr [ebp + 0x2c]
// 004fe7bd  dfe0                 fnstsw ax
// 004fe7bf  f6c444               test ah, 0x44
// 004fe7c2  7a15                 jp 0x4fe7d9
// 004fe7c4  d94104               fld dword ptr [ecx + 4]
// 004fe7c7  d85d30               fcomp dword ptr [ebp + 0x30]
// 004fe7ca  dfe0                 fnstsw ax
// 004fe7cc  f6c444               test ah, 0x44
// 004fe7cf  7a08                 jp 0x4fe7d9
// 004fe7d1  d94524               fld dword ptr [ebp + 0x24]
// 004fe7d4  d94528               fld dword ptr [ebp + 0x28]
// 004fe7d7  eb08                 jmp 0x4fe7e1
// 004fe7d9  d9442434             fld dword ptr [esp + 0x34]
// 004fe7dd  d9442438             fld dword ptr [esp + 0x38]
// 004fe7e1  d905ac9b8100         fld dword ptr [0x819bac]
// 004fe7e7  8d442454             lea eax, [esp + 0x54]
// 004fe7eb  dcca                 fmul st(2), st(0)
// 004fe7ed  50                   push eax
// 004fe7ee  d9ca                 fxch st(2)
// 004fe7f0  8d4c247c             lea ecx, [esp + 0x7c]
// 004fe7f4  51                   push ecx
// 004fe7f5  d95c2454             fstp dword ptr [esp + 0x54]
// 004fe7f9  dec9                 fmulp st(1)
// 004fe7fb  d95c2458             fstp dword ptr [esp + 0x58]
// 004fe7ff  e89cd90e00           call 0x5ec1a0
// 004fe804  8d542468             lea edx, [esp + 0x68]
// 004fe808  52                   push edx
// 004fe809  8d842490000000       lea eax, [esp + 0x90]
// 004fe810  50                   push eax
// 004fe811  e88ad90e00           call 0x5ec1a0
// 004fe816  6a01                 push 1
// 004fe818  8d4c2460             lea ecx, [esp + 0x60]
// 004fe81c  51                   push ecx
// 004fe81d  8d942490000000       lea edx, [esp + 0x90]
// 004fe824  52                   push edx
// 004fe825  8d8424a0000000       lea eax, [esp + 0xa0]
// 004fe82c  50                   push eax
// 004fe82d  e8ce970400           call 0x548000
// 004fe832  d9442460             fld dword ptr [esp + 0x60]
// 004fe836  0fbf4d3a             movsx ecx, word ptr [ebp + 0x3a]
// 004fe83a  d844243c             fadd dword ptr [esp + 0x3c]
// 004fe83e  41                   inc ecx
// 004fe83f  0fafcb               imul ecx, ebx
// 004fe842  d954243c             fst dword ptr [esp + 0x3c]
// 004fe846  d9442468             fld dword ptr [esp + 0x68]
// 004fe84a  d8442440             fadd dword ptr [esp + 0x40]
// 004fe84e  d9542440             fst dword ptr [esp + 0x40]
// 004fe852  03cf                 add ecx, edi
// 004fe854  89048e               mov dword ptr [esi + ecx*4], eax
// 004fe857  668b453a             mov ax, word ptr [ebp + 0x3a]
// 004fe85b  0fbfd0               movsx edx, ax
// 004fe85e  47                   inc edi
// 004fe85f  83c420               add esp, 0x20
// 004fe862  3bfa                 cmp edi, edx
// 004fe864  0f8edcfeffff         jle 0x4fe746
// 004fe86a  8b5538               mov edx, dword ptr [ebp + 0x38]
// 004fe86d  ddd9                 fstp st(1)
// 004fe86f  ddd8                 fstp st(0)
// 004fe871  d9ee                 fldz 
// 004fe873  eb04                 jmp 0x4fe879
// 004fe875  ddd9                 fstp st(1)
// 004fe877  ddd8                 fstp st(0)
// 004fe879  d944243c             fld dword ptr [esp + 0x3c]
// 004fe87d  0fbfca               movsx ecx, dx
// 004fe880  d8442410             fadd dword ptr [esp + 0x10]
// 004fe884  43                   inc ebx
// 004fe885  3bd9                 cmp ebx, ecx
// 004fe887  d95c2410             fstp dword ptr [esp + 0x10]
// 004fe88b  d9442444             fld dword ptr [esp + 0x44]
// 004fe88f  d8442414             fadd dword ptr [esp + 0x14]
// 004fe893  d95c2414             fstp dword ptr [esp + 0x14]
// 004fe897  0f8e6efeffff         jle 0x4fe70b
// 004fe89d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004fe8a1  ddd8                 fstp st(0)
// 004fe8a3  33c9                 xor ecx, ecx
// 004fe8a5  33db                 xor ebx, ebx
// 004fe8a7  663bca               cmp cx, dx
// 004fe8aa  7d48                 jge 0x4fe8f4
// 004fe8ac  0fbfc8               movsx ecx, ax
// 004fe8af  90                   nop 
// 004fe8b0  33ff                 xor edi, edi
// 004fe8b2  85c9                 test ecx, ecx
// 004fe8b4  7e32                 jle 0x4fe8e8
// 004fe8b6  8d4101               lea eax, [ecx + 1]
// 004fe8b9  0fafc3               imul eax, ebx
// 004fe8bc  03c7                 add eax, edi
// 004fe8be  03c8                 add ecx, eax
// 004fe8c0  8b548e08             mov edx, dword ptr [esi + ecx*4 + 8]
// 004fe8c4  8b4c8e04             mov ecx, dword ptr [esi + ecx*4 + 4]
// 004fe8c8  52                   push edx
// 004fe8c9  8b1486               mov edx, dword ptr [esi + eax*4]
// 004fe8cc  8b448604             mov eax, dword ptr [esi + eax*4 + 4]
// 004fe8d0  51                   push ecx
// 004fe8d1  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 004fe8d5  52                   push edx
// 004fe8d6  50                   push eax
// 004fe8d7  e8d4250000           call 0x500eb0
// 004fe8dc  0fbf4d3a             movsx ecx, word ptr [ebp + 0x3a]
// 004fe8e0  47                   inc edi
// 004fe8e1  3bf9                 cmp edi, ecx
// 004fe8e3  7cd1                 jl 0x4fe8b6
// 004fe8e5  8b5538               mov edx, dword ptr [ebp + 0x38]
// 004fe8e8  0fbfc2               movsx eax, dx
// 004fe8eb  43                   inc ebx
// 004fe8ec  3bd8                 cmp ebx, eax
// 004fe8ee  7cc0                 jl 0x4fe8b0
// 004fe8f0  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004fe8f4  33db                 xor ebx, ebx
// 004fe8f6  85ff                 test edi, edi
// 004fe8f8  7617                 jbe 0x4fe911
// 004fe8fa  8d9b00000000         lea ebx, [ebx]
// 004fe900  8b0c9e               mov ecx, dword ptr [esi + ebx*4]
// 004fe903  51                   push ecx
// 004fe904  e8379d0400           call 0x548640
// 004fe909  43                   inc ebx
// 004fe90a  83c404               add esp, 4
// 004fe90d  3bdf                 cmp ebx, edi
// 004fe90f  72ef                 jb 0x4fe900
// 004fe911  56                   push esi
// 004fe912  e833201a00           call 0x6a094a
// 004fe917  83c404               add esp, 4
// 004fe91a  5f                   pop edi
// 004fe91b  5e                   pop esi
// 004fe91c  5b                   pop ebx
// 004fe91d  8be5                 mov esp, ebp
// 004fe91f  5d                   pop ebp
// 004fe920  c23400               ret 0x34

// from server: 98% by EspClaude
// roc 2008-06 004fe640  unit: RBX::ViewNew::CylinderBuilder  size: 739 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004fe640
//
// 004fe640  55                   push ebp
// 004fe641  8bec                 mov ebp, esp
// 004fe643  83e4f8               and esp, 0xfffffff8
// 004fe646  81ec84000000         sub esp, 0x84
// 004fe64c  53                   push ebx
// 004fe64d  56                   push esi
// 004fe64e  894c242c             mov dword ptr [esp + 0x2c], ecx
// 004fe652  57                   push edi
// 004fe653  83c104               add ecx, 4
// 004fe656  51                   push ecx
// 004fe657  8d442464             lea eax, [esp + 0x64]
// 004fe65b  50                   push eax
// 004fe65c  e83fdb0e00           call 0x5ec1a0
// 004fe661  d9442468             fld dword ptr [esp + 0x68]
// 004fe665  0fbf4538             movsx eax, word ptr [ebp + 0x38]
// 004fe669  d9e1                 fabs 
// 004fe66b  d95c2474             fstp dword ptr [esp + 0x74]
// 004fe66f  8944242c             mov dword ptr [esp + 0x2c], eax
// 004fe673  d944246c             fld dword ptr [esp + 0x6c]
// 004fe677  0fbf7d3a             movsx edi, word ptr [ebp + 0x3a]
// 004fe67b  d9e1                 fabs 
// 004fe67d  d95c2478             fstp dword ptr [esp + 0x78]
// 004fe681  d9442470             fld dword ptr [esp + 0x70]
// 004fe685  40                   inc eax
// 004fe686  d9e1                 fabs 
// 004fe688  33c9                 xor ecx, ecx
// 004fe68a  d95c247c             fstp dword ptr [esp + 0x7c]
// 004fe68e  ba04000000           mov edx, 4
// 004fe693  db44242c             fild dword ptr [esp + 0x2c]
// 004fe697  897c242c             mov dword ptr [esp + 0x2c], edi
// 004fe69b  d94518               fld dword ptr [ebp + 0x18]
// 004fe69e  47                   inc edi
// 004fe69f  d86510               fsub dword ptr [ebp + 0x10]
// 004fe6a2  0faff8               imul edi, eax
// 004fe6a5  d8f1                 fdiv st(1)
// 004fe6a7  8bc7                 mov eax, edi
// 004fe6a9  d95c2444             fstp dword ptr [esp + 0x44]
// 004fe6ad  f7e2                 mul edx
// 004fe6af  db44242c             fild dword ptr [esp + 0x2c]
// 004fe6b3  d9451c               fld dword ptr [ebp + 0x1c]
// 004fe6b6  d86514               fsub dword ptr [ebp + 0x14]
// 004fe6b9  d8f1                 fdiv st(1)
// 004fe6bb  0f90c1               seto cl
// 004fe6be  897c242c             mov dword ptr [esp + 0x2c], edi
// 004fe6c2  f7d9                 neg ecx
// 004fe6c4  0bc8                 or ecx, eax
// 004fe6c6  51                   push ecx
// 004fe6c7  d95c244c             fstp dword ptr [esp + 0x4c]
// 004fe6cb  d9452c               fld dword ptr [ebp + 0x2c]
// 004fe6ce  def2                 fdivrp st(2)
// 004fe6d0  d9c9                 fxch st(1)
// 004fe6d2  d95c2450             fstp dword ptr [esp + 0x50]
// 004fe6d6  d87d30               fdivr dword ptr [ebp + 0x30]
// 004fe6d9  d95c2454             fstp dword ptr [esp + 0x54]
// 004fe6dd  e874221a00           call 0x6a0956
// 004fe6e2  d94510               fld dword ptr [ebp + 0x10]
// 004fe6e5  8b5538               mov edx, dword ptr [ebp + 0x38]
// 004fe6e8  d95c241c             fstp dword ptr [esp + 0x1c]
// 004fe6ec  d94524               fld dword ptr [ebp + 0x24]
// 004fe6ef  8bf0                 mov esi, eax
// 004fe6f1  33c0                 xor eax, eax
// 004fe6f3  d95c2420             fstp dword ptr [esp + 0x20]
// 004fe6f7  83c40c               add esp, 0xc
// 004fe6fa  33db                 xor ebx, ebx
// 004fe6fc  663bc2               cmp ax, dx
// 004fe6ff  668b453a             mov ax, word ptr [ebp + 0x3a]
// 004fe703  0f8f9a010000         jg 0x4fe8a3
// 004fe709  d9ee                 fldz 
// 004fe70b  d94514               fld dword ptr [ebp + 0x14]
// 004fe70e  33c9                 xor ecx, ecx
// 004fe710  d954241c             fst dword ptr [esp + 0x1c]
// 004fe714  33ff                 xor edi, edi
// 004fe716  663bc8               cmp cx, ax
// 004fe719  d94528               fld dword ptr [ebp + 0x28]
// 004fe71c  d9542420             fst dword ptr [esp + 0x20]
// 004fe720  0f8f4f010000         jg 0x4fe875
// 004fe726  8b4d34               mov ecx, dword ptr [ebp + 0x34]
// 004fe729  03c9                 add ecx, ecx
// 004fe72b  03c9                 add ecx, ecx
// 004fe72d  8d442438             lea eax, [esp + 0x38]
// 004fe731  2bc1                 sub eax, ecx
// 004fe733  8d540c34             lea edx, [esp + ecx + 0x34]
// 004fe737  89442428             mov dword ptr [esp + 0x28], eax
// 004fe73b  8954242c             mov dword ptr [esp + 0x2c], edx
// 004fe73f  66895c2418           mov word ptr [esp + 0x18], bx
// 004fe744  eb0a                 jmp 0x4fe750
// 004fe746  d9ee                 fldz 
// 004fe748  8b442428             mov eax, dword ptr [esp + 0x28]
// 004fe74c  d9ca                 fxch st(2)
// 004fe74e  d9c9                 fxch st(1)
// 004fe750  d9442410             fld dword ptr [esp + 0x10]
// 004fe754  8d4c2418             lea ecx, [esp + 0x18]
// 004fe758  d95c2460             fstp dword ptr [esp + 0x60]
// 004fe75c  51                   push ecx
// 004fe75d  d9c9                 fxch st(1)
// 004fe75f  8d542470             lea edx, [esp + 0x70]
// 004fe763  d95c2468             fstp dword ptr [esp + 0x68]
// 004fe767  52                   push edx
// 004fe768  d94520               fld dword ptr [ebp + 0x20]
// 004fe76b  8d4c245c             lea ecx, [esp + 0x5c]
// 004fe76f  d95c2470             fstp dword ptr [esp + 0x70]
// 004fe773  8d542468             lea edx, [esp + 0x68]
// 004fe777  d9c9                 fxch st(1)
// 004fe779  66897c2422           mov word ptr [esp + 0x22], di
// 004fe77e  d954243c             fst dword ptr [esp + 0x3c]
// 004fe782  d9542440             fst dword ptr [esp + 0x40]
// 004fe786  d944241c             fld dword ptr [esp + 0x1c]
// 004fe78a  d918                 fstp dword ptr [eax]
// 004fe78c  8b442434             mov eax, dword ptr [esp + 0x34]
// 004fe790  d9c9                 fxch st(1)
// 004fe792  d918                 fstp dword ptr [eax]
// 004fe794  8d44243c             lea eax, [esp + 0x3c]
// 004fe798  50                   push eax
// 004fe799  d9542460             fst dword ptr [esp + 0x60]
// 004fe79d  51                   push ecx
// 004fe79e  d95c2468             fstp dword ptr [esp + 0x68]
// 004fe7a2  52                   push edx
// 004fe7a3  d9e8                 fld1 
// 004fe7a5  8d4d08               lea ecx, [ebp + 8]
// 004fe7a8  d95c2470             fstp dword ptr [esp + 0x70]
// 004fe7ac  e81ff4ffff           call 0x4fdbd0
// 004fe7b1  e8eab30000           call 0x509ba0
// 004fe7b6  8bc8                 mov ecx, eax
// 004fe7b8  d901                 fld dword ptr [ecx]
// 004fe7ba  d85d2c               fcomp dword ptr [ebp + 0x2c]
// 004fe7bd  dfe0                 fnstsw ax
// 004fe7bf  f6c444               test ah, 0x44
// 004fe7c2  7a15                 jp 0x4fe7d9
// 004fe7c4  d94104               fld dword ptr [ecx + 4]
// 004fe7c7  d85d30               fcomp dword ptr [ebp + 0x30]
// 004fe7ca  dfe0                 fnstsw ax
// 004fe7cc  f6c444               test ah, 0x44
// 004fe7cf  7a08                 jp 0x4fe7d9
// 004fe7d1  d94524               fld dword ptr [ebp + 0x24]
// 004fe7d4  d94528               fld dword ptr [ebp + 0x28]
// 004fe7d7  eb08                 jmp 0x4fe7e1
// 004fe7d9  d9442434             fld dword ptr [esp + 0x34]
// 004fe7dd  d9442438             fld dword ptr [esp + 0x38]
// 004fe7e1  d905ac9b8100         fld dword ptr [0x819bac]
// 004fe7e7  8d442454             lea eax, [esp + 0x54]
// 004fe7eb  dcca                 fmul st(2), st(0)
// 004fe7ed  50                   push eax
// 004fe7ee  d9ca                 fxch st(2)
// 004fe7f0  8d4c247c             lea ecx, [esp + 0x7c]
// 004fe7f4  51                   push ecx
// 004fe7f5  d95c2454             fstp dword ptr [esp + 0x54]
// 004fe7f9  dec9                 fmulp st(1)
// 004fe7fb  d95c2458             fstp dword ptr [esp + 0x58]
// 004fe7ff  e89cd90e00           call 0x5ec1a0
// 004fe804  8d542468             lea edx, [esp + 0x68]
// 004fe808  52                   push edx
// 004fe809  8d842490000000       lea eax, [esp + 0x90]
// 004fe810  50                   push eax
// 004fe811  e88ad90e00           call 0x5ec1a0
// 004fe816  6a01                 push 1
// 004fe818  8d4c2460             lea ecx, [esp + 0x60]
// 004fe81c  51                   push ecx
// 004fe81d  8d942490000000       lea edx, [esp + 0x90]
// 004fe824  52                   push edx
// 004fe825  8d8424a0000000       lea eax, [esp + 0xa0]
// 004fe82c  50                   push eax
// 004fe82d  e8ce970400           call 0x548000
// 004fe832  d9442460             fld dword ptr [esp + 0x60]
// 004fe836  0fbf4d3a             movsx ecx, word ptr [ebp + 0x3a]
// 004fe83a  d844243c             fadd dword ptr [esp + 0x3c]
// 004fe83e  41                   inc ecx
// 004fe83f  0fafcb               imul ecx, ebx
// 004fe842  d954243c             fst dword ptr [esp + 0x3c]
// 004fe846  d9442468             fld dword ptr [esp + 0x68]
// 004fe84a  d8442440             fadd dword ptr [esp + 0x40]
// 004fe84e  d9542440             fst dword ptr [esp + 0x40]
// 004fe852  03cf                 add ecx, edi
// 004fe854  89048e               mov dword ptr [esi + ecx*4], eax
// 004fe857  668b453a             mov ax, word ptr [ebp + 0x3a]
// 004fe85b  0fbfd0               movsx edx, ax
// 004fe85e  47                   inc edi
// 004fe85f  83c420               add esp, 0x20
// 004fe862  3bfa                 cmp edi, edx
// 004fe864  0f8edcfeffff         jle 0x4fe746
// 004fe86a  8b5538               mov edx, dword ptr [ebp + 0x38]
// 004fe86d  ddd9                 fstp st(1)
// 004fe86f  ddd8                 fstp st(0)
// 004fe871  d9ee                 fldz 
// 004fe873  eb04                 jmp 0x4fe879
// 004fe875  ddd9                 fstp st(1)
// 004fe877  ddd8                 fstp st(0)
// 004fe879  d944243c             fld dword ptr [esp + 0x3c]
// 004fe87d  0fbfca               movsx ecx, dx
// 004fe880  d8442410             fadd dword ptr [esp + 0x10]
// 004fe884  43                   inc ebx
// 004fe885  3bd9                 cmp ebx, ecx
// 004fe887  d95c2410             fstp dword ptr [esp + 0x10]
// 004fe88b  d9442444             fld dword ptr [esp + 0x44]
// 004fe88f  d8442414             fadd dword ptr [esp + 0x14]
// 004fe893  d95c2414             fstp dword ptr [esp + 0x14]
// 004fe897  0f8e6efeffff         jle 0x4fe70b
// 004fe89d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004fe8a1  ddd8                 fstp st(0)
// 004fe8a3  33c9                 xor ecx, ecx
// 004fe8a5  33db                 xor ebx, ebx
// 004fe8a7  663bca               cmp cx, dx
// 004fe8aa  7d48                 jge 0x4fe8f4
// 004fe8ac  0fbfc8               movsx ecx, ax
// 004fe8af  90                   nop 
// 004fe8b0  33ff                 xor edi, edi
// 004fe8b2  85c9                 test ecx, ecx
// 004fe8b4  7e32                 jle 0x4fe8e8
// 004fe8b6  8d4101               lea eax, [ecx + 1]
// 004fe8b9  0fafc3               imul eax, ebx
// 004fe8bc  03c7                 add eax, edi
// 004fe8be  03c8                 add ecx, eax
// 004fe8c0  8b548e08             mov edx, dword ptr [esi + ecx*4 + 8]
// 004fe8c4  8b4c8e04             mov ecx, dword ptr [esi + ecx*4 + 4]
// 004fe8c8  52                   push edx
// 004fe8c9  8b1486               mov edx, dword ptr [esi + eax*4]
// 004fe8cc  8b448604             mov eax, dword ptr [esi + eax*4 + 4]
// 004fe8d0  51                   push ecx
// 004fe8d1  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 004fe8d5  52                   push edx
// 004fe8d6  50                   push eax
// 004fe8d7  e8d4250000           call 0x500eb0
// 004fe8dc  0fbf4d3a             movsx ecx, word ptr [ebp + 0x3a]
// 004fe8e0  47                   inc edi
// 004fe8e1  3bf9                 cmp edi, ecx
// 004fe8e3  7cd1                 jl 0x4fe8b6
// 004fe8e5  8b5538               mov edx, dword ptr [ebp + 0x38]
// 004fe8e8  0fbfc2               movsx eax, dx
// 004fe8eb  43                   inc ebx
// 004fe8ec  3bd8                 cmp ebx, eax
// 004fe8ee  7cc0                 jl 0x4fe8b0
// 004fe8f0  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004fe8f4  33db                 xor ebx, ebx
// 004fe8f6  85ff                 test edi, edi
// 004fe8f8  7617                 jbe 0x4fe911
// 004fe8fa  8d9b00000000         lea ebx, [ebx]
// 004fe900  8b0c9e               mov ecx, dword ptr [esi + ebx*4]
// 004fe903  51                   push ecx
// 004fe904  e8379d0400           call 0x548640
// 004fe909  43                   inc ebx
// 004fe90a  83c404               add esp, 4
// 004fe90d  3bdf                 cmp ebx, edi
// 004fe90f  72ef                 jb 0x4fe900
// 004fe911  56                   push esi
// 004fe912  e833201a00           call 0x6a094a
// 004fe917  83c404               add esp, 4
// 004fe91a  5f                   pop edi
// 004fe91b  5e                   pop esi
// 004fe91c  5b                   pop ebx
// 004fe91d  8be5                 mov esp, ebp
// 004fe91f  5d                   pop ebp
// 004fe920  c23400               ret 0x34

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
