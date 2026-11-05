// from server: 100% by auto
// roc 2009-12 00603240  unit: seg_00600000  size: 336 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00603240
//
// 00603240  51                   push ecx
// 00603241  53                   push ebx
// 00603242  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00603246  85db                 test ebx, ebx
// 00603248  0f843f010000         je 0x60338d
// 0060324e  55                   push ebp
// 0060324f  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00603253  85ed                 test ebp, ebp
// 00603255  0f8431010000         je 0x60338c
// 0060325b  57                   push edi
// 0060325c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00603260  85ff                 test edi, edi
// 00603262  0f8423010000         je 0x60338b
// 00603268  8b85c0000000         mov eax, dword ptr [ebp + 0xc0]
// 0060326e  03c7                 add eax, edi
// 00603270  8d0480               lea eax, [eax + eax*4]
// 00603273  03c0                 add eax, eax
// 00603275  56                   push esi
// 00603276  03c0                 add eax, eax
// 00603278  50                   push eax
// 00603279  53                   push ebx
// 0060327a  e891da0000           call 0x610d10
// 0060327f  8bf0                 mov esi, eax
// 00603281  83c408               add esp, 8
// 00603284  89742410             mov dword ptr [esp + 0x10], esi
// 00603288  85f6                 test esi, esi
// 0060328a  7514                 jne 0x6032a0
// 0060328c  6888379c00           push 0x9c3788
// 00603291  53                   push ebx
// 00603292  e8a9cf0000           call 0x610240
// 00603297  83c408               add esp, 8
// 0060329a  5e                   pop esi
// 0060329b  5f                   pop edi
// 0060329c  5d                   pop ebp
// 0060329d  5b                   pop ebx
// 0060329e  59                   pop ecx
// 0060329f  c3                   ret 
// 006032a0  8b85c0000000         mov eax, dword ptr [ebp + 0xc0]
// 006032a6  8b95bc000000         mov edx, dword ptr [ebp + 0xbc]
// 006032ac  8d0c80               lea ecx, [eax + eax*4]
// 006032af  03c9                 add ecx, ecx
// 006032b1  03c9                 add ecx, ecx
// 006032b3  51                   push ecx
// 006032b4  52                   push edx
// 006032b5  56                   push esi
// 006032b6  e82b1a1f00           call 0x7f4ce6
// 006032bb  8b85bc000000         mov eax, dword ptr [ebp + 0xbc]
// 006032c1  50                   push eax
// 006032c2  53                   push ebx
// 006032c3  e818da0000           call 0x610ce0
// 006032c8  33c9                 xor ecx, ecx
// 006032ca  83c414               add esp, 0x14
// 006032cd  3bf9                 cmp edi, ecx
// 006032cf  898dbc000000         mov dword ptr [ebp + 0xbc], ecx
// 006032d5  894c2418             mov dword ptr [esp + 0x18], ecx
// 006032d9  0f8e95000000         jle 0x603374
// 006032df  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006032e3  83c70c               add edi, 0xc
// 006032e6  eb08                 jmp 0x6032f0
// 006032e8  8da42400000000       lea esp, [esp]
// 006032ef  90                   nop 
// 006032f0  8b85c0000000         mov eax, dword ptr [ebp + 0xc0]
// 006032f6  8b57f4               mov edx, dword ptr [edi - 0xc]
// 006032f9  03c1                 add eax, ecx
// 006032fb  8d0c80               lea ecx, [eax + eax*4]
// 006032fe  8d348e               lea esi, [esi + ecx*4]
// 00603301  8916                 mov dword ptr [esi], edx
// 00603303  c6460400             mov byte ptr [esi + 4], 0
// 00603307  8b0f                 mov ecx, dword ptr [edi]
// 00603309  894e0c               mov dword ptr [esi + 0xc], ecx
// 0060330c  8a5368               mov dl, byte ptr [ebx + 0x68]
// 0060330f  885610               mov byte ptr [esi + 0x10], dl
// 00603312  833f00               cmp dword ptr [edi], 0
// 00603315  7509                 jne 0x603320
// 00603317  c7460800000000       mov dword ptr [esi + 8], 0
// 0060331e  eb3a                 jmp 0x60335a
// 00603320  8b07                 mov eax, dword ptr [edi]
// 00603322  50                   push eax
// 00603323  53                   push ebx
// 00603324  e8e7d90000           call 0x610d10
// 00603329  83c408               add esp, 8
// 0060332c  894608               mov dword ptr [esi + 8], eax
// 0060332f  85c0                 test eax, eax
// 00603331  7517                 jne 0x60334a
// 00603333  6888379c00           push 0x9c3788
// 00603338  53                   push ebx
// 00603339  e802cf0000           call 0x610240
// 0060333e  83c408               add esp, 8
// 00603341  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00603348  eb10                 jmp 0x60335a
// 0060334a  8b0f                 mov ecx, dword ptr [edi]
// 0060334c  8b57fc               mov edx, dword ptr [edi - 4]
// 0060334f  51                   push ecx
// 00603350  52                   push edx
// 00603351  50                   push eax
// 00603352  e88f191f00           call 0x7f4ce6
// 00603357  83c40c               add esp, 0xc
// 0060335a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0060335e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00603362  41                   inc ecx
// 00603363  83c714               add edi, 0x14
// 00603366  3b4c2424             cmp ecx, dword ptr [esp + 0x24]
// 0060336a  894c2418             mov dword ptr [esp + 0x18], ecx
// 0060336e  7c80                 jl 0x6032f0
// 00603370  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00603374  01bdc0000000         add dword ptr [ebp + 0xc0], edi
// 0060337a  818db800000000020000 or dword ptr [ebp + 0xb8], 0x200
// 00603384  89b5bc000000         mov dword ptr [ebp + 0xbc], esi
// 0060338a  5e                   pop esi
// 0060338b  5f                   pop edi
// 0060338c  5d                   pop ebp
// 0060338d  5b                   pop ebx
// 0060338e  59                   pop ecx
// 0060338f  c3                   ret 
// library libpng-1.2.29/pngset.c (function _png_set_unknown_chunks)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngset.c
