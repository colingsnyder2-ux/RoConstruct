// roc 2012-06 005babb0  unit: RakNet::RakPeer  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005babb0
//
// 005babb0  57                   push edi
// 005babb1  8bf9                 mov edi, ecx
// 005babb3  684c69e200           push 0xe2694c
// 005babb8  8d4c240c             lea ecx, [esp + 0xc]
// 005babbc  e8df6cfaff           call 0x5618a0
// 005babc1  84c0                 test al, al
// 005babc3  740a                 je 0x5babcf
// 005babc5  8d8758040000         lea eax, [edi + 0x458]
// 005babcb  5f                   pop edi
// 005babcc  c21400               ret 0x14
// 005babcf  668b44241a           mov ax, word ptr [esp + 0x1a]
// 005babd4  b9ffff0000           mov ecx, 0xffff
// 005babd9  663bc1               cmp ax, cx
// 005babdc  7443                 je 0x5bac21
// 005babde  663b470e             cmp ax, word ptr [edi + 0xe]
// 005babe2  733d                 jae 0x5bac21
// 005babe4  8b8f2c020000         mov ecx, dword ptr [edi + 0x22c]
// 005babea  0fb7c0               movzx eax, ax
// 005babed  69c008120000         imul eax, eax, 0x1208
// 005babf3  8d542408             lea edx, [esp + 8]
// 005babf7  52                   push edx
// 005babf8  8d4c0804             lea ecx, [eax + ecx + 4]
// 005babfc  e89f6cfaff           call 0x5618a0
// 005bac01  84c0                 test al, al
// 005bac03  741c                 je 0x5bac21
// 005bac05  0fb754241a           movzx edx, word ptr [esp + 0x1a]
// 005bac0a  8b872c020000         mov eax, dword ptr [edi + 0x22c]
// 005bac10  69d208120000         imul edx, edx, 0x1208
// 005bac16  8d8402e0110000       lea eax, [edx + eax + 0x11e0]
// 005bac1d  5f                   pop edi
// 005bac1e  c21400               ret 0x14
// 005bac21  53                   push ebx
// 005bac22  56                   push esi
// 005bac23  33c9                 xor ecx, ecx
// 005bac25  33f6                 xor esi, esi
// 005bac27  663b4f0e             cmp cx, word ptr [edi + 0xe]
// 005bac2b  732a                 jae 0x5bac57
// 005bac2d  33db                 xor ebx, ebx
// 005bac2f  90                   nop 
// 005bac30  8b872c020000         mov eax, dword ptr [edi + 0x22c]
// 005bac36  8d542410             lea edx, [esp + 0x10]
// 005bac3a  52                   push edx
// 005bac3b  8d4c1804             lea ecx, [eax + ebx + 4]
// 005bac3f  e85c6cfaff           call 0x5618a0
// 005bac44  84c0                 test al, al
// 005bac46  751a                 jne 0x5bac62
// 005bac48  0fb74f0e             movzx ecx, word ptr [edi + 0xe]
// 005bac4c  46                   inc esi
// 005bac4d  81c308120000         add ebx, 0x1208
// 005bac53  3bf1                 cmp esi, ecx
// 005bac55  72d9                 jb 0x5bac30
// 005bac57  5e                   pop esi
// 005bac58  5b                   pop ebx
// 005bac59  b8f815d900           mov eax, 0xd915f8
// 005bac5e  5f                   pop edi
// 005bac5f  c21400               ret 0x14
// 005bac62  8b972c020000         mov edx, dword ptr [edi + 0x22c]
// 005bac68  69f608120000         imul esi, esi, 0x1208
// 005bac6e  8d8416e0110000       lea eax, [esi + edx + 0x11e0]
// 005bac75  5e                   pop esi
// 005bac76  5b                   pop ebx
// 005bac77  5f                   pop edi
// 005bac78  c21400               ret 0x14
// copied from an identical function in another client (function ?GetGuidFromSystemAddress@RakPeer@RakNet@@UBEABURakNetGUID@2@USystemAddress@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp