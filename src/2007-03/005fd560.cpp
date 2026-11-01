// from server: 100% by auto
// roc 2007-03 005fd560  unit: seg_005f0000  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fd560
//
// 005fd560  817e101d010000       cmp dword ptr [esi + 0x10], 0x11d
// 005fd567  7424                 je 0x5fd58d
// 005fd569  681d010000           push 0x11d
// 005fd56e  56                   push esi
// 005fd56f  e8fc380000           call 0x600e70
// 005fd574  50                   push eax
// 005fd575  8b4634               mov eax, dword ptr [esi + 0x34]
// 005fd578  6828047c00           push 0x7c0428
// 005fd57d  50                   push eax
// 005fd57e  e8bdb2ffff           call 0x5f8840
// 005fd583  50                   push eax
// 005fd584  56                   push esi
// 005fd585  e8e6390000           call 0x600f70
// 005fd58a  83c41c               add esp, 0x1c
// 005fd58d  53                   push ebx
// 005fd58e  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 005fd591  56                   push esi
// 005fd592  e8094e0000           call 0x6023a0
// 005fd597  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 005fd59a  53                   push ebx
// 005fd59b  51                   push ecx
// 005fd59c  e87f720100           call 0x614820
// 005fd5a1  83c9ff               or ecx, 0xffffffff
// 005fd5a4  83c40c               add esp, 0xc
// 005fd5a7  894f10               mov dword ptr [edi + 0x10], ecx
// 005fd5aa  894f14               mov dword ptr [edi + 0x14], ecx
// 005fd5ad  c70704000000         mov dword ptr [edi], 4
// 005fd5b3  894708               mov dword ptr [edi + 8], eax
// 005fd5b6  5b                   pop ebx
// 005fd5b7  c3                   ret 
// library lua-5.1.1/lparser.c (function _checkname)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
