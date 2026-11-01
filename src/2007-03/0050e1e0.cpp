// from server: 100% by auto
// roc 2007-03 0050e1e0  unit: seg_00500000  size: 646 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050e1e0
//
// 0050e1e0  55                   push ebp
// 0050e1e1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0050e1e5  8a5508               mov dl, byte ptr [ebp + 8]
// 0050e1e8  80fa02               cmp dl, 2
// 0050e1eb  56                   push esi
// 0050e1ec  8b742410             mov esi, dword ptr [esp + 0x10]
// 0050e1f0  57                   push edi
// 0050e1f1  8b7d00               mov edi, dword ptr [ebp]
// 0050e1f4  8bc6                 mov eax, esi
// 0050e1f6  8bce                 mov ecx, esi
// 0050e1f8  0f857e010000         jne 0x50e37c
// 0050e1fe  807d0a04             cmp byte ptr [ebp + 0xa], 4
// 0050e202  0f8574010000         jne 0x50e37c
// 0050e208  807d0908             cmp byte ptr [ebp + 9], 8
// 0050e20c  0f8593000000         jne 0x50e2a5
// 0050e212  f644241880           test byte ptr [esp + 0x18], 0x80
// 0050e217  7448                 je 0x50e261
// 0050e219  83ff01               cmp edi, 1
// 0050e21c  8d5603               lea edx, [esi + 3]
// 0050e21f  8d4604               lea eax, [esi + 4]
// 0050e222  766f                 jbe 0x50e293
// 0050e224  8d77ff               lea esi, [edi - 1]
// 0050e227  0fb608               movzx ecx, byte ptr [eax]
// 0050e22a  880a                 mov byte ptr [edx], cl
// 0050e22c  0fb64801             movzx ecx, byte ptr [eax + 1]
// 0050e230  83c001               add eax, 1
// 0050e233  83c201               add edx, 1
// 0050e236  880a                 mov byte ptr [edx], cl
// 0050e238  0fb64801             movzx ecx, byte ptr [eax + 1]
// 0050e23c  83c001               add eax, 1
// 0050e23f  83c201               add edx, 1
// 0050e242  880a                 mov byte ptr [edx], cl
// 0050e244  83c201               add edx, 1
// 0050e247  83c002               add eax, 2
// 0050e24a  83ee01               sub esi, 1
// 0050e24d  75d8                 jne 0x50e227
// 0050e24f  8d047f               lea eax, [edi + edi*2]
// 0050e252  5f                   pop edi
// 0050e253  5e                   pop esi
// 0050e254  c6450b18             mov byte ptr [ebp + 0xb], 0x18
// 0050e258  894504               mov dword ptr [ebp + 4], eax
// 0050e25b  c6450a03             mov byte ptr [ebp + 0xa], 3
// 0050e25f  5d                   pop ebp
// 0050e260  c3                   ret 
// 0050e261  85ff                 test edi, edi
// 0050e263  762e                 jbe 0x50e293
// 0050e265  8bf7                 mov esi, edi
// 0050e267  0fb65001             movzx edx, byte ptr [eax + 1]
// 0050e26b  83c001               add eax, 1
// 0050e26e  8811                 mov byte ptr [ecx], dl
// 0050e270  0fb65001             movzx edx, byte ptr [eax + 1]
// 0050e274  83c001               add eax, 1
// 0050e277  83c101               add ecx, 1
// 0050e27a  8811                 mov byte ptr [ecx], dl
// 0050e27c  0fb65001             movzx edx, byte ptr [eax + 1]
// 0050e280  83c001               add eax, 1
// 0050e283  83c101               add ecx, 1
// 0050e286  8811                 mov byte ptr [ecx], dl
// 0050e288  83c101               add ecx, 1
// 0050e28b  83c001               add eax, 1
// 0050e28e  83ee01               sub esi, 1
// 0050e291  75d4                 jne 0x50e267
// 0050e293  8d047f               lea eax, [edi + edi*2]
// 0050e296  5f                   pop edi
// 0050e297  5e                   pop esi
// 0050e298  c6450b18             mov byte ptr [ebp + 0xb], 0x18
// 0050e29c  894504               mov dword ptr [ebp + 4], eax
// 0050e29f  c6450a03             mov byte ptr [ebp + 0xa], 3
// 0050e2a3  5d                   pop ebp
// 0050e2a4  c3                   ret 
// 0050e2a5  f644241880           test byte ptr [esp + 0x18], 0x80
// 0050e2aa  7464                 je 0x50e310
// 0050e2ac  83ff01               cmp edi, 1
// 0050e2af  8d5608               lea edx, [esi + 8]
// 0050e2b2  8d4606               lea eax, [esi + 6]
// 0050e2b5  0f86ad000000         jbe 0x50e368
// 0050e2bb  8d77ff               lea esi, [edi - 1]
// 0050e2be  8bff                 mov edi, edi
// 0050e2c0  0fb60a               movzx ecx, byte ptr [edx]
// 0050e2c3  8808                 mov byte ptr [eax], cl
// 0050e2c5  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 0050e2c9  83c201               add edx, 1
// 0050e2cc  884801               mov byte ptr [eax + 1], cl
// 0050e2cf  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 0050e2d3  83c001               add eax, 1
// 0050e2d6  83c201               add edx, 1
// 0050e2d9  884801               mov byte ptr [eax + 1], cl
// 0050e2dc  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 0050e2e0  83c001               add eax, 1
// 0050e2e3  83c201               add edx, 1
// 0050e2e6  83c001               add eax, 1
// 0050e2e9  8808                 mov byte ptr [eax], cl
// 0050e2eb  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 0050e2ef  83c201               add edx, 1
// 0050e2f2  83c001               add eax, 1
// 0050e2f5  8808                 mov byte ptr [eax], cl
// 0050e2f7  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 0050e2fb  83c201               add edx, 1
// 0050e2fe  83c001               add eax, 1
// 0050e301  8808                 mov byte ptr [eax], cl
// 0050e303  83c001               add eax, 1
// 0050e306  83c203               add edx, 3
// 0050e309  83ee01               sub esi, 1
// 0050e30c  75b2                 jne 0x50e2c0
// 0050e30e  eb58                 jmp 0x50e368
// 0050e310  85ff                 test edi, edi
// 0050e312  7654                 jbe 0x50e368
// 0050e314  8bf7                 mov esi, edi
// 0050e316  0fb65002             movzx edx, byte ptr [eax + 2]
// 0050e31a  8811                 mov byte ptr [ecx], dl
// 0050e31c  83c002               add eax, 2
// 0050e31f  0fb65001             movzx edx, byte ptr [eax + 1]
// 0050e323  83c001               add eax, 1
// 0050e326  885101               mov byte ptr [ecx + 1], dl
// 0050e329  0fb65001             movzx edx, byte ptr [eax + 1]
// 0050e32d  83c101               add ecx, 1
// 0050e330  83c001               add eax, 1
// 0050e333  885101               mov byte ptr [ecx + 1], dl
// 0050e336  0fb65001             movzx edx, byte ptr [eax + 1]
// 0050e33a  83c101               add ecx, 1
// 0050e33d  83c001               add eax, 1
// 0050e340  83c101               add ecx, 1
// 0050e343  8811                 mov byte ptr [ecx], dl
// 0050e345  0fb65001             movzx edx, byte ptr [eax + 1]
// 0050e349  83c001               add eax, 1
// 0050e34c  83c101               add ecx, 1
// 0050e34f  8811                 mov byte ptr [ecx], dl
// 0050e351  0fb65001             movzx edx, byte ptr [eax + 1]
// 0050e355  83c001               add eax, 1
// 0050e358  83c101               add ecx, 1
// 0050e35b  8811                 mov byte ptr [ecx], dl
// 0050e35d  83c101               add ecx, 1
// 0050e360  83c001               add eax, 1
// 0050e363  83ee01               sub esi, 1
// 0050e366  75ae                 jne 0x50e316
// 0050e368  8d047f               lea eax, [edi + edi*2]
// 0050e36b  5f                   pop edi
// 0050e36c  03c0                 add eax, eax
// 0050e36e  5e                   pop esi
// 0050e36f  c6450b30             mov byte ptr [ebp + 0xb], 0x30
// 0050e373  894504               mov dword ptr [ebp + 4], eax
// 0050e376  c6450a03             mov byte ptr [ebp + 0xa], 3
// 0050e37a  5d                   pop ebp
// 0050e37b  c3                   ret 
// 0050e37c  84d2                 test dl, dl
// 0050e37e  0f85de000000         jne 0x50e462
// 0050e384  807d0a02             cmp byte ptr [ebp + 0xa], 2
// 0050e388  0f85d4000000         jne 0x50e462
// 0050e38e  b208                 mov dl, 8
// 0050e390  385509               cmp byte ptr [ebp + 9], dl
// 0050e393  7554                 jne 0x50e3e9
// 0050e395  f644241880           test byte ptr [esp + 0x18], 0x80
// 0050e39a  53                   push ebx
// 0050e39b  7424                 je 0x50e3c1
// 0050e39d  85ff                 test edi, edi
// 0050e39f  7639                 jbe 0x50e3da
// 0050e3a1  8bf7                 mov esi, edi
// 0050e3a3  8a18                 mov bl, byte ptr [eax]
// 0050e3a5  8819                 mov byte ptr [ecx], bl
// 0050e3a7  83c101               add ecx, 1
// 0050e3aa  83c002               add eax, 2
// 0050e3ad  83ee01               sub esi, 1
// 0050e3b0  75f1                 jne 0x50e3a3
// 0050e3b2  5b                   pop ebx
// 0050e3b3  897d04               mov dword ptr [ebp + 4], edi
// 0050e3b6  5f                   pop edi
// 0050e3b7  5e                   pop esi
// 0050e3b8  88550b               mov byte ptr [ebp + 0xb], dl
// 0050e3bb  c6450a01             mov byte ptr [ebp + 0xa], 1
// 0050e3bf  5d                   pop ebp
// 0050e3c0  c3                   ret 
// 0050e3c1  85ff                 test edi, edi
// 0050e3c3  7615                 jbe 0x50e3da
// 0050e3c5  8bf7                 mov esi, edi
// 0050e3c7  8a5801               mov bl, byte ptr [eax + 1]
// 0050e3ca  83c001               add eax, 1
// 0050e3cd  8819                 mov byte ptr [ecx], bl
// 0050e3cf  83c101               add ecx, 1
// 0050e3d2  83c001               add eax, 1
// 0050e3d5  83ee01               sub esi, 1
// 0050e3d8  75ed                 jne 0x50e3c7
// 0050e3da  5b                   pop ebx
// 0050e3db  897d04               mov dword ptr [ebp + 4], edi
// 0050e3de  5f                   pop edi
// 0050e3df  5e                   pop esi
// 0050e3e0  88550b               mov byte ptr [ebp + 0xb], dl
// 0050e3e3  c6450a01             mov byte ptr [ebp + 0xa], 1
// 0050e3e7  5d                   pop ebp
// 0050e3e8  c3                   ret 
// 0050e3e9  f644241880           test byte ptr [esp + 0x18], 0x80
// 0050e3ee  743e                 je 0x50e42e
// 0050e3f0  83ff01               cmp edi, 1
// 0050e3f3  8d5604               lea edx, [esi + 4]
// 0050e3f6  8d4602               lea eax, [esi + 2]
// 0050e3f9  7659                 jbe 0x50e454
// 0050e3fb  8d77ff               lea esi, [edi - 1]
// 0050e3fe  8bff                 mov edi, edi
// 0050e400  0fb60a               movzx ecx, byte ptr [edx]
// 0050e403  8808                 mov byte ptr [eax], cl
// 0050e405  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 0050e409  83c201               add edx, 1
// 0050e40c  83c001               add eax, 1
// 0050e40f  8808                 mov byte ptr [eax], cl
// 0050e411  83c001               add eax, 1
// 0050e414  83c203               add edx, 3
// 0050e417  83ee01               sub esi, 1
// 0050e41a  75e4                 jne 0x50e400
// 0050e41c  8d043f               lea eax, [edi + edi]
// 0050e41f  5f                   pop edi
// 0050e420  5e                   pop esi
// 0050e421  c6450b10             mov byte ptr [ebp + 0xb], 0x10
// 0050e425  894504               mov dword ptr [ebp + 4], eax
// 0050e428  c6450a01             mov byte ptr [ebp + 0xa], 1
// 0050e42c  5d                   pop ebp
// 0050e42d  c3                   ret 
// 0050e42e  85ff                 test edi, edi
// 0050e430  7622                 jbe 0x50e454
// 0050e432  8bf7                 mov esi, edi
// 0050e434  0fb65002             movzx edx, byte ptr [eax + 2]
// 0050e438  83c002               add eax, 2
// 0050e43b  8811                 mov byte ptr [ecx], dl
// 0050e43d  0fb65001             movzx edx, byte ptr [eax + 1]
// 0050e441  83c001               add eax, 1
// 0050e444  83c101               add ecx, 1
// 0050e447  8811                 mov byte ptr [ecx], dl
// 0050e449  83c101               add ecx, 1
// 0050e44c  83c001               add eax, 1
// 0050e44f  83ee01               sub esi, 1
// 0050e452  75e0                 jne 0x50e434
// 0050e454  8d043f               lea eax, [edi + edi]
// 0050e457  c6450b10             mov byte ptr [ebp + 0xb], 0x10
// 0050e45b  894504               mov dword ptr [ebp + 4], eax
// 0050e45e  c6450a01             mov byte ptr [ebp + 0xa], 1
// 0050e462  5f                   pop edi
// 0050e463  5e                   pop esi
// 0050e464  5d                   pop ebp
// 0050e465  c3                   ret 
// library libpng-1.2.7/pngtrans.c (function _png_do_strip_filler)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngtrans.c
