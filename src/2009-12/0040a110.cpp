// from server: 100% by auto
// roc 2009-12 0040a110  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0040a110
//
// 0040a110  56                   push esi
// 0040a111  8bf1                 mov esi, ecx
// 0040a113  8b4624               mov eax, dword ptr [esi + 0x24]
// 0040a116  57                   push edi
// 0040a117  33ff                 xor edi, edi
// 0040a119  3bc7                 cmp eax, edi
// 0040a11b  7409                 je 0x40a126
// 0040a11d  50                   push eax
// 0040a11e  e837973e00           call 0x7f385a
// 0040a123  83c404               add esp, 4
// 0040a126  8b4618               mov eax, dword ptr [esi + 0x18]
// 0040a129  50                   push eax
// 0040a12a  897e24               mov dword ptr [esi + 0x24], edi
// 0040a12d  897e28               mov dword ptr [esi + 0x28], edi
// 0040a130  897e2c               mov dword ptr [esi + 0x2c], edi
// 0040a133  e822973e00           call 0x7f385a
// 0040a138  8b460c               mov eax, dword ptr [esi + 0xc]
// 0040a13b  83c404               add esp, 4
// 0040a13e  3bc7                 cmp eax, edi
// 0040a140  7409                 je 0x40a14b
// 0040a142  50                   push eax
// 0040a143  e812973e00           call 0x7f385a
// 0040a148  83c404               add esp, 4
// 0040a14b  8b0e                 mov ecx, dword ptr [esi]
// 0040a14d  51                   push ecx
// 0040a14e  897e0c               mov dword ptr [esi + 0xc], edi
// 0040a151  897e10               mov dword ptr [esi + 0x10], edi
// 0040a154  897e14               mov dword ptr [esi + 0x14], edi
// 0040a157  e8fe963e00           call 0x7f385a
// 0040a15c  83c404               add esp, 4
// 0040a15f  5f                   pop edi
// 0040a160  5e                   pop esi
// 0040a161  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexPolygon2.cpp (function ??1?$ConvexPolygon2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolygon2.cpp
