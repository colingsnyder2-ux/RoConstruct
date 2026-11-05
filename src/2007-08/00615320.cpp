// from server: 100% by auto
// roc 2007-08 00615320  unit: seg_00610000  size: 257 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00615320
//
// 00615320  83ec18               sub esp, 0x18
// 00615323  53                   push ebx
// 00615324  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00615328  8b4334               mov eax, dword ptr [ebx + 0x34]
// 0061532b  55                   push ebp
// 0061532c  56                   push esi
// 0061532d  be01000000           mov esi, 1
// 00615332  66017034             add word ptr [eax + 0x34], si
// 00615336  8b4334               mov eax, dword ptr [ebx + 0x34]
// 00615339  66817834c800         cmp word ptr [eax + 0x34], 0xc8
// 0061533f  7610                 jbe 0x615351
// 00615341  6a00                 push 0
// 00615343  6830347c00           push 0x7c3430
// 00615348  53                   push ebx
// 00615349  e8d2210000           call 0x617520
// 0061534e  83c40c               add esp, 0xc
// 00615351  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00615354  83f823               cmp eax, 0x23
// 00615357  0f8499000000         je 0x6153f6
// 0061535d  83f82d               cmp eax, 0x2d
// 00615360  0f848c000000         je 0x6153f2
// 00615366  3d0e010000           cmp eax, 0x10e
// 0061536b  0f848a000000         je 0x6153fb
// 00615371  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 00615375  8bc5                 mov eax, ebp
// 00615377  e814fcffff           call 0x614f90
// 0061537c  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0061537f  e8ecfdffff           call 0x615170
// 00615384  8bf0                 mov esi, eax
// 00615386  83fe0f               cmp esi, 0xf
// 00615389  7455                 je 0x6153e0
// 0061538b  57                   push edi
// 0061538c  8d642400             lea esp, [esp]
// 00615390  0fb6147550337c00     movzx edx, byte ptr [esi*2 + 0x7c3350]
// 00615398  3b542434             cmp edx, dword ptr [esp + 0x34]
// 0061539c  7641                 jbe 0x6153df
// 0061539e  53                   push ebx
// 0061539f  e84c360000           call 0x6189f0
// 006153a4  8b4330               mov eax, dword ptr [ebx + 0x30]
// 006153a7  55                   push ebp
// 006153a8  56                   push esi
// 006153a9  50                   push eax
// 006153aa  e801480100           call 0x629bb0
// 006153af  0fb60c7551337c00     movzx ecx, byte ptr [esi*2 + 0x7c3351]
// 006153b7  51                   push ecx
// 006153b8  8d542424             lea edx, [esp + 0x24]
// 006153bc  52                   push edx
// 006153bd  53                   push ebx
// 006153be  e85dffffff           call 0x615320
// 006153c3  8b4b30               mov ecx, dword ptr [ebx + 0x30]
// 006153c6  8bf8                 mov edi, eax
// 006153c8  8d44242c             lea eax, [esp + 0x2c]
// 006153cc  50                   push eax
// 006153cd  55                   push ebp
// 006153ce  56                   push esi
// 006153cf  51                   push ecx
// 006153d0  e84b480100           call 0x629c20
// 006153d5  83c42c               add esp, 0x2c
// 006153d8  83ff0f               cmp edi, 0xf
// 006153db  8bf7                 mov esi, edi
// 006153dd  75b1                 jne 0x615390
// 006153df  5f                   pop edi
// 006153e0  8b5b34               mov ebx, dword ptr [ebx + 0x34]
// 006153e3  66814334ffff         add word ptr [ebx + 0x34], 0xffff
// 006153e9  8bc6                 mov eax, esi
// 006153eb  5e                   pop esi
// 006153ec  5d                   pop ebp
// 006153ed  5b                   pop ebx
// 006153ee  83c418               add esp, 0x18
// 006153f1  c3                   ret 
// 006153f2  33f6                 xor esi, esi
// 006153f4  eb05                 jmp 0x6153fb
// 006153f6  be02000000           mov esi, 2
// 006153fb  53                   push ebx
// 006153fc  e8ef350000           call 0x6189f0
// 00615401  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 00615405  6a08                 push 8
// 00615407  55                   push ebp
// 00615408  53                   push ebx
// 00615409  e812ffffff           call 0x615320
// 0061540e  8b4b30               mov ecx, dword ptr [ebx + 0x30]
// 00615411  55                   push ebp
// 00615412  56                   push esi
// 00615413  51                   push ecx
// 00615414  e8f7460100           call 0x629b10
// 00615419  83c41c               add esp, 0x1c
// 0061541c  e95bffffff           jmp 0x61537c
// library lua-5.1/lparser.c (function _subexpr)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
