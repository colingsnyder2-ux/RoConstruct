// from server: 100% by auto
// roc 2007-03 005f9f20  unit: seg_005f0000  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9f20
//
// 005f9f20  51                   push ecx
// 005f9f21  85ff                 test edi, edi
// 005f9f23  55                   push ebp
// 005f9f24  7431                 je 0x5f9f57
// 005f9f26  b801000000           mov eax, 1
// 005f9f2b  8bce                 mov ecx, esi
// 005f9f2d  d3e0                 shl eax, cl
// 005f9f2f  844706               test byte ptr [edi + 6], al
// 005f9f32  89442404             mov dword ptr [esp + 4], eax
// 005f9f36  751f                 jne 0x5f9f57
// 005f9f38  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005f9f3c  8b4810               mov ecx, dword ptr [eax + 0x10]
// 005f9f3f  8b94b1bc000000       mov edx, dword ptr [ecx + esi*4 + 0xbc]
// 005f9f46  52                   push edx
// 005f9f47  56                   push esi
// 005f9f48  57                   push edi
// 005f9f49  e8a2faffff           call 0x5f99f0
// 005f9f4e  8be8                 mov ebp, eax
// 005f9f50  83c40c               add esp, 0xc
// 005f9f53  85ed                 test ebp, ebp
// 005f9f55  7505                 jne 0x5f9f5c
// 005f9f57  33c0                 xor eax, eax
// 005f9f59  5d                   pop ebp
// 005f9f5a  59                   pop ecx
// 005f9f5b  c3                   ret 
// 005f9f5c  3bfb                 cmp edi, ebx
// 005f9f5e  743a                 je 0x5f9f9a
// 005f9f60  85db                 test ebx, ebx
// 005f9f62  74f3                 je 0x5f9f57
// 005f9f64  8a442404             mov al, byte ptr [esp + 4]
// 005f9f68  844306               test byte ptr [ebx + 6], al
// 005f9f6b  75ea                 jne 0x5f9f57
// 005f9f6d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005f9f71  8b5110               mov edx, dword ptr [ecx + 0x10]
// 005f9f74  8b84b2bc000000       mov eax, dword ptr [edx + esi*4 + 0xbc]
// 005f9f7b  50                   push eax
// 005f9f7c  56                   push esi
// 005f9f7d  53                   push ebx
// 005f9f7e  e86dfaffff           call 0x5f99f0
// 005f9f83  83c40c               add esp, 0xc
// 005f9f86  85c0                 test eax, eax
// 005f9f88  74cd                 je 0x5f9f57
// 005f9f8a  50                   push eax
// 005f9f8b  55                   push ebp
// 005f9f8c  e89fe4ffff           call 0x5f8430
// 005f9f91  83c408               add esp, 8
// 005f9f94  f7d8                 neg eax
// 005f9f96  1bc0                 sbb eax, eax
// 005f9f98  23c5                 and eax, ebp
// 005f9f9a  5d                   pop ebp
// 005f9f9b  59                   pop ecx
// 005f9f9c  c3                   ret 
// library lua-5.1.1/lvm.c (function _get_compTM)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lvm.c
