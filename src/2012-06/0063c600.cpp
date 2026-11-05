// from server: 100% by auto
// roc 2012-06 0063c600  unit: G3D::_internal::DialogTemplate  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0063c600
//
// 0063c600  8b442404             mov eax, dword ptr [esp + 4]
// 0063c604  56                   push esi
// 0063c605  8b7054               mov esi, dword ptr [eax + 0x54]
// 0063c608  8b4640               mov eax, dword ptr [esi + 0x40]
// 0063c60b  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 0063c60e  57                   push edi
// 0063c60f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0063c613  03c7                 add eax, edi
// 0063c615  3bc8                 cmp ecx, eax
// 0063c617  7c02                 jl 0x63c61b
// 0063c619  8bc1                 mov eax, ecx
// 0063c61b  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 0063c61e  894638               mov dword ptr [esi + 0x38], eax
// 0063c621  7e09                 jle 0x63c62c
// 0063c623  51                   push ecx
// 0063c624  57                   push edi
// 0063c625  8bce                 mov ecx, esi
// 0063c627  e8948fffff           call 0x6355c0
// 0063c62c  8b5634               mov edx, dword ptr [esi + 0x34]
// 0063c62f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0063c633  035640               add edx, dword ptr [esi + 0x40]
// 0063c636  57                   push edi
// 0063c637  51                   push ecx
// 0063c638  52                   push edx
// 0063c639  e8a2e3feff           call 0x62a9e0
// 0063c63e  017e40               add dword ptr [esi + 0x40], edi
// 0063c641  83c40c               add esp, 0xc
// 0063c644  5f                   pop edi
// 0063c645  5e                   pop esi
// 0063c646  c3                   ret 
// library rbx2016-g3d/GImage_png.cpp (function ?png_write_data@G3D@@YAXPAUpng_struct_def@@PAEI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage_png.cpp
