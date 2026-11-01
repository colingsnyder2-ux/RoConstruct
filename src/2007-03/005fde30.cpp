// from server: 100% by auto
// roc 2007-03 005fde30  unit: seg_005f0000  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fde30
//
// 005fde30  83ec34               sub esp, 0x34
// 005fde33  817b101d010000       cmp dword ptr [ebx + 0x10], 0x11d
// 005fde3a  55                   push ebp
// 005fde3b  8b6b30               mov ebp, dword ptr [ebx + 0x30]
// 005fde3e  8b4524               mov eax, dword ptr [ebp + 0x24]
// 005fde41  56                   push esi
// 005fde42  57                   push edi
// 005fde43  8944240c             mov dword ptr [esp + 0xc], eax
// 005fde47  7527                 jne 0x5fde70
// 005fde49  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 005fde4d  bafdffff7f           mov edx, 0x7ffffffd
// 005fde52  39511c               cmp dword ptr [ecx + 0x1c], edx
// 005fde55  7e0c                 jle 0x5fde63
// 005fde57  b924057c00           mov ecx, 0x7c0524
// 005fde5c  8bf5                 mov esi, ebp
// 005fde5e  e81df6ffff           call 0x5fd480
// 005fde63  8d7c2410             lea edi, [esp + 0x10]
// 005fde67  8bf3                 mov esi, ebx
// 005fde69  e8f2f6ffff           call 0x5fd560
// 005fde6e  eb0b                 jmp 0x5fde7b
// 005fde70  8d7c2410             lea edi, [esp + 0x10]
// 005fde74  8bf3                 mov esi, ebx
// 005fde76  e865ffffff           call 0x5fdde0
// 005fde7b  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 005fde7f  83471c01             add dword ptr [edi + 0x1c], 1
// 005fde83  837b103d             cmp dword ptr [ebx + 0x10], 0x3d
// 005fde87  7421                 je 0x5fdeaa
// 005fde89  6a3d                 push 0x3d
// 005fde8b  53                   push ebx
// 005fde8c  e8df2f0000           call 0x600e70
// 005fde91  8b5334               mov edx, dword ptr [ebx + 0x34]
// 005fde94  50                   push eax
// 005fde95  6828047c00           push 0x7c0428
// 005fde9a  52                   push edx
// 005fde9b  e8a0a9ffff           call 0x5f8840
// 005fdea0  50                   push eax
// 005fdea1  53                   push ebx
// 005fdea2  e8c9300000           call 0x600f70
// 005fdea7  83c41c               add esp, 0x1c
// 005fdeaa  53                   push ebx
// 005fdeab  e8f0440000           call 0x6023a0
// 005fdeb0  8d442414             lea eax, [esp + 0x14]
// 005fdeb4  50                   push eax
// 005fdeb5  55                   push ebp
// 005fdeb6  e8f5730100           call 0x6152b0
// 005fdebb  6a00                 push 0
// 005fdebd  8d4c2438             lea ecx, [esp + 0x38]
// 005fdec1  51                   push ecx
// 005fdec2  53                   push ebx
// 005fdec3  8bf0                 mov esi, eax
// 005fdec5  e8060e0000           call 0x5fecd0
// 005fdeca  8d542440             lea edx, [esp + 0x40]
// 005fdece  52                   push edx
// 005fdecf  55                   push ebp
// 005fded0  e8db730100           call 0x6152b0
// 005fded5  50                   push eax
// 005fded6  8b4718               mov eax, dword ptr [edi + 0x18]
// 005fded9  8b4808               mov ecx, dword ptr [eax + 8]
// 005fdedc  56                   push esi
// 005fdedd  51                   push ecx
// 005fdede  6a09                 push 9
// 005fdee0  55                   push ebp
// 005fdee1  e8ca6c0100           call 0x614bb0
// 005fdee6  8b542440             mov edx, dword ptr [esp + 0x40]
// 005fdeea  83c434               add esp, 0x34
// 005fdeed  5f                   pop edi
// 005fdeee  5e                   pop esi
// 005fdeef  895524               mov dword ptr [ebp + 0x24], edx
// 005fdef2  5d                   pop ebp
// 005fdef3  83c434               add esp, 0x34
// 005fdef6  c3                   ret 
// library lua-5.1.1/lparser.c (function _recfield)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
