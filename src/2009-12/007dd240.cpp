// from server: 100% by auto
// roc 2009-12 007dd240  unit: RBX::GroupDragTool  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dd240
//
// 007dd240  8b442404             mov eax, dword ptr [esp + 4]
// 007dd244  55                   push ebp
// 007dd245  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007dd249  56                   push esi
// 007dd24a  50                   push eax
// 007dd24b  8bc5                 mov eax, ebp
// 007dd24d  8bf3                 mov esi, ebx
// 007dd24f  e8ecf1ffff           call 0x7dc440
// 007dd254  83c404               add esp, 4
// 007dd257  85c0                 test eax, eax
// 007dd259  0f85c6000000         jne 0x7dd325
// 007dd25f  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007dd263  83f812               cmp eax, 0x12
// 007dd266  7413                 je 0x7dd27b
// 007dd268  83f814               cmp eax, 0x14
// 007dd26b  740e                 je 0x7dd27b
// 007dd26d  55                   push ebp
// 007dd26e  57                   push edi
// 007dd26f  e88cfaffff           call 0x7dcd00
// 007dd274  83c408               add esp, 8
// 007dd277  8bf0                 mov esi, eax
// 007dd279  eb02                 jmp 0x7dd27d
// 007dd27b  33f6                 xor esi, esi
// 007dd27d  53                   push ebx
// 007dd27e  57                   push edi
// 007dd27f  e87cfaffff           call 0x7dcd00
// 007dd284  83c408               add esp, 8
// 007dd287  3bc6                 cmp eax, esi
// 007dd289  7e39                 jle 0x7dd2c4
// 007dd28b  833b0c               cmp dword ptr [ebx], 0xc
// 007dd28e  7516                 jne 0x7dd2a6
// 007dd290  8b4b08               mov ecx, dword ptr [ebx + 8]
// 007dd293  f7c100010000         test ecx, 0x100
// 007dd299  750b                 jne 0x7dd2a6
// 007dd29b  0fb65732             movzx edx, byte ptr [edi + 0x32]
// 007dd29f  3bca                 cmp ecx, edx
// 007dd2a1  7c03                 jl 0x7dd2a6
// 007dd2a3  ff4f24               dec dword ptr [edi + 0x24]
// 007dd2a6  837d000c             cmp dword ptr [ebp], 0xc
// 007dd2aa  7552                 jne 0x7dd2fe
// 007dd2ac  8b6d08               mov ebp, dword ptr [ebp + 8]
// 007dd2af  f7c500010000         test ebp, 0x100
// 007dd2b5  7547                 jne 0x7dd2fe
// 007dd2b7  0fb64f32             movzx ecx, byte ptr [edi + 0x32]
// 007dd2bb  3be9                 cmp ebp, ecx
// 007dd2bd  7c3f                 jl 0x7dd2fe
// 007dd2bf  ff4f24               dec dword ptr [edi + 0x24]
// 007dd2c2  eb3a                 jmp 0x7dd2fe
// 007dd2c4  83caff               or edx, 0xffffffff
// 007dd2c7  837d000c             cmp dword ptr [ebp], 0xc
// 007dd2cb  7516                 jne 0x7dd2e3
// 007dd2cd  8b6d08               mov ebp, dword ptr [ebp + 8]
// 007dd2d0  f7c500010000         test ebp, 0x100
// 007dd2d6  750b                 jne 0x7dd2e3
// 007dd2d8  0fb64f32             movzx ecx, byte ptr [edi + 0x32]
// 007dd2dc  3be9                 cmp ebp, ecx
// 007dd2de  7c03                 jl 0x7dd2e3
// 007dd2e0  015724               add dword ptr [edi + 0x24], edx
// 007dd2e3  833b0c               cmp dword ptr [ebx], 0xc
// 007dd2e6  7516                 jne 0x7dd2fe
// 007dd2e8  8b4b08               mov ecx, dword ptr [ebx + 8]
// 007dd2eb  f7c100010000         test ecx, 0x100
// 007dd2f1  750b                 jne 0x7dd2fe
// 007dd2f3  0fb66f32             movzx ebp, byte ptr [edi + 0x32]
// 007dd2f7  3bcd                 cmp ecx, ebp
// 007dd2f9  7c03                 jl 0x7dd2fe
// 007dd2fb  015724               add dword ptr [edi + 0x24], edx
// 007dd2fe  8b570c               mov edx, dword ptr [edi + 0xc]
// 007dd301  8b4a08               mov ecx, dword ptr [edx + 8]
// 007dd304  c1e009               shl eax, 9
// 007dd307  0bc6                 or eax, esi
// 007dd309  c1e00e               shl eax, 0xe
// 007dd30c  0b44240c             or eax, dword ptr [esp + 0xc]
// 007dd310  51                   push ecx
// 007dd311  50                   push eax
// 007dd312  8bf7                 mov esi, edi
// 007dd314  e847f2ffff           call 0x7dc560
// 007dd319  83c408               add esp, 8
// 007dd31c  894308               mov dword ptr [ebx + 8], eax
// 007dd31f  c7030b000000         mov dword ptr [ebx], 0xb
// 007dd325  5e                   pop esi
// 007dd326  5d                   pop ebp
// 007dd327  c3                   ret 
// library lua-5.1.2/lcode.c (function _codearith)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lcode.c
