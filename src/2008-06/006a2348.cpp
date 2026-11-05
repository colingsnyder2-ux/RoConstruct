// from server: 100% by colin
// roc 2008-06 006a2348  unit: ActiveDocView  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006a2348
//
// 006a2348  8bff                 mov edi, edi
// 006a234a  55                   push ebp
// 006a234b  8bec                 mov ebp, esp
// 006a234d  83ec10               sub esp, 0x10
// 006a2350  a1c05c9600           mov eax, dword ptr [0x965cc0]
// 006a2355  8365f800             and dword ptr [ebp - 8], 0
// 006a2359  8365fc00             and dword ptr [ebp - 4], 0
// 006a235d  53                   push ebx
// 006a235e  57                   push edi
// 006a235f  bf4ee640bb           mov edi, 0xbb40e64e
// 006a2364  bb0000ffff           mov ebx, 0xffff0000
// 006a2369  3bc7                 cmp eax, edi
// 006a236b  740d                 je 0x6a237a
// 006a236d  85c3                 test ebx, eax
// 006a236f  7409                 je 0x6a237a
// 006a2371  f7d0                 not eax
// 006a2373  a3c45c9600           mov dword ptr [0x965cc4], eax
// 006a2378  eb60                 jmp 0x6a23da
// 006a237a  56                   push esi
// 006a237b  8d45f8               lea eax, [ebp - 8]
// 006a237e  50                   push eax
// 006a237f  ff159c228000         call dword ptr [0x80229c]
// 006a2385  8b75fc               mov esi, dword ptr [ebp - 4]
// 006a2388  3375f8               xor esi, dword ptr [ebp - 8]
// 006a238b  ff1538228000         call dword ptr [0x802238]
// 006a2391  33f0                 xor esi, eax
// 006a2393  ff1598218000         call dword ptr [0x802198]
// 006a2399  33f0                 xor esi, eax
// 006a239b  ff15e8218000         call dword ptr [0x8021e8]
// 006a23a1  33f0                 xor esi, eax
// 006a23a3  8d45f0               lea eax, [ebp - 0x10]
// 006a23a6  50                   push eax
// 006a23a7  ff1550228000         call dword ptr [0x802250]
// 006a23ad  8b45f4               mov eax, dword ptr [ebp - 0xc]
// 006a23b0  3345f0               xor eax, dword ptr [ebp - 0x10]
// 006a23b3  33f0                 xor esi, eax
// 006a23b5  3bf7                 cmp esi, edi
// 006a23b7  7507                 jne 0x6a23c0
// 006a23b9  be4fe640bb           mov esi, 0xbb40e64f
// 006a23be  eb0b                 jmp 0x6a23cb
// 006a23c0  85f3                 test ebx, esi
// 006a23c2  7507                 jne 0x6a23cb
// 006a23c4  8bc6                 mov eax, esi
// 006a23c6  c1e010               shl eax, 0x10
// 006a23c9  0bf0                 or esi, eax
// 006a23cb  8935c05c9600         mov dword ptr [0x965cc0], esi
// 006a23d1  f7d6                 not esi
// 006a23d3  8935c45c9600         mov dword ptr [0x965cc4], esi
// 006a23d9  5e                   pop esi
// 006a23da  5f                   pop edi
// 006a23db  5b                   pop ebx
// 006a23dc  c9                   leave 
// 006a23dd  c3                   ret 
// CRT libcmt.lib/f:\dd\vctools\crt_bld\SELF_X86\crt\src\build\INTEL\mt_obj\gs_support.obj (function ___security_init_cookie)

// roc-lang: cpp
// roc-cl: 21022
// roc-archive: msvc-crt libcmt.lib/f:/dd/vctools/crt_bld/SELF_X86/crt/src/build/INTEL/mt_obj/gs_support.obj
