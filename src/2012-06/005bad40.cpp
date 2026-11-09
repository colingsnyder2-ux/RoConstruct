// roc 2012-06 005bad40  unit: RakNet::RakPeer  size: 421 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bad40
//
// 005bad40  53                   push ebx
// 005bad41  56                   push esi
// 005bad42  57                   push edi
// 005bad43  8bf1                 mov esi, ecx
// 005bad45  68f815d900           push 0xd915f8
// 005bad4a  8d4c2418             lea ecx, [esp + 0x18]
// 005bad4e  e8bd6ffaff           call 0x561d10
// 005bad53  84c0                 test al, al
// 005bad55  7436                 je 0x5bad8d
// 005bad57  8b0d4c69e200         mov ecx, dword ptr [0xe2694c]
// 005bad5d  8b442410             mov eax, dword ptr [esp + 0x10]
// 005bad61  8908                 mov dword ptr [eax], ecx
// 005bad63  8b155069e200         mov edx, dword ptr [0xe26950]
// 005bad69  895004               mov dword ptr [eax + 4], edx
// 005bad6c  8b0d5469e200         mov ecx, dword ptr [0xe26954]
// 005bad72  894808               mov dword ptr [eax + 8], ecx
// 005bad75  8b155869e200         mov edx, dword ptr [0xe26958]
// 005bad7b  89500c               mov dword ptr [eax + 0xc], edx
// 005bad7e  8b0d5c69e200         mov ecx, dword ptr [0xe2695c]
// 005bad84  894810               mov dword ptr [eax + 0x10], ecx
// 005bad87  5f                   pop edi
// 005bad88  5e                   pop esi
// 005bad89  5b                   pop ebx
// 005bad8a  c21400               ret 0x14
// 005bad8d  8d9658040000         lea edx, [esi + 0x458]
// 005bad93  52                   push edx
// 005bad94  8d4c2418             lea ecx, [esp + 0x18]
// 005bad98  e8736ffaff           call 0x561d10
// 005bad9d  84c0                 test al, al
// 005bad9f  744c                 je 0x5baded
// 005bada1  8b0d4c69e200         mov ecx, dword ptr [0xe2694c]
// 005bada7  8b16                 mov edx, dword ptr [esi]
// 005bada9  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005badad  8b92b8000000         mov edx, dword ptr [edx + 0xb8]
// 005badb3  6a00                 push 0
// 005badb5  83ec14               sub esp, 0x14
// 005badb8  8bc4                 mov eax, esp
// 005badba  8908                 mov dword ptr [eax], ecx
// 005badbc  8b0d5069e200         mov ecx, dword ptr [0xe26950]
// 005badc2  894804               mov dword ptr [eax + 4], ecx
// 005badc5  8b0d5469e200         mov ecx, dword ptr [0xe26954]
// 005badcb  894808               mov dword ptr [eax + 8], ecx
// 005badce  8b0d5869e200         mov ecx, dword ptr [0xe26958]
// 005badd4  89480c               mov dword ptr [eax + 0xc], ecx
// 005badd7  8b0d5c69e200         mov ecx, dword ptr [0xe2695c]
// 005baddd  894810               mov dword ptr [eax + 0x10], ecx
// 005bade0  57                   push edi
// 005bade1  8bce                 mov ecx, esi
// 005bade3  ffd2                 call edx
// 005bade5  8bc7                 mov eax, edi
// 005bade7  5f                   pop edi
// 005bade8  5e                   pop esi
// 005bade9  5b                   pop ebx
// 005badea  c21400               ret 0x14
// 005baded  668b44241c           mov ax, word ptr [esp + 0x1c]
// 005badf2  b9ffff0000           mov ecx, 0xffff
// 005badf7  663bc1               cmp ax, cx
// 005badfa  7465                 je 0x5bae61
// 005badfc  663b460e             cmp ax, word ptr [esi + 0xe]
// 005bae00  735f                 jae 0x5bae61
// 005bae02  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 005bae08  0fb7c0               movzx eax, ax
// 005bae0b  69c008120000         imul eax, eax, 0x1208
// 005bae11  8d542414             lea edx, [esp + 0x14]
// 005bae15  52                   push edx
// 005bae16  8d8c08e0110000       lea ecx, [eax + ecx + 0x11e0]
// 005bae1d  e8ee6efaff           call 0x561d10
// 005bae22  84c0                 test al, al
// 005bae24  743b                 je 0x5bae61
// 005bae26  0fb754241c           movzx edx, word ptr [esp + 0x1c]
// 005bae2b  8b862c020000         mov eax, dword ptr [esi + 0x22c]
// 005bae31  69d208120000         imul edx, edx, 0x1208
// 005bae37  8d4c0204             lea ecx, [edx + eax + 4]
// 005bae3b  8b11                 mov edx, dword ptr [ecx]
// 005bae3d  8b442410             mov eax, dword ptr [esp + 0x10]
// 005bae41  8910                 mov dword ptr [eax], edx
// 005bae43  8b5104               mov edx, dword ptr [ecx + 4]
// 005bae46  895004               mov dword ptr [eax + 4], edx
// 005bae49  8b5108               mov edx, dword ptr [ecx + 8]
// 005bae4c  895008               mov dword ptr [eax + 8], edx
// 005bae4f  8b510c               mov edx, dword ptr [ecx + 0xc]
// 005bae52  89500c               mov dword ptr [eax + 0xc], edx
// 005bae55  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 005bae58  894810               mov dword ptr [eax + 0x10], ecx
// 005bae5b  5f                   pop edi
// 005bae5c  5e                   pop esi
// 005bae5d  5b                   pop ebx
// 005bae5e  c21400               ret 0x14
// 005bae61  33d2                 xor edx, edx
// 005bae63  33ff                 xor edi, edi
// 005bae65  663b560e             cmp dx, word ptr [esi + 0xe]
// 005bae69  732f                 jae 0x5bae9a
// 005bae6b  33db                 xor ebx, ebx
// 005bae6d  8d4900               lea ecx, [ecx]
// 005bae70  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 005bae76  8d442414             lea eax, [esp + 0x14]
// 005bae7a  50                   push eax
// 005bae7b  8d8c0be0110000       lea ecx, [ebx + ecx + 0x11e0]
// 005bae82  e8896efaff           call 0x561d10
// 005bae87  84c0                 test al, al
// 005bae89  7545                 jne 0x5baed0
// 005bae8b  0fb7560e             movzx edx, word ptr [esi + 0xe]
// 005bae8f  47                   inc edi
// 005bae90  81c308120000         add ebx, 0x1208
// 005bae96  3bfa                 cmp edi, edx
// 005bae98  72d6                 jb 0x5bae70
// 005bae9a  8b154c69e200         mov edx, dword ptr [0xe2694c]
// 005baea0  8b442410             mov eax, dword ptr [esp + 0x10]
// 005baea4  8910                 mov dword ptr [eax], edx
// 005baea6  8b0d5069e200         mov ecx, dword ptr [0xe26950]
// 005baeac  894804               mov dword ptr [eax + 4], ecx
// 005baeaf  8b155469e200         mov edx, dword ptr [0xe26954]
// 005baeb5  895008               mov dword ptr [eax + 8], edx
// 005baeb8  8b0d5869e200         mov ecx, dword ptr [0xe26958]
// 005baebe  5f                   pop edi
// 005baebf  89480c               mov dword ptr [eax + 0xc], ecx
// 005baec2  8b155c69e200         mov edx, dword ptr [0xe2695c]
// 005baec8  5e                   pop esi
// 005baec9  895010               mov dword ptr [eax + 0x10], edx
// 005baecc  5b                   pop ebx
// 005baecd  c21400               ret 0x14
// 005baed0  8b862c020000         mov eax, dword ptr [esi + 0x22c]
// 005baed6  69ff08120000         imul edi, edi, 0x1208
// 005baedc  8d4c0704             lea ecx, [edi + eax + 4]
// 005baee0  e956ffffff           jmp 0x5bae3b
// copied from an identical function in another client (function ?GetSystemAddressFromGuid@RakPeer@RakNet@@UBE?AUSystemAddress@2@URakNetGUID@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp