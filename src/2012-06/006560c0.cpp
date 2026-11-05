// from server: 100% by auto
// roc 2012-06 006560c0  unit: seg_00650000  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006560c0
//
// 006560c0  83ec08               sub esp, 8
// 006560c3  56                   push esi
// 006560c4  8b742410             mov esi, dword ptr [esp + 0x10]
// 006560c8  85f6                 test esi, esi
// 006560ca  7456                 je 0x656122
// 006560cc  8b442418             mov eax, dword ptr [esp + 0x18]
// 006560d0  8bc8                 mov ecx, eax
// 006560d2  c1e918               shr ecx, 0x18
// 006560d5  57                   push edi
// 006560d6  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 006560da  884c2408             mov byte ptr [esp + 8], cl
// 006560de  8bd0                 mov edx, eax
// 006560e0  8bc8                 mov ecx, eax
// 006560e2  c1ea10               shr edx, 0x10
// 006560e5  8844240b             mov byte ptr [esp + 0xb], al
// 006560e9  6a08                 push 8
// 006560eb  8d44240c             lea eax, [esp + 0xc]
// 006560ef  8854240d             mov byte ptr [esp + 0xd], dl
// 006560f3  8b17                 mov edx, dword ptr [edi]
// 006560f5  50                   push eax
// 006560f6  c1e908               shr ecx, 8
// 006560f9  56                   push esi
// 006560fa  884c2416             mov byte ptr [esp + 0x16], cl
// 006560fe  89542418             mov dword ptr [esp + 0x18], edx
// 00656102  e8b915ffff           call 0x6476c0
// 00656107  8b0f                 mov ecx, dword ptr [edi]
// 00656109  56                   push esi
// 0065610a  898e1c010000         mov dword ptr [esi + 0x11c], ecx
// 00656110  e85b7dfeff           call 0x63de70
// 00656115  6a04                 push 4
// 00656117  57                   push edi
// 00656118  56                   push esi
// 00656119  e8727dfeff           call 0x63de90
// 0065611e  83c41c               add esp, 0x1c
// 00656121  5f                   pop edi
// 00656122  5e                   pop esi
// 00656123  83c408               add esp, 8
// 00656126  c3                   ret 
// library libpng-1.2.32/pngwutil.c (function _png_write_chunk_start)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngwutil.c
