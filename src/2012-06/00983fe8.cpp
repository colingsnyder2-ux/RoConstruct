// roc 2012-06 00983fe8  unit: boost::exception  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00983fe8
//
// 00983fe8  8bff                 mov edi, edi
// 00983fea  55                   push ebp
// 00983feb  8bec                 mov ebp, esp
// 00983fed  83ec10               sub esp, 0x10
// 00983ff0  a1d027e000           mov eax, dword ptr [0xe027d0]
// 00983ff5  8365f800             and dword ptr [ebp - 8], 0
// 00983ff9  8365fc00             and dword ptr [ebp - 4], 0
// 00983ffd  53                   push ebx
// 00983ffe  57                   push edi
// 00983fff  bf4ee640bb           mov edi, 0xbb40e64e
// 00984004  bb0000ffff           mov ebx, 0xffff0000
// 00984009  3bc7                 cmp eax, edi
// 0098400b  740d                 je 0x98401a
// 0098400d  85c3                 test ebx, eax
// 0098400f  7409                 je 0x98401a
// 00984011  f7d0                 not eax
// 00984013  a3d427e000           mov dword ptr [0xe027d4], eax
// 00984018  eb60                 jmp 0x98407a
// 0098401a  56                   push esi
// 0098401b  8d45f8               lea eax, [ebp - 8]
// 0098401e  50                   push eax
// 0098401f  ff153822b200         call dword ptr [0xb22238]
// 00984025  8b75fc               mov esi, dword ptr [ebp - 4]
// 00984028  3375f8               xor esi, dword ptr [ebp - 8]
// 0098402b  ff15d021b200         call dword ptr [0xb221d0]
// 00984031  33f0                 xor esi, eax
// 00984033  ff15a021b200         call dword ptr [0xb221a0]
// 00984039  33f0                 xor esi, eax
// 0098403b  ff157422b200         call dword ptr [0xb22274]
// 00984041  33f0                 xor esi, eax
// 00984043  8d45f0               lea eax, [ebp - 0x10]
// 00984046  50                   push eax
// 00984047  ff154423b200         call dword ptr [0xb22344]
// 0098404d  8b45f4               mov eax, dword ptr [ebp - 0xc]
// 00984050  3345f0               xor eax, dword ptr [ebp - 0x10]
// 00984053  33f0                 xor esi, eax
// 00984055  3bf7                 cmp esi, edi
// 00984057  7507                 jne 0x984060
// 00984059  be4fe640bb           mov esi, 0xbb40e64f
// 0098405e  eb0b                 jmp 0x98406b
// 00984060  85f3                 test ebx, esi
// 00984062  7507                 jne 0x98406b
// 00984064  8bc6                 mov eax, esi
// 00984066  c1e010               shl eax, 0x10
// 00984069  0bf0                 or esi, eax
// 0098406b  8935d027e000         mov dword ptr [0xe027d0], esi
// 00984071  f7d6                 not esi
// 00984073  8935d427e000         mov dword ptr [0xe027d4], esi
// 00984079  5e                   pop esi
// 0098407a  5f                   pop edi
// 0098407b  5b                   pop ebx
// 0098407c  c9                   leave 
// 0098407d  c3                   ret 
// copied from an identical function in another client (function ___security_init_cookie)

// roc-flags: /O2 /GS- /EHsc /MD
// roc-lang: cpp
// roc-cl: 21022
// roc-archive: msvc-crt libcmt.lib/f:/dd/vctools/crt_bld/SELF_X86/crt/src/build/INTEL/mt_obj/gs_support.obj