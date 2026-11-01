// from server: 100% by auto
// roc 2007-03 005f9480  unit: seg_005f0000  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9480
//
// 005f9480  33c0                 xor eax, eax
// 005f9482  56                   push esi
// 005f9483  8b7710               mov esi, dword ptr [edi + 0x10]
// 005f9486  894624               mov dword ptr [esi + 0x24], eax
// 005f9489  894628               mov dword ptr [esi + 0x28], eax
// 005f948c  89462c               mov dword ptr [esi + 0x2c], eax
// 005f948f  8b4670               mov eax, dword ptr [esi + 0x70]
// 005f9492  f6400503             test byte ptr [eax + 5], 3
// 005f9496  740a                 je 0x5f94a2
// 005f9498  50                   push eax
// 005f9499  56                   push esi
// 005f949a  e821f5ffff           call 0x5f89c0
// 005f949f  83c408               add esp, 8
// 005f94a2  8b4670               mov eax, dword ptr [esi + 0x70]
// 005f94a5  83785004             cmp dword ptr [eax + 0x50], 4
// 005f94a9  7c13                 jl 0x5f94be
// 005f94ab  8b4048               mov eax, dword ptr [eax + 0x48]
// 005f94ae  f6400503             test byte ptr [eax + 5], 3
// 005f94b2  740a                 je 0x5f94be
// 005f94b4  50                   push eax
// 005f94b5  56                   push esi
// 005f94b6  e805f5ffff           call 0x5f89c0
// 005f94bb  83c408               add esp, 8
// 005f94be  8b4710               mov eax, dword ptr [edi + 0x10]
// 005f94c1  83786804             cmp dword ptr [eax + 0x68], 4
// 005f94c5  7c13                 jl 0x5f94da
// 005f94c7  8b4060               mov eax, dword ptr [eax + 0x60]
// 005f94ca  f6400503             test byte ptr [eax + 5], 3
// 005f94ce  740a                 je 0x5f94da
// 005f94d0  50                   push eax
// 005f94d1  56                   push esi
// 005f94d2  e8e9f4ffff           call 0x5f89c0
// 005f94d7  83c408               add esp, 8
// 005f94da  56                   push esi
// 005f94db  e860ffffff           call 0x5f9440
// 005f94e0  83c404               add esp, 4
// 005f94e3  c6461501             mov byte ptr [esi + 0x15], 1
// 005f94e7  5e                   pop esi
// 005f94e8  c3                   ret 
// library lua-5.1.1/lgc.c (function _markroot)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
