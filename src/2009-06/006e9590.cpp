// from server: 100% by auto
// roc 2009-06 006e9590  unit: RBX::PartDropTool  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e9590
//
// 006e9590  0fb65004             movzx edx, byte ptr [eax + 4]
// 006e9594  83c2fc               add edx, -4
// 006e9597  83fa06               cmp edx, 6
// 006e959a  776b                 ja 0x6e9607
// 006e959c  ff249508966e00       jmp dword ptr [edx*4 + 0x6e9608]
// 006e95a3  50                   push eax
// 006e95a4  51                   push ecx
// 006e95a5  e8a6390000           call 0x6ecf50
// 006e95aa  83c408               add esp, 8
// 006e95ad  c3                   ret 
// 006e95ae  50                   push eax
// 006e95af  51                   push ecx
// 006e95b0  e83b3a0000           call 0x6ecff0
// 006e95b5  83c408               add esp, 8
// 006e95b8  c3                   ret 
// 006e95b9  50                   push eax
// 006e95ba  51                   push ecx
// 006e95bb  e840380000           call 0x6ece00
// 006e95c0  83c408               add esp, 8
// 006e95c3  c3                   ret 
// 006e95c4  50                   push eax
// 006e95c5  51                   push ecx
// 006e95c6  e8e52b0000           call 0x6ec1b0
// 006e95cb  83c408               add esp, 8
// 006e95ce  c3                   ret 
// 006e95cf  50                   push eax
// 006e95d0  51                   push ecx
// 006e95d1  e81aa5fdff           call 0x6c3af0
// 006e95d6  83c408               add esp, 8
// 006e95d9  c3                   ret 
// 006e95da  8b5110               mov edx, dword ptr [ecx + 0x10]
// 006e95dd  ff4a04               dec dword ptr [edx + 4]
// 006e95e0  8b500c               mov edx, dword ptr [eax + 0xc]
// 006e95e3  6a00                 push 0
// 006e95e5  83c211               add edx, 0x11
// 006e95e8  52                   push edx
// 006e95e9  50                   push eax
// 006e95ea  51                   push ecx
// 006e95eb  e870410000           call 0x6ed760
// 006e95f0  83c410               add esp, 0x10
// 006e95f3  c3                   ret 
// 006e95f4  8b5010               mov edx, dword ptr [eax + 0x10]
// 006e95f7  6a00                 push 0
// 006e95f9  83c218               add edx, 0x18
// 006e95fc  52                   push edx
// 006e95fd  50                   push eax
// 006e95fe  51                   push ecx
// 006e95ff  e85c410000           call 0x6ed760
// 006e9604  83c410               add esp, 0x10
// 006e9607  c3                   ret 
// 006e9608  da956e00c495         ficom dword ptr [ebp - 0x6a3bff92]
// 006e960e  6e                   outsb dx, byte ptr [esi]
// 006e960f  00ae956e00f4         add byte ptr [esi - 0xbff916b], ch
// 006e9615  95                   xchg ebp, eax
// 006e9616  6e                   outsb dx, byte ptr [esi]
// 006e9617  00cf                 add bh, cl
// 006e9619  95                   xchg ebp, eax
// 006e961a  6e                   outsb dx, byte ptr [esi]
// 006e961b  00a3956e00b9         add byte ptr [ebx - 0x46ff916b], ah
// 006e9621  95                   xchg ebp, eax
// 006e9622  6e                   outsb dx, byte ptr [esi]
// library lua-5.1/lgc.c (function _freeobj)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
