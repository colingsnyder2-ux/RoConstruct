// from server: 100% by auto
// roc 2009-06 005800f0  unit: G3D::_internal::DialogTemplate  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005800f0
//
// 005800f0  8b442404             mov eax, dword ptr [esp + 4]
// 005800f4  53                   push ebx
// 005800f5  55                   push ebp
// 005800f6  56                   push esi
// 005800f7  33f6                 xor esi, esi
// 005800f9  33db                 xor ebx, ebx
// 005800fb  33ed                 xor ebp, ebp
// 005800fd  85c0                 test eax, eax
// 005800ff  740e                 je 0x58010f
// 00580101  8b30                 mov esi, dword ptr [eax]
// 00580103  8b9e4c020000         mov ebx, dword ptr [esi + 0x24c]
// 00580109  8bae44020000         mov ebp, dword ptr [esi + 0x244]
// 0058010f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00580113  85c0                 test eax, eax
// 00580115  7459                 je 0x580170
// 00580117  57                   push edi
// 00580118  8b38                 mov edi, dword ptr [eax]
// 0058011a  85ff                 test edi, edi
// 0058011c  7451                 je 0x58016f
// 0058011e  85f6                 test esi, esi
// 00580120  7438                 je 0x58015a
// 00580122  6aff                 push -1
// 00580124  68ff7f0000           push 0x7fff
// 00580129  57                   push edi
// 0058012a  56                   push esi
// 0058012b  e8e0170000           call 0x581910
// 00580130  83c410               add esp, 0x10
// 00580133  83be2002000000       cmp dword ptr [esi + 0x220], 0
// 0058013a  741e                 je 0x58015a
// 0058013c  8b8624020000         mov eax, dword ptr [esi + 0x224]
// 00580142  50                   push eax
// 00580143  56                   push esi
// 00580144  e867eb0000           call 0x58ecb0
// 00580149  83c408               add esp, 8
// 0058014c  33c0                 xor eax, eax
// 0058014e  898624020000         mov dword ptr [esi + 0x224], eax
// 00580154  898620020000         mov dword ptr [esi + 0x220], eax
// 0058015a  55                   push ebp
// 0058015b  53                   push ebx
// 0058015c  57                   push edi
// 0058015d  e80eea0000           call 0x58eb70
// 00580162  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00580166  83c40c               add esp, 0xc
// 00580169  c70100000000         mov dword ptr [ecx], 0
// 0058016f  5f                   pop edi
// 00580170  85f6                 test esi, esi
// 00580172  741b                 je 0x58018f
// 00580174  56                   push esi
// 00580175  e8b6f8ffff           call 0x57fa30
// 0058017a  55                   push ebp
// 0058017b  53                   push ebx
// 0058017c  56                   push esi
// 0058017d  e8eee90000           call 0x58eb70
// 00580182  8b542420             mov edx, dword ptr [esp + 0x20]
// 00580186  83c410               add esp, 0x10
// 00580189  c70200000000         mov dword ptr [edx], 0
// 0058018f  5e                   pop esi
// 00580190  5d                   pop ebp
// 00580191  5b                   pop ebx
// 00580192  c3                   ret 
// library libpng-1.2.29/pngwrite.c (function _png_destroy_write_struct)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngwrite.c
