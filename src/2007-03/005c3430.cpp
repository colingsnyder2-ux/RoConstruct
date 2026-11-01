// from server: 100% by auto
// roc 2007-03 005c3430  unit: seg_005c0000  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c3430
//
// 005c3430  68c0000000           push 0xc0
// 005c3435  6a00                 push 0
// 005c3437  6a00                 push 0
// 005c3439  57                   push edi
// 005c343a  e8619f0300           call 0x5fd3a0
// 005c343f  68d0020000           push 0x2d0
// 005c3444  6a00                 push 0
// 005c3446  894628               mov dword ptr [esi + 0x28], eax
// 005c3449  894614               mov dword ptr [esi + 0x14], eax
// 005c344c  05a8000000           add eax, 0xa8
// 005c3451  6a00                 push 0
// 005c3453  57                   push edi
// 005c3454  c7463008000000       mov dword ptr [esi + 0x30], 8
// 005c345b  894624               mov dword ptr [esi + 0x24], eax
// 005c345e  e83d9f0300           call 0x5fd3a0
// 005c3463  8b5614               mov edx, dword ptr [esi + 0x14]
// 005c3466  894608               mov dword ptr [esi + 8], eax
// 005c3469  894620               mov dword ptr [esi + 0x20], eax
// 005c346c  8d8870020000         lea ecx, [eax + 0x270]
// 005c3472  894e1c               mov dword ptr [esi + 0x1c], ecx
// 005c3475  c7462c2d000000       mov dword ptr [esi + 0x2c], 0x2d
// 005c347c  894204               mov dword ptr [edx + 4], eax
// 005c347f  8b4608               mov eax, dword ptr [esi + 8]
// 005c3482  c7400800000000       mov dword ptr [eax + 8], 0
// 005c3489  83460810             add dword ptr [esi + 8], 0x10
// 005c348d  8b4608               mov eax, dword ptr [esi + 8]
// 005c3490  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005c3493  8901                 mov dword ptr [ecx], eax
// 005c3495  8b4614               mov eax, dword ptr [esi + 0x14]
// 005c3498  8b4e08               mov ecx, dword ptr [esi + 8]
// 005c349b  8b10                 mov edx, dword ptr [eax]
// 005c349d  81c140010000         add ecx, 0x140
// 005c34a3  89560c               mov dword ptr [esi + 0xc], edx
// 005c34a6  83c420               add esp, 0x20
// 005c34a9  894808               mov dword ptr [eax + 8], ecx
// 005c34ac  c3                   ret 
// library lua-5.1.1/lstate.c (function _stack_init)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstate.c
