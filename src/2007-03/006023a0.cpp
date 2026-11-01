// from server: 100% by auto
// roc 2007-03 006023a0  unit: seg_00600000  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006023a0
//
// 006023a0  56                   push esi
// 006023a1  8b742408             mov esi, dword ptr [esp + 8]
// 006023a5  8b4604               mov eax, dword ptr [esi + 4]
// 006023a8  894608               mov dword ptr [esi + 8], eax
// 006023ab  b81f010000           mov eax, 0x11f
// 006023b0  394620               cmp dword ptr [esi + 0x20], eax
// 006023b3  741d                 je 0x6023d2
// 006023b5  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 006023b8  8b5624               mov edx, dword ptr [esi + 0x24]
// 006023bb  894e10               mov dword ptr [esi + 0x10], ecx
// 006023be  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 006023c1  895614               mov dword ptr [esi + 0x14], edx
// 006023c4  8b562c               mov edx, dword ptr [esi + 0x2c]
// 006023c7  894e18               mov dword ptr [esi + 0x18], ecx
// 006023ca  89561c               mov dword ptr [esi + 0x1c], edx
// 006023cd  894620               mov dword ptr [esi + 0x20], eax
// 006023d0  5e                   pop esi
// 006023d1  c3                   ret 
// 006023d2  8d4618               lea eax, [esi + 0x18]
// 006023d5  50                   push eax
// 006023d6  8bc6                 mov eax, esi
// 006023d8  e803f9ffff           call 0x601ce0
// 006023dd  83c404               add esp, 4
// 006023e0  894610               mov dword ptr [esi + 0x10], eax
// 006023e3  5e                   pop esi
// 006023e4  c3                   ret 
// library lua-5.1.1/llex.c (function _luaX_next)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 llex.c
