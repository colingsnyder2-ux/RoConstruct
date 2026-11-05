// from server: 100% by auto
// roc 2009-12 00601ec0  unit: G3D::_internal::DialogTemplate  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00601ec0
//
// 00601ec0  8b442404             mov eax, dword ptr [esp + 4]
// 00601ec4  53                   push ebx
// 00601ec5  55                   push ebp
// 00601ec6  56                   push esi
// 00601ec7  33f6                 xor esi, esi
// 00601ec9  33db                 xor ebx, ebx
// 00601ecb  33ed                 xor ebp, ebp
// 00601ecd  85c0                 test eax, eax
// 00601ecf  740e                 je 0x601edf
// 00601ed1  8b30                 mov esi, dword ptr [eax]
// 00601ed3  8b9e4c020000         mov ebx, dword ptr [esi + 0x24c]
// 00601ed9  8bae44020000         mov ebp, dword ptr [esi + 0x244]
// 00601edf  8b442414             mov eax, dword ptr [esp + 0x14]
// 00601ee3  85c0                 test eax, eax
// 00601ee5  7459                 je 0x601f40
// 00601ee7  57                   push edi
// 00601ee8  8b38                 mov edi, dword ptr [eax]
// 00601eea  85ff                 test edi, edi
// 00601eec  7451                 je 0x601f3f
// 00601eee  85f6                 test esi, esi
// 00601ef0  7438                 je 0x601f2a
// 00601ef2  6aff                 push -1
// 00601ef4  68ff7f0000           push 0x7fff
// 00601ef9  57                   push edi
// 00601efa  56                   push esi
// 00601efb  e8c0170000           call 0x6036c0
// 00601f00  83c410               add esp, 0x10
// 00601f03  83be2002000000       cmp dword ptr [esi + 0x220], 0
// 00601f0a  741e                 je 0x601f2a
// 00601f0c  8b8624020000         mov eax, dword ptr [esi + 0x224]
// 00601f12  50                   push eax
// 00601f13  56                   push esi
// 00601f14  e8c7ed0000           call 0x610ce0
// 00601f19  83c408               add esp, 8
// 00601f1c  33c0                 xor eax, eax
// 00601f1e  898624020000         mov dword ptr [esi + 0x224], eax
// 00601f24  898620020000         mov dword ptr [esi + 0x220], eax
// 00601f2a  55                   push ebp
// 00601f2b  53                   push ebx
// 00601f2c  57                   push edi
// 00601f2d  e86eec0000           call 0x610ba0
// 00601f32  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00601f36  83c40c               add esp, 0xc
// 00601f39  c70100000000         mov dword ptr [ecx], 0
// 00601f3f  5f                   pop edi
// 00601f40  85f6                 test esi, esi
// 00601f42  741b                 je 0x601f5f
// 00601f44  56                   push esi
// 00601f45  e8c6f8ffff           call 0x601810
// 00601f4a  55                   push ebp
// 00601f4b  53                   push ebx
// 00601f4c  56                   push esi
// 00601f4d  e84eec0000           call 0x610ba0
// 00601f52  8b542420             mov edx, dword ptr [esp + 0x20]
// 00601f56  83c410               add esp, 0x10
// 00601f59  c70200000000         mov dword ptr [edx], 0
// 00601f5f  5e                   pop esi
// 00601f60  5d                   pop ebp
// 00601f61  5b                   pop ebx
// 00601f62  c3                   ret 
// library libpng-1.2.29/pngwrite.c (function _png_destroy_write_struct)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngwrite.c
