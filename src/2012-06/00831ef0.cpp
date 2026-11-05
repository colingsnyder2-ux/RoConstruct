// from server: 100% by auto
// roc 2012-06 00831ef0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831ef0
//
// 00831ef0  56                   push esi
// 00831ef1  8b742408             mov esi, dword ptr [esp + 8]
// 00831ef5  57                   push edi
// 00831ef6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00831efa  8bc7                 mov eax, edi
// 00831efc  8bce                 mov ecx, esi
// 00831efe  e83dfaffff           call 0x831940
// 00831f03  83780804             cmp dword ptr [eax + 8], 4
// 00831f07  743e                 je 0x831f47
// 00831f09  50                   push eax
// 00831f0a  56                   push esi
// 00831f0b  e8c0161000           call 0x9335d0
// 00831f10  83c408               add esp, 8
// 00831f13  85c0                 test eax, eax
// 00831f15  7513                 jne 0x831f2a
// 00831f17  8b442414             mov eax, dword ptr [esp + 0x14]
// 00831f1b  85c0                 test eax, eax
// 00831f1d  7406                 je 0x831f25
// 00831f1f  c70000000000         mov dword ptr [eax], 0
// 00831f25  5f                   pop edi
// 00831f26  33c0                 xor eax, eax
// 00831f28  5e                   pop esi
// 00831f29  c3                   ret 
// 00831f2a  8b4610               mov eax, dword ptr [esi + 0x10]
// 00831f2d  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00831f30  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00831f33  7209                 jb 0x831f3e
// 00831f35  56                   push esi
// 00831f36  e875131000           call 0x9332b0
// 00831f3b  83c404               add esp, 4
// 00831f3e  8bc7                 mov eax, edi
// 00831f40  8bce                 mov ecx, esi
// 00831f42  e8f9f9ffff           call 0x831940
// 00831f47  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00831f4b  85c9                 test ecx, ecx
// 00831f4d  7407                 je 0x831f56
// 00831f4f  8b10                 mov edx, dword ptr [eax]
// 00831f51  8b520c               mov edx, dword ptr [edx + 0xc]
// 00831f54  8911                 mov dword ptr [ecx], edx
// 00831f56  8b00                 mov eax, dword ptr [eax]
// 00831f58  5f                   pop edi
// 00831f59  83c010               add eax, 0x10
// 00831f5c  5e                   pop esi
// 00831f5d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tolstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
