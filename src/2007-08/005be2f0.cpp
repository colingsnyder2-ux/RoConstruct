// from server: 100% by auto
// roc 2007-08 005be2f0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005be2f0
//
// 005be2f0  8b442410             mov eax, dword ptr [esp + 0x10]
// 005be2f4  83ec08               sub esp, 8
// 005be2f7  85c0                 test eax, eax
// 005be2f9  56                   push esi
// 005be2fa  8b742410             mov esi, dword ptr [esp + 0x10]
// 005be2fe  7504                 jne 0x5be304
// 005be300  33c9                 xor ecx, ecx
// 005be302  eb0c                 jmp 0x5be310
// 005be304  8bce                 mov ecx, esi
// 005be306  e825f1ffff           call 0x5bd430
// 005be30b  2b4620               sub eax, dword ptr [esi + 0x20]
// 005be30e  8bc8                 mov ecx, eax
// 005be310  8b442414             mov eax, dword ptr [esp + 0x14]
// 005be314  83c001               add eax, 1
// 005be317  c1e004               shl eax, 4
// 005be31a  8bd0                 mov edx, eax
// 005be31c  8b4608               mov eax, dword ptr [esi + 8]
// 005be31f  57                   push edi
// 005be320  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 005be324  2bc2                 sub eax, edx
// 005be326  89442408             mov dword ptr [esp + 8], eax
// 005be32a  2b4620               sub eax, dword ptr [esi + 0x20]
// 005be32d  51                   push ecx
// 005be32e  50                   push eax
// 005be32f  8d442410             lea eax, [esp + 0x10]
// 005be333  50                   push eax
// 005be334  68d0e25b00           push 0x5be2d0
// 005be339  56                   push esi
// 005be33a  897c2420             mov dword ptr [esp + 0x20], edi
// 005be33e  e80d810000           call 0x5c6450
// 005be343  83c414               add esp, 0x14
// 005be346  83ffff               cmp edi, -1
// 005be349  5f                   pop edi
// 005be34a  750e                 jne 0x5be35a
// 005be34c  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005be34f  8b7608               mov esi, dword ptr [esi + 8]
// 005be352  3b7108               cmp esi, dword ptr [ecx + 8]
// 005be355  7203                 jb 0x5be35a
// 005be357  897108               mov dword ptr [ecx + 8], esi
// 005be35a  5e                   pop esi
// 005be35b  83c408               add esp, 8
// 005be35e  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pcall)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
