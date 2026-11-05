// from server: 100% by auto
// roc 2010-06 00571ab0  unit: G3D::LineSegment  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00571ab0
//
// 00571ab0  83ec10               sub esp, 0x10
// 00571ab3  55                   push ebp
// 00571ab4  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00571ab8  56                   push esi
// 00571ab9  8b742420             mov esi, dword ptr [esp + 0x20]
// 00571abd  85ed                 test ebp, ebp
// 00571abf  0f8487000000         je 0x571b4c
// 00571ac5  8b556c               mov edx, dword ptr [ebp + 0x6c]
// 00571ac8  f7c200000c00         test edx, 0xc0000
// 00571ace  746e                 je 0x571b3e
// 00571ad0  803e23               cmp byte ptr [esi], 0x23
// 00571ad3  7553                 jne 0x571b28
// 00571ad5  b801000000           mov eax, 1
// 00571ada  b120                 mov cl, 0x20
// 00571adc  8d642400             lea esp, [esp]
// 00571ae0  380c30               cmp byte ptr [eax + esi], cl
// 00571ae3  7411                 je 0x571af6
// 00571ae5  384c3001             cmp byte ptr [eax + esi + 1], cl
// 00571ae9  740a                 je 0x571af5
// 00571aeb  83c002               add eax, 2
// 00571aee  83f80f               cmp eax, 0xf
// 00571af1  7ced                 jl 0x571ae0
// 00571af3  eb01                 jmp 0x571af6
// 00571af5  40                   inc eax
// 00571af6  f7c200000800         test edx, 0x80000
// 00571afc  7426                 je 0x571b24
// 00571afe  57                   push edi
// 00571aff  8d78ff               lea edi, [eax - 1]
// 00571b02  33c9                 xor ecx, ecx
// 00571b04  85ff                 test edi, edi
// 00571b06  7e14                 jle 0x571b1c
// 00571b08  8d4601               lea eax, [esi + 1]
// 00571b0b  57                   push edi
// 00571b0c  50                   push eax
// 00571b0d  8d442414             lea eax, [esp + 0x14]
// 00571b11  50                   push eax
// 00571b12  e80f732300           call 0x7a8e26
// 00571b17  83c40c               add esp, 0xc
// 00571b1a  8bcf                 mov ecx, edi
// 00571b1c  c6440c0b00           mov byte ptr [esp + ecx + 0xb], 0
// 00571b21  5f                   pop edi
// 00571b22  eb16                 jmp 0x571b3a
// 00571b24  03f0                 add esi, eax
// 00571b26  eb16                 jmp 0x571b3e
// 00571b28  f7c200000800         test edx, 0x80000
// 00571b2e  740e                 je 0x571b3e
// 00571b30  c644240830           mov byte ptr [esp + 8], 0x30
// 00571b35  c644240900           mov byte ptr [esp + 9], 0
// 00571b3a  8d742408             lea esi, [esp + 8]
// 00571b3e  8b4540               mov eax, dword ptr [ebp + 0x40]
// 00571b41  85c0                 test eax, eax
// 00571b43  7407                 je 0x571b4c
// 00571b45  56                   push esi
// 00571b46  55                   push ebp
// 00571b47  ffd0                 call eax
// 00571b49  83c408               add esp, 8
// 00571b4c  55                   push ebp
// 00571b4d  8bc6                 mov eax, esi
// 00571b4f  e8fcfcffff           call 0x571850
// 00571b54  83c404               add esp, 4
// 00571b57  5e                   pop esi
// 00571b58  5d                   pop ebp
// 00571b59  83c410               add esp, 0x10
// 00571b5c  c3                   ret 
// library libpng-1.2.32/pngerror.c (function _png_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngerror.c
