// from server: 100% by auto
// roc 2011-06 00559620  unit: seg_00550000  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00559620
//
// 00559620  8b442404             mov eax, dword ptr [esp + 4]
// 00559624  53                   push ebx
// 00559625  55                   push ebp
// 00559626  56                   push esi
// 00559627  33f6                 xor esi, esi
// 00559629  33db                 xor ebx, ebx
// 0055962b  33ed                 xor ebp, ebp
// 0055962d  85c0                 test eax, eax
// 0055962f  740e                 je 0x55963f
// 00559631  8b30                 mov esi, dword ptr [eax]
// 00559633  8b9e4c020000         mov ebx, dword ptr [esi + 0x24c]
// 00559639  8bae44020000         mov ebp, dword ptr [esi + 0x244]
// 0055963f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00559643  85c0                 test eax, eax
// 00559645  7459                 je 0x5596a0
// 00559647  57                   push edi
// 00559648  8b38                 mov edi, dword ptr [eax]
// 0055964a  85ff                 test edi, edi
// 0055964c  7451                 je 0x55969f
// 0055964e  85f6                 test esi, esi
// 00559650  7438                 je 0x55968a
// 00559652  6aff                 push -1
// 00559654  68ff7f0000           push 0x7fff
// 00559659  57                   push edi
// 0055965a  56                   push esi
// 0055965b  e84072ffff           call 0x5508a0
// 00559660  83c410               add esp, 0x10
// 00559663  83be2002000000       cmp dword ptr [esi + 0x220], 0
// 0055966a  741e                 je 0x55968a
// 0055966c  8b8624020000         mov eax, dword ptr [esi + 0x224]
// 00559672  50                   push eax
// 00559673  56                   push esi
// 00559674  e827800000           call 0x5616a0
// 00559679  83c408               add esp, 8
// 0055967c  33c0                 xor eax, eax
// 0055967e  898624020000         mov dword ptr [esi + 0x224], eax
// 00559684  898620020000         mov dword ptr [esi + 0x220], eax
// 0055968a  55                   push ebp
// 0055968b  53                   push ebx
// 0055968c  57                   push edi
// 0055968d  e8ce7e0000           call 0x561560
// 00559692  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00559696  83c40c               add esp, 0xc
// 00559699  c70100000000         mov dword ptr [ecx], 0
// 0055969f  5f                   pop edi
// 005596a0  85f6                 test esi, esi
// 005596a2  741b                 je 0x5596bf
// 005596a4  56                   push esi
// 005596a5  e8c6f8ffff           call 0x558f70
// 005596aa  55                   push ebp
// 005596ab  53                   push ebx
// 005596ac  56                   push esi
// 005596ad  e8ae7e0000           call 0x561560
// 005596b2  8b542420             mov edx, dword ptr [esp + 0x20]
// 005596b6  83c410               add esp, 0x10
// 005596b9  c70200000000         mov dword ptr [edx], 0
// 005596bf  5e                   pop esi
// 005596c0  5d                   pop ebp
// 005596c1  5b                   pop ebx
// 005596c2  c3                   ret 
// library libpng-1.2.29/pngwrite.c (function _png_destroy_write_struct)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngwrite.c
