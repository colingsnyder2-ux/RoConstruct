// from server: 100% by auto
// roc 2010-06 0056e230  unit: G3D::LineSegment  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056e230
//
// 0056e230  83ec08               sub esp, 8
// 0056e233  56                   push esi
// 0056e234  8b742410             mov esi, dword ptr [esp + 0x10]
// 0056e238  85f6                 test esi, esi
// 0056e23a  7456                 je 0x56e292
// 0056e23c  8b442418             mov eax, dword ptr [esp + 0x18]
// 0056e240  8bc8                 mov ecx, eax
// 0056e242  c1e918               shr ecx, 0x18
// 0056e245  57                   push edi
// 0056e246  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0056e24a  884c2408             mov byte ptr [esp + 8], cl
// 0056e24e  8bd0                 mov edx, eax
// 0056e250  8bc8                 mov ecx, eax
// 0056e252  c1ea10               shr edx, 0x10
// 0056e255  8844240b             mov byte ptr [esp + 0xb], al
// 0056e259  6a08                 push 8
// 0056e25b  8d44240c             lea eax, [esp + 0xc]
// 0056e25f  8854240d             mov byte ptr [esp + 0xd], dl
// 0056e263  8b17                 mov edx, dword ptr [edi]
// 0056e265  50                   push eax
// 0056e266  c1e908               shr ecx, 8
// 0056e269  56                   push esi
// 0056e26a  884c2416             mov byte ptr [esp + 0x16], cl
// 0056e26e  89542418             mov dword ptr [esp + 0x18], edx
// 0056e272  e8896affff           call 0x564d00
// 0056e277  8b0f                 mov ecx, dword ptr [edi]
// 0056e279  56                   push esi
// 0056e27a  898e1c010000         mov dword ptr [esi + 0x11c], ecx
// 0056e280  e83b6dffff           call 0x564fc0
// 0056e285  6a04                 push 4
// 0056e287  57                   push edi
// 0056e288  56                   push esi
// 0056e289  e8526dffff           call 0x564fe0
// 0056e28e  83c41c               add esp, 0x1c
// 0056e291  5f                   pop edi
// 0056e292  5e                   pop esi
// 0056e293  83c408               add esp, 8
// 0056e296  c3                   ret 
// library libpng-1.2.32/pngwutil.c (function _png_write_chunk_start)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngwutil.c
