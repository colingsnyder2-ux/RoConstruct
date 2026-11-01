// from server: 100% by auto
// roc 2007-03 00615560  unit: seg_00610000  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00615560
//
// 00615560  833f0b               cmp dword ptr [edi], 0xb
// 00615563  7534                 jne 0x615599
// 00615565  8b0e                 mov ecx, dword ptr [esi]
// 00615567  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0061556a  8b4708               mov eax, dword ptr [edi + 8]
// 0061556d  8b0482               mov eax, dword ptr [edx + eax*4]
// 00615570  8bc8                 mov ecx, eax
// 00615572  83e13f               and ecx, 0x3f
// 00615575  80f913               cmp cl, 0x13
// 00615578  751f                 jne 0x615599
// 0061557a  834618ff             add dword ptr [esi + 0x18], -1
// 0061557e  33d2                 xor edx, edx
// 00615580  85db                 test ebx, ebx
// 00615582  0f94c2               sete dl
// 00615585  c1e817               shr eax, 0x17
// 00615588  8bce                 mov ecx, esi
// 0061558a  52                   push edx
// 0061558b  50                   push eax
// 0061558c  6a1a                 push 0x1a
// 0061558e  33c0                 xor eax, eax
// 00615590  e81bf8ffff           call 0x614db0
// 00615595  83c40c               add esp, 0xc
// 00615598  c3                   ret 
// 00615599  57                   push edi
// 0061559a  8bc6                 mov eax, esi
// 0061559c  e89ffaffff           call 0x615040
// 006155a1  83c404               add esp, 4
// 006155a4  833f0c               cmp dword ptr [edi], 0xc
// 006155a7  7516                 jne 0x6155bf
// 006155a9  8b4708               mov eax, dword ptr [edi + 8]
// 006155ac  a900010000           test eax, 0x100
// 006155b1  750c                 jne 0x6155bf
// 006155b3  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 006155b7  3bc1                 cmp eax, ecx
// 006155b9  7c04                 jl 0x6155bf
// 006155bb  834624ff             add dword ptr [esi + 0x24], -1
// 006155bf  8b4708               mov eax, dword ptr [edi + 8]
// 006155c2  53                   push ebx
// 006155c3  68ff000000           push 0xff
// 006155c8  6a1b                 push 0x1b
// 006155ca  8bce                 mov ecx, esi
// 006155cc  e8dff7ffff           call 0x614db0
// 006155d1  83c40c               add esp, 0xc
// 006155d4  c3                   ret 
// library lua-5.1.1/lcode.c (function _jumponcond)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
