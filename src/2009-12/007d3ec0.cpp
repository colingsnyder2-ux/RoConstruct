// from server: 100% by auto
// roc 2009-12 007d3ec0  unit: seg_007d0000  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d3ec0
//
// 007d3ec0  51                   push ecx
// 007d3ec1  53                   push ebx
// 007d3ec2  56                   push esi
// 007d3ec3  8bf0                 mov esi, eax
// 007d3ec5  57                   push edi
// 007d3ec6  8b7e30               mov edi, dword ptr [esi + 0x30]
// 007d3ec9  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 007d3ed1  e86affffff           call 0x7d3e40
// 007d3ed6  817e1005010000       cmp dword ptr [esi + 0x10], 0x105
// 007d3edd  8bd8                 mov ebx, eax
// 007d3edf  752c                 jne 0x7d3f0d
// 007d3ee1  57                   push edi
// 007d3ee2  e8a9880000           call 0x7dc790
// 007d3ee7  50                   push eax
// 007d3ee8  8d442414             lea eax, [esp + 0x14]
// 007d3eec  50                   push eax
// 007d3eed  57                   push edi
// 007d3eee  e8dd810000           call 0x7dc0d0
// 007d3ef3  53                   push ebx
// 007d3ef4  57                   push edi
// 007d3ef5  e866890000           call 0x7dc860
// 007d3efa  83c418               add esp, 0x18
// 007d3efd  e83effffff           call 0x7d3e40
// 007d3f02  817e1005010000       cmp dword ptr [esi + 0x10], 0x105
// 007d3f09  8bd8                 mov ebx, eax
// 007d3f0b  74d4                 je 0x7d3ee1
// 007d3f0d  817e1004010000       cmp dword ptr [esi + 0x10], 0x104
// 007d3f14  752b                 jne 0x7d3f41
// 007d3f16  57                   push edi
// 007d3f17  e874880000           call 0x7dc790
// 007d3f1c  50                   push eax
// 007d3f1d  8d4c2414             lea ecx, [esp + 0x14]
// 007d3f21  51                   push ecx
// 007d3f22  57                   push edi
// 007d3f23  e8a8810000           call 0x7dc0d0
// 007d3f28  53                   push ebx
// 007d3f29  57                   push edi
// 007d3f2a  e831890000           call 0x7dc860
// 007d3f2f  56                   push esi
// 007d3f30  e8fb270000           call 0x7d6730
// 007d3f35  83c41c               add esp, 0x1c
// 007d3f38  8bc6                 mov eax, esi
// 007d3f3a  e881f2ffff           call 0x7d31c0
// 007d3f3f  eb0f                 jmp 0x7d3f50
// 007d3f41  53                   push ebx
// 007d3f42  8d542410             lea edx, [esp + 0x10]
// 007d3f46  52                   push edx
// 007d3f47  57                   push edi
// 007d3f48  e883810000           call 0x7dc0d0
// 007d3f4d  83c40c               add esp, 0xc
// 007d3f50  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007d3f54  50                   push eax
// 007d3f55  57                   push edi
// 007d3f56  e805890000           call 0x7dc860
// 007d3f5b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007d3f5f  680a010000           push 0x10a
// 007d3f64  bf06010000           mov edi, 0x106
// 007d3f69  e872d9ffff           call 0x7d18e0
// 007d3f6e  83c40c               add esp, 0xc
// 007d3f71  5f                   pop edi
// 007d3f72  5e                   pop esi
// 007d3f73  5b                   pop ebx
// 007d3f74  59                   pop ecx
// 007d3f75  c3                   ret 
// library lua-5.1/lparser.c (function _ifstat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
