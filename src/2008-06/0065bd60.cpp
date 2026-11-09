// from server: 100% by auto
// roc 2008-06 0065bd60  unit: RBX::BallBallContact  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065bd60
//
// 0065bd60  0fb65004             movzx edx, byte ptr [eax + 4]
// 0065bd64  83c2fc               add edx, -4
// 0065bd67  83fa06               cmp edx, 6
// 0065bd6a  776b                 ja 0x65bdd7
// 0065bd6c  ff2495d8bd6500       jmp dword ptr [edx*4 + 0x65bdd8]
// 0065bd73  50                   push eax
// 0065bd74  51                   push ecx
// 0065bd75  e886390000           call 0x65f700
// 0065bd7a  83c408               add esp, 8
// 0065bd7d  c3                   ret 
// 0065bd7e  50                   push eax
// 0065bd7f  51                   push ecx
// 0065bd80  e81b3a0000           call 0x65f7a0
// 0065bd85  83c408               add esp, 8
// 0065bd88  c3                   ret 
// 0065bd89  50                   push eax
// 0065bd8a  51                   push ecx
// 0065bd8b  e830380000           call 0x65f5c0
// 0065bd90  83c408               add esp, 8
// 0065bd93  c3                   ret 
// 0065bd94  50                   push eax
// 0065bd95  51                   push ecx
// 0065bd96  e8d52b0000           call 0x65e970
// 0065bd9b  83c408               add esp, 8
// 0065bd9e  c3                   ret 
// 0065bd9f  50                   push eax
// 0065bda0  51                   push ecx
// 0065bda1  e8ea7ffcff           call 0x623d90
// 0065bda6  83c408               add esp, 8
// 0065bda9  c3                   ret 
// 0065bdaa  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0065bdad  ff4a04               dec dword ptr [edx + 4]
// 0065bdb0  8b500c               mov edx, dword ptr [eax + 0xc]
// 0065bdb3  6a00                 push 0
// 0065bdb5  83c211               add edx, 0x11
// 0065bdb8  52                   push edx
// 0065bdb9  50                   push eax
// 0065bdba  51                   push ecx
// 0065bdbb  e830490000           call 0x6606f0
// 0065bdc0  83c410               add esp, 0x10
// 0065bdc3  c3                   ret 
// 0065bdc4  8b5010               mov edx, dword ptr [eax + 0x10]
// 0065bdc7  6a00                 push 0
// 0065bdc9  83c218               add edx, 0x18
// 0065bdcc  52                   push edx
// 0065bdcd  50                   push eax
// 0065bdce  51                   push ecx
// 0065bdcf  e81c490000           call 0x6606f0
// 0065bdd4  83c410               add esp, 0x10
// 0065bdd7  c3                   ret 
// 0065bdd8  aa                   stosb byte ptr es:[edi], al
// 0065bdd9  bd650094bd           mov ebp, 0xbd940065
// 0065bdde  65007ebd             add byte ptr gs:[esi - 0x43], bh
// 0065bde2  6500c4               add ah, al
// 0065bde5  bd65009fbd           mov ebp, 0xbd9f0065
// 0065bdea  650073bd             add byte ptr gs:[ebx - 0x43], dh
// library lua-5.1/lgc.c (function _freeobj)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
