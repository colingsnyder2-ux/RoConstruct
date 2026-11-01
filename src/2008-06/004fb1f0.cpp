// from server: 100% by EspClaude
// from server: 98% by EspClaude
// roc 2008-06 004fb1f0  unit: RBX::ViewNew::TorsoBuilder  size: 739 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004fb1f0
//
// 004fb1f0  55                   push ebp
// 004fb1f1  8bec                 mov ebp, esp
// 004fb1f3  83e4f8               and esp, 0xfffffff8
// 004fb1f6  81ec84000000         sub esp, 0x84
// 004fb1fc  53                   push ebx
// 004fb1fd  56                   push esi
// 004fb1fe  894c242c             mov dword ptr [esp + 0x2c], ecx
// 004fb202  57                   push edi
// 004fb203  83c104               add ecx, 4
// 004fb206  51                   push ecx
// 004fb207  8d442464             lea eax, [esp + 0x64]
// 004fb20b  50                   push eax
// 004fb20c  e8bfd21700           call 0x6784d0
// 004fb211  d9442468             fld dword ptr [esp + 0x68]
// 004fb215  0fbf4534             movsx eax, word ptr [ebp + 0x34]
// 004fb219  d9e1                 fabs 
// 004fb21b  d95c2474             fstp dword ptr [esp + 0x74]
// 004fb21f  8944242c             mov dword ptr [esp + 0x2c], eax
// 004fb223  d944246c             fld dword ptr [esp + 0x6c]
// 004fb227  0fbf7d36             movsx edi, word ptr [ebp + 0x36]
// 004fb22b  d9e1                 fabs 
// 004fb22d  d95c2478             fstp dword ptr [esp + 0x78]
// 004fb231  d9442470             fld dword ptr [esp + 0x70]
// 004fb235  40                   inc eax
// 004fb236  d9e1                 fabs 
// 004fb238  33c9                 xor ecx, ecx
// 004fb23a  d95c247c             fstp dword ptr [esp + 0x7c]
// 004fb23e  ba04000000           mov edx, 4
// 004fb243  db44242c             fild dword ptr [esp + 0x2c]
// 004fb247  897c242c             mov dword ptr [esp + 0x2c], edi
// 004fb24b  d94514               fld dword ptr [ebp + 0x14]
// 004fb24e  47                   inc edi
// 004fb24f  d8650c               fsub dword ptr [ebp + 0xc]
// 004fb252  0faff8               imul edi, eax
// 004fb255  d8f1                 fdiv st(1)
// 004fb257  8bc7                 mov eax, edi
// 004fb259  d95c2444             fstp dword ptr [esp + 0x44]
// 004fb25d  f7e2                 mul edx
// 004fb25f  db44242c             fild dword ptr [esp + 0x2c]
// 004fb263  d94518               fld dword ptr [ebp + 0x18]
// 004fb266  d86510               fsub dword ptr [ebp + 0x10]
// 004fb269  d8f1                 fdiv st(1)
// 004fb26b  0f90c1               seto cl
// 004fb26e  897c242c             mov dword ptr [esp + 0x2c], edi
// 004fb272  f7d9                 neg ecx
// 004fb274  0bc8                 or ecx, eax
// 004fb276  51                   push ecx
// 004fb277  d95c244c             fstp dword ptr [esp + 0x4c]
// 004fb27b  d94528               fld dword ptr [ebp + 0x28]
// 004fb27e  def2                 fdivrp st(2)
// 004fb280  d9c9                 fxch st(1)
// 004fb282  d95c2450             fstp dword ptr [esp + 0x50]
// 004fb286  d87d2c               fdivr dword ptr [ebp + 0x2c]
// 004fb289  d95c2454             fstp dword ptr [esp + 0x54]
// 004fb28d  e8c4561a00           call 0x6a0956
// 004fb292  d9450c               fld dword ptr [ebp + 0xc]
// 004fb295  8b5534               mov edx, dword ptr [ebp + 0x34]
// 004fb298  d95c241c             fstp dword ptr [esp + 0x1c]
// 004fb29c  d94520               fld dword ptr [ebp + 0x20]
// 004fb29f  8bf0                 mov esi, eax
// 004fb2a1  33c0                 xor eax, eax
// 004fb2a3  d95c2420             fstp dword ptr [esp + 0x20]
// 004fb2a7  83c40c               add esp, 0xc
// 004fb2aa  33db                 xor ebx, ebx
// 004fb2ac  663bc2               cmp ax, dx
// 004fb2af  668b4536             mov ax, word ptr [ebp + 0x36]
// 004fb2b3  0f8f9c010000         jg 0x4fb455
// 004fb2b9  d9ee                 fldz 
// 004fb2bb  d94510               fld dword ptr [ebp + 0x10]
// 004fb2be  33c9                 xor ecx, ecx
// 004fb2c0  d954241c             fst dword ptr [esp + 0x1c]
// 004fb2c4  33ff                 xor edi, edi
// 004fb2c6  663bc8               cmp cx, ax
// 004fb2c9  d94524               fld dword ptr [ebp + 0x24]
// 004fb2cc  d9542420             fst dword ptr [esp + 0x20]
// 004fb2d0  0f8f51010000         jg 0x4fb427
// 004fb2d6  8b4d30               mov ecx, dword ptr [ebp + 0x30]
// 004fb2d9  03c9                 add ecx, ecx
// 004fb2db  03c9                 add ecx, ecx
// 004fb2dd  8d442438             lea eax, [esp + 0x38]
// 004fb2e1  2bc1                 sub eax, ecx
// 004fb2e3  8d540c34             lea edx, [esp + ecx + 0x34]
// 004fb2e7  89442428             mov dword ptr [esp + 0x28], eax
// 004fb2eb  8954242c             mov dword ptr [esp + 0x2c], edx
// 004fb2ef  eb0a                 jmp 0x4fb2fb
// 004fb2f1  d9ee                 fldz 
// 004fb2f3  8b442428             mov eax, dword ptr [esp + 0x28]
// 004fb2f7  d9ca                 fxch st(2)
// 004fb2f9  d9c9                 fxch st(1)
// 004fb2fb  d9442410             fld dword ptr [esp + 0x10]
// 004fb2ff  8d4c2418             lea ecx, [esp + 0x18]
// 004fb303  d95c2460             fstp dword ptr [esp + 0x60]
// 004fb307  51                   push ecx
// 004fb308  d9c9                 fxch st(1)
// 004fb30a  8d542470             lea edx, [esp + 0x70]
// 004fb30e  d95c2468             fstp dword ptr [esp + 0x68]
// 004fb312  52                   push edx
// 004fb313  d9451c               fld dword ptr [ebp + 0x1c]
// 004fb316  8d4c245c             lea ecx, [esp + 0x5c]
// 004fb31a  d95c2470             fstp dword ptr [esp + 0x70]
// 004fb31e  8d542468             lea edx, [esp + 0x68]
// 004fb322  d9c9                 fxch st(1)
// 004fb324  66895c2420           mov word ptr [esp + 0x20], bx
// 004fb329  d954243c             fst dword ptr [esp + 0x3c]
// 004fb32d  66897c2422           mov word ptr [esp + 0x22], di
// 004fb332  d9542440             fst dword ptr [esp + 0x40]
// 004fb336  d944241c             fld dword ptr [esp + 0x1c]
// 004fb33a  d918                 fstp dword ptr [eax]
// 004fb33c  8b442434             mov eax, dword ptr [esp + 0x34]
// 004fb340  d9c9                 fxch st(1)
// 004fb342  d918                 fstp dword ptr [eax]
// 004fb344  8d44243c             lea eax, [esp + 0x3c]
// 004fb348  50                   push eax
// 004fb349  d9542460             fst dword ptr [esp + 0x60]
// 004fb34d  51                   push ecx
// 004fb34e  d95c2468             fstp dword ptr [esp + 0x68]
// 004fb352  52                   push edx
// 004fb353  d9e8                 fld1 
// 004fb355  d95c2470             fstp dword ptr [esp + 0x70]
// 004fb359  ff5508               call dword ptr [ebp + 8]
// 004fb35c  83c414               add esp, 0x14
// 004fb35f  e83ce80000           call 0x509ba0
// 004fb364  8bc8                 mov ecx, eax
// 004fb366  d901                 fld dword ptr [ecx]
// 004fb368  d85d28               fcomp dword ptr [ebp + 0x28]
// 004fb36b  dfe0                 fnstsw ax
// 004fb36d  f6c444               test ah, 0x44
// 004fb370  7a1b                 jp 0x4fb38d
// 004fb372  d94104               fld dword ptr [ecx + 4]
// 004fb375  d85d2c               fcomp dword ptr [ebp + 0x2c]
// 004fb378  dfe0                 fnstsw ax
// 004fb37a  f6c444               test ah, 0x44
// 004fb37d  7a0e                 jp 0x4fb38d
// 004fb37f  d94520               fld dword ptr [ebp + 0x20]
// 004fb382  d95c2434             fstp dword ptr [esp + 0x34]
// 004fb386  d94524               fld dword ptr [ebp + 0x24]
// 004fb389  d95c2438             fstp dword ptr [esp + 0x38]
// 004fb38d  d9442434             fld dword ptr [esp + 0x34]
// 004fb391  8d442454             lea eax, [esp + 0x54]
// 004fb395  d905ac9b8100         fld dword ptr [0x819bac]
// 004fb39b  50                   push eax
// 004fb39c  dcc9                 fmul st(1), st(0)
// 004fb39e  8d4c247c             lea ecx, [esp + 0x7c]
// 004fb3a2  d9c9                 fxch st(1)
// 004fb3a4  51                   push ecx
// 004fb3a5  d95c2454             fstp dword ptr [esp + 0x54]
// 004fb3a9  d84c2440             fmul dword ptr [esp + 0x40]
// 004fb3ad  d95c2458             fstp dword ptr [esp + 0x58]
// 004fb3b1  e81ad11700           call 0x6784d0
// 004fb3b6  8d542468             lea edx, [esp + 0x68]
// 004fb3ba  52                   push edx
// 004fb3bb  8d842490000000       lea eax, [esp + 0x90]
// 004fb3c2  50                   push eax
// 004fb3c3  e808d11700           call 0x6784d0
// 004fb3c8  6a01                 push 1
// 004fb3ca  8d4c2460             lea ecx, [esp + 0x60]
// 004fb3ce  51                   push ecx
// 004fb3cf  8d942490000000       lea edx, [esp + 0x90]
// 004fb3d6  52                   push edx
// 004fb3d7  8d8424a0000000       lea eax, [esp + 0xa0]
// 004fb3de  50                   push eax
// 004fb3df  e81ccc0400           call 0x548000
// 004fb3e4  d9442460             fld dword ptr [esp + 0x60]
// 004fb3e8  0fbf4d36             movsx ecx, word ptr [ebp + 0x36]
// 004fb3ec  d844243c             fadd dword ptr [esp + 0x3c]
// 004fb3f0  41                   inc ecx
// 004fb3f1  0fafcb               imul ecx, ebx
// 004fb3f4  d954243c             fst dword ptr [esp + 0x3c]
// 004fb3f8  d9442468             fld dword ptr [esp + 0x68]
// 004fb3fc  d8442440             fadd dword ptr [esp + 0x40]
// 004fb400  d9542440             fst dword ptr [esp + 0x40]
// 004fb404  03cf                 add ecx, edi
// 004fb406  89048e               mov dword ptr [esi + ecx*4], eax
// 004fb409  668b4536             mov ax, word ptr [ebp + 0x36]
// 004fb40d  0fbfd0               movsx edx, ax
// 004fb410  47                   inc edi
// 004fb411  83c420               add esp, 0x20
// 004fb414  3bfa                 cmp edi, edx
// 004fb416  0f8ed5feffff         jle 0x4fb2f1
// 004fb41c  8b5534               mov edx, dword ptr [ebp + 0x34]
// 004fb41f  ddd9                 fstp st(1)
// 004fb421  ddd8                 fstp st(0)
// 004fb423  d9ee                 fldz 
// 004fb425  eb04                 jmp 0x4fb42b
// 004fb427  ddd9                 fstp st(1)
// 004fb429  ddd8                 fstp st(0)
// 004fb42b  d944243c             fld dword ptr [esp + 0x3c]
// 004fb42f  0fbfca               movsx ecx, dx
// 004fb432  d8442410             fadd dword ptr [esp + 0x10]
// 004fb436  43                   inc ebx
// 004fb437  3bd9                 cmp ebx, ecx
// 004fb439  d95c2410             fstp dword ptr [esp + 0x10]
// 004fb43d  d9442444             fld dword ptr [esp + 0x44]
// 004fb441  d8442414             fadd dword ptr [esp + 0x14]
// 004fb445  d95c2414             fstp dword ptr [esp + 0x14]
// 004fb449  0f8e6cfeffff         jle 0x4fb2bb
// 004fb44f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004fb453  ddd8                 fstp st(0)
// 004fb455  33c9                 xor ecx, ecx
// 004fb457  33db                 xor ebx, ebx
// 004fb459  663bca               cmp cx, dx
// 004fb45c  7d47                 jge 0x4fb4a5
// 004fb45e  0fbfc8               movsx ecx, ax
// 004fb461  33ff                 xor edi, edi
// 004fb463  85c9                 test ecx, ecx
// 004fb465  7e32                 jle 0x4fb499
// 004fb467  8d4101               lea eax, [ecx + 1]
// 004fb46a  0fafc3               imul eax, ebx
// 004fb46d  03c7                 add eax, edi
// 004fb46f  03c8                 add ecx, eax
// 004fb471  8b548e08             mov edx, dword ptr [esi + ecx*4 + 8]
// 004fb475  8b4c8e04             mov ecx, dword ptr [esi + ecx*4 + 4]
// 004fb479  52                   push edx
// 004fb47a  8b1486               mov edx, dword ptr [esi + eax*4]
// 004fb47d  8b448604             mov eax, dword ptr [esi + eax*4 + 4]
// 004fb481  51                   push ecx
// 004fb482  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 004fb486  52                   push edx
// 004fb487  50                   push eax
// 004fb488  e8235a0000           call 0x500eb0
// 004fb48d  0fbf4d36             movsx ecx, word ptr [ebp + 0x36]
// 004fb491  47                   inc edi
// 004fb492  3bf9                 cmp edi, ecx
// 004fb494  7cd1                 jl 0x4fb467
// 004fb496  8b5534               mov edx, dword ptr [ebp + 0x34]
// 004fb499  0fbfc2               movsx eax, dx
// 004fb49c  43                   inc ebx
// 004fb49d  3bd8                 cmp ebx, eax
// 004fb49f  7cc0                 jl 0x4fb461
// 004fb4a1  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004fb4a5  33db                 xor ebx, ebx
// 004fb4a7  85ff                 test edi, edi
// 004fb4a9  7616                 jbe 0x4fb4c1
// 004fb4ab  eb03                 jmp 0x4fb4b0
// 004fb4ad  8d4900               lea ecx, [ecx]
// 004fb4b0  8b0c9e               mov ecx, dword ptr [esi + ebx*4]
// 004fb4b3  51                   push ecx
// 004fb4b4  e887d10400           call 0x548640
// 004fb4b9  43                   inc ebx
// 004fb4ba  83c404               add esp, 4
// 004fb4bd  3bdf                 cmp ebx, edi
// 004fb4bf  72ef                 jb 0x4fb4b0
// 004fb4c1  56                   push esi
// 004fb4c2  e883541a00           call 0x6a094a
// 004fb4c7  83c404               add esp, 4
// 004fb4ca  5f                   pop edi
// 004fb4cb  5e                   pop esi
// 004fb4cc  5b                   pop ebx
// 004fb4cd  8be5                 mov esp, ebp
// 004fb4cf  5d                   pop ebp
// 004fb4d0  c23000               ret 0x30

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

typedef void (__cdecl *VertexCallback)(
    Vec3*, Vec3*, Vec2*, const Vec3*, const GridSize*);

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

            GridSize index;
            index.x = (short)i;
            index.y = (short)j;

            callback(&position, &normal, &texture, &absoluteDimensions, &index);

            const Vec2& size = currentTextureSize();
            if (textureExtent.x == size.x && textureExtent.y == size.y) {
                texture.x = textureOrigin.x;
                texture.y = textureOrigin.y;
            }

            Vec2 scaledTexture;
            scaledTexture.x = texture.x * textureScale;
            scaledTexture.y = texture.y * textureScale;

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

#pragma float_control(pop)
