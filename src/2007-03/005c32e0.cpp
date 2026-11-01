// from server: 100% by auto
// roc 2007-03 005c32e0  unit: seg_005c0000  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c32e0
//
// 005c32e0  51                   push ecx
// 005c32e1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005c32e5  8b4808               mov ecx, dword ptr [eax + 8]
// 005c32e8  53                   push ebx
// 005c32e9  8b1c8d00027c00       mov ebx, dword ptr [ecx*4 + 0x7c0200]
// 005c32f0  56                   push esi
// 005c32f1  57                   push edi
// 005c32f2  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005c32f6  8b5714               mov edx, dword ptr [edi + 0x14]
// 005c32f9  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 005c3301  8b0a                 mov ecx, dword ptr [edx]
// 005c3303  8b7208               mov esi, dword ptr [edx + 8]
// 005c3306  3bce                 cmp ecx, esi
// 005c3308  7311                 jae 0x5c331b
// 005c330a  8d9b00000000         lea ebx, [ebx]
// 005c3310  3bc1                 cmp eax, ecx
// 005c3312  7420                 je 0x5c3334
// 005c3314  83c110               add ecx, 0x10
// 005c3317  3bce                 cmp ecx, esi
// 005c3319  72f5                 jb 0x5c3310
// 005c331b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005c331f  53                   push ebx
// 005c3320  51                   push ecx
// 005c3321  689c9a7b00           push 0x7b9a9c
// 005c3326  57                   push edi
// 005c3327  e884fdffff           call 0x5c30b0
// 005c332c  83c410               add esp, 0x10
// 005c332f  5f                   pop edi
// 005c3330  5e                   pop esi
// 005c3331  5b                   pop ebx
// 005c3332  59                   pop ecx
// 005c3333  c3                   ret 
// 005c3334  2b470c               sub eax, dword ptr [edi + 0xc]
// 005c3337  8d4c240c             lea ecx, [esp + 0xc]
// 005c333b  51                   push ecx
// 005c333c  52                   push edx
// 005c333d  c1f804               sar eax, 4
// 005c3340  57                   push edi
// 005c3341  e84afaffff           call 0x5c2d90
// 005c3346  83c40c               add esp, 0xc
// 005c3349  85c0                 test eax, eax
// 005c334b  74ce                 je 0x5c331b
// 005c334d  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005c3351  53                   push ebx
// 005c3352  52                   push edx
// 005c3353  50                   push eax
// 005c3354  8b442428             mov eax, dword ptr [esp + 0x28]
// 005c3358  50                   push eax
// 005c3359  68789a7b00           push 0x7b9a78
// 005c335e  57                   push edi
// 005c335f  e84cfdffff           call 0x5c30b0
// 005c3364  83c418               add esp, 0x18
// 005c3367  5f                   pop edi
// 005c3368  5e                   pop esi
// 005c3369  5b                   pop ebx
// 005c336a  59                   pop ecx
// 005c336b  c3                   ret 
// library lua-5.1.1/ldebug.c (function _luaG_typeerror)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldebug.c
