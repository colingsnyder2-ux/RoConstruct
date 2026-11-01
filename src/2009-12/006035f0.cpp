// from server: 100% by auto
// roc 2009-12 006035f0  unit: seg_00600000  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006035f0
//
// 006035f0  53                   push ebx
// 006035f1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 006035f5  83c8ff               or eax, 0xffffffff
// 006035f8  33d2                 xor edx, edx
// 006035fa  f7f3                 div ebx
// 006035fc  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00603600  56                   push esi
// 00603601  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00603605  57                   push edi
// 00603606  8b7e6c               mov edi, dword ptr [esi + 0x6c]
// 00603609  3bc8                 cmp ecx, eax
// 0060360b  7614                 jbe 0x603621
// 0060360d  68a4389c00           push 0x9c38a4
// 00603612  56                   push esi
// 00603613  e828cc0000           call 0x610240
// 00603618  83c408               add esp, 8
// 0060361b  5f                   pop edi
// 0060361c  5e                   pop esi
// 0060361d  33c0                 xor eax, eax
// 0060361f  5b                   pop ebx
// 00603620  c3                   ret 
// 00603621  0fafcb               imul ecx, ebx
// 00603624  8bc7                 mov eax, edi
// 00603626  51                   push ecx
// 00603627  0d00001000           or eax, 0x100000
// 0060362c  56                   push esi
// 0060362d  89466c               mov dword ptr [esi + 0x6c], eax
// 00603630  e84bd60000           call 0x610c80
// 00603635  83c408               add esp, 8
// 00603638  897e6c               mov dword ptr [esi + 0x6c], edi
// 0060363b  5f                   pop edi
// 0060363c  5e                   pop esi
// 0060363d  5b                   pop ebx
// 0060363e  c3                   ret 
// library libpng-1.2.6/png.c (function _png_zalloc)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.6 png.c
