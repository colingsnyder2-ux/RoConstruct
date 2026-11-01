// from server: 100% by auto
// roc 2007-03 005ffb70  unit: seg_005f0000  size: 257 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ffb70
//
// 005ffb70  83ec30               sub esp, 0x30
// 005ffb73  817b101d010000       cmp dword ptr [ebx + 0x10], 0x11d
// 005ffb7a  55                   push ebp
// 005ffb7b  56                   push esi
// 005ffb7c  57                   push edi
// 005ffb7d  8b7b30               mov edi, dword ptr [ebx + 0x30]
// 005ffb80  7424                 je 0x5ffba6
// 005ffb82  681d010000           push 0x11d
// 005ffb87  53                   push ebx
// 005ffb88  e8e3120000           call 0x600e70
// 005ffb8d  50                   push eax
// 005ffb8e  8b4334               mov eax, dword ptr [ebx + 0x34]
// 005ffb91  6828047c00           push 0x7c0428
// 005ffb96  50                   push eax
// 005ffb97  e8a48cffff           call 0x5f8840
// 005ffb9c  50                   push eax
// 005ffb9d  53                   push ebx
// 005ffb9e  e8cd130000           call 0x600f70
// 005ffba3  83c41c               add esp, 0x1c
// 005ffba6  8b6b18               mov ebp, dword ptr [ebx + 0x18]
// 005ffba9  53                   push ebx
// 005ffbaa  e8f1270000           call 0x6023a0
// 005ffbaf  8b7330               mov esi, dword ptr [ebx + 0x30]
// 005ffbb2  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 005ffbb6  83c101               add ecx, 1
// 005ffbb9  83c404               add esp, 4
// 005ffbbc  81f9c8000000         cmp ecx, 0xc8
// 005ffbc2  7e0f                 jle 0x5ffbd3
// 005ffbc4  b9cc047c00           mov ecx, 0x7c04cc
// 005ffbc9  bac8000000           mov edx, 0xc8
// 005ffbce  e8add8ffff           call 0x5fd480
// 005ffbd3  55                   push ebp
// 005ffbd4  53                   push ebx
// 005ffbd5  e8e6d9ffff           call 0x5fd5c0
// 005ffbda  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 005ffbde  66898456ac000000     mov word ptr [esi + edx*2 + 0xac], ax
// 005ffbe6  8b4724               mov eax, dword ptr [edi + 0x24]
// 005ffbe9  83c9ff               or ecx, 0xffffffff
// 005ffbec  6a01                 push 1
// 005ffbee  57                   push edi
// 005ffbef  894c242c             mov dword ptr [esp + 0x2c], ecx
// 005ffbf3  894c2430             mov dword ptr [esp + 0x30], ecx
// 005ffbf7  c744241c06000000     mov dword ptr [esp + 0x1c], 6
// 005ffbff  89442424             mov dword ptr [esp + 0x24], eax
// 005ffc03  e8d84a0100           call 0x6146e0
// 005ffc08  8b4330               mov eax, dword ptr [ebx + 0x30]
// 005ffc0b  80403201             add byte ptr [eax + 0x32], 1
// 005ffc0f  0fb64832             movzx ecx, byte ptr [eax + 0x32]
// 005ffc13  0fb78c48aa000000     movzx ecx, word ptr [eax + ecx*2 + 0xaa]
// 005ffc1b  8d1449               lea edx, [ecx + ecx*2]
// 005ffc1e  8b08                 mov ecx, dword ptr [eax]
// 005ffc20  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005ffc23  8b4018               mov eax, dword ptr [eax + 0x18]
// 005ffc26  89449104             mov dword ptr [ecx + edx*4 + 4], eax
// 005ffc2a  8b4b04               mov ecx, dword ptr [ebx + 4]
// 005ffc2d  51                   push ecx
// 005ffc2e  8d542438             lea edx, [esp + 0x38]
// 005ffc32  6a00                 push 0
// 005ffc34  52                   push edx
// 005ffc35  8bc3                 mov eax, ebx
// 005ffc37  e8d4e6ffff           call 0x5fe310
// 005ffc3c  8d442440             lea eax, [esp + 0x40]
// 005ffc40  50                   push eax
// 005ffc41  8d4c242c             lea ecx, [esp + 0x2c]
// 005ffc45  51                   push ecx
// 005ffc46  57                   push edi
// 005ffc47  e864570100           call 0x6153b0
// 005ffc4c  0fb65732             movzx edx, byte ptr [edi + 0x32]
// 005ffc50  8b0f                 mov ecx, dword ptr [edi]
// 005ffc52  0fb78457aa000000     movzx eax, word ptr [edi + edx*2 + 0xaa]
// 005ffc5a  8b5118               mov edx, dword ptr [ecx + 0x18]
// 005ffc5d  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005ffc60  83c428               add esp, 0x28
// 005ffc63  5f                   pop edi
// 005ffc64  8d0440               lea eax, [eax + eax*2]
// 005ffc67  5e                   pop esi
// 005ffc68  894c8204             mov dword ptr [edx + eax*4 + 4], ecx
// 005ffc6c  5d                   pop ebp
// 005ffc6d  83c430               add esp, 0x30
// 005ffc70  c3                   ret 
// library lua-5.1.1/lparser.c (function _localfunc)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
