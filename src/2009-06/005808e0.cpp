// from server: 100% by auto
// roc 2009-06 005808e0  unit: G3D::_internal::DialogTemplate  size: 549 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005808e0
//
// 005808e0  57                   push edi
// 005808e1  8b7c2408             mov edi, dword ptr [esp + 8]
// 005808e5  85ff                 test edi, edi
// 005808e7  0f8416020000         je 0x580b03
// 005808ed  56                   push esi
// 005808ee  8b742410             mov esi, dword ptr [esp + 0x10]
// 005808f2  85f6                 test esi, esi
// 005808f4  0f8408020000         je 0x580b02
// 005808fa  53                   push ebx
// 005808fb  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 005808ff  55                   push ebp
// 00580900  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00580904  85ed                 test ebp, ebp
// 00580906  7404                 je 0x58090c
// 00580908  85db                 test ebx, ebx
// 0058090a  750e                 jne 0x58091a
// 0058090c  68d0c68c00           push 0x8cc6d0
// 00580911  57                   push edi
// 00580912  e849d80000           call 0x58e160
// 00580917  83c408               add esp, 8
// 0058091a  3baf64020000         cmp ebp, dword ptr [edi + 0x264]
// 00580920  7708                 ja 0x58092a
// 00580922  3b9f68020000         cmp ebx, dword ptr [edi + 0x268]
// 00580928  760e                 jbe 0x580938
// 0058092a  68a8c68c00           push 0x8cc6a8
// 0058092f  57                   push edi
// 00580930  e82bd80000           call 0x58e160
// 00580935  83c408               add esp, 8
// 00580938  81fdffffff7f         cmp ebp, 0x7fffffff
// 0058093e  7708                 ja 0x580948
// 00580940  81fbffffff7f         cmp ebx, 0x7fffffff
// 00580946  760e                 jbe 0x580956
// 00580948  688cc68c00           push 0x8cc68c
// 0058094d  57                   push edi
// 0058094e  e80dd80000           call 0x58e160
// 00580953  83c408               add esp, 8
// 00580956  81fd7effff1f         cmp ebp, 0x1fffff7e
// 0058095c  760e                 jbe 0x58096c
// 0058095e  685cc68c00           push 0x8cc65c
// 00580963  57                   push edi
// 00580964  e8a7d80000           call 0x58e210
// 00580969  83c408               add esp, 8
// 0058096c  8b442424             mov eax, dword ptr [esp + 0x24]
// 00580970  83f801               cmp eax, 1
// 00580973  7422                 je 0x580997
// 00580975  83f802               cmp eax, 2
// 00580978  741d                 je 0x580997
// 0058097a  83f804               cmp eax, 4
// 0058097d  7418                 je 0x580997
// 0058097f  83f808               cmp eax, 8
// 00580982  7413                 je 0x580997
// 00580984  83f810               cmp eax, 0x10
// 00580987  740e                 je 0x580997
// 00580989  6840c68c00           push 0x8cc640
// 0058098e  57                   push edi
// 0058098f  e8ccd70000           call 0x58e160
// 00580994  83c408               add esp, 8
// 00580997  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0058099b  85db                 test ebx, ebx
// 0058099d  7c0f                 jl 0x5809ae
// 0058099f  83fb01               cmp ebx, 1
// 005809a2  740a                 je 0x5809ae
// 005809a4  83fb05               cmp ebx, 5
// 005809a7  7405                 je 0x5809ae
// 005809a9  83fb06               cmp ebx, 6
// 005809ac  7e0e                 jle 0x5809bc
// 005809ae  6824c68c00           push 0x8cc624
// 005809b3  57                   push edi
// 005809b4  e8a7d70000           call 0x58e160
// 005809b9  83c408               add esp, 8
// 005809bc  83fb03               cmp ebx, 3
// 005809bf  7509                 jne 0x5809ca
// 005809c1  837c242408           cmp dword ptr [esp + 0x24], 8
// 005809c6  7f18                 jg 0x5809e0
// 005809c8  eb24                 jmp 0x5809ee
// 005809ca  83fb02               cmp ebx, 2
// 005809cd  740a                 je 0x5809d9
// 005809cf  83fb04               cmp ebx, 4
// 005809d2  7405                 je 0x5809d9
// 005809d4  83fb06               cmp ebx, 6
// 005809d7  7515                 jne 0x5809ee
// 005809d9  837c242408           cmp dword ptr [esp + 0x24], 8
// 005809de  7d0e                 jge 0x5809ee
// 005809e0  68f0c58c00           push 0x8cc5f0
// 005809e5  57                   push edi
// 005809e6  e875d70000           call 0x58e160
// 005809eb  83c408               add esp, 8
// 005809ee  837c242c02           cmp dword ptr [esp + 0x2c], 2
// 005809f3  7c0e                 jl 0x580a03
// 005809f5  68ccc58c00           push 0x8cc5cc
// 005809fa  57                   push edi
// 005809fb  e860d70000           call 0x58e160
// 00580a00  83c408               add esp, 8
// 00580a03  837c243000           cmp dword ptr [esp + 0x30], 0
// 00580a08  740e                 je 0x580a18
// 00580a0a  68a8c58c00           push 0x8cc5a8
// 00580a0f  57                   push edi
// 00580a10  e84bd70000           call 0x58e160
// 00580a15  83c408               add esp, 8
// 00580a18  bd00100000           mov ebp, 0x1000
// 00580a1d  856f68               test dword ptr [edi + 0x68], ebp
// 00580a20  7417                 je 0x580a39
// 00580a22  83bf3002000000       cmp dword ptr [edi + 0x230], 0
// 00580a29  740e                 je 0x580a39
// 00580a2b  683cc28c00           push 0x8cc23c
// 00580a30  57                   push edi
// 00580a31  e8dad70000           call 0x58e210
// 00580a36  83c408               add esp, 8
// 00580a39  8b442434             mov eax, dword ptr [esp + 0x34]
// 00580a3d  85c0                 test eax, eax
// 00580a3f  743e                 je 0x580a7f
// 00580a41  f6873002000004       test byte ptr [edi + 0x230], 4
// 00580a48  7414                 je 0x580a5e
// 00580a4a  83f840               cmp eax, 0x40
// 00580a4d  750f                 jne 0x580a5e
// 00580a4f  856f68               test dword ptr [edi + 0x68], ebp
// 00580a52  750a                 jne 0x580a5e
// 00580a54  83fb02               cmp ebx, 2
// 00580a57  7413                 je 0x580a6c
// 00580a59  83fb06               cmp ebx, 6
// 00580a5c  740e                 je 0x580a6c
// 00580a5e  6888c58c00           push 0x8cc588
// 00580a63  57                   push edi
// 00580a64  e8f7d60000           call 0x58e160
// 00580a69  83c408               add esp, 8
// 00580a6c  856f68               test dword ptr [edi + 0x68], ebp
// 00580a6f  740e                 je 0x580a7f
// 00580a71  6868c58c00           push 0x8cc568
// 00580a76  57                   push edi
// 00580a77  e894d70000           call 0x58e210
// 00580a7c  83c408               add esp, 8
// 00580a7f  8b442420             mov eax, dword ptr [esp + 0x20]
// 00580a83  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00580a87  8a542424             mov dl, byte ptr [esp + 0x24]
// 00580a8b  894604               mov dword ptr [esi + 4], eax
// 00580a8e  8a442430             mov al, byte ptr [esp + 0x30]
// 00580a92  88461a               mov byte ptr [esi + 0x1a], al
// 00580a95  8a442434             mov al, byte ptr [esp + 0x34]
// 00580a99  88461b               mov byte ptr [esi + 0x1b], al
// 00580a9c  8a44242c             mov al, byte ptr [esp + 0x2c]
// 00580aa0  890e                 mov dword ptr [esi], ecx
// 00580aa2  885618               mov byte ptr [esi + 0x18], dl
// 00580aa5  885e19               mov byte ptr [esi + 0x19], bl
// 00580aa8  88461c               mov byte ptr [esi + 0x1c], al
// 00580aab  80fb03               cmp bl, 3
// 00580aae  740b                 je 0x580abb
// 00580ab0  f6c302               test bl, 2
// 00580ab3  7406                 je 0x580abb
// 00580ab5  c6461d03             mov byte ptr [esi + 0x1d], 3
// 00580ab9  eb04                 jmp 0x580abf
// 00580abb  c6461d01             mov byte ptr [esi + 0x1d], 1
// 00580abf  5d                   pop ebp
// 00580ac0  f6c304               test bl, 4
// 00580ac3  5b                   pop ebx
// 00580ac4  7403                 je 0x580ac9
// 00580ac6  fe461d               inc byte ptr [esi + 0x1d]
// 00580ac9  8a461d               mov al, byte ptr [esi + 0x1d]
// 00580acc  f6ea                 imul dl
// 00580ace  88461e               mov byte ptr [esi + 0x1e], al
// 00580ad1  81f97effff1f         cmp ecx, 0x1fffff7e
// 00580ad7  760a                 jbe 0x580ae3
// 00580ad9  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00580ae0  5e                   pop esi
// 00580ae1  5f                   pop edi
// 00580ae2  c3                   ret 
// 00580ae3  3c08                 cmp al, 8
// 00580ae5  0fb6c0               movzx eax, al
// 00580ae8  720c                 jb 0x580af6
// 00580aea  c1e803               shr eax, 3
// 00580aed  0fafc1               imul eax, ecx
// 00580af0  89460c               mov dword ptr [esi + 0xc], eax
// 00580af3  5e                   pop esi
// 00580af4  5f                   pop edi
// 00580af5  c3                   ret 
// 00580af6  0fafc1               imul eax, ecx
// 00580af9  83c007               add eax, 7
// 00580afc  c1e803               shr eax, 3
// 00580aff  89460c               mov dword ptr [esi + 0xc], eax
// 00580b02  5e                   pop esi
// 00580b03  5f                   pop edi
// 00580b04  c3                   ret 
// library libpng-1.2.10/pngset.c (function _png_set_IHDR)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngset.c
