// from server: 100% by auto
// roc 2009-12 007dcfb0  unit: RBX::GroupDragTool  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dcfb0
//
// 007dcfb0  833f0b               cmp dword ptr [edi], 0xb
// 007dcfb3  7533                 jne 0x7dcfe8
// 007dcfb5  8b0e                 mov ecx, dword ptr [esi]
// 007dcfb7  8b510c               mov edx, dword ptr [ecx + 0xc]
// 007dcfba  8b4708               mov eax, dword ptr [edi + 8]
// 007dcfbd  8b0482               mov eax, dword ptr [edx + eax*4]
// 007dcfc0  8bc8                 mov ecx, eax
// 007dcfc2  83e13f               and ecx, 0x3f
// 007dcfc5  80f913               cmp cl, 0x13
// 007dcfc8  751e                 jne 0x7dcfe8
// 007dcfca  ff4e18               dec dword ptr [esi + 0x18]
// 007dcfcd  33d2                 xor edx, edx
// 007dcfcf  85db                 test ebx, ebx
// 007dcfd1  0f94c2               sete dl
// 007dcfd4  c1e817               shr eax, 0x17
// 007dcfd7  8bce                 mov ecx, esi
// 007dcfd9  52                   push edx
// 007dcfda  50                   push eax
// 007dcfdb  6a1a                 push 0x1a
// 007dcfdd  33c0                 xor eax, eax
// 007dcfdf  e81cf8ffff           call 0x7dc800
// 007dcfe4  83c40c               add esp, 0xc
// 007dcfe7  c3                   ret 
// 007dcfe8  57                   push edi
// 007dcfe9  8bc6                 mov eax, esi
// 007dcfeb  e8a0faffff           call 0x7dca90
// 007dcff0  83c404               add esp, 4
// 007dcff3  833f0c               cmp dword ptr [edi], 0xc
// 007dcff6  7515                 jne 0x7dd00d
// 007dcff8  8b4708               mov eax, dword ptr [edi + 8]
// 007dcffb  a900010000           test eax, 0x100
// 007dd000  750b                 jne 0x7dd00d
// 007dd002  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 007dd006  3bc1                 cmp eax, ecx
// 007dd008  7c03                 jl 0x7dd00d
// 007dd00a  ff4e24               dec dword ptr [esi + 0x24]
// 007dd00d  8b4708               mov eax, dword ptr [edi + 8]
// 007dd010  53                   push ebx
// 007dd011  68ff000000           push 0xff
// 007dd016  6a1b                 push 0x1b
// 007dd018  8bce                 mov ecx, esi
// 007dd01a  e8e1f7ffff           call 0x7dc800
// 007dd01f  83c40c               add esp, 0xc
// 007dd022  c3                   ret 
// library lua-5.1/lcode.c (function _jumponcond)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
