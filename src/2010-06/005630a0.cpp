// from server: 100% by auto
// roc 2010-06 005630a0  unit: G3D::_internal::DialogTemplate  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005630a0
//
// 005630a0  56                   push esi
// 005630a1  8b742408             mov esi, dword ptr [esp + 8]
// 005630a5  85f6                 test esi, esi
// 005630a7  0f84c9000000         je 0x563176
// 005630ad  8b86e4000000         mov eax, dword ptr [esi + 0xe4]
// 005630b3  3b86d0000000         cmp eax, dword ptr [esi + 0xd0]
// 005630b9  0f83b7000000         jae 0x563176
// 005630bf  57                   push edi
// 005630c0  8d7e74               lea edi, [esi + 0x74]
// 005630c3  6a02                 push 2
// 005630c5  57                   push edi
// 005630c6  e815f60000           call 0x5726e0
// 005630cb  83c408               add esp, 8
// 005630ce  85c0                 test eax, eax
// 005630d0  741b                 je 0x5630ed
// 005630d2  8b868c000000         mov eax, dword ptr [esi + 0x8c]
// 005630d8  85c0                 test eax, eax
// 005630da  7403                 je 0x5630df
// 005630dc  50                   push eax
// 005630dd  eb05                 jmp 0x5630e4
// 005630df  68140fa200           push 0xa20f14
// 005630e4  56                   push esi
// 005630e5  e8c6e90000           call 0x571ab0
// 005630ea  83c408               add esp, 8
// 005630ed  83be8400000000       cmp dword ptr [esi + 0x84], 0
// 005630f4  7531                 jne 0x563127
// 005630f6  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 005630fc  8b96ac000000         mov edx, dword ptr [esi + 0xac]
// 00563102  51                   push ecx
// 00563103  52                   push edx
// 00563104  56                   push esi
// 00563105  e856c70000           call 0x56f860
// 0056310a  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 00563110  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 00563116  83c40c               add esp, 0xc
// 00563119  898680000000         mov dword ptr [esi + 0x80], eax
// 0056311f  898e84000000         mov dword ptr [esi + 0x84], ecx
// 00563125  eb9c                 jmp 0x5630c3
// 00563127  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0056312d  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 00563133  5f                   pop edi
// 00563134  3bc1                 cmp eax, ecx
// 00563136  742b                 je 0x563163
// 00563138  8b96ac000000         mov edx, dword ptr [esi + 0xac]
// 0056313e  2bc1                 sub eax, ecx
// 00563140  50                   push eax
// 00563141  52                   push edx
// 00563142  56                   push esi
// 00563143  e818c70000           call 0x56f860
// 00563148  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 0056314e  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 00563154  83c40c               add esp, 0xc
// 00563157  898680000000         mov dword ptr [esi + 0x80], eax
// 0056315d  898e84000000         mov dword ptr [esi + 0x84], ecx
// 00563163  56                   push esi
// 00563164  c7865401000000000000 mov dword ptr [esi + 0x154], 0
// 0056316e  e8ed1b0000           call 0x564d60
// 00563173  83c404               add esp, 4
// 00563176  5e                   pop esi
// 00563177  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_write_flush)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
