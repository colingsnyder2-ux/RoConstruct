// from server: 100% by auto
// roc 2008-06 004c9790  unit: RBX::Network::InterpolatingPhysicsReceiver  size: 378 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c9790
//
// 004c9790  83ec10               sub esp, 0x10
// 004c9793  803da41a970000       cmp byte ptr [0x971aa4], 0
// 004c979a  53                   push ebx
// 004c979b  55                   push ebp
// 004c979c  56                   push esi
// 004c979d  57                   push edi
// 004c979e  bb01000000           mov ebx, 1
// 004c97a3  7413                 je 0x4c97b8
// 004c97a5  a1a81a9700           mov eax, dword ptr [0x971aa8]
// 004c97aa  03c3                 add eax, ebx
// 004c97ac  a3a81a9700           mov dword ptr [0x971aa8], eax
// 004c97b1  3dc8000000           cmp eax, 0xc8
// 004c97b6  753d                 jne 0x4c97f5
// 004c97b8  68981a9700           push 0x971a98
// 004c97bd  ff155c228000         call dword ptr [0x80225c]
// 004c97c3  c705a81a970000000000 mov dword ptr [0x971aa8], 0
// 004c97cd  881da41a9700         mov byte ptr [0x971aa4], bl
// 004c97d3  ff15e4218000         call dword ptr [0x8021e4]
// 004c97d9  68a01a9700           push 0x971aa0
// 004c97de  68941a9700           push 0x971a94
// 004c97e3  50                   push eax
// 004c97e4  ff1558228000         call dword ptr [0x802258]
// 004c97ea  ff1530228000         call dword ptr [0x802230]
// 004c97f0  a3901a9700           mov dword ptr [0x971a90], eax
// 004c97f5  841dbc1a9700         test byte ptr [0x971abc], bl
// 004c97fb  7511                 jne 0x4c980e
// 004c97fd  091dbc1a9700         or dword ptr [0x971abc], ebx
// 004c9803  ff15e8218000         call dword ptr [0x8021e8]
// 004c9809  a3b81a9700           mov dword ptr [0x971ab8], eax
// 004c980e  a1901a9700           mov eax, dword ptr [0x971a90]
// 004c9813  8b3554228000         mov esi, dword ptr [0x802254]
// 004c9819  53                   push ebx
// 004c981a  50                   push eax
// 004c981b  ffd6                 call esi
// 004c981d  8d4c2410             lea ecx, [esp + 0x10]
// 004c9821  51                   push ecx
// 004c9822  ff1550228000         call dword ptr [0x802250]
// 004c9828  8b15941a9700         mov edx, dword ptr [0x971a94]
// 004c982e  a1901a9700           mov eax, dword ptr [0x971a90]
// 004c9833  52                   push edx
// 004c9834  50                   push eax
// 004c9835  ffd6                 call esi
// 004c9837  8b359c1a9700         mov esi, dword ptr [0x971a9c]
// 004c983d  8b3d981a9700         mov edi, dword ptr [0x971a98]
// 004c9843  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004c9847  8b542410             mov edx, dword ptr [esp + 0x10]
// 004c984b  56                   push esi
// 004c984c  57                   push edi
// 004c984d  51                   push ecx
// 004c984e  52                   push edx
// 004c984f  e88c841d00           call 0x6a1ce0
// 004c9854  6a00                 push 0
// 004c9856  6840420f00           push 0xf4240
// 004c985b  53                   push ebx
// 004c985c  51                   push ecx
// 004c985d  8be8                 mov ebp, eax
// 004c985f  8954242c             mov dword ptr [esp + 0x2c], edx
// 004c9863  e8687e1d00           call 0x6a16d0
// 004c9868  56                   push esi
// 004c9869  57                   push edi
// 004c986a  52                   push edx
// 004c986b  50                   push eax
// 004c986c  e8bf831d00           call 0x6a1c30
// 004c9871  6a00                 push 0
// 004c9873  8bf0                 mov esi, eax
// 004c9875  8b442420             mov eax, dword ptr [esp + 0x20]
// 004c9879  6840420f00           push 0xf4240
// 004c987e  50                   push eax
// 004c987f  55                   push ebp
// 004c9880  8bfa                 mov edi, edx
// 004c9882  e8497e1d00           call 0x6a16d0
// 004c9887  8b0db01a9700         mov ecx, dword ptr [0x971ab0]
// 004c988d  03f0                 add esi, eax
// 004c988f  13fa                 adc edi, edx
// 004c9891  0b0db41a9700         or ecx, dword ptr [0x971ab4]
// 004c9897  7459                 je 0x4c98f2
// 004c9899  ff15e8218000         call dword ptr [0x8021e8]
// 004c989f  8be8                 mov ebp, eax
// 004c98a1  8bdd                 mov ebx, ebp
// 004c98a3  2b1db81a9700         sub ebx, dword ptr [0x971ab8]
// 004c98a9  8bd6                 mov edx, esi
// 004c98ab  2b15b01a9700         sub edx, dword ptr [0x971ab0]
// 004c98b1  6a00                 push 0
// 004c98b3  8bc7                 mov eax, edi
// 004c98b5  1b05b41a9700         sbb eax, dword ptr [0x971ab4]
// 004c98bb  68e8030000           push 0x3e8
// 004c98c0  50                   push eax
// 004c98c1  52                   push edx
// 004c98c2  e869831d00           call 0x6a1c30
// 004c98c7  33c9                 xor ecx, ecx
// 004c98c9  3bd1                 cmp edx, ecx
// 004c98cb  7c1f                 jl 0x4c98ec
// 004c98cd  7f07                 jg 0x4c98d6
// 004c98cf  8d4b64               lea ecx, [ebx + 0x64]
// 004c98d2  3bc1                 cmp eax, ecx
// 004c98d4  7616                 jbe 0x4c98ec
// 004c98d6  69dbe8030000         imul ebx, ebx, 0x3e8
// 004c98dc  8bf3                 mov esi, ebx
// 004c98de  33ff                 xor edi, edi
// 004c98e0  0335b01a9700         add esi, dword ptr [0x971ab0]
// 004c98e6  133db41a9700         adc edi, dword ptr [0x971ab4]
// 004c98ec  892db81a9700         mov dword ptr [0x971ab8], ebp
// 004c98f2  8bd7                 mov edx, edi
// 004c98f4  893db41a9700         mov dword ptr [0x971ab4], edi
// 004c98fa  5f                   pop edi
// 004c98fb  8bc6                 mov eax, esi
// 004c98fd  8935b01a9700         mov dword ptr [0x971ab0], esi
// 004c9903  5e                   pop esi
// 004c9904  5d                   pop ebp
// 004c9905  5b                   pop ebx
// 004c9906  83c410               add esp, 0x10
// 004c9909  c3                   ret 
// library openrbx-raknet/GetTime.cpp (function ?GetTimeNS@RakNet@@YA_JXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet GetTime.cpp
