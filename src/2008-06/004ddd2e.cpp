// roc 2008-06 004ddd2e  unit: RBX::RenderBase::Mesh::Level  size: 250 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004ddd2e
//
// 004ddd2e  6a00                 push 0
// 004ddd30  6a00                 push 0
// 004ddd32  e855381c00           call 0x6a158c
// 004ddd37  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004ddd3a  8bd3                 mov edx, ebx
// 004ddd3c  2bd1                 sub edx, ecx
// 004ddd3e  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004ddd43  f7ea                 imul edx
// 004ddd45  d1fa                 sar edx, 1
// 004ddd47  8bc2                 mov eax, edx
// 004ddd49  c1e81f               shr eax, 0x1f
// 004ddd4c  03c2                 add eax, edx
// 004ddd4e  3bc7                 cmp eax, edi
// 004ddd50  8b4514               mov eax, dword ptr [ebp + 0x14]
// 004ddd53  d900                 fld dword ptr [eax]
// 004ddd55  d95ddc               fstp dword ptr [ebp - 0x24]
// 004ddd58  d94004               fld dword ptr [eax + 4]
// 004ddd5b  d95de0               fstp dword ptr [ebp - 0x20]
// 004ddd5e  d94008               fld dword ptr [eax + 8]
// 004ddd61  d95de4               fstp dword ptr [ebp - 0x1c]
// 004ddd64  7373                 jae 0x4dddd9
// 004ddd66  8d047f               lea eax, [edi + edi*2]
// 004ddd69  03c0                 add eax, eax
// 004ddd6b  03c0                 add eax, eax
// 004ddd6d  894514               mov dword ptr [ebp + 0x14], eax
// 004ddd70  03c1                 add eax, ecx
// 004ddd72  50                   push eax
// 004ddd73  53                   push ebx
// 004ddd74  51                   push ecx
// 004ddd75  8bce                 mov ecx, esi
// 004ddd77  e824faffff           call 0x4dd7a0
// 004ddd7c  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004ddd7f  8d4ddc               lea ecx, [ebp - 0x24]
// 004ddd82  51                   push ecx
// 004ddd83  8bcb                 mov ecx, ebx
// 004ddd85  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 004ddd88  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004ddd8d  f7e9                 imul ecx
// 004ddd8f  d1fa                 sar edx, 1
// 004ddd91  8bc2                 mov eax, edx
// 004ddd93  c1e81f               shr eax, 0x1f
// 004ddd96  03c2                 add eax, edx
// 004ddd98  2bf8                 sub edi, eax
// 004ddd9a  57                   push edi
// 004ddd9b  53                   push ebx
// 004ddd9c  8bce                 mov ecx, esi
// 004ddd9e  c745fc02000000       mov dword ptr [ebp - 4], 2
// 004ddda5  e8e6efffff           call 0x4dcd90
// 004dddaa  8b4514               mov eax, dword ptr [ebp + 0x14]
// 004dddad  014610               add dword ptr [esi + 0x10], eax
// 004dddb0  8b7610               mov esi, dword ptr [esi + 0x10]
// 004dddb3  8b550c               mov edx, dword ptr [ebp + 0xc]
// 004dddb6  8d4ddc               lea ecx, [ebp - 0x24]
// 004dddb9  51                   push ecx
// 004dddba  2bf0                 sub esi, eax
// 004dddbc  56                   push esi
// 004dddbd  52                   push edx
// 004dddbe  e8fd191a00           call 0x67f7c0
// 004dddc3  83c40c               add esp, 0xc
// 004dddc6  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004dddc9  64890d00000000       mov dword ptr fs:[0], ecx
// 004dddd0  5f                   pop edi
// 004dddd1  5e                   pop esi
// 004dddd2  5b                   pop ebx
// 004dddd3  8be5                 mov esp, ebp
// 004dddd5  5d                   pop ebp
// 004dddd6  c21000               ret 0x10
// 004dddd9  8d3c7f               lea edi, [edi + edi*2]
// 004ddddc  03ff                 add edi, edi
// 004dddde  53                   push ebx
// 004ddddf  03ff                 add edi, edi
// 004ddde1  8bc3                 mov eax, ebx
// 004ddde3  2bc7                 sub eax, edi
// 004ddde5  53                   push ebx
// 004ddde6  50                   push eax
// 004ddde7  8bce                 mov ecx, esi
// 004ddde9  894514               mov dword ptr [ebp + 0x14], eax
// 004dddec  e8aff9ffff           call 0x4dd7a0
// 004dddf1  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004dddf4  894610               mov dword ptr [esi + 0x10], eax
// 004dddf7  8b4514               mov eax, dword ptr [ebp + 0x14]
// 004dddfa  53                   push ebx
// 004dddfb  50                   push eax
// 004dddfc  51                   push ecx
// 004dddfd  e85eefffff           call 0x4dcd60
// 004dde02  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004dde05  8d55dc               lea edx, [ebp - 0x24]
// 004dde08  52                   push edx
// 004dde09  03f8                 add edi, eax
// 004dde0b  57                   push edi
// 004dde0c  50                   push eax
// 004dde0d  e8ae191a00           call 0x67f7c0
// 004dde12  83c418               add esp, 0x18
// 004dde15  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004dde18  5f                   pop edi
// 004dde19  5e                   pop esi
// 004dde1a  64890d00000000       mov dword ptr fs:[0], ecx
// 004dde21  5b                   pop ebx
// 004dde22  8be5                 mov esp, ebp
// 004dde24  5d                   pop ebp
// 004dde25  c21000               ret 0x10
// library ogre-1.4.9/OgreMeshSerializerImpl.cpp (function __catch$?_Insert_n@?$vector@VVector3@Ogre@@V?$allocator@VVector3@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@VVector3@Ogre@@V?$allocator@VVector3@Ogre@@@std@@@2@IABVVector3@Ogre@@@Z$2)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreMeshSerializerImpl.cpp
