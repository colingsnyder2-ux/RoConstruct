// from server: 100% by auto
// roc 2009-12 0079b6d0  unit: seg_00790000  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079b6d0
//
// 0079b6d0  68c0000000           push 0xc0
// 0079b6d5  6a00                 push 0
// 0079b6d7  6a00                 push 0
// 0079b6d9  57                   push edi
// 0079b6da  e8d1600300           call 0x7d17b0
// 0079b6df  68d0020000           push 0x2d0
// 0079b6e4  6a00                 push 0
// 0079b6e6  894628               mov dword ptr [esi + 0x28], eax
// 0079b6e9  894614               mov dword ptr [esi + 0x14], eax
// 0079b6ec  05a8000000           add eax, 0xa8
// 0079b6f1  6a00                 push 0
// 0079b6f3  57                   push edi
// 0079b6f4  c7463008000000       mov dword ptr [esi + 0x30], 8
// 0079b6fb  894624               mov dword ptr [esi + 0x24], eax
// 0079b6fe  e8ad600300           call 0x7d17b0
// 0079b703  8b5614               mov edx, dword ptr [esi + 0x14]
// 0079b706  894608               mov dword ptr [esi + 8], eax
// 0079b709  894620               mov dword ptr [esi + 0x20], eax
// 0079b70c  8d8870020000         lea ecx, [eax + 0x270]
// 0079b712  894e1c               mov dword ptr [esi + 0x1c], ecx
// 0079b715  c7462c2d000000       mov dword ptr [esi + 0x2c], 0x2d
// 0079b71c  894204               mov dword ptr [edx + 4], eax
// 0079b71f  8b4608               mov eax, dword ptr [esi + 8]
// 0079b722  c7400800000000       mov dword ptr [eax + 8], 0
// 0079b729  83460810             add dword ptr [esi + 8], 0x10
// 0079b72d  8b4608               mov eax, dword ptr [esi + 8]
// 0079b730  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0079b733  8901                 mov dword ptr [ecx], eax
// 0079b735  8b4614               mov eax, dword ptr [esi + 0x14]
// 0079b738  8b4e08               mov ecx, dword ptr [esi + 8]
// 0079b73b  8b10                 mov edx, dword ptr [eax]
// 0079b73d  81c140010000         add ecx, 0x140
// 0079b743  89560c               mov dword ptr [esi + 0xc], edx
// 0079b746  83c420               add esp, 0x20
// 0079b749  894808               mov dword ptr [eax + 8], ecx
// 0079b74c  c3                   ret 
// library lua-5.1/lstate.c (function _stack_init)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstate.c
