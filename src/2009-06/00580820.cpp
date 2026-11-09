// from server: 100% by auto
// roc 2009-06 00580820  unit: G3D::_internal::DialogTemplate  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00580820
//
// 00580820  57                   push edi
// 00580821  8b7c2408             mov edi, dword ptr [esp + 8]
// 00580825  85ff                 test edi, edi
// 00580827  0f84b1000000         je 0x5808de
// 0058082d  56                   push esi
// 0058082e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00580832  85f6                 test esi, esi
// 00580834  0f84a3000000         je 0x5808dd
// 0058083a  0fb74614             movzx eax, word ptr [esi + 0x14]
// 0058083e  6685c0               test ax, ax
// 00580841  0f8488000000         je 0x5808cf
// 00580847  b900010000           mov ecx, 0x100
// 0058084c  663bc1               cmp ax, cx
// 0058084f  777e                 ja 0x5808cf
// 00580851  6a00                 push 0
// 00580853  6a08                 push 8
// 00580855  56                   push esi
// 00580856  57                   push edi
// 00580857  e8b4100000           call 0x581910
// 0058085c  6800020000           push 0x200
// 00580861  57                   push edi
// 00580862  e879e40000           call 0x58ece0
// 00580867  83c418               add esp, 0x18
// 0058086a  8987f4010000         mov dword ptr [edi + 0x1f4], eax
// 00580870  85c0                 test eax, eax
// 00580872  7511                 jne 0x580885
// 00580874  683cc58c00           push 0x8cc53c
// 00580879  57                   push edi
// 0058087a  e891d90000           call 0x58e210
// 0058087f  83c408               add esp, 8
// 00580882  5e                   pop esi
// 00580883  5f                   pop edi
// 00580884  c3                   ret 
// 00580885  33d2                 xor edx, edx
// 00580887  33c0                 xor eax, eax
// 00580889  663b5614             cmp dx, word ptr [esi + 0x14]
// 0058088d  7329                 jae 0x5808b8
// 0058088f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00580893  53                   push ebx
// 00580894  eb0a                 jmp 0x5808a0
// 00580896  8da42400000000       lea esp, [esp]
// 0058089d  8d4900               lea ecx, [ecx]
// 005808a0  8b97f4010000         mov edx, dword ptr [edi + 0x1f4]
// 005808a6  668b1c41             mov bx, word ptr [ecx + eax*2]
// 005808aa  66891c42             mov word ptr [edx + eax*2], bx
// 005808ae  0fb75614             movzx edx, word ptr [esi + 0x14]
// 005808b2  40                   inc eax
// 005808b3  3bc2                 cmp eax, edx
// 005808b5  7ce9                 jl 0x5808a0
// 005808b7  5b                   pop ebx
// 005808b8  8b87f4010000         mov eax, dword ptr [edi + 0x1f4]
// 005808be  834e0840             or dword ptr [esi + 8], 0x40
// 005808c2  838eb800000008       or dword ptr [esi + 0xb8], 8
// 005808c9  89467c               mov dword ptr [esi + 0x7c], eax
// 005808cc  5e                   pop esi
// 005808cd  5f                   pop edi
// 005808ce  c3                   ret 
// 005808cf  680cc58c00           push 0x8cc50c
// 005808d4  57                   push edi
// 005808d5  e836d90000           call 0x58e210
// 005808da  83c408               add esp, 8
// 005808dd  5e                   pop esi
// 005808de  5f                   pop edi
// 005808df  c3                   ret 
// library libpng-1.2.22/pngset.c (function _png_set_hIST)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngset.c
