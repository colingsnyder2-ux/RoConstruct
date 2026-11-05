// from server: 100% by auto
// roc 2010-06 00563830  unit: G3D::_internal::DialogTemplate  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00563830
//
// 00563830  8b442404             mov eax, dword ptr [esp + 4]
// 00563834  53                   push ebx
// 00563835  55                   push ebp
// 00563836  56                   push esi
// 00563837  33f6                 xor esi, esi
// 00563839  33db                 xor ebx, ebx
// 0056383b  33ed                 xor ebp, ebp
// 0056383d  85c0                 test eax, eax
// 0056383f  740e                 je 0x56384f
// 00563841  8b30                 mov esi, dword ptr [eax]
// 00563843  8b9e4c020000         mov ebx, dword ptr [esi + 0x24c]
// 00563849  8bae44020000         mov ebp, dword ptr [esi + 0x244]
// 0056384f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00563853  85c0                 test eax, eax
// 00563855  7459                 je 0x5638b0
// 00563857  57                   push edi
// 00563858  8b38                 mov edi, dword ptr [eax]
// 0056385a  85ff                 test edi, edi
// 0056385c  7451                 je 0x5638af
// 0056385e  85f6                 test esi, esi
// 00563860  7438                 je 0x56389a
// 00563862  6aff                 push -1
// 00563864  68ff7f0000           push 0x7fff
// 00563869  57                   push edi
// 0056386a  56                   push esi
// 0056386b  e8c0170000           call 0x565030
// 00563870  83c410               add esp, 0x10
// 00563873  83be2002000000       cmp dword ptr [esi + 0x220], 0
// 0056387a  741e                 je 0x56389a
// 0056387c  8b8624020000         mov eax, dword ptr [esi + 0x224]
// 00563882  50                   push eax
// 00563883  56                   push esi
// 00563884  e877ed0000           call 0x572600
// 00563889  83c408               add esp, 8
// 0056388c  33c0                 xor eax, eax
// 0056388e  898624020000         mov dword ptr [esi + 0x224], eax
// 00563894  898620020000         mov dword ptr [esi + 0x220], eax
// 0056389a  55                   push ebp
// 0056389b  53                   push ebx
// 0056389c  57                   push edi
// 0056389d  e81eec0000           call 0x5724c0
// 005638a2  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005638a6  83c40c               add esp, 0xc
// 005638a9  c70100000000         mov dword ptr [ecx], 0
// 005638af  5f                   pop edi
// 005638b0  85f6                 test esi, esi
// 005638b2  741b                 je 0x5638cf
// 005638b4  56                   push esi
// 005638b5  e8c6f8ffff           call 0x563180
// 005638ba  55                   push ebp
// 005638bb  53                   push ebx
// 005638bc  56                   push esi
// 005638bd  e8feeb0000           call 0x5724c0
// 005638c2  8b542420             mov edx, dword ptr [esp + 0x20]
// 005638c6  83c410               add esp, 0x10
// 005638c9  c70200000000         mov dword ptr [edx], 0
// 005638cf  5e                   pop esi
// 005638d0  5d                   pop ebp
// 005638d1  5b                   pop ebx
// 005638d2  c3                   ret 
// library libpng-1.2.29/pngwrite.c (function _png_destroy_write_struct)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngwrite.c
