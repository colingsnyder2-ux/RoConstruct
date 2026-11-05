// from server: 100% by auto
// roc 2011-06 0056a9b0  unit: seg_00560000  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056a9b0
//
// 0056a9b0  83ec08               sub esp, 8
// 0056a9b3  56                   push esi
// 0056a9b4  8b742410             mov esi, dword ptr [esp + 0x10]
// 0056a9b8  85f6                 test esi, esi
// 0056a9ba  7456                 je 0x56aa12
// 0056a9bc  8b442418             mov eax, dword ptr [esp + 0x18]
// 0056a9c0  8bc8                 mov ecx, eax
// 0056a9c2  c1e918               shr ecx, 0x18
// 0056a9c5  57                   push edi
// 0056a9c6  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0056a9ca  884c2408             mov byte ptr [esp + 8], cl
// 0056a9ce  8bd0                 mov edx, eax
// 0056a9d0  8bc8                 mov ecx, eax
// 0056a9d2  c1ea10               shr edx, 0x10
// 0056a9d5  8844240b             mov byte ptr [esp + 0xb], al
// 0056a9d9  6a08                 push 8
// 0056a9db  8d44240c             lea eax, [esp + 0xc]
// 0056a9df  8854240d             mov byte ptr [esp + 0xd], dl
// 0056a9e3  8b17                 mov edx, dword ptr [edi]
// 0056a9e5  50                   push eax
// 0056a9e6  c1e908               shr ecx, 8
// 0056a9e9  56                   push esi
// 0056a9ea  884c2416             mov byte ptr [esp + 0x16], cl
// 0056a9ee  89542418             mov dword ptr [esp + 0x18], edx
// 0056a9f2  e849fefeff           call 0x55a840
// 0056a9f7  8b0f                 mov ecx, dword ptr [edi]
// 0056a9f9  56                   push esi
// 0056a9fa  898e1c010000         mov dword ptr [esi + 0x11c], ecx
// 0056aa00  e82b5efeff           call 0x550830
// 0056aa05  6a04                 push 4
// 0056aa07  57                   push edi
// 0056aa08  56                   push esi
// 0056aa09  e8425efeff           call 0x550850
// 0056aa0e  83c41c               add esp, 0x1c
// 0056aa11  5f                   pop edi
// 0056aa12  5e                   pop esi
// 0056aa13  83c408               add esp, 8
// 0056aa16  c3                   ret 
// library libpng-1.2.32/pngwutil.c (function _png_write_chunk_start)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngwutil.c
