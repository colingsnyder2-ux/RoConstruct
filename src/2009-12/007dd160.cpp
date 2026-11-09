// roc 2009-12 007dd160  unit: RBX::GroupDragTool  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dd160
//
// 007dd160  56                   push esi
// 007dd161  57                   push edi
// 007dd162  e819f7ffff           call 0x7dc880
// 007dd167  8b06                 mov eax, dword ptr [esi]
// 007dd169  48                   dec eax
// 007dd16a  83c408               add esp, 8
// 007dd16d  83f80b               cmp eax, 0xb
// 007dd170  776a                 ja 0x7dd1dc
// 007dd172  0fb68014d27d00       movzx eax, byte ptr [eax + 0x7dd214]
// 007dd179  ff248500d27d00       jmp dword ptr [eax*4 + 0x7dd200]
// 007dd180  c70602000000         mov dword ptr [esi], 2
// 007dd186  eb54                 jmp 0x7dd1dc
// 007dd188  c70603000000         mov dword ptr [esi], 3
// 007dd18e  eb4c                 jmp 0x7dd1dc
// 007dd190  8bc6                 mov eax, esi
// 007dd192  8bcf                 mov ecx, edi
// 007dd194  e857f2ffff           call 0x7dc3f0
// 007dd199  eb41                 jmp 0x7dd1dc
// 007dd19b  56                   push esi
// 007dd19c  8bc7                 mov eax, edi
// 007dd19e  e8edf8ffff           call 0x7dca90
// 007dd1a3  83c404               add esp, 4
// 007dd1a6  833e0c               cmp dword ptr [esi], 0xc
// 007dd1a9  7515                 jne 0x7dd1c0
// 007dd1ab  8b4608               mov eax, dword ptr [esi + 8]
// 007dd1ae  a900010000           test eax, 0x100
// 007dd1b3  750b                 jne 0x7dd1c0
// 007dd1b5  0fb64f32             movzx ecx, byte ptr [edi + 0x32]
// 007dd1b9  3bc1                 cmp eax, ecx
// 007dd1bb  7c03                 jl 0x7dd1c0
// 007dd1bd  ff4f24               dec dword ptr [edi + 0x24]
// 007dd1c0  8b5608               mov edx, dword ptr [esi + 8]
// 007dd1c3  6a00                 push 0
// 007dd1c5  52                   push edx
// 007dd1c6  6a00                 push 0
// 007dd1c8  6a13                 push 0x13
// 007dd1ca  57                   push edi
// 007dd1cb  e830f4ffff           call 0x7dc600
// 007dd1d0  83c414               add esp, 0x14
// 007dd1d3  894608               mov dword ptr [esi + 8], eax
// 007dd1d6  c7060b000000         mov dword ptr [esi], 0xb
// 007dd1dc  8b4614               mov eax, dword ptr [esi + 0x14]
// 007dd1df  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007dd1e2  894610               mov dword ptr [esi + 0x10], eax
// 007dd1e5  57                   push edi
// 007dd1e6  8bc1                 mov eax, ecx
// 007dd1e8  894e14               mov dword ptr [esi + 0x14], ecx
// 007dd1eb  e890edffff           call 0x7dbf80
// 007dd1f0  8b4610               mov eax, dword ptr [esi + 0x10]
// 007dd1f3  57                   push edi
// 007dd1f4  e887edffff           call 0x7dbf80
// 007dd1f9  83c408               add esp, 8
// 007dd1fc  c3                   ret 
// 007dd1fd  8d4900               lea ecx, [ecx]
// 007dd200  80d17d               adc cl, 0x7d
// 007dd203  0088d17d0090         add byte ptr [eax - 0x6fff822f], cl
// 007dd209  d17d00               sar dword ptr [ebp], 1
// 007dd20c  9b                   wait 
// 007dd20d  d17d00               sar dword ptr [ebp], 1
// library lua-5.1/lcode.c (function _codenot)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
