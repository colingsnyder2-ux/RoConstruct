// roc 2012-06 005baa40  unit: RakNet::RakPeer  size: 309 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005baa40
//
// 005baa40  83ec14               sub esp, 0x14
// 005baa43  56                   push esi
// 005baa44  8bf1                 mov esi, ecx
// 005baa46  8d4c2404             lea ecx, [esp + 4]
// 005baa4a  e8e16ffaff           call 0x561a30
// 005baa4f  684c69e200           push 0xe2694c
// 005baa54  8d4c2408             lea ecx, [esp + 8]
// 005baa58  e8b36dfaff           call 0x561810
// 005baa5d  684c69e200           push 0xe2694c
// 005baa62  8d4c2424             lea ecx, [esp + 0x24]
// 005baa66  e8356efaff           call 0x5618a0
// 005baa6b  84c0                 test al, al
// 005baa6d  7437                 je 0x5baaa6
// 005baa6f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005baa73  8b8e70040000         mov ecx, dword ptr [esi + 0x470]
// 005baa79  8b9674040000         mov edx, dword ptr [esi + 0x474]
// 005baa7f  8908                 mov dword ptr [eax], ecx
// 005baa81  8b8e78040000         mov ecx, dword ptr [esi + 0x478]
// 005baa87  895004               mov dword ptr [eax + 4], edx
// 005baa8a  8b967c040000         mov edx, dword ptr [esi + 0x47c]
// 005baa90  894808               mov dword ptr [eax + 8], ecx
// 005baa93  8b8e80040000         mov ecx, dword ptr [esi + 0x480]
// 005baa99  89500c               mov dword ptr [eax + 0xc], edx
// 005baa9c  894810               mov dword ptr [eax + 0x10], ecx
// 005baa9f  5e                   pop esi
// 005baaa0  83c414               add esp, 0x14
// 005baaa3  c21800               ret 0x18
// 005baaa6  53                   push ebx
// 005baaa7  33d2                 xor edx, edx
// 005baaa9  33db                 xor ebx, ebx
// 005baaab  57                   push edi
// 005baaac  663b560e             cmp dx, word ptr [esi + 0xe]
// 005baab0  735d                 jae 0x5bab0f
// 005baab2  33ff                 xor edi, edi
// 005baab4  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 005baaba  8d442428             lea eax, [esp + 0x28]
// 005baabe  50                   push eax
// 005baabf  8d4c3904             lea ecx, [ecx + edi + 4]
// 005baac3  e8d86dfaff           call 0x5618a0
// 005baac8  84c0                 test al, al
// 005baaca  7434                 je 0x5bab00
// 005baacc  8b962c020000         mov edx, dword ptr [esi + 0x22c]
// 005baad2  803c3a00             cmp byte ptr [edx + edi], 0
// 005baad6  8d043a               lea eax, [edx + edi]
// 005baad9  7563                 jne 0x5bab3e
// 005baadb  684c69e200           push 0xe2694c
// 005baae0  8d4818               lea ecx, [eax + 0x18]
// 005baae3  e8e86dfaff           call 0x5618d0
// 005baae8  84c0                 test al, al
// 005baaea  7414                 je 0x5bab00
// 005baaec  8b862c020000         mov eax, dword ptr [esi + 0x22c]
// 005baaf2  8d4c3818             lea ecx, [eax + edi + 0x18]
// 005baaf6  51                   push ecx
// 005baaf7  8d4c2410             lea ecx, [esp + 0x10]
// 005baafb  e8106dfaff           call 0x561810
// 005bab00  0fb7560e             movzx edx, word ptr [esi + 0xe]
// 005bab04  43                   inc ebx
// 005bab05  81c708120000         add edi, 0x1208
// 005bab0b  3bda                 cmp ebx, edx
// 005bab0d  72a5                 jb 0x5baab4
// 005bab0f  8b442424             mov eax, dword ptr [esp + 0x24]
// 005bab13  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005bab17  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005bab1b  8910                 mov dword ptr [eax], edx
// 005bab1d  8b542414             mov edx, dword ptr [esp + 0x14]
// 005bab21  894804               mov dword ptr [eax + 4], ecx
// 005bab24  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005bab28  895008               mov dword ptr [eax + 8], edx
// 005bab2b  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 005bab2f  5f                   pop edi
// 005bab30  5b                   pop ebx
// 005bab31  89480c               mov dword ptr [eax + 0xc], ecx
// 005bab34  895010               mov dword ptr [eax + 0x10], edx
// 005bab37  5e                   pop esi
// 005bab38  83c414               add esp, 0x14
// 005bab3b  c21800               ret 0x18
// 005bab3e  69db08120000         imul ebx, ebx, 0x1208
// 005bab44  8bc2                 mov eax, edx
// 005bab46  8b540318             mov edx, dword ptr [ebx + eax + 0x18]
// 005bab4a  8d4c0318             lea ecx, [ebx + eax + 0x18]
// 005bab4e  8b442424             mov eax, dword ptr [esp + 0x24]
// 005bab52  8910                 mov dword ptr [eax], edx
// 005bab54  8b5104               mov edx, dword ptr [ecx + 4]
// 005bab57  895004               mov dword ptr [eax + 4], edx
// 005bab5a  8b5108               mov edx, dword ptr [ecx + 8]
// 005bab5d  895008               mov dword ptr [eax + 8], edx
// 005bab60  8b510c               mov edx, dword ptr [ecx + 0xc]
// 005bab63  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 005bab66  5f                   pop edi
// 005bab67  5b                   pop ebx
// 005bab68  89500c               mov dword ptr [eax + 0xc], edx
// 005bab6b  894810               mov dword ptr [eax + 0x10], ecx
// 005bab6e  5e                   pop esi
// 005bab6f  83c414               add esp, 0x14
// 005bab72  c21800               ret 0x18
// copied from an identical function in another client (function ?GetExternalID@RakPeer@RakNet@@UBE?AUSystemAddress@2@U32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp