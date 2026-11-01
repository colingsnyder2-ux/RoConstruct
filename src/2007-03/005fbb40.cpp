// from server: 100% by auto
// roc 2007-03 005fbb40  unit: seg_005f0000  size: 198 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fbb40
//
// 005fbb40  55                   push ebp
// 005fbb41  8bec                 mov ebp, esp
// 005fbb43  83e4f8               and esp, 0xfffffff8
// 005fbb46  83ec18               sub esp, 0x18
// 005fbb49  8a4b07               mov cl, byte ptr [ebx + 7]
// 005fbb4c  56                   push esi
// 005fbb4d  be01000000           mov esi, 1
// 005fbb52  d3e6                 shl esi, cl
// 005fbb54  57                   push edi
// 005fbb55  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005fbb5d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 005fbb65  85f6                 test esi, esi
// 005fbb67  0f8488000000         je 0x5fbbf5
// 005fbb6d  8bfe                 mov edi, esi
// 005fbb6f  c1e705               shl edi, 5
// 005fbb72  8b4310               mov eax, dword ptr [ebx + 0x10]
// 005fbb75  83ef20               sub edi, 0x20
// 005fbb78  03c7                 add eax, edi
// 005fbb7a  83ee01               sub esi, 1
// 005fbb7d  83780800             cmp dword ptr [eax + 8], 0
// 005fbb81  745b                 je 0x5fbbde
// 005fbb83  83781803             cmp dword ptr [eax + 0x18], 3
// 005fbb87  754a                 jne 0x5fbbd3
// 005fbb89  dd4010               fld qword ptr [eax + 0x10]
// 005fbb8c  dd5c2418             fstp qword ptr [esp + 0x18]
// 005fbb90  dd442418             fld qword ptr [esp + 0x18]
// 005fbb94  db5c2414             fistp dword ptr [esp + 0x14]
// 005fbb98  db442414             fild dword ptr [esp + 0x14]
// 005fbb9c  dc5c2418             fcomp qword ptr [esp + 0x18]
// 005fbba0  dfe0                 fnstsw ax
// 005fbba2  f6c444               test ah, 0x44
// 005fbba5  7a2c                 jp 0x5fbbd3
// 005fbba7  8b442414             mov eax, dword ptr [esp + 0x14]
// 005fbbab  85c0                 test eax, eax
// 005fbbad  7e24                 jle 0x5fbbd3
// 005fbbaf  3d00000004           cmp eax, 0x4000000
// 005fbbb4  7f1d                 jg 0x5fbbd3
// 005fbbb6  83c0ff               add eax, -1
// 005fbbb9  50                   push eax
// 005fbbba  e841c8ffff           call 0x5f8400
// 005fbbbf  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005fbbc2  8d448104             lea eax, [ecx + eax*4 + 4]
// 005fbbc6  83c404               add esp, 4
// 005fbbc9  830001               add dword ptr [eax], 1
// 005fbbcc  b801000000           mov eax, 1
// 005fbbd1  eb02                 jmp 0x5fbbd5
// 005fbbd3  33c0                 xor eax, eax
// 005fbbd5  0144240c             add dword ptr [esp + 0xc], eax
// 005fbbd9  8344241001           add dword ptr [esp + 0x10], 1
// 005fbbde  85f6                 test esi, esi
// 005fbbe0  7590                 jne 0x5fbb72
// 005fbbe2  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005fbbe5  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005fbbe9  0110                 add dword ptr [eax], edx
// 005fbbeb  8b442410             mov eax, dword ptr [esp + 0x10]
// 005fbbef  5f                   pop edi
// 005fbbf0  5e                   pop esi
// 005fbbf1  8be5                 mov esp, ebp
// 005fbbf3  5d                   pop ebp
// 005fbbf4  c3                   ret 
// 005fbbf5  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005fbbf8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005fbbfc  0108                 add dword ptr [eax], ecx
// 005fbbfe  5f                   pop edi
// 005fbbff  8bc1                 mov eax, ecx
// 005fbc01  5e                   pop esi
// 005fbc02  8be5                 mov esp, ebp
// 005fbc04  5d                   pop ebp
// 005fbc05  c3                   ret 
// library lua-5.1.1/ltable.c (function _numusehash)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c
