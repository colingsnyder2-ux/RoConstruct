// from server: 100% by auto
// roc 2009-12 006025d0  unit: G3D::_internal::DialogTemplate  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006025d0
//
// 006025d0  57                   push edi
// 006025d1  8b7c2408             mov edi, dword ptr [esp + 8]
// 006025d5  85ff                 test edi, edi
// 006025d7  0f84b1000000         je 0x60268e
// 006025dd  56                   push esi
// 006025de  8b742410             mov esi, dword ptr [esp + 0x10]
// 006025e2  85f6                 test esi, esi
// 006025e4  0f84a3000000         je 0x60268d
// 006025ea  0fb74614             movzx eax, word ptr [esi + 0x14]
// 006025ee  6685c0               test ax, ax
// 006025f1  0f8488000000         je 0x60267f
// 006025f7  b900010000           mov ecx, 0x100
// 006025fc  663bc1               cmp ax, cx
// 006025ff  777e                 ja 0x60267f
// 00602601  6a00                 push 0
// 00602603  6a08                 push 8
// 00602605  56                   push esi
// 00602606  57                   push edi
// 00602607  e8b4100000           call 0x6036c0
// 0060260c  6800020000           push 0x200
// 00602611  57                   push edi
// 00602612  e8f9e60000           call 0x610d10
// 00602617  83c418               add esp, 0x18
// 0060261a  8987f4010000         mov dword ptr [edi + 0x1f4], eax
// 00602620  85c0                 test eax, eax
// 00602622  7511                 jne 0x602635
// 00602624  68dc339c00           push 0x9c33dc
// 00602629  57                   push edi
// 0060262a  e811dc0000           call 0x610240
// 0060262f  83c408               add esp, 8
// 00602632  5e                   pop esi
// 00602633  5f                   pop edi
// 00602634  c3                   ret 
// 00602635  33d2                 xor edx, edx
// 00602637  33c0                 xor eax, eax
// 00602639  663b5614             cmp dx, word ptr [esi + 0x14]
// 0060263d  7329                 jae 0x602668
// 0060263f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00602643  53                   push ebx
// 00602644  eb0a                 jmp 0x602650
// 00602646  8da42400000000       lea esp, [esp]
// 0060264d  8d4900               lea ecx, [ecx]
// 00602650  8b97f4010000         mov edx, dword ptr [edi + 0x1f4]
// 00602656  668b1c41             mov bx, word ptr [ecx + eax*2]
// 0060265a  66891c42             mov word ptr [edx + eax*2], bx
// 0060265e  0fb75614             movzx edx, word ptr [esi + 0x14]
// 00602662  40                   inc eax
// 00602663  3bc2                 cmp eax, edx
// 00602665  7ce9                 jl 0x602650
// 00602667  5b                   pop ebx
// 00602668  8b87f4010000         mov eax, dword ptr [edi + 0x1f4]
// 0060266e  834e0840             or dword ptr [esi + 8], 0x40
// 00602672  838eb800000008       or dword ptr [esi + 0xb8], 8
// 00602679  89467c               mov dword ptr [esi + 0x7c], eax
// 0060267c  5e                   pop esi
// 0060267d  5f                   pop edi
// 0060267e  c3                   ret 
// 0060267f  68ac339c00           push 0x9c33ac
// 00602684  57                   push edi
// 00602685  e8b6db0000           call 0x610240
// 0060268a  83c408               add esp, 8
// 0060268d  5e                   pop esi
// 0060268e  5f                   pop edi
// 0060268f  c3                   ret 
// library libpng-1.2.22/pngset.c (function _png_set_hIST)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngset.c
