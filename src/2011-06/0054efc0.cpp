// from server: 100% by auto
// roc 2011-06 0054efc0  unit: G3D::_internal::DialogTemplate  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0054efc0
//
// 0054efc0  8b442404             mov eax, dword ptr [esp + 4]
// 0054efc4  56                   push esi
// 0054efc5  8b7054               mov esi, dword ptr [eax + 0x54]
// 0054efc8  8b4640               mov eax, dword ptr [esi + 0x40]
// 0054efcb  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 0054efce  57                   push edi
// 0054efcf  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0054efd3  03c7                 add eax, edi
// 0054efd5  3bc8                 cmp ecx, eax
// 0054efd7  7c02                 jl 0x54efdb
// 0054efd9  8bc1                 mov eax, ecx
// 0054efdb  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 0054efde  894638               mov dword ptr [esi + 0x38], eax
// 0054efe1  7e09                 jle 0x54efec
// 0054efe3  51                   push ecx
// 0054efe4  57                   push edi
// 0054efe5  8bce                 mov ecx, esi
// 0054efe7  e84461ffff           call 0x545130
// 0054efec  8b5634               mov edx, dword ptr [esi + 0x34]
// 0054efef  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0054eff3  035640               add edx, dword ptr [esi + 0x40]
// 0054eff6  57                   push edi
// 0054eff7  51                   push ecx
// 0054eff8  52                   push edx
// 0054eff9  e8e2fafeff           call 0x53eae0
// 0054effe  017e40               add dword ptr [esi + 0x40], edi
// 0054f001  83c40c               add esp, 0xc
// 0054f004  5f                   pop edi
// 0054f005  5e                   pop esi
// 0054f006  c3                   ret 
// library rbx2016-g3d/GImage_png.cpp (function ?png_write_data@G3D@@YAXPAUpng_struct_def@@PAEI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage_png.cpp
