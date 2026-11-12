// from server: 100% by auto
// roc 2008-06 004c2840  unit: ProfiledRakPeer  size: 277 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c2840
//
// 004c2840  56                   push esi
// 004c2841  8bf1                 mov esi, ecx
// 004c2843  6870cb9300           push 0x93cb70
// 004c2848  8d4c240c             lea ecx, [esp + 0xc]
// 004c284c  e8cf6ffeff           call 0x4a9820
// 004c2851  84c0                 test al, al
// 004c2853  757a                 jne 0x4c28cf
// 004c2855  55                   push ebp
// 004c2856  33ed                 xor ebp, ebp
// 004c2858  39ae2c020000         cmp dword ptr [esi + 0x22c], ebp
// 004c285e  746e                 je 0x4c28ce
// 004c2860  8a4604               mov al, byte ptr [esi + 4]
// 004c2863  3c01                 cmp al, 1
// 004c2865  7467                 je 0x4c28ce
// 004c2867  807c241400           cmp byte ptr [esp + 0x14], 0
// 004c286c  7420                 je 0x4c288e
// 004c286e  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004c2872  8b542418             mov edx, dword ptr [esp + 0x18]
// 004c2876  8b442410             mov eax, dword ptr [esp + 0x10]
// 004c287a  51                   push ecx
// 004c287b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c287f  52                   push edx
// 004c2880  50                   push eax
// 004c2881  51                   push ecx
// 004c2882  8bce                 mov ecx, esi
// 004c2884  e8c7f9ffff           call 0x4c2250
// 004c2889  5d                   pop ebp
// 004c288a  5e                   pop esi
// 004c288b  c21400               ret 0x14
// 004c288e  807c241800           cmp byte ptr [esp + 0x18], 0
// 004c2893  747a                 je 0x4c290f
// 004c2895  57                   push edi
// 004c2896  33d2                 xor edx, edx
// 004c2898  33ff                 xor edi, edi
// 004c289a  663b5608             cmp dx, word ptr [esi + 8]
// 004c289e  732d                 jae 0x4c28cd
// 004c28a0  8b862c020000         mov eax, dword ptr [esi + 0x22c]
// 004c28a6  03c5                 add eax, ebp
// 004c28a8  803800               cmp byte ptr [eax], 0
// 004c28ab  7411                 je 0x4c28be
// 004c28ad  8d4c2410             lea ecx, [esp + 0x10]
// 004c28b1  51                   push ecx
// 004c28b2  8d4804               lea ecx, [eax + 4]
// 004c28b5  e8666ffeff           call 0x4a9820
// 004c28ba  84c0                 test al, al
// 004c28bc  7515                 jne 0x4c28d3
// 004c28be  0fb75608             movzx edx, word ptr [esi + 8]
// 004c28c2  47                   inc edi
// 004c28c3  81c550080000         add ebp, 0x850
// 004c28c9  3bfa                 cmp edi, edx
// 004c28cb  72d3                 jb 0x4c28a0
// 004c28cd  5f                   pop edi
// 004c28ce  5d                   pop ebp
// 004c28cf  5e                   pop esi
// 004c28d0  c21400               ret 0x14
// 004c28d3  8b862c020000         mov eax, dword ptr [esi + 0x22c]
// 004c28d9  69ff50080000         imul edi, edi, 0x850
// 004c28df  c6040700             mov byte ptr [edi + eax], 0
// 004c28e3  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 004c28e9  6a00                 push 0
// 004c28eb  8d4c3918             lea ecx, [ecx + edi + 0x18]
// 004c28ef  e87c130100           call 0x4d3c70
// 004c28f4  6850b54b00           push 0x4bb550
// 004c28f9  8d542414             lea edx, [esp + 0x14]
// 004c28fd  52                   push edx
// 004c28fe  8d8e30020000         lea ecx, [esi + 0x230]
// 004c2904  e857deffff           call 0x4c0760
// 004c2909  5f                   pop edi
// 004c290a  5d                   pop ebp
// 004c290b  5e                   pop esi
// 004c290c  c21400               ret 0x14
// 004c290f  81c6e4060000         add esi, 0x6e4
// 004c2915  8bce                 mov ecx, esi
// 004c2917  e8249bffff           call 0x4bc440
// 004c291c  c7403401000000       mov dword ptr [eax + 0x34], 1
// 004c2923  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004c2927  894810               mov dword ptr [eax + 0x10], ecx
// 004c292a  668b542410           mov dx, word ptr [esp + 0x10]
// 004c292f  8a4c241c             mov cl, byte ptr [esp + 0x1c]
// 004c2933  66895014             mov word ptr [eax + 0x14], dx
// 004c2937  896830               mov dword ptr [eax + 0x30], ebp
// 004c293a  88480c               mov byte ptr [eax + 0xc], cl
// 004c293d  8b560c               mov edx, dword ptr [esi + 0xc]
// 004c2940  ff4614               inc dword ptr [esi + 0x14]
// 004c2943  c6423801             mov byte ptr [edx + 0x38], 1
// 004c2947  8b460c               mov eax, dword ptr [esi + 0xc]
// 004c294a  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 004c294d  5d                   pop ebp
// 004c294e  894e0c               mov dword ptr [esi + 0xc], ecx
// 004c2951  5e                   pop esi
// 004c2952  c21400               ret 0x14
// library openrbx-raknet/RakPeer.cpp (function ?CloseConnectionInternal@RakPeer@@IAEXUSystemAddress@@_N1E@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
