// from server: 100% by auto
// roc 2009-12 007d6730  unit: seg_007d0000  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d6730
//
// 007d6730  56                   push esi
// 007d6731  8b742408             mov esi, dword ptr [esp + 8]
// 007d6735  8b4604               mov eax, dword ptr [esi + 4]
// 007d6738  894608               mov dword ptr [esi + 8], eax
// 007d673b  b81f010000           mov eax, 0x11f
// 007d6740  394620               cmp dword ptr [esi + 0x20], eax
// 007d6743  741d                 je 0x7d6762
// 007d6745  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 007d6748  8b5624               mov edx, dword ptr [esi + 0x24]
// 007d674b  894e10               mov dword ptr [esi + 0x10], ecx
// 007d674e  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 007d6751  895614               mov dword ptr [esi + 0x14], edx
// 007d6754  8b562c               mov edx, dword ptr [esi + 0x2c]
// 007d6757  894e18               mov dword ptr [esi + 0x18], ecx
// 007d675a  89561c               mov dword ptr [esi + 0x1c], edx
// 007d675d  894620               mov dword ptr [esi + 0x20], eax
// 007d6760  5e                   pop esi
// 007d6761  c3                   ret 
// 007d6762  8d4618               lea eax, [esi + 0x18]
// 007d6765  50                   push eax
// 007d6766  8bc6                 mov eax, esi
// 007d6768  e813f9ffff           call 0x7d6080
// 007d676d  83c404               add esp, 4
// 007d6770  894610               mov dword ptr [esi + 0x10], eax
// 007d6773  5e                   pop esi
// 007d6774  c3                   ret 
// library lua-5.1/llex.c (function _luaX_next)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 llex.c
