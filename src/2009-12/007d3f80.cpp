// from server: 100% by auto
// roc 2009-12 007d3f80  unit: seg_007d0000  size: 254 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d3f80
//
// 007d3f80  83ec30               sub esp, 0x30
// 007d3f83  817b101d010000       cmp dword ptr [ebx + 0x10], 0x11d
// 007d3f8a  55                   push ebp
// 007d3f8b  56                   push esi
// 007d3f8c  57                   push edi
// 007d3f8d  8b7b30               mov edi, dword ptr [ebx + 0x30]
// 007d3f90  7424                 je 0x7d3fb6
// 007d3f92  681d010000           push 0x11d
// 007d3f97  53                   push ebx
// 007d3f98  e8a3120000           call 0x7d5240
// 007d3f9d  50                   push eax
// 007d3f9e  8b4334               mov eax, dword ptr [ebx + 0x34]
// 007d3fa1  68d0ed9e00           push 0x9eedd0
// 007d3fa6  50                   push eax
// 007d3fa7  e8d465fcff           call 0x79a580
// 007d3fac  50                   push eax
// 007d3fad  53                   push ebx
// 007d3fae  e88d130000           call 0x7d5340
// 007d3fb3  83c41c               add esp, 0x1c
// 007d3fb6  8b6b18               mov ebp, dword ptr [ebx + 0x18]
// 007d3fb9  53                   push ebx
// 007d3fba  e871270000           call 0x7d6730
// 007d3fbf  8b7330               mov esi, dword ptr [ebx + 0x30]
// 007d3fc2  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 007d3fc6  41                   inc ecx
// 007d3fc7  83c404               add esp, 4
// 007d3fca  81f9c8000000         cmp ecx, 0xc8
// 007d3fd0  7e0f                 jle 0x7d3fe1
// 007d3fd2  b974ee9e00           mov ecx, 0x9eee74
// 007d3fd7  bac8000000           mov edx, 0xc8
// 007d3fdc  e8afd8ffff           call 0x7d1890
// 007d3fe1  55                   push ebp
// 007d3fe2  53                   push ebx
// 007d3fe3  e8e8d9ffff           call 0x7d19d0
// 007d3fe8  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 007d3fec  66898456ac000000     mov word ptr [esi + edx*2 + 0xac], ax
// 007d3ff4  8b4724               mov eax, dword ptr [edi + 0x24]
// 007d3ff7  83c9ff               or ecx, 0xffffffff
// 007d3ffa  6a01                 push 1
// 007d3ffc  57                   push edi
// 007d3ffd  894c242c             mov dword ptr [esp + 0x2c], ecx
// 007d4001  894c2430             mov dword ptr [esp + 0x30], ecx
// 007d4005  c744241c06000000     mov dword ptr [esp + 0x1c], 6
// 007d400d  89442424             mov dword ptr [esp + 0x24], eax
// 007d4011  e84a810000           call 0x7dc160
// 007d4016  8b4330               mov eax, dword ptr [ebx + 0x30]
// 007d4019  fe4032               inc byte ptr [eax + 0x32]
// 007d401c  0fb64832             movzx ecx, byte ptr [eax + 0x32]
// 007d4020  0fb78c48aa000000     movzx ecx, word ptr [eax + ecx*2 + 0xaa]
// 007d4028  8d1449               lea edx, [ecx + ecx*2]
// 007d402b  8b08                 mov ecx, dword ptr [eax]
// 007d402d  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 007d4030  8b4018               mov eax, dword ptr [eax + 0x18]
// 007d4033  89449104             mov dword ptr [ecx + edx*4 + 4], eax
// 007d4037  8b4b04               mov ecx, dword ptr [ebx + 4]
// 007d403a  51                   push ecx
// 007d403b  8d542438             lea edx, [esp + 0x38]
// 007d403f  6a00                 push 0
// 007d4041  52                   push edx
// 007d4042  8bc3                 mov eax, ebx
// 007d4044  e8a7e6ffff           call 0x7d26f0
// 007d4049  8d442440             lea eax, [esp + 0x40]
// 007d404d  50                   push eax
// 007d404e  8d4c242c             lea ecx, [esp + 0x2c]
// 007d4052  51                   push ecx
// 007d4053  57                   push edi
// 007d4054  e8a78d0000           call 0x7dce00
// 007d4059  0fb65732             movzx edx, byte ptr [edi + 0x32]
// 007d405d  8b0f                 mov ecx, dword ptr [edi]
// 007d405f  0fb78457aa000000     movzx eax, word ptr [edi + edx*2 + 0xaa]
// 007d4067  8b5118               mov edx, dword ptr [ecx + 0x18]
// 007d406a  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 007d406d  83c428               add esp, 0x28
// 007d4070  5f                   pop edi
// 007d4071  8d0440               lea eax, [eax + eax*2]
// 007d4074  5e                   pop esi
// 007d4075  894c8204             mov dword ptr [edx + eax*4 + 4], ecx
// 007d4079  5d                   pop ebp
// 007d407a  83c430               add esp, 0x30
// 007d407d  c3                   ret 
// library lua-5.1/lparser.c (function _localfunc)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
