// from server: 100% by auto
// roc 2007-03 005185e0  unit: seg_00510000  size: 655 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005185e0
//
// 005185e0  8b542404             mov edx, dword ptr [esp + 4]
// 005185e4  83ec34               sub esp, 0x34
// 005185e7  53                   push ebx
// 005185e8  8a5a08               mov bl, byte ptr [edx + 8]
// 005185eb  80fb03               cmp bl, 3
// 005185ee  0f8476020000         je 0x51886a
// 005185f4  f6c302               test bl, 2
// 005185f7  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 005185fb  55                   push ebp
// 005185fc  56                   push esi
// 005185fd  57                   push edi
// 005185fe  7434                 je 0x518634
// 00518600  0fb64209             movzx eax, byte ptr [edx + 9]
// 00518604  0fb631               movzx esi, byte ptr [ecx]
// 00518607  8bf8                 mov edi, eax
// 00518609  2bfe                 sub edi, esi
// 0051860b  89742424             mov dword ptr [esp + 0x24], esi
// 0051860f  0fb67101             movzx esi, byte ptr [ecx + 1]
// 00518613  8be8                 mov ebp, eax
// 00518615  2bee                 sub ebp, esi
// 00518617  89742428             mov dword ptr [esp + 0x28], esi
// 0051861b  0fb67102             movzx esi, byte ptr [ecx + 2]
// 0051861f  2bc6                 sub eax, esi
// 00518621  896c2438             mov dword ptr [esp + 0x38], ebp
// 00518625  8944243c             mov dword ptr [esp + 0x3c], eax
// 00518629  8974242c             mov dword ptr [esp + 0x2c], esi
// 0051862d  bd03000000           mov ebp, 3
// 00518632  eb13                 jmp 0x518647
// 00518634  0fb64103             movzx eax, byte ptr [ecx + 3]
// 00518638  0fb67a09             movzx edi, byte ptr [edx + 9]
// 0051863c  2bf8                 sub edi, eax
// 0051863e  89442424             mov dword ptr [esp + 0x24], eax
// 00518642  bd01000000           mov ebp, 1
// 00518647  f6c304               test bl, 4
// 0051864a  896c2448             mov dword ptr [esp + 0x48], ebp
// 0051864e  897c2434             mov dword ptr [esp + 0x34], edi
// 00518652  741d                 je 0x518671
// 00518654  0fb64104             movzx eax, byte ptr [ecx + 4]
// 00518658  0fb67209             movzx esi, byte ptr [edx + 9]
// 0051865c  2bf0                 sub esi, eax
// 0051865e  8974ac34             mov dword ptr [esp + ebp*4 + 0x34], esi
// 00518662  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00518666  8944ac24             mov dword ptr [esp + ebp*4 + 0x24], eax
// 0051866a  83c501               add ebp, 1
// 0051866d  896c2448             mov dword ptr [esp + 0x48], ebp
// 00518671  8a5a09               mov bl, byte ptr [edx + 9]
// 00518674  80fb08               cmp bl, 8
// 00518677  0f839d000000         jae 0x51871a
// 0051867d  8a4903               mov cl, byte ptr [ecx + 3]
// 00518680  80f901               cmp cl, 1
// 00518683  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 00518687  8b7204               mov esi, dword ptr [edx + 4]
// 0051868a  750c                 jne 0x518698
// 0051868c  80fb02               cmp bl, 2
// 0051868f  7507                 jne 0x518698
// 00518691  c644244855           mov byte ptr [esp + 0x48], 0x55
// 00518696  eb14                 jmp 0x5186ac
// 00518698  80fb04               cmp bl, 4
// 0051869b  750a                 jne 0x5186a7
// 0051869d  80f903               cmp cl, 3
// 005186a0  c644244811           mov byte ptr [esp + 0x48], 0x11
// 005186a5  7405                 je 0x5186ac
// 005186a7  c6442448ff           mov byte ptr [esp + 0x48], 0xff
// 005186ac  85f6                 test esi, esi
// 005186ae  0f86b3010000         jbe 0x518867
// 005186b4  8b542424             mov edx, dword ptr [esp + 0x24]
// 005186b8  f7da                 neg edx
// 005186ba  89742410             mov dword ptr [esp + 0x10], esi
// 005186be  8bff                 mov edi, edi
// 005186c0  3bfa                 cmp edi, edx
// 005186c2  660fb608             movzx cx, byte ptr [eax]
// 005186c6  0fb7c9               movzx ecx, cx
// 005186c9  894c2414             mov dword ptr [esp + 0x14], ecx
// 005186cd  c60000               mov byte ptr [eax], 0
// 005186d0  8bf7                 mov esi, edi
// 005186d2  7e34                 jle 0x518708
// 005186d4  8bef                 mov ebp, edi
// 005186d6  f7dd                 neg ebp
// 005186d8  eb0a                 jmp 0x5186e4
// 005186da  8d9b00000000         lea ebx, [ebx]
// 005186e0  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005186e4  85f6                 test esi, esi
// 005186e6  7e08                 jle 0x5186f0
// 005186e8  8ad9                 mov bl, cl
// 005186ea  8bce                 mov ecx, esi
// 005186ec  d2e3                 shl bl, cl
// 005186ee  eb0c                 jmp 0x5186fc
// 005186f0  8bd9                 mov ebx, ecx
// 005186f2  668bcd               mov cx, bp
// 005186f5  66d3eb               shr bx, cl
// 005186f8  225c2448             and bl, byte ptr [esp + 0x48]
// 005186fc  2b742424             sub esi, dword ptr [esp + 0x24]
// 00518700  0818                 or byte ptr [eax], bl
// 00518702  2bea                 sub ebp, edx
// 00518704  3bf2                 cmp esi, edx
// 00518706  7fd8                 jg 0x5186e0
// 00518708  83c001               add eax, 1
// 0051870b  836c241001           sub dword ptr [esp + 0x10], 1
// 00518710  75ae                 jne 0x5186c0
// 00518712  5f                   pop edi
// 00518713  5e                   pop esi
// 00518714  5d                   pop ebp
// 00518715  5b                   pop ebx
// 00518716  83c434               add esp, 0x34
// 00518719  c3                   ret 
// 0051871a  8b74244c             mov esi, dword ptr [esp + 0x4c]
// 0051871e  8b12                 mov edx, dword ptr [edx]
// 00518720  0f8590000000         jne 0x5187b6
// 00518726  0fafd5               imul edx, ebp
// 00518729  33db                 xor ebx, ebx
// 0051872b  85d2                 test edx, edx
// 0051872d  8954241c             mov dword ptr [esp + 0x1c], edx
// 00518731  895c2414             mov dword ptr [esp + 0x14], ebx
// 00518735  0f862c010000         jbe 0x518867
// 0051873b  eb03                 jmp 0x518740
// 0051873d  8d4900               lea ecx, [ecx]
// 00518740  33d2                 xor edx, edx
// 00518742  8bc3                 mov eax, ebx
// 00518744  f7f5                 div ebp
// 00518746  660fb606             movzx ax, byte ptr [esi]
// 0051874a  0fb7c8               movzx ecx, ax
// 0051874d  894c2410             mov dword ptr [esp + 0x10], ecx
// 00518751  c60600               mov byte ptr [esi], 0
// 00518754  8b449434             mov eax, dword ptr [esp + edx*4 + 0x34]
// 00518758  8d4c9424             lea ecx, [esp + edx*4 + 0x24]
// 0051875c  8b11                 mov edx, dword ptr [ecx]
// 0051875e  8bfa                 mov edi, edx
// 00518760  f7df                 neg edi
// 00518762  3bc7                 cmp eax, edi
// 00518764  7e38                 jle 0x51879e
// 00518766  8bca                 mov ecx, edx
// 00518768  f7d9                 neg ecx
// 0051876a  8be8                 mov ebp, eax
// 0051876c  894c2418             mov dword ptr [esp + 0x18], ecx
// 00518770  f7dd                 neg ebp
// 00518772  85c0                 test eax, eax
// 00518774  7e0a                 jle 0x518780
// 00518776  8a5c2410             mov bl, byte ptr [esp + 0x10]
// 0051877a  8bc8                 mov ecx, eax
// 0051877c  d2e3                 shl bl, cl
// 0051877e  eb0a                 jmp 0x51878a
// 00518780  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00518784  668bcd               mov cx, bp
// 00518787  66d3eb               shr bx, cl
// 0051878a  081e                 or byte ptr [esi], bl
// 0051878c  2bc2                 sub eax, edx
// 0051878e  2bef                 sub ebp, edi
// 00518790  3b442418             cmp eax, dword ptr [esp + 0x18]
// 00518794  7fdc                 jg 0x518772
// 00518796  8b6c2448             mov ebp, dword ptr [esp + 0x48]
// 0051879a  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0051879e  83c301               add ebx, 1
// 005187a1  83c601               add esi, 1
// 005187a4  3b5c241c             cmp ebx, dword ptr [esp + 0x1c]
// 005187a8  895c2414             mov dword ptr [esp + 0x14], ebx
// 005187ac  7292                 jb 0x518740
// 005187ae  5f                   pop edi
// 005187af  5e                   pop esi
// 005187b0  5d                   pop ebp
// 005187b1  5b                   pop ebx
// 005187b2  83c434               add esp, 0x34
// 005187b5  c3                   ret 
// 005187b6  0fafd5               imul edx, ebp
// 005187b9  33ff                 xor edi, edi
// 005187bb  85d2                 test edx, edx
// 005187bd  89542420             mov dword ptr [esp + 0x20], edx
// 005187c1  897c2414             mov dword ptr [esp + 0x14], edi
// 005187c5  0f869c000000         jbe 0x518867
// 005187cb  eb03                 jmp 0x5187d0
// 005187cd  8d4900               lea ecx, [ecx]
// 005187d0  33d2                 xor edx, edx
// 005187d2  8bc7                 mov eax, edi
// 005187d4  f7f5                 div ebp
// 005187d6  660fb606             movzx ax, byte ptr [esi]
// 005187da  660fb64e01           movzx cx, byte ptr [esi + 1]
// 005187df  66c1e008             shl ax, 8
// 005187e3  6603c1               add ax, cx
// 005187e6  0fb7d8               movzx ebx, ax
// 005187e9  895c241c             mov dword ptr [esp + 0x1c], ebx
// 005187ed  c744244800000000     mov dword ptr [esp + 0x48], 0
// 005187f5  8b449434             mov eax, dword ptr [esp + edx*4 + 0x34]
// 005187f9  8d4c9424             lea ecx, [esp + edx*4 + 0x24]
// 005187fd  8b11                 mov edx, dword ptr [ecx]
// 005187ff  89542418             mov dword ptr [esp + 0x18], edx
// 00518803  f7da                 neg edx
// 00518805  3bc2                 cmp eax, edx
// 00518807  7e3b                 jle 0x518844
// 00518809  8b09                 mov ecx, dword ptr [ecx]
// 0051880b  f7d9                 neg ecx
// 0051880d  8bf8                 mov edi, eax
// 0051880f  894c2410             mov dword ptr [esp + 0x10], ecx
// 00518813  f7df                 neg edi
// 00518815  eb04                 jmp 0x51881b
// 00518817  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0051881b  85c0                 test eax, eax
// 0051881d  7e0a                 jle 0x518829
// 0051881f  8bc8                 mov ecx, eax
// 00518821  d3e3                 shl ebx, cl
// 00518823  095c2448             or dword ptr [esp + 0x48], ebx
// 00518827  eb0b                 jmp 0x518834
// 00518829  668bcf               mov cx, di
// 0051882c  66d3eb               shr bx, cl
// 0051882f  66095c2448           or word ptr [esp + 0x48], bx
// 00518834  2b442418             sub eax, dword ptr [esp + 0x18]
// 00518838  2bfa                 sub edi, edx
// 0051883a  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0051883e  7fd7                 jg 0x518817
// 00518840  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00518844  8a542449             mov dl, byte ptr [esp + 0x49]
// 00518848  8a442448             mov al, byte ptr [esp + 0x48]
// 0051884c  8816                 mov byte ptr [esi], dl
// 0051884e  83c601               add esi, 1
// 00518851  83c701               add edi, 1
// 00518854  8806                 mov byte ptr [esi], al
// 00518856  83c601               add esi, 1
// 00518859  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 0051885d  897c2414             mov dword ptr [esp + 0x14], edi
// 00518861  0f8269ffffff         jb 0x5187d0
// 00518867  5f                   pop edi
// 00518868  5e                   pop esi
// 00518869  5d                   pop ebp
// 0051886a  5b                   pop ebx
// 0051886b  83c434               add esp, 0x34
// 0051886e  c3                   ret 
// library libpng-1.2.7/pngwtran.c (function _png_do_shift)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwtran.c
