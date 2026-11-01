// from server: 100% by auto
// roc 2007-03 00614b10  unit: seg_00610000  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614b10
//
// 00614b10  8b4618               mov eax, dword ptr [esi + 0x18]
// 00614b13  57                   push edi
// 00614b14  8b3e                 mov edi, dword ptr [esi]
// 00614b16  50                   push eax
// 00614b17  68ff000000           push 0xff
// 00614b1c  50                   push eax
// 00614b1d  8b4620               mov eax, dword ptr [esi + 0x20]
// 00614b20  56                   push esi
// 00614b21  e86afaffff           call 0x614590
// 00614b26  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00614b29  8d472c               lea eax, [edi + 0x2c]
// 00614b2c  83c101               add ecx, 1
// 00614b2f  83c410               add esp, 0x10
// 00614b32  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 00614b39  3b08                 cmp ecx, dword ptr [eax]
// 00614b3b  7e20                 jle 0x614b5d
// 00614b3d  8b570c               mov edx, dword ptr [edi + 0xc]
// 00614b40  68b8207c00           push 0x7c20b8
// 00614b45  68fdffff7f           push 0x7ffffffd
// 00614b4a  6a04                 push 4
// 00614b4c  50                   push eax
// 00614b4d  8b4610               mov eax, dword ptr [esi + 0x10]
// 00614b50  52                   push edx
// 00614b51  50                   push eax
// 00614b52  e89988feff           call 0x5fd3f0
// 00614b57  83c418               add esp, 0x18
// 00614b5a  89470c               mov dword ptr [edi + 0xc], eax
// 00614b5d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00614b60  8b442408             mov eax, dword ptr [esp + 8]
// 00614b64  8b570c               mov edx, dword ptr [edi + 0xc]
// 00614b67  89048a               mov dword ptr [edx + ecx*4], eax
// 00614b6a  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00614b6d  8d4730               lea eax, [edi + 0x30]
// 00614b70  83c101               add ecx, 1
// 00614b73  3b08                 cmp ecx, dword ptr [eax]
// 00614b75  7e20                 jle 0x614b97
// 00614b77  8b5714               mov edx, dword ptr [edi + 0x14]
// 00614b7a  68b8207c00           push 0x7c20b8
// 00614b7f  68fdffff7f           push 0x7ffffffd
// 00614b84  6a04                 push 4
// 00614b86  50                   push eax
// 00614b87  8b4610               mov eax, dword ptr [esi + 0x10]
// 00614b8a  52                   push edx
// 00614b8b  50                   push eax
// 00614b8c  e85f88feff           call 0x5fd3f0
// 00614b91  83c418               add esp, 0x18
// 00614b94  894714               mov dword ptr [edi + 0x14], eax
// 00614b97  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00614b9a  8b5714               mov edx, dword ptr [edi + 0x14]
// 00614b9d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00614ba1  89048a               mov dword ptr [edx + ecx*4], eax
// 00614ba4  8b4618               mov eax, dword ptr [esi + 0x18]
// 00614ba7  8d4801               lea ecx, [eax + 1]
// 00614baa  894e18               mov dword ptr [esi + 0x18], ecx
// 00614bad  5f                   pop edi
// 00614bae  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_code)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
