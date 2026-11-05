// roc 2012-06 005c0600  unit: RakNet::RakPeer  size: 290 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c0600
//
// 005c0600  83ec08               sub esp, 8
// 005c0603  53                   push ebx
// 005c0604  55                   push ebp
// 005c0605  56                   push esi
// 005c0606  57                   push edi
// 005c0607  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 005c060b  8b07                 mov eax, dword ptr [edi]
// 005c060d  83c007               add eax, 7
// 005c0610  8bf1                 mov esi, ecx
// 005c0612  a9f8ffffff           test eax, 0xfffffff8
// 005c0617  0f84f9000000         je 0x5c0716
// 005c061d  83be2c02000000       cmp dword ptr [esi + 0x22c], 0
// 005c0624  0f84ec000000         je 0x5c0716
// 005c062a  8a4e04               mov cl, byte ptr [esi + 4]
// 005c062d  80f901               cmp cl, 1
// 005c0630  0f84e0000000         je 0x5c0716
// 005c0636  807c245400           cmp byte ptr [esp + 0x54], 0
// 005c063b  7511                 jne 0x5c064e
// 005c063d  8d4c242c             lea ecx, [esp + 0x2c]
// 005c0641  e84a9fffff           call 0x5ba590
// 005c0646  84c0                 test al, al
// 005c0648  0f85c8000000         jne 0x5c0716
// 005c064e  8b5c2458             mov ebx, dword ptr [esp + 0x58]
// 005c0652  85db                 test ebx, ebx
// 005c0654  750b                 jne 0x5c0661
// 005c0656  8b16                 mov edx, dword ptr [esi]
// 005c0658  8b4248               mov eax, dword ptr [edx + 0x48]
// 005c065b  8bce                 mov ecx, esi
// 005c065d  ffd0                 call eax
// 005c065f  8bd8                 mov ebx, eax
// 005c0661  807c245400           cmp byte ptr [esp + 0x54], 0
// 005c0666  756e                 jne 0x5c06d6
// 005c0668  6a01                 push 1
// 005c066a  8d4c2430             lea ecx, [esp + 0x30]
// 005c066e  51                   push ecx
// 005c066f  8bce                 mov ecx, esi
// 005c0671  e8faadffff           call 0x5bb470
// 005c0676  84c0                 test al, al
// 005c0678  745c                 je 0x5c06d6
// 005c067a  8b07                 mov eax, dword ptr [edi]
// 005c067c  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 005c067f  8b16                 mov edx, dword ptr [esi]
// 005c0681  8b5254               mov edx, dword ptr [edx + 0x54]
// 005c0684  83c007               add eax, 7
// 005c0687  c1e803               shr eax, 3
// 005c068a  50                   push eax
// 005c068b  51                   push ecx
// 005c068c  8bce                 mov ecx, esi
// 005c068e  ffd2                 call edx
// 005c0690  837c242405           cmp dword ptr [esp + 0x24], 5
// 005c0695  7c33                 jl 0x5c06ca
// 005c0697  8dbec8050000         lea edi, [esi + 0x5c8]
// 005c069d  8bcf                 mov ecx, edi
// 005c069f  c64424100e           mov byte ptr [esp + 0x10], 0xe
// 005c06a4  e8b788e5ff           call 0x418f60
// 005c06a9  8b86e0050000         mov eax, dword ptr [esi + 0x5e0]
// 005c06af  8bcf                 mov ecx, edi
// 005c06b1  89442411             mov dword ptr [esp + 0x11], eax
// 005c06b5  e8b688e5ff           call 0x418f70
// 005c06ba  8b16                 mov edx, dword ptr [esi]
// 005c06bc  8b5254               mov edx, dword ptr [edx + 0x54]
// 005c06bf  6a05                 push 5
// 005c06c1  8d442414             lea eax, [esp + 0x14]
// 005c06c5  50                   push eax
// 005c06c6  8bce                 mov ecx, esi
// 005c06c8  ffd2                 call edx
// 005c06ca  8bc3                 mov eax, ebx
// 005c06cc  5f                   pop edi
// 005c06cd  5e                   pop esi
// 005c06ce  5d                   pop ebp
// 005c06cf  5b                   pop ebx
// 005c06d0  83c408               add esp, 8
// 005c06d3  c24000               ret 0x40
// 005c06d6  8b442454             mov eax, dword ptr [esp + 0x54]
// 005c06da  8b2f                 mov ebp, dword ptr [edi]
// 005c06dc  8b7f0c               mov edi, dword ptr [edi + 0xc]
// 005c06df  53                   push ebx
// 005c06e0  6a00                 push 0
// 005c06e2  50                   push eax
// 005c06e3  83ec28               sub esp, 0x28
// 005c06e6  8d542460             lea edx, [esp + 0x60]
// 005c06ea  8bcc                 mov ecx, esp
// 005c06ec  52                   push edx
// 005c06ed  e8fe9dffff           call 0x5ba4f0
// 005c06f2  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 005c06f6  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 005c06fa  8b542454             mov edx, dword ptr [esp + 0x54]
// 005c06fe  50                   push eax
// 005c06ff  51                   push ecx
// 005c0700  52                   push edx
// 005c0701  55                   push ebp
// 005c0702  57                   push edi
// 005c0703  8bce                 mov ecx, esi
// 005c0705  e8d6f6ffff           call 0x5bfde0
// 005c070a  8bc3                 mov eax, ebx
// 005c070c  5f                   pop edi
// 005c070d  5e                   pop esi
// 005c070e  5d                   pop ebp
// 005c070f  5b                   pop ebx
// 005c0710  83c408               add esp, 8
// 005c0713  c24000               ret 0x40
// 005c0716  5f                   pop edi
// 005c0717  5e                   pop esi
// 005c0718  5d                   pop ebp
// 005c0719  33c0                 xor eax, eax
// 005c071b  5b                   pop ebx
// 005c071c  83c408               add esp, 8
// 005c071f  c24000               ret 0x40
// copied from an identical function in another client (function ?Send@RakPeer@RakNet@@UAEIPBVBitStream@2@W4PacketPriority@@W4PacketReliability@@DUAddressOrGUID@2@_NI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp