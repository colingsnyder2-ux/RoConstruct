// from server: 100% by auto
// roc 2010-06 005785e0  unit: seg_00570000  size: 444 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005785e0
//
// 005785e0  83ec10               sub esp, 0x10
// 005785e3  53                   push ebx
// 005785e4  55                   push ebp
// 005785e5  56                   push esi
// 005785e6  8b742420             mov esi, dword ptr [esp + 0x20]
// 005785ea  f6466801             test byte ptr [esi + 0x68], 1
// 005785ee  57                   push edi
// 005785ef  740e                 je 0x5785ff
// 005785f1  68486da200           push 0xa26d48
// 005785f6  56                   push esi
// 005785f7  e8b494ffff           call 0x571ab0
// 005785fc  83c408               add esp, 8
// 005785ff  837c242c0d           cmp dword ptr [esp + 0x2c], 0xd
// 00578604  740e                 je 0x578614
// 00578606  68346da200           push 0xa26d34
// 0057860b  56                   push esi
// 0057860c  e89f94ffff           call 0x571ab0
// 00578611  83c408               add esp, 8
// 00578614  834e6801             or dword ptr [esi + 0x68], 1
// 00578618  6a0d                 push 0xd
// 0057861a  8d442414             lea eax, [esp + 0x14]
// 0057861e  50                   push eax
// 0057861f  56                   push esi
// 00578620  e8eb3dffff           call 0x56c410
// 00578625  6a0d                 push 0xd
// 00578627  8d4c2420             lea ecx, [esp + 0x20]
// 0057862b  51                   push ecx
// 0057862c  56                   push esi
// 0057862d  e8aec9feff           call 0x564fe0
// 00578632  6a00                 push 0
// 00578634  56                   push esi
// 00578635  e8d6feffff           call 0x578510
// 0057863a  0fb67c2430           movzx edi, byte ptr [esp + 0x30]
// 0057863f  0fb6542431           movzx edx, byte ptr [esp + 0x31]
// 00578644  0fb6442432           movzx eax, byte ptr [esp + 0x32]
// 00578649  0fb64c2433           movzx ecx, byte ptr [esp + 0x33]
// 0057864e  c1e708               shl edi, 8
// 00578651  03fa                 add edi, edx
// 00578653  c1e708               shl edi, 8
// 00578656  03f8                 add edi, eax
// 00578658  c1e708               shl edi, 8
// 0057865b  03f9                 add edi, ecx
// 0057865d  83c420               add esp, 0x20
// 00578660  81ffffffff7f         cmp edi, 0x7fffffff
// 00578666  760e                 jbe 0x578676
// 00578668  68506ba200           push 0xa26b50
// 0057866d  56                   push esi
// 0057866e  e83d94ffff           call 0x571ab0
// 00578673  83c408               add esp, 8
// 00578676  0fb66c2414           movzx ebp, byte ptr [esp + 0x14]
// 0057867b  0fb6542415           movzx edx, byte ptr [esp + 0x15]
// 00578680  0fb6442416           movzx eax, byte ptr [esp + 0x16]
// 00578685  0fb64c2417           movzx ecx, byte ptr [esp + 0x17]
// 0057868a  c1e508               shl ebp, 8
// 0057868d  03ea                 add ebp, edx
// 0057868f  c1e508               shl ebp, 8
// 00578692  03e8                 add ebp, eax
// 00578694  c1e508               shl ebp, 8
// 00578697  03e9                 add ebp, ecx
// 00578699  81fdffffff7f         cmp ebp, 0x7fffffff
// 0057869f  760e                 jbe 0x5786af
// 005786a1  68506ba200           push 0xa26b50
// 005786a6  56                   push esi
// 005786a7  e80494ffff           call 0x571ab0
// 005786ac  83c408               add esp, 8
// 005786af  0fb644241b           movzx eax, byte ptr [esp + 0x1b]
// 005786b4  0fb64c2419           movzx ecx, byte ptr [esp + 0x19]
// 005786b9  0fb6542418           movzx edx, byte ptr [esp + 0x18]
// 005786be  0fb65c241a           movzx ebx, byte ptr [esp + 0x1a]
// 005786c3  89442424             mov dword ptr [esp + 0x24], eax
// 005786c7  0fb644241c           movzx eax, byte ptr [esp + 0x1c]
// 005786cc  8944242c             mov dword ptr [esp + 0x2c], eax
// 005786d0  888623010000         mov byte ptr [esi + 0x123], al
// 005786d6  8a442424             mov al, byte ptr [esp + 0x24]
// 005786da  888638020000         mov byte ptr [esi + 0x238], al
// 005786e0  0fb6c1               movzx eax, cl
// 005786e3  89bec8000000         mov dword ptr [esi + 0xc8], edi
// 005786e9  89aecc000000         mov dword ptr [esi + 0xcc], ebp
// 005786ef  889627010000         mov byte ptr [esi + 0x127], dl
// 005786f5  888e26010000         mov byte ptr [esi + 0x126], cl
// 005786fb  889e60020000         mov byte ptr [esi + 0x260], bl
// 00578701  83f806               cmp eax, 6
// 00578704  7729                 ja 0x57872f
// 00578706  ff248580875700       jmp dword ptr [eax*4 + 0x578780]
// 0057870d  c6862a01000001       mov byte ptr [esi + 0x12a], 1
// 00578714  eb19                 jmp 0x57872f
// 00578716  c6862a01000003       mov byte ptr [esi + 0x12a], 3
// 0057871d  eb10                 jmp 0x57872f
// 0057871f  c6862a01000002       mov byte ptr [esi + 0x12a], 2
// 00578726  eb07                 jmp 0x57872f
// 00578728  c6862a01000004       mov byte ptr [esi + 0x12a], 4
// 0057872f  8a862a010000         mov al, byte ptr [esi + 0x12a]
// 00578735  f6ea                 imul dl
// 00578737  888629010000         mov byte ptr [esi + 0x129], al
// 0057873d  3c08                 cmp al, 8
// 0057873f  0fb6c0               movzx eax, al
// 00578742  7208                 jb 0x57874c
// 00578744  c1e803               shr eax, 3
// 00578747  0fafc7               imul eax, edi
// 0057874a  eb09                 jmp 0x578755
// 0057874c  0fafc7               imul eax, edi
// 0057874f  83c007               add eax, 7
// 00578752  c1e803               shr eax, 3
// 00578755  8986d8000000         mov dword ptr [esi + 0xd8], eax
// 0057875b  8b442424             mov eax, dword ptr [esp + 0x24]
// 0057875f  50                   push eax
// 00578760  8b442430             mov eax, dword ptr [esp + 0x30]
// 00578764  53                   push ebx
// 00578765  50                   push eax
// 00578766  51                   push ecx
// 00578767  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0057876b  52                   push edx
// 0057876c  55                   push ebp
// 0057876d  57                   push edi
// 0057876e  51                   push ecx
// 0057876f  56                   push esi
// 00578770  e88bb8feff           call 0x564000
// 00578775  83c424               add esp, 0x24
// 00578778  5f                   pop edi
// 00578779  5e                   pop esi
// 0057877a  5d                   pop ebp
// 0057877b  5b                   pop ebx
// 0057877c  83c410               add esp, 0x10
// 0057877f  c3                   ret 
// 00578780  0d8757002f           or eax, 0x2f005787
// 00578785  875700               xchg dword ptr [edi], edx
// 00578788  16                   push ss
// 00578789  875700               xchg dword ptr [edi], edx
// 0057878c  0d8757001f           or eax, 0x1f005787
// 00578791  875700               xchg dword ptr [edi], edx
// 00578794  2f                   das 
// 00578795  875700               xchg dword ptr [edi], edx
// library libpng-1.2.10/pngrutil.c (function _png_handle_IHDR)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngrutil.c
