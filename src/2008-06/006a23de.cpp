// from server: 100% by colin
// roc 2008-06 006a23de  unit: ActiveDocView  size: 262 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006a23de
//
// 006a23de  8bff                 mov edi, edi
// 006a23e0  55                   push ebp
// 006a23e1  8bec                 mov ebp, esp
// 006a23e3  81ec28030000         sub esp, 0x328
// 006a23e9  a310de9700           mov dword ptr [0x97de10], eax
// 006a23ee  890d0cde9700         mov dword ptr [0x97de0c], ecx
// 006a23f4  891508de9700         mov dword ptr [0x97de08], edx
// 006a23fa  891d04de9700         mov dword ptr [0x97de04], ebx
// 006a2400  893500de9700         mov dword ptr [0x97de00], esi
// 006a2406  893dfcdd9700         mov dword ptr [0x97ddfc], edi
// 006a240c  668c1528de9700       mov word ptr [0x97de28], ss
// 006a2413  668c0d1cde9700       mov word ptr [0x97de1c], cs
// 006a241a  668c1df8dd9700       mov word ptr [0x97ddf8], ds
// 006a2421  668c05f4dd9700       mov word ptr [0x97ddf4], es
// 006a2428  668c25f0dd9700       mov word ptr [0x97ddf0], fs
// 006a242f  668c2decdd9700       mov word ptr [0x97ddec], gs
// 006a2436  9c                   pushfd 
// 006a2437  8f0520de9700         pop dword ptr [0x97de20]
// 006a243d  8b4500               mov eax, dword ptr [ebp]
// 006a2440  a314de9700           mov dword ptr [0x97de14], eax
// 006a2445  8b4504               mov eax, dword ptr [ebp + 4]
// 006a2448  a318de9700           mov dword ptr [0x97de18], eax
// 006a244d  8d4508               lea eax, [ebp + 8]
// 006a2450  a324de9700           mov dword ptr [0x97de24], eax
// 006a2455  8b85e0fcffff         mov eax, dword ptr [ebp - 0x320]
// 006a245b  c70560dd970001000100 mov dword ptr [0x97dd60], 0x10001
// 006a2465  a118de9700           mov eax, dword ptr [0x97de18]
// 006a246a  a314dd9700           mov dword ptr [0x97dd14], eax
// 006a246f  c70508dd9700090400c0 mov dword ptr [0x97dd08], 0xc0000409
// 006a2479  c7050cdd970001000000 mov dword ptr [0x97dd0c], 1
// 006a2483  a1c05c9600           mov eax, dword ptr [0x965cc0]
// 006a2488  8985d8fcffff         mov dword ptr [ebp - 0x328], eax
// 006a248e  a1c45c9600           mov eax, dword ptr [0x965cc4]
// 006a2493  8985dcfcffff         mov dword ptr [ebp - 0x324], eax
// 006a2499  ff15d0228000         call dword ptr [0x8022d0]
// 006a249f  a358dd9700           mov dword ptr [0x97dd58], eax
// 006a24a4  6a01                 push 1
// 006a24a6  e89b000000           call 0x6a2546
// 006a24ab  59                   pop ecx
// 006a24ac  6a00                 push 0
// 006a24ae  ff1544228000         call dword ptr [0x802244]
// 006a24b4  6884018500           push 0x850184
// 006a24b9  ff15cc228000         call dword ptr [0x8022cc]
// 006a24bf  833d58dd970000       cmp dword ptr [0x97dd58], 0
// 006a24c6  7508                 jne 0x6a24d0
// 006a24c8  6a01                 push 1
// 006a24ca  e877000000           call 0x6a2546
// 006a24cf  59                   pop ecx
// 006a24d0  68090400c0           push 0xc0000409
// 006a24d5  ff15e4218000         call dword ptr [0x8021e4]
// 006a24db  50                   push eax
// 006a24dc  ff15c8228000         call dword ptr [0x8022c8]
// 006a24e2  c9                   leave 
// 006a24e3  c3                   ret 
// CRT libcmt.lib/f:\dd\vctools\crt_bld\SELF_X86\crt\src\build\INTEL\mt_obj\gs_report.obj (function ___report_gsfailure)

// roc-lang: cpp
// roc-cl: 21022
// roc-archive: msvc-crt libcmt.lib/f:/dd/vctools/crt_bld/SELF_X86/crt/src/build/INTEL/mt_obj/gs_report.obj
