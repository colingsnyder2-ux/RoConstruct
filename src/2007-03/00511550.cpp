// from server: 100% by auto
// roc 2007-03 00511550  unit: seg_00510000  size: 1815 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00511550
//
// 00511550  55                   push ebp
// 00511551  8bec                 mov ebp, esp
// 00511553  83e4f8               and esp, 0xfffffff8
// 00511556  d9ee                 fldz 
// 00511558  83ec34               sub esp, 0x34
// 0051155b  53                   push ebx
// 0051155c  56                   push esi
// 0051155d  8b7508               mov esi, dword ptr [ebp + 8]
// 00511560  d89e5c010000         fcomp dword ptr [esi + 0x15c]
// 00511566  57                   push edi
// 00511567  dfe0                 fnstsw ax
// 00511569  f6c444               test ah, 0x44
// 0051156c  0f8bee060000         jnp 0x511c60
// 00511572  ba08000000           mov edx, 8
// 00511577  389627010000         cmp byte ptr [esi + 0x127], dl
// 0051157d  0f87e0010000         ja 0x511763
// 00511583  d98660010000         fld dword ptr [esi + 0x160]
// 00511589  dd05a0267a00         fld qword ptr [0x7a26a0]
// 0051158f  d8d9                 fcomp st(1)
// 00511591  dfe0                 fnstsw ax
// 00511593  f6c405               test ah, 5
// 00511596  7a0c                 jp 0x5115a4
// 00511598  d88e5c010000         fmul dword ptr [esi + 0x15c]
// 0051159e  d9e8                 fld1 
// 005115a0  def1                 fdivrp st(1)
// 005115a2  eb04                 jmp 0x5115a8
// 005115a4  ddd8                 fstp st(0)
// 005115a6  d9e8                 fld1 
// 005115a8  6800010000           push 0x100
// 005115ad  dd5c2434             fstp qword ptr [esp + 0x34]
// 005115b1  56                   push esi
// 005115b2  e8e9790000           call 0x518fa0
// 005115b7  dd0510c47800         fld qword ptr [0x78c410]
// 005115bd  83c408               add esp, 8
// 005115c0  33ff                 xor edi, edi
// 005115c2  898664010000         mov dword ptr [esi + 0x164], eax
// 005115c8  897c2418             mov dword ptr [esp + 0x18], edi
// 005115cc  da7c2418             fidivr dword ptr [esp + 0x18]
// 005115d0  dd442430             fld qword ptr [esp + 0x30]
// 005115d4  e865e01000           call 0x61f63e
// 005115d9  dd0510c47800         fld qword ptr [0x78c410]
// 005115df  8b8e64010000         mov ecx, dword ptr [esi + 0x164]
// 005115e5  d97c240c             fnstcw word ptr [esp + 0xc]
// 005115e9  0fb744240c           movzx eax, word ptr [esp + 0xc]
// 005115ee  dcc9                 fmul st(1), st(0)
// 005115f0  0d000c0000           or eax, 0xc00
// 005115f5  d9c9                 fxch st(1)
// 005115f7  89442420             mov dword ptr [esp + 0x20], eax
// 005115fb  83c701               add edi, 1
// 005115fe  81ff00010000         cmp edi, 0x100
// 00511604  dc05584f7900         fadd qword ptr [0x794f58]
// 0051160a  d96c2420             fldcw word ptr [esp + 0x20]
// 0051160e  897c2418             mov dword ptr [esp + 0x18], edi
// 00511612  db5c2420             fistp dword ptr [esp + 0x20]
// 00511616  8a442420             mov al, byte ptr [esp + 0x20]
// 0051161a  88440fff             mov byte ptr [edi + ecx - 1], al
// 0051161e  d96c240c             fldcw word ptr [esp + 0xc]
// 00511622  7ca8                 jl 0x5115cc
// 00511624  f7467080006000       test dword ptr [esi + 0x70], 0x600080
// 0051162b  ddd8                 fstp st(0)
// 0051162d  0f842d060000         je 0x511c60
// 00511633  d9865c010000         fld dword ptr [esi + 0x15c]
// 00511639  6800010000           push 0x100
// 0051163e  d9e8                 fld1 
// 00511640  56                   push esi
// 00511641  def1                 fdivrp st(1)
// 00511643  dd5c2438             fstp qword ptr [esp + 0x38]
// 00511647  e854790000           call 0x518fa0
// 0051164c  dd0510c47800         fld qword ptr [0x78c410]
// 00511652  83c408               add esp, 8
// 00511655  33ff                 xor edi, edi
// 00511657  89866c010000         mov dword ptr [esi + 0x16c], eax
// 0051165d  897c2418             mov dword ptr [esp + 0x18], edi
// 00511661  da7c2418             fidivr dword ptr [esp + 0x18]
// 00511665  dd442430             fld qword ptr [esp + 0x30]
// 00511669  e8d0df1000           call 0x61f63e
// 0051166e  dd0510c47800         fld qword ptr [0x78c410]
// 00511674  d97c240c             fnstcw word ptr [esp + 0xc]
// 00511678  83c701               add edi, 1
// 0051167b  0fb744240c           movzx eax, word ptr [esp + 0xc]
// 00511680  dcc9                 fmul st(1), st(0)
// 00511682  0d000c0000           or eax, 0xc00
// 00511687  d9c9                 fxch st(1)
// 00511689  81ff00010000         cmp edi, 0x100
// 0051168f  89442420             mov dword ptr [esp + 0x20], eax
// 00511693  dc05584f7900         fadd qword ptr [0x794f58]
// 00511699  8b866c010000         mov eax, dword ptr [esi + 0x16c]
// 0051169f  897c2418             mov dword ptr [esp + 0x18], edi
// 005116a3  d96c2420             fldcw word ptr [esp + 0x20]
// 005116a7  db5c2420             fistp dword ptr [esp + 0x20]
// 005116ab  8a542420             mov dl, byte ptr [esp + 0x20]
// 005116af  885407ff             mov byte ptr [edi + eax - 1], dl
// 005116b3  d96c240c             fldcw word ptr [esp + 0xc]
// 005116b7  7ca8                 jl 0x511661
// 005116b9  6800010000           push 0x100
// 005116be  ddd8                 fstp st(0)
// 005116c0  56                   push esi
// 005116c1  e8da780000           call 0x518fa0
// 005116c6  d98660010000         fld dword ptr [esi + 0x160]
// 005116cc  dd05a0267a00         fld qword ptr [0x7a26a0]
// 005116d2  898668010000         mov dword ptr [esi + 0x168], eax
// 005116d8  d8d9                 fcomp st(1)
// 005116da  83c408               add esp, 8
// 005116dd  dfe0                 fnstsw ax
// 005116df  f6c405               test ah, 5
// 005116e2  7a06                 jp 0x5116ea
// 005116e4  d9e8                 fld1 
// 005116e6  def1                 fdivrp st(1)
// 005116e8  eb08                 jmp 0x5116f2
// 005116ea  ddd8                 fstp st(0)
// 005116ec  d9865c010000         fld dword ptr [esi + 0x15c]
// 005116f2  33ff                 xor edi, edi
// 005116f4  dd5c2430             fstp qword ptr [esp + 0x30]
// 005116f8  dd0510c47800         fld qword ptr [0x78c410]
// 005116fe  897c2418             mov dword ptr [esp + 0x18], edi
// 00511702  da7c2418             fidivr dword ptr [esp + 0x18]
// 00511706  dd442430             fld qword ptr [esp + 0x30]
// 0051170a  e82fdf1000           call 0x61f63e
// 0051170f  dd0510c47800         fld qword ptr [0x78c410]
// 00511715  8b9668010000         mov edx, dword ptr [esi + 0x168]
// 0051171b  d97c240c             fnstcw word ptr [esp + 0xc]
// 0051171f  0fb744240c           movzx eax, word ptr [esp + 0xc]
// 00511724  dcc9                 fmul st(1), st(0)
// 00511726  d9c9                 fxch st(1)
// 00511728  0d000c0000           or eax, 0xc00
// 0051172d  89442420             mov dword ptr [esp + 0x20], eax
// 00511731  83c701               add edi, 1
// 00511734  81ff00010000         cmp edi, 0x100
// 0051173a  dc05584f7900         fadd qword ptr [0x794f58]
// 00511740  d96c2420             fldcw word ptr [esp + 0x20]
// 00511744  897c2418             mov dword ptr [esp + 0x18], edi
// 00511748  db5c2420             fistp dword ptr [esp + 0x20]
// 0051174c  8a4c2420             mov cl, byte ptr [esp + 0x20]
// 00511750  884c17ff             mov byte ptr [edi + edx - 1], cl
// 00511754  d96c240c             fldcw word ptr [esp + 0xc]
// 00511758  7ca8                 jl 0x511702
// 0051175a  ddd8                 fstp st(0)
// 0051175c  5f                   pop edi
// 0051175d  5e                   pop esi
// 0051175e  5b                   pop ebx
// 0051175f  8be5                 mov esp, ebp
// 00511761  5d                   pop ebp
// 00511762  c3                   ret 
// 00511763  f6862601000002       test byte ptr [esi + 0x126], 2
// 0051176a  7423                 je 0x51178f
// 0051176c  0fb68e7c010000       movzx ecx, byte ptr [esi + 0x17c]
// 00511773  0fb6867d010000       movzx eax, byte ptr [esi + 0x17d]
// 0051177a  3bc1                 cmp eax, ecx
// 0051177c  7e02                 jle 0x511780
// 0051177e  8bc8                 mov ecx, eax
// 00511780  0fb6867e010000       movzx eax, byte ptr [esi + 0x17e]
// 00511787  3bc1                 cmp eax, ecx
// 00511789  7e0b                 jle 0x511796
// 0051178b  8bc8                 mov ecx, eax
// 0051178d  eb07                 jmp 0x511796
// 0051178f  0fb68e7f010000       movzx ecx, byte ptr [esi + 0x17f]
// 00511796  33ff                 xor edi, edi
// 00511798  3bcf                 cmp ecx, edi
// 0051179a  7e0d                 jle 0x5117a9
// 0051179c  b810000000           mov eax, 0x10
// 005117a1  2bc1                 sub eax, ecx
// 005117a3  89442410             mov dword ptr [esp + 0x10], eax
// 005117a7  eb06                 jmp 0x5117af
// 005117a9  897c2410             mov dword ptr [esp + 0x10], edi
// 005117ad  8bc7                 mov eax, edi
// 005117af  f7467000040000       test dword ptr [esi + 0x70], 0x400
// 005117b6  740f                 je 0x5117c7
// 005117b8  83f805               cmp eax, 5
// 005117bb  7d0a                 jge 0x5117c7
// 005117bd  c744241005000000     mov dword ptr [esp + 0x10], 5
// 005117c5  eb12                 jmp 0x5117d9
// 005117c7  3bc2                 cmp eax, edx
// 005117c9  7e06                 jle 0x5117d1
// 005117cb  89542410             mov dword ptr [esp + 0x10], edx
// 005117cf  eb08                 jmp 0x5117d9
// 005117d1  3bc7                 cmp eax, edi
// 005117d3  7d08                 jge 0x5117dd
// 005117d5  897c2410             mov dword ptr [esp + 0x10], edi
// 005117d9  8b442410             mov eax, dword ptr [esp + 0x10]
// 005117dd  d98660010000         fld dword ptr [esi + 0x160]
// 005117e3  0fb6c8               movzx ecx, al
// 005117e6  dd05a0267a00         fld qword ptr [0x7a26a0]
// 005117ec  898e58010000         mov dword ptr [esi + 0x158], ecx
// 005117f2  8bca                 mov ecx, edx
// 005117f4  d8d9                 fcomp st(1)
// 005117f6  2bc8                 sub ecx, eax
// 005117f8  bb01000000           mov ebx, 1
// 005117fd  d3e3                 shl ebx, cl
// 005117ff  dfe0                 fnstsw ax
// 00511801  f6c405               test ah, 5
// 00511804  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00511808  895c2418             mov dword ptr [esp + 0x18], ebx
// 0051180c  7a0c                 jp 0x51181a
// 0051180e  d88e5c010000         fmul dword ptr [esi + 0x15c]
// 00511814  d9e8                 fld1 
// 00511816  def1                 fdivrp st(1)
// 00511818  eb04                 jmp 0x51181e
// 0051181a  ddd8                 fstp st(0)
// 0051181c  d9e8                 fld1 
// 0051181e  8d049d00000000       lea eax, [ebx*4]
// 00511825  dd5c2430             fstp qword ptr [esp + 0x30]
// 00511829  50                   push eax
// 0051182a  56                   push esi
// 0051182b  e870770000           call 0x518fa0
// 00511830  83c408               add esp, 8
// 00511833  f7467080040000       test dword ptr [esi + 0x70], 0x480
// 0051183a  898670010000         mov dword ptr [esi + 0x170], eax
// 00511840  0f8455010000         je 0x51199b
// 00511846  85db                 test ebx, ebx
// 00511848  7e24                 jle 0x51186e
// 0051184a  8d9b00000000         lea ebx, [ebx]
// 00511850  6800020000           push 0x200
// 00511855  56                   push esi
// 00511856  e845770000           call 0x518fa0
// 0051185b  8b9670010000         mov edx, dword ptr [esi + 0x170]
// 00511861  8904ba               mov dword ptr [edx + edi*4], eax
// 00511864  83c701               add edi, 1
// 00511867  83c408               add esp, 8
// 0051186a  3bfb                 cmp edi, ebx
// 0051186c  7ce2                 jl 0x511850
// 0051186e  d9e8                 fld1 
// 00511870  8bc3                 mov eax, ebx
// 00511872  dc742430             fdiv qword ptr [esp + 0x30]
// 00511876  c1e008               shl eax, 8
// 00511879  33ff                 xor edi, edi
// 0051187b  85c0                 test eax, eax
// 0051187d  89442428             mov dword ptr [esp + 0x28], eax
// 00511881  897c2414             mov dword ptr [esp + 0x14], edi
// 00511885  89442420             mov dword ptr [esp + 0x20], eax
// 00511889  dd5c2430             fstp qword ptr [esp + 0x30]
// 0051188d  db442428             fild dword ptr [esp + 0x28]
// 00511891  7d06                 jge 0x511899
// 00511893  dc05a89b7800         fadd qword ptr [0x789ba8]
// 00511899  dd5c2438             fstp qword ptr [esp + 0x38]
// 0051189d  db442414             fild dword ptr [esp + 0x14]
// 005118a1  dc05584f7900         fadd qword ptr [0x794f58]
// 005118a7  dc0de0727900         fmul qword ptr [0x7972e0]
// 005118ad  dd442430             fld qword ptr [esp + 0x30]
// 005118b1  e888dd1000           call 0x61f63e
// 005118b6  dc4c2438             fmul qword ptr [esp + 0x38]
// 005118ba  d97c240c             fnstcw word ptr [esp + 0xc]
// 005118be  0fb744240c           movzx eax, word ptr [esp + 0xc]
// 005118c3  0d000c0000           or eax, 0xc00
// 005118c8  89442424             mov dword ptr [esp + 0x24], eax
// 005118cc  d96c2424             fldcw word ptr [esp + 0x24]
// 005118d0  df7c2428             fistp qword ptr [esp + 0x28]
// 005118d4  8b442428             mov eax, dword ptr [esp + 0x28]
// 005118d8  3bf8                 cmp edi, eax
// 005118da  89442428             mov dword ptr [esp + 0x28], eax
// 005118de  d96c240c             fldcw word ptr [esp + 0xc]
// 005118e2  7759                 ja 0x51193d
// 005118e4  0fb7442414           movzx eax, word ptr [esp + 0x14]
// 005118e9  33c9                 xor ecx, ecx
// 005118eb  8ae8                 mov ch, al
// 005118ed  0bc8                 or ecx, eax
// 005118ef  894c2424             mov dword ptr [esp + 0x24], ecx
// 005118f3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005118f7  b8ff000000           mov eax, 0xff
// 005118fc  d3f8                 sar eax, cl
// 005118fe  8944240c             mov dword ptr [esp + 0xc], eax
// 00511902  eb10                 jmp 0x511914
// 00511904  eb0a                 jmp 0x511910
// 00511906  8da42400000000       lea esp, [esp]
// 0051190d  8d4900               lea ecx, [ecx]
// 00511910  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00511914  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00511918  8b9670010000         mov edx, dword ptr [esi + 0x170]
// 0051191e  8bdf                 mov ebx, edi
// 00511920  d3eb                 shr ebx, cl
// 00511922  668b4c2424           mov cx, word ptr [esp + 0x24]
// 00511927  23c7                 and eax, edi
// 00511929  8b0482               mov eax, dword ptr [edx + eax*4]
// 0051192c  83c701               add edi, 1
// 0051192f  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00511933  66890c58             mov word ptr [eax + ebx*2], cx
// 00511937  76d7                 jbe 0x511910
// 00511939  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0051193d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00511941  83c001               add eax, 1
// 00511944  3d00010000           cmp eax, 0x100
// 00511949  89442414             mov dword ptr [esp + 0x14], eax
// 0051194d  0f8c4affffff         jl 0x51189d
// 00511953  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 00511957  0f8315010000         jae 0x511a72
// 0051195d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00511961  b8ff000000           mov eax, 0xff
// 00511966  d3f8                 sar eax, cl
// 00511968  8944240c             mov dword ptr [esp + 0xc], eax
// 0051196c  eb06                 jmp 0x511974
// 0051196e  8bff                 mov edi, edi
// 00511970  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00511974  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00511978  8b9670010000         mov edx, dword ptr [esi + 0x170]
// 0051197e  8bdf                 mov ebx, edi
// 00511980  23c7                 and eax, edi
// 00511982  8b0482               mov eax, dword ptr [edx + eax*4]
// 00511985  d3eb                 shr ebx, cl
// 00511987  83c701               add edi, 1
// 0051198a  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 0051198e  66c70458ffff         mov word ptr [eax + ebx*2], 0xffff
// 00511994  72da                 jb 0x511970
// 00511996  e9d3000000           jmp 0x511a6e
// 0051199b  85db                 test ebx, ebx
// 0051199d  897c2414             mov dword ptr [esp + 0x14], edi
// 005119a1  0f8ecb000000         jle 0x511a72
// 005119a7  eb0b                 jmp 0x5119b4
// 005119a9  8da42400000000       lea esp, [esp]
// 005119b0  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005119b4  6800020000           push 0x200
// 005119b9  56                   push esi
// 005119ba  e8e1750000           call 0x518fa0
// 005119bf  dd05d8727900         fld qword ptr [0x7972d8]
// 005119c5  8b8e70010000         mov ecx, dword ptr [esi + 0x170]
// 005119cb  8b542418             mov edx, dword ptr [esp + 0x18]
// 005119cf  8904b9               mov dword ptr [ecx + edi*4], eax
// 005119d2  8b049578688900       mov eax, dword ptr [edx*4 + 0x896878]
// 005119d9  0fafc7               imul eax, edi
// 005119dc  c1e804               shr eax, 4
// 005119df  83c408               add esp, 8
// 005119e2  33ff                 xor edi, edi
// 005119e4  8bd8                 mov ebx, eax
// 005119e6  8bc3                 mov eax, ebx
// 005119e8  85c0                 test eax, eax
// 005119ea  89442428             mov dword ptr [esp + 0x28], eax
// 005119ee  db442428             fild dword ptr [esp + 0x28]
// 005119f2  7d06                 jge 0x5119fa
// 005119f4  dc05a89b7800         fadd qword ptr [0x789ba8]
// 005119fa  def1                 fdivrp st(1)
// 005119fc  dd442430             fld qword ptr [esp + 0x30]
// 00511a00  e839dc1000           call 0x61f63e
// 00511a05  dd05d8727900         fld qword ptr [0x7972d8]
// 00511a0b  8b9670010000         mov edx, dword ptr [esi + 0x170]
// 00511a11  d97c240c             fnstcw word ptr [esp + 0xc]
// 00511a15  0fb744240c           movzx eax, word ptr [esp + 0xc]
// 00511a1a  dcc9                 fmul st(1), st(0)
// 00511a1c  0d000c0000           or eax, 0xc00
// 00511a21  d9c9                 fxch st(1)
// 00511a23  89442428             mov dword ptr [esp + 0x28], eax
// 00511a27  8b442414             mov eax, dword ptr [esp + 0x14]
// 00511a2b  dc05584f7900         fadd qword ptr [0x794f58]
// 00511a31  8b1482               mov edx, dword ptr [edx + eax*4]
// 00511a34  d96c2428             fldcw word ptr [esp + 0x28]
// 00511a38  83c702               add edi, 2
// 00511a3b  81c300010000         add ebx, 0x100
// 00511a41  81ff00020000         cmp edi, 0x200
// 00511a47  db5c2428             fistp dword ptr [esp + 0x28]
// 00511a4b  668b4c2428           mov cx, word ptr [esp + 0x28]
// 00511a50  66894c17fe           mov word ptr [edi + edx - 2], cx
// 00511a55  d96c240c             fldcw word ptr [esp + 0xc]
// 00511a59  7c8b                 jl 0x5119e6
// 00511a5b  83c001               add eax, 1
// 00511a5e  ddd8                 fstp st(0)
// 00511a60  3b442418             cmp eax, dword ptr [esp + 0x18]
// 00511a64  89442414             mov dword ptr [esp + 0x14], eax
// 00511a68  0f8c42ffffff         jl 0x5119b0
// 00511a6e  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00511a72  f7467080006000       test dword ptr [esi + 0x70], 0x600080
// 00511a79  0f84e1010000         je 0x511c60
// 00511a7f  d9865c010000         fld dword ptr [esi + 0x15c]
// 00511a85  03db                 add ebx, ebx
// 00511a87  d9e8                 fld1 
// 00511a89  03db                 add ebx, ebx
// 00511a8b  def1                 fdivrp st(1)
// 00511a8d  53                   push ebx
// 00511a8e  56                   push esi
// 00511a8f  dd5c2438             fstp qword ptr [esp + 0x38]
// 00511a93  e808750000           call 0x518fa0
// 00511a98  33db                 xor ebx, ebx
// 00511a9a  83c408               add esp, 8
// 00511a9d  395c2418             cmp dword ptr [esp + 0x18], ebx
// 00511aa1  898678010000         mov dword ptr [esi + 0x178], eax
// 00511aa7  0f8eb4000000         jle 0x511b61
// 00511aad  6800020000           push 0x200
// 00511ab2  56                   push esi
// 00511ab3  e8e8740000           call 0x518fa0
// 00511ab8  dd05d8727900         fld qword ptr [0x7972d8]
// 00511abe  8b8e78010000         mov ecx, dword ptr [esi + 0x178]
// 00511ac4  8b542418             mov edx, dword ptr [esp + 0x18]
// 00511ac8  890499               mov dword ptr [ecx + ebx*4], eax
// 00511acb  8b049578688900       mov eax, dword ptr [edx*4 + 0x896878]
// 00511ad2  0fafc3               imul eax, ebx
// 00511ad5  c1e804               shr eax, 4
// 00511ad8  83c408               add esp, 8
// 00511adb  33ff                 xor edi, edi
// 00511add  89442414             mov dword ptr [esp + 0x14], eax
// 00511ae1  8b442414             mov eax, dword ptr [esp + 0x14]
// 00511ae5  db442414             fild dword ptr [esp + 0x14]
// 00511ae9  85c0                 test eax, eax
// 00511aeb  7d06                 jge 0x511af3
// 00511aed  dc05a89b7800         fadd qword ptr [0x789ba8]
// 00511af3  def1                 fdivrp st(1)
// 00511af5  dd442430             fld qword ptr [esp + 0x30]
// 00511af9  e840db1000           call 0x61f63e
// 00511afe  dd05d8727900         fld qword ptr [0x7972d8]
// 00511b04  8b9678010000         mov edx, dword ptr [esi + 0x178]
// 00511b0a  d97c240c             fnstcw word ptr [esp + 0xc]
// 00511b0e  0fb744240c           movzx eax, word ptr [esp + 0xc]
// 00511b13  dcc9                 fmul st(1), st(0)
// 00511b15  8144241400010000     add dword ptr [esp + 0x14], 0x100
// 00511b1d  d9c9                 fxch st(1)
// 00511b1f  0d000c0000           or eax, 0xc00
// 00511b24  89442428             mov dword ptr [esp + 0x28], eax
// 00511b28  dc05584f7900         fadd qword ptr [0x794f58]
// 00511b2e  8b049a               mov eax, dword ptr [edx + ebx*4]
// 00511b31  83c702               add edi, 2
// 00511b34  81ff00020000         cmp edi, 0x200
// 00511b3a  d96c2428             fldcw word ptr [esp + 0x28]
// 00511b3e  db5c2428             fistp dword ptr [esp + 0x28]
// 00511b42  668b4c2428           mov cx, word ptr [esp + 0x28]
// 00511b47  66894c07fe           mov word ptr [edi + eax - 2], cx
// 00511b4c  d96c240c             fldcw word ptr [esp + 0xc]
// 00511b50  7c8f                 jl 0x511ae1
// 00511b52  83c301               add ebx, 1
// 00511b55  ddd8                 fstp st(0)
// 00511b57  3b5c2418             cmp ebx, dword ptr [esp + 0x18]
// 00511b5b  0f8c4cffffff         jl 0x511aad
// 00511b61  d98660010000         fld dword ptr [esi + 0x160]
// 00511b67  dd05a0267a00         fld qword ptr [0x7a26a0]
// 00511b6d  d8d9                 fcomp st(1)
// 00511b6f  dfe0                 fnstsw ax
// 00511b71  f6c405               test ah, 5
// 00511b74  7a06                 jp 0x511b7c
// 00511b76  d9e8                 fld1 
// 00511b78  def1                 fdivrp st(1)
// 00511b7a  eb08                 jmp 0x511b84
// 00511b7c  ddd8                 fstp st(0)
// 00511b7e  d9865c010000         fld dword ptr [esi + 0x15c]
// 00511b84  8b442418             mov eax, dword ptr [esp + 0x18]
// 00511b88  dd5c2430             fstp qword ptr [esp + 0x30]
// 00511b8c  03c0                 add eax, eax
// 00511b8e  03c0                 add eax, eax
// 00511b90  50                   push eax
// 00511b91  56                   push esi
// 00511b92  e809740000           call 0x518fa0
// 00511b97  33db                 xor ebx, ebx
// 00511b99  83c408               add esp, 8
// 00511b9c  395c2418             cmp dword ptr [esp + 0x18], ebx
// 00511ba0  898674010000         mov dword ptr [esi + 0x174], eax
// 00511ba6  0f8eb4000000         jle 0x511c60
// 00511bac  6800020000           push 0x200
// 00511bb1  56                   push esi
// 00511bb2  e8e9730000           call 0x518fa0
// 00511bb7  dd05d8727900         fld qword ptr [0x7972d8]
// 00511bbd  8b8e74010000         mov ecx, dword ptr [esi + 0x174]
// 00511bc3  8b542418             mov edx, dword ptr [esp + 0x18]
// 00511bc7  890499               mov dword ptr [ecx + ebx*4], eax
// 00511bca  8b049578688900       mov eax, dword ptr [edx*4 + 0x896878]
// 00511bd1  0fafc3               imul eax, ebx
// 00511bd4  c1e804               shr eax, 4
// 00511bd7  83c408               add esp, 8
// 00511bda  33ff                 xor edi, edi
// 00511bdc  89442414             mov dword ptr [esp + 0x14], eax
// 00511be0  8b442414             mov eax, dword ptr [esp + 0x14]
// 00511be4  db442414             fild dword ptr [esp + 0x14]
// 00511be8  85c0                 test eax, eax
// 00511bea  7d06                 jge 0x511bf2
// 00511bec  dc05a89b7800         fadd qword ptr [0x789ba8]
// 00511bf2  def1                 fdivrp st(1)
// 00511bf4  dd442430             fld qword ptr [esp + 0x30]
// 00511bf8  e841da1000           call 0x61f63e
// 00511bfd  dd05d8727900         fld qword ptr [0x7972d8]
// 00511c03  8b9674010000         mov edx, dword ptr [esi + 0x174]
// 00511c09  d97c240c             fnstcw word ptr [esp + 0xc]
// 00511c0d  0fb744240c           movzx eax, word ptr [esp + 0xc]
// 00511c12  dcc9                 fmul st(1), st(0)
// 00511c14  8144241400010000     add dword ptr [esp + 0x14], 0x100
// 00511c1c  d9c9                 fxch st(1)
// 00511c1e  0d000c0000           or eax, 0xc00
// 00511c23  89442428             mov dword ptr [esp + 0x28], eax
// 00511c27  dc05584f7900         fadd qword ptr [0x794f58]
// 00511c2d  8b049a               mov eax, dword ptr [edx + ebx*4]
// 00511c30  83c702               add edi, 2
// 00511c33  81ff00020000         cmp edi, 0x200
// 00511c39  d96c2428             fldcw word ptr [esp + 0x28]
// 00511c3d  db5c2428             fistp dword ptr [esp + 0x28]
// 00511c41  668b4c2428           mov cx, word ptr [esp + 0x28]
// 00511c46  66894c07fe           mov word ptr [edi + eax - 2], cx
// 00511c4b  d96c240c             fldcw word ptr [esp + 0xc]
// 00511c4f  7c8f                 jl 0x511be0
// 00511c51  83c301               add ebx, 1
// 00511c54  ddd8                 fstp st(0)
// 00511c56  3b5c2418             cmp ebx, dword ptr [esp + 0x18]
// 00511c5a  0f8c4cffffff         jl 0x511bac
// 00511c60  5f                   pop edi
// 00511c61  5e                   pop esi
// 00511c62  5b                   pop ebx
// 00511c63  8be5                 mov esp, ebp
// 00511c65  5d                   pop ebp
// 00511c66  c3                   ret 
// library libpng-1.2.7/pngrtran.c (function _png_build_gamma_table)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c
