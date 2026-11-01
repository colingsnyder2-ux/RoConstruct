// from server: 100% by auto
// roc 2009-12 007977d0  unit: lua_exception  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007977d0
//
// 007977d0  8b4628               mov eax, dword ptr [esi + 0x28]
// 007977d3  894614               mov dword ptr [esi + 0x14], eax
// 007977d6  8b00                 mov eax, dword ptr [eax]
// 007977d8  50                   push eax
// 007977d9  56                   push esi
// 007977da  89460c               mov dword ptr [esi + 0xc], eax
// 007977dd  e8ae960300           call 0x7d0e90
// 007977e2  8b460c               mov eax, dword ptr [esi + 0xc]
// 007977e5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007977e9  50                   push eax
// 007977ea  51                   push ecx
// 007977eb  56                   push esi
// 007977ec  e8dff7ffff           call 0x796fd0
// 007977f1  668b5636             mov dx, word ptr [esi + 0x36]
// 007977f5  83c414               add esp, 0x14
// 007977f8  817e30204e0000       cmp dword ptr [esi + 0x30], 0x4e20
// 007977ff  66895634             mov word ptr [esi + 0x34], dx
// 00797803  c6463901             mov byte ptr [esi + 0x39], 1
// 00797807  7e2f                 jle 0x797838
// 00797809  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0079780c  2b4e28               sub ecx, dword ptr [esi + 0x28]
// 0079780f  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00797814  f7e9                 imul ecx
// 00797816  c1fa02               sar edx, 2
// 00797819  8bc2                 mov eax, edx
// 0079781b  c1e81f               shr eax, 0x1f
// 0079781e  8d4c0201             lea ecx, [edx + eax + 1]
// 00797822  81f9204e0000         cmp ecx, 0x4e20
// 00797828  7d0e                 jge 0x797838
// 0079782a  68204e0000           push 0x4e20
// 0079782f  56                   push esi
// 00797830  e87bfaffff           call 0x7972b0
// 00797835  83c408               add esp, 8
// 00797838  33c0                 xor eax, eax
// 0079783a  894674               mov dword ptr [esi + 0x74], eax
// 0079783d  894670               mov dword ptr [esi + 0x70], eax
// 00797840  c3                   ret 
// library lua-5.1.3/ldo.c (function _resetstack)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 ldo.c
