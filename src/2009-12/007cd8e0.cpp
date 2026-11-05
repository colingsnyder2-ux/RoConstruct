// from server: 100% by auto
// roc 2009-12 007cd8e0  unit: RBX::PartDropTool  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cd8e0
//
// 007cd8e0  33c0                 xor eax, eax
// 007cd8e2  56                   push esi
// 007cd8e3  8b7710               mov esi, dword ptr [edi + 0x10]
// 007cd8e6  894624               mov dword ptr [esi + 0x24], eax
// 007cd8e9  894628               mov dword ptr [esi + 0x28], eax
// 007cd8ec  89462c               mov dword ptr [esi + 0x2c], eax
// 007cd8ef  8b4670               mov eax, dword ptr [esi + 0x70]
// 007cd8f2  f6400503             test byte ptr [eax + 5], 3
// 007cd8f6  740a                 je 0x7cd902
// 007cd8f8  50                   push eax
// 007cd8f9  56                   push esi
// 007cd8fa  e851f5ffff           call 0x7cce50
// 007cd8ff  83c408               add esp, 8
// 007cd902  8b4670               mov eax, dword ptr [esi + 0x70]
// 007cd905  83785004             cmp dword ptr [eax + 0x50], 4
// 007cd909  7c13                 jl 0x7cd91e
// 007cd90b  8b4048               mov eax, dword ptr [eax + 0x48]
// 007cd90e  f6400503             test byte ptr [eax + 5], 3
// 007cd912  740a                 je 0x7cd91e
// 007cd914  50                   push eax
// 007cd915  56                   push esi
// 007cd916  e835f5ffff           call 0x7cce50
// 007cd91b  83c408               add esp, 8
// 007cd91e  8b4710               mov eax, dword ptr [edi + 0x10]
// 007cd921  83786804             cmp dword ptr [eax + 0x68], 4
// 007cd925  7c13                 jl 0x7cd93a
// 007cd927  8b4060               mov eax, dword ptr [eax + 0x60]
// 007cd92a  f6400503             test byte ptr [eax + 5], 3
// 007cd92e  740a                 je 0x7cd93a
// 007cd930  50                   push eax
// 007cd931  56                   push esi
// 007cd932  e819f5ffff           call 0x7cce50
// 007cd937  83c408               add esp, 8
// 007cd93a  56                   push esi
// 007cd93b  e860ffffff           call 0x7cd8a0
// 007cd940  83c404               add esp, 4
// 007cd943  c6461501             mov byte ptr [esi + 0x15], 1
// 007cd947  5e                   pop esi
// 007cd948  c3                   ret 
// library lua-5.1/lgc.c (function _markroot)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
