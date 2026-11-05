// from server: 100% by auto
// roc 2009-12 007cdc90  unit: RBX::PartDropTool  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cdc90
//
// 007cdc90  56                   push esi
// 007cdc91  57                   push edi
// 007cdc92  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007cdc96  8b7710               mov esi, dword ptr [edi + 0x10]
// 007cdc99  807e1501             cmp byte ptr [esi + 0x15], 1
// 007cdc9d  7718                 ja 0x7cdcb7
// 007cdc9f  33c0                 xor eax, eax
// 007cdca1  8d4e1c               lea ecx, [esi + 0x1c]
// 007cdca4  894618               mov dword ptr [esi + 0x18], eax
// 007cdca7  894e20               mov dword ptr [esi + 0x20], ecx
// 007cdcaa  894624               mov dword ptr [esi + 0x24], eax
// 007cdcad  894628               mov dword ptr [esi + 0x28], eax
// 007cdcb0  89462c               mov dword ptr [esi + 0x2c], eax
// 007cdcb3  c6461502             mov byte ptr [esi + 0x15], 2
// 007cdcb7  807e1504             cmp byte ptr [esi + 0x15], 4
// 007cdcbb  7410                 je 0x7cdccd
// 007cdcbd  8d4900               lea ecx, [ecx]
// 007cdcc0  8bc7                 mov eax, edi
// 007cdcc2  e849feffff           call 0x7cdb10
// 007cdcc7  807e1504             cmp byte ptr [esi + 0x15], 4
// 007cdccb  75f3                 jne 0x7cdcc0
// 007cdccd  e80efcffff           call 0x7cd8e0
// 007cdcd2  807e1500             cmp byte ptr [esi + 0x15], 0
// 007cdcd6  740d                 je 0x7cdce5
// 007cdcd8  8bc7                 mov eax, edi
// 007cdcda  e831feffff           call 0x7cdb10
// 007cdcdf  807e1500             cmp byte ptr [esi + 0x15], 0
// 007cdce3  75f3                 jne 0x7cdcd8
// 007cdce5  b81f85eb51           mov eax, 0x51eb851f
// 007cdcea  f76648               mul dword ptr [esi + 0x48]
// 007cdced  c1ea05               shr edx, 5
// 007cdcf0  0faf5650             imul edx, dword ptr [esi + 0x50]
// 007cdcf4  5f                   pop edi
// 007cdcf5  895640               mov dword ptr [esi + 0x40], edx
// 007cdcf8  5e                   pop esi
// 007cdcf9  c3                   ret 
// library lua-5.1/lgc.c (function _luaC_fullgc)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
