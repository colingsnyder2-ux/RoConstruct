// from server: 100% by auto
// roc 2010-06 0056f390  unit: G3D::LineSegment  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056f390
//
// 0056f390  56                   push esi
// 0056f391  8b742408             mov esi, dword ptr [esp + 8]
// 0056f395  85f6                 test esi, esi
// 0056f397  746b                 je 0x56f404
// 0056f399  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0056f39d  53                   push ebx
// 0056f39e  57                   push edi
// 0056f39f  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0056f3a3  57                   push edi
// 0056f3a4  50                   push eax
// 0056f3a5  56                   push esi
// 0056f3a6  e885eeffff           call 0x56e230
// 0056f3ab  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0056f3af  83c40c               add esp, 0xc
// 0056f3b2  85db                 test ebx, ebx
// 0056f3b4  7417                 je 0x56f3cd
// 0056f3b6  85ff                 test edi, edi
// 0056f3b8  7613                 jbe 0x56f3cd
// 0056f3ba  57                   push edi
// 0056f3bb  53                   push ebx
// 0056f3bc  56                   push esi
// 0056f3bd  e83e59ffff           call 0x564d00
// 0056f3c2  57                   push edi
// 0056f3c3  53                   push ebx
// 0056f3c4  56                   push esi
// 0056f3c5  e8165cffff           call 0x564fe0
// 0056f3ca  83c418               add esp, 0x18
// 0056f3cd  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0056f3d3  8bd0                 mov edx, eax
// 0056f3d5  8bc8                 mov ecx, eax
// 0056f3d7  c1e918               shr ecx, 0x18
// 0056f3da  c1ea10               shr edx, 0x10
// 0056f3dd  884c2410             mov byte ptr [esp + 0x10], cl
// 0056f3e1  88542411             mov byte ptr [esp + 0x11], dl
// 0056f3e5  6a04                 push 4
// 0056f3e7  8d542414             lea edx, [esp + 0x14]
// 0056f3eb  8bc8                 mov ecx, eax
// 0056f3ed  52                   push edx
// 0056f3ee  c1e908               shr ecx, 8
// 0056f3f1  56                   push esi
// 0056f3f2  884c241e             mov byte ptr [esp + 0x1e], cl
// 0056f3f6  8844241f             mov byte ptr [esp + 0x1f], al
// 0056f3fa  e80159ffff           call 0x564d00
// 0056f3ff  83c40c               add esp, 0xc
// 0056f402  5f                   pop edi
// 0056f403  5b                   pop ebx
// 0056f404  5e                   pop esi
// 0056f405  c3                   ret 
// library libpng-1.2.16/pngwutil.c (function _png_write_chunk)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwutil.c
