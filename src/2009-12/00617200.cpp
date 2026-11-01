// from server: 100% by auto
// roc 2009-12 00617200  unit: seg_00610000  size: 384 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00617200
//
// 00617200  51                   push ecx
// 00617201  53                   push ebx
// 00617202  56                   push esi
// 00617203  8b742410             mov esi, dword ptr [esp + 0x10]
// 00617207  8b4668               mov eax, dword ptr [esi + 0x68]
// 0061720a  33db                 xor ebx, ebx
// 0061720c  885c240b             mov byte ptr [esp + 0xb], bl
// 00617210  885c240a             mov byte ptr [esp + 0xa], bl
// 00617214  885c2409             mov byte ptr [esp + 9], bl
// 00617218  885c2408             mov byte ptr [esp + 8], bl
// 0061721c  a801                 test al, 1
// 0061721e  750d                 jne 0x61722d
// 00617220  684c929c00           push 0x9c924c
// 00617225  56                   push esi
// 00617226  e8658fffff           call 0x610190
// 0061722b  eb30                 jmp 0x61725d
// 0061722d  a804                 test al, 4
// 0061722f  741d                 je 0x61724e
// 00617231  6834929c00           push 0x9c9234
// 00617236  56                   push esi
// 00617237  e80490ffff           call 0x610240
// 0061723c  8b442420             mov eax, dword ptr [esp + 0x20]
// 00617240  50                   push eax
// 00617241  56                   push esi
// 00617242  e8a9f9ffff           call 0x616bf0
// 00617247  83c410               add esp, 0x10
// 0061724a  5e                   pop esi
// 0061724b  5b                   pop ebx
// 0061724c  59                   pop ecx
// 0061724d  c3                   ret 
// 0061724e  a802                 test al, 2
// 00617250  740e                 je 0x617260
// 00617252  681c929c00           push 0x9c921c
// 00617257  56                   push esi
// 00617258  e8e38fffff           call 0x610240
// 0061725d  83c408               add esp, 8
// 00617260  8b442414             mov eax, dword ptr [esp + 0x14]
// 00617264  3bc3                 cmp eax, ebx
// 00617266  7423                 je 0x61728b
// 00617268  f6400802             test byte ptr [eax + 8], 2
// 0061726c  741d                 je 0x61728b
// 0061726e  6804929c00           push 0x9c9204
// 00617273  56                   push esi
// 00617274  e8c78fffff           call 0x610240
// 00617279  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0061727d  51                   push ecx
// 0061727e  56                   push esi
// 0061727f  e86cf9ffff           call 0x616bf0
// 00617284  83c410               add esp, 0x10
// 00617287  5e                   pop esi
// 00617288  5b                   pop ebx
// 00617289  59                   pop ecx
// 0061728a  c3                   ret 
// 0061728b  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 00617292  57                   push edi
// 00617293  bf03000000           mov edi, 3
// 00617298  7407                 je 0x6172a1
// 0061729a  0fb6be2a010000       movzx edi, byte ptr [esi + 0x12a]
// 006172a1  55                   push ebp
// 006172a2  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 006172a6  3bef                 cmp ebp, edi
// 006172a8  0f85b7000000         jne 0x617365
// 006172ae  83fd04               cmp ebp, 4
// 006172b1  0f87ae000000         ja 0x617365
// 006172b7  57                   push edi
// 006172b8  8d542414             lea edx, [esp + 0x14]
// 006172bc  52                   push edx
// 006172bd  56                   push esi
// 006172be  e8cd37ffff           call 0x60aa90
// 006172c3  57                   push edi
// 006172c4  8d442420             lea eax, [esp + 0x20]
// 006172c8  50                   push eax
// 006172c9  56                   push esi
// 006172ca  e8a1c3feff           call 0x603670
// 006172cf  53                   push ebx
// 006172d0  56                   push esi
// 006172d1  e81af9ffff           call 0x616bf0
// 006172d6  83c420               add esp, 0x20
// 006172d9  85c0                 test eax, eax
// 006172db  0f8599000000         jne 0x61737a
// 006172e1  f6862601000002       test byte ptr [esi + 0x126], 2
// 006172e8  8d867c010000         lea eax, [esi + 0x17c]
// 006172ee  743d                 je 0x61732d
// 006172f0  0fb6542411           movzx edx, byte ptr [esp + 0x11]
// 006172f5  0fb64c2410           movzx ecx, byte ptr [esp + 0x10]
// 006172fa  88967d010000         mov byte ptr [esi + 0x17d], dl
// 00617300  0fb6542413           movzx edx, byte ptr [esp + 0x13]
// 00617305  889680010000         mov byte ptr [esi + 0x180], dl
// 0061730b  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0061730f  50                   push eax
// 00617310  8808                 mov byte ptr [eax], cl
// 00617312  0fb64c2416           movzx ecx, byte ptr [esp + 0x16]
// 00617317  52                   push edx
// 00617318  56                   push esi
// 00617319  888e7e010000         mov byte ptr [esi + 0x17e], cl
// 0061731f  e89cb8feff           call 0x602bc0
// 00617324  83c40c               add esp, 0xc
// 00617327  5d                   pop ebp
// 00617328  5f                   pop edi
// 00617329  5e                   pop esi
// 0061732a  5b                   pop ebx
// 0061732b  59                   pop ecx
// 0061732c  c3                   ret 
// 0061732d  8a4c2410             mov cl, byte ptr [esp + 0x10]
// 00617331  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00617335  50                   push eax
// 00617336  888e7f010000         mov byte ptr [esi + 0x17f], cl
// 0061733c  8808                 mov byte ptr [eax], cl
// 0061733e  888e7d010000         mov byte ptr [esi + 0x17d], cl
// 00617344  888e7e010000         mov byte ptr [esi + 0x17e], cl
// 0061734a  0fb64c2415           movzx ecx, byte ptr [esp + 0x15]
// 0061734f  52                   push edx
// 00617350  56                   push esi
// 00617351  888e80010000         mov byte ptr [esi + 0x180], cl
// 00617357  e864b8feff           call 0x602bc0
// 0061735c  83c40c               add esp, 0xc
// 0061735f  5d                   pop ebp
// 00617360  5f                   pop edi
// 00617361  5e                   pop esi
// 00617362  5b                   pop ebx
// 00617363  59                   pop ecx
// 00617364  c3                   ret 
// 00617365  68e8919c00           push 0x9c91e8
// 0061736a  56                   push esi
// 0061736b  e8d08effff           call 0x610240
// 00617370  55                   push ebp
// 00617371  56                   push esi
// 00617372  e879f8ffff           call 0x616bf0
// 00617377  83c410               add esp, 0x10
// 0061737a  5d                   pop ebp
// 0061737b  5f                   pop edi
// 0061737c  5e                   pop esi
// 0061737d  5b                   pop ebx
// 0061737e  59                   pop ecx
// 0061737f  c3                   ret 
// library libpng-1.2.6/pngrutil.c (function _png_handle_sBIT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.6 pngrutil.c
