// from server: 100% by auto
// roc 2009-06 0058b1e0  unit: seg_00580000  size: 324 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058b1e0
//
// 0058b1e0  83ec20               sub esp, 0x20
// 0058b1e3  8b442428             mov eax, dword ptr [esp + 0x28]
// 0058b1e7  55                   push ebp
// 0058b1e8  56                   push esi
// 0058b1e9  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0058b1ed  57                   push edi
// 0058b1ee  33ff                 xor edi, edi
// 0058b1f0  c64424107a           mov byte ptr [esp + 0x10], 0x7a
// 0058b1f5  c644241154           mov byte ptr [esp + 0x11], 0x54
// 0058b1fa  c644241258           mov byte ptr [esp + 0x12], 0x58
// 0058b1ff  c644241374           mov byte ptr [esp + 0x13], 0x74
// 0058b204  c644241400           mov byte ptr [esp + 0x14], 0
// 0058b209  897c2420             mov dword ptr [esp + 0x20], edi
// 0058b20d  897c2424             mov dword ptr [esp + 0x24], edi
// 0058b211  897c2428             mov dword ptr [esp + 0x28], edi
// 0058b215  897c2418             mov dword ptr [esp + 0x18], edi
// 0058b219  897c241c             mov dword ptr [esp + 0x1c], edi
// 0058b21d  3bc7                 cmp eax, edi
// 0058b21f  0f84df000000         je 0x58b304
// 0058b225  8d4c240c             lea ecx, [esp + 0xc]
// 0058b229  51                   push ecx
// 0058b22a  50                   push eax
// 0058b22b  56                   push esi
// 0058b22c  e8effcffff           call 0x58af20
// 0058b231  8be8                 mov ebp, eax
// 0058b233  83c40c               add esp, 0xc
// 0058b236  3bef                 cmp ebp, edi
// 0058b238  0f84c6000000         je 0x58b304
// 0058b23e  8b542438             mov edx, dword ptr [esp + 0x38]
// 0058b242  53                   push ebx
// 0058b243  3bd7                 cmp edx, edi
// 0058b245  0f849a000000         je 0x58b2e5
// 0058b24b  803a00               cmp byte ptr [edx], 0
// 0058b24e  0f8491000000         je 0x58b2e5
// 0058b254  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 0058b258  83fbff               cmp ebx, -1
// 0058b25b  0f8484000000         je 0x58b2e5
// 0058b261  8bc2                 mov eax, edx
// 0058b263  8d7801               lea edi, [eax + 1]
// 0058b266  8a08                 mov cl, byte ptr [eax]
// 0058b268  40                   inc eax
// 0058b269  84c9                 test cl, cl
// 0058b26b  75f9                 jne 0x58b266
// 0058b26d  2bc7                 sub eax, edi
// 0058b26f  8bc8                 mov ecx, eax
// 0058b271  52                   push edx
// 0058b272  8d7c2420             lea edi, [esp + 0x20]
// 0058b276  8bc3                 mov eax, ebx
// 0058b278  8bd6                 mov edx, esi
// 0058b27a  e831f7ffff           call 0x58a9b0
// 0058b27f  8d542802             lea edx, [eax + ebp + 2]
// 0058b283  52                   push edx
// 0058b284  8d44241c             lea eax, [esp + 0x1c]
// 0058b288  50                   push eax
// 0058b289  56                   push esi
// 0058b28a  e831f6ffff           call 0x58a8c0
// 0058b28f  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0058b293  45                   inc ebp
// 0058b294  55                   push ebp
// 0058b295  57                   push edi
// 0058b296  56                   push esi
// 0058b297  e894f6ffff           call 0x58a930
// 0058b29c  57                   push edi
// 0058b29d  56                   push esi
// 0058b29e  e80d3a0000           call 0x58ecb0
// 0058b2a3  83c424               add esp, 0x24
// 0058b2a6  885c2438             mov byte ptr [esp + 0x38], bl
// 0058b2aa  85f6                 test esi, esi
// 0058b2ac  741d                 je 0x58b2cb
// 0058b2ae  6a01                 push 1
// 0058b2b0  8d4c243c             lea ecx, [esp + 0x3c]
// 0058b2b4  51                   push ecx
// 0058b2b5  56                   push esi
// 0058b2b6  e82563ffff           call 0x5815e0
// 0058b2bb  6a01                 push 1
// 0058b2bd  8d542448             lea edx, [esp + 0x48]
// 0058b2c1  52                   push edx
// 0058b2c2  56                   push esi
// 0058b2c3  e8f865ffff           call 0x5818c0
// 0058b2c8  83c418               add esp, 0x18
// 0058b2cb  8d44241c             lea eax, [esp + 0x1c]
// 0058b2cf  e85cf9ffff           call 0x58ac30
// 0058b2d4  56                   push esi
// 0058b2d5  e896f6ffff           call 0x58a970
// 0058b2da  83c404               add esp, 4
// 0058b2dd  5b                   pop ebx
// 0058b2de  5f                   pop edi
// 0058b2df  5e                   pop esi
// 0058b2e0  5d                   pop ebp
// 0058b2e1  83c420               add esp, 0x20
// 0058b2e4  c3                   ret 
// 0058b2e5  57                   push edi
// 0058b2e6  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0058b2ea  52                   push edx
// 0058b2eb  57                   push edi
// 0058b2ec  56                   push esi
// 0058b2ed  e80efeffff           call 0x58b100
// 0058b2f2  57                   push edi
// 0058b2f3  56                   push esi
// 0058b2f4  e8b7390000           call 0x58ecb0
// 0058b2f9  83c418               add esp, 0x18
// 0058b2fc  5b                   pop ebx
// 0058b2fd  5f                   pop edi
// 0058b2fe  5e                   pop esi
// 0058b2ff  5d                   pop ebp
// 0058b300  83c420               add esp, 0x20
// 0058b303  c3                   ret 
// 0058b304  68f4ec8c00           push 0x8cecf4
// 0058b309  56                   push esi
// 0058b30a  e8012f0000           call 0x58e210
// 0058b30f  8b442414             mov eax, dword ptr [esp + 0x14]
// 0058b313  50                   push eax
// 0058b314  56                   push esi
// 0058b315  e896390000           call 0x58ecb0
// 0058b31a  83c410               add esp, 0x10
// 0058b31d  5f                   pop edi
// 0058b31e  5e                   pop esi
// 0058b31f  5d                   pop ebp
// 0058b320  83c420               add esp, 0x20
// 0058b323  c3                   ret 
// library libpng-1.2.32/pngwutil.c (function _png_write_zTXt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngwutil.c
