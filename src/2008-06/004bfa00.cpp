// from server: 100% by auto
// roc 2008-06 004bfa00  unit: ProfiledRakPeer  size: 211 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bfa00
//
// 004bfa00  56                   push esi
// 004bfa01  57                   push edi
// 004bfa02  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004bfa06  8b07                 mov eax, dword ptr [edi]
// 004bfa08  83c007               add eax, 7
// 004bfa0b  8bf1                 mov esi, ecx
// 004bfa0d  a9f8ffffff           test eax, 0xfffffff8
// 004bfa12  7507                 jne 0x4bfa1b
// 004bfa14  5f                   pop edi
// 004bfa15  32c0                 xor al, al
// 004bfa17  5e                   pop esi
// 004bfa18  c21c00               ret 0x1c
// 004bfa1b  83be2c02000000       cmp dword ptr [esi + 0x22c], 0
// 004bfa22  74f0                 je 0x4bfa14
// 004bfa24  8a4e04               mov cl, byte ptr [esi + 4]
// 004bfa27  80f901               cmp cl, 1
// 004bfa2a  74e8                 je 0x4bfa14
// 004bfa2c  53                   push ebx
// 004bfa2d  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 004bfa31  84db                 test bl, bl
// 004bfa33  756c                 jne 0x4bfaa1
// 004bfa35  6870cb9300           push 0x93cb70
// 004bfa3a  8d4c2424             lea ecx, [esp + 0x24]
// 004bfa3e  e8dd9dfeff           call 0x4a9820
// 004bfa43  84c0                 test al, al
// 004bfa45  7408                 je 0x4bfa4f
// 004bfa47  5b                   pop ebx
// 004bfa48  5f                   pop edi
// 004bfa49  32c0                 xor al, al
// 004bfa4b  5e                   pop esi
// 004bfa4c  c21c00               ret 0x1c
// 004bfa4f  83be2c07000000       cmp dword ptr [esi + 0x72c], 0
// 004bfa56  7449                 je 0x4bfaa1
// 004bfa58  8b442424             mov eax, dword ptr [esp + 0x24]
// 004bfa5c  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004bfa60  8b16                 mov edx, dword ptr [esi]
// 004bfa62  8b5268               mov edx, dword ptr [edx + 0x68]
// 004bfa65  50                   push eax
// 004bfa66  51                   push ecx
// 004bfa67  8bce                 mov ecx, esi
// 004bfa69  ffd2                 call edx
// 004bfa6b  84c0                 test al, al
// 004bfa6d  7532                 jne 0x4bfaa1
// 004bfa6f  8b8e2c070000         mov ecx, dword ptr [esi + 0x72c]
// 004bfa75  8b742424             mov esi, dword ptr [esp + 0x24]
// 004bfa79  8b07                 mov eax, dword ptr [edi]
// 004bfa7b  8b7f0c               mov edi, dword ptr [edi + 0xc]
// 004bfa7e  8b11                 mov edx, dword ptr [ecx]
// 004bfa80  56                   push esi
// 004bfa81  8b742424             mov esi, dword ptr [esp + 0x24]
// 004bfa85  56                   push esi
// 004bfa86  8b742424             mov esi, dword ptr [esp + 0x24]
// 004bfa8a  56                   push esi
// 004bfa8b  8b742424             mov esi, dword ptr [esp + 0x24]
// 004bfa8f  56                   push esi
// 004bfa90  8b742424             mov esi, dword ptr [esp + 0x24]
// 004bfa94  56                   push esi
// 004bfa95  50                   push eax
// 004bfa96  8b02                 mov eax, dword ptr [edx]
// 004bfa98  57                   push edi
// 004bfa99  ffd0                 call eax
// 004bfa9b  5b                   pop ebx
// 004bfa9c  5f                   pop edi
// 004bfa9d  5e                   pop esi
// 004bfa9e  c21c00               ret 0x1c
// 004bfaa1  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004bfaa5  8b542420             mov edx, dword ptr [esp + 0x20]
// 004bfaa9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004bfaad  6a00                 push 0
// 004bfaaf  53                   push ebx
// 004bfab0  51                   push ecx
// 004bfab1  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004bfab5  52                   push edx
// 004bfab6  8b542424             mov edx, dword ptr [esp + 0x24]
// 004bfaba  50                   push eax
// 004bfabb  8b07                 mov eax, dword ptr [edi]
// 004bfabd  51                   push ecx
// 004bfabe  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 004bfac1  52                   push edx
// 004bfac2  50                   push eax
// 004bfac3  51                   push ecx
// 004bfac4  8bce                 mov ecx, esi
// 004bfac6  e865dbffff           call 0x4bd630
// 004bfacb  5b                   pop ebx
// 004bfacc  5f                   pop edi
// 004bfacd  b001                 mov al, 1
// 004bfacf  5e                   pop esi
// 004bfad0  c21c00               ret 0x1c
// library openrbx-raknet/RakPeer.cpp (function ?Send@RakPeer@@UAE_NPBVBitStream@RakNet@@W4PacketPriority@@W4PacketReliability@@DUSystemAddress@@_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
