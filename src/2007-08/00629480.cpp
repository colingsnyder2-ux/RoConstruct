// from server: 100% by auto
// roc 2007-08 00629480  unit: RBX::AssemblyStage  size: 248 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00629480
//
// 00629480  83ec10               sub esp, 0x10
// 00629483  53                   push ebx
// 00629484  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00629488  56                   push esi
// 00629489  8b742420             mov esi, dword ptr [esp + 0x20]
// 0062948d  8b4610               mov eax, dword ptr [esi + 0x10]
// 00629490  3b4614               cmp eax, dword ptr [esi + 0x14]
// 00629493  56                   push esi
// 00629494  53                   push ebx
// 00629495  7407                 je 0x62949e
// 00629497  e874ffffff           call 0x629410
// 0062949c  eb05                 jmp 0x6294a3
// 0062949e  e85dfbffff           call 0x629000
// 006294a3  8b06                 mov eax, dword ptr [esi]
// 006294a5  8d48ff               lea ecx, [eax - 1]
// 006294a8  83c408               add esp, 8
// 006294ab  83f904               cmp ecx, 4
// 006294ae  0f87a0000000         ja 0x629554
// 006294b4  ff248d64956200       jmp dword ptr [ecx*4 + 0x629564]
// 006294bb  817b28ff000000       cmp dword ptr [ebx + 0x28], 0xff
// 006294c2  0f8f8c000000         jg 0x629554
// 006294c8  83f801               cmp eax, 1
// 006294cb  751b                 jne 0x6294e8
// 006294cd  8bc3                 mov eax, ebx
// 006294cf  e87cf5ffff           call 0x628a50
// 006294d4  894608               mov dword ptr [esi + 8], eax
// 006294d7  c70604000000         mov dword ptr [esi], 4
// 006294dd  5e                   pop esi
// 006294de  0d00010000           or eax, 0x100
// 006294e3  5b                   pop ebx
// 006294e4  83c410               add esp, 0x10
// 006294e7  c3                   ret 
// 006294e8  83f805               cmp eax, 5
// 006294eb  7526                 jne 0x629513
// 006294ed  dd4608               fld qword ptr [esi + 8]
// 006294f0  83ec08               sub esp, 8
// 006294f3  dd1c24               fstp qword ptr [esp]
// 006294f6  53                   push ebx
// 006294f7  e824f5ffff           call 0x628a20
// 006294fc  83c40c               add esp, 0xc
// 006294ff  894608               mov dword ptr [esi + 8], eax
// 00629502  c70604000000         mov dword ptr [esi], 4
// 00629508  5e                   pop esi
// 00629509  0d00010000           or eax, 0x100
// 0062950e  5b                   pop ebx
// 0062950f  83c410               add esp, 0x10
// 00629512  c3                   ret 
// 00629513  33c9                 xor ecx, ecx
// 00629515  83f802               cmp eax, 2
// 00629518  0f94c1               sete cl
// 0062951b  8d542408             lea edx, [esp + 8]
// 0062951f  52                   push edx
// 00629520  c744241401000000     mov dword ptr [esp + 0x14], 1
// 00629528  894c240c             mov dword ptr [esp + 0xc], ecx
// 0062952c  8bca                 mov ecx, edx
// 0062952e  e8ddf3ffff           call 0x628910
// 00629533  83c404               add esp, 4
// 00629536  894608               mov dword ptr [esi + 8], eax
// 00629539  c70604000000         mov dword ptr [esi], 4
// 0062953f  5e                   pop esi
// 00629540  0d00010000           or eax, 0x100
// 00629545  5b                   pop ebx
// 00629546  83c410               add esp, 0x10
// 00629549  c3                   ret 
// 0062954a  8b4608               mov eax, dword ptr [esi + 8]
// 0062954d  3dff000000           cmp eax, 0xff
// 00629552  7eeb                 jle 0x62953f
// 00629554  56                   push esi
// 00629555  53                   push ebx
// 00629556  e8b5feffff           call 0x629410
// 0062955b  83c408               add esp, 8
// 0062955e  5e                   pop esi
// 0062955f  5b                   pop ebx
// 00629560  83c410               add esp, 0x10
// 00629563  c3                   ret 
// 00629564  bb946200bb           mov ebx, 0xbb006294
// 00629569  94                   xchg esp, eax
// 0062956a  6200                 bound eax, qword ptr [eax]
// 0062956c  bb9462004a           mov ebx, 0x4a006294
// 00629571  95                   xchg ebp, eax
// 00629572  6200                 bound eax, qword ptr [eax]
// library lua-5.1/lcode.c (function _luaK_exp2RK)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
