// from server: 100% by auto
// roc 2008-06 004bcf30  unit: ProfiledRakPeer  size: 188 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bcf30
//
// 004bcf30  8b442408             mov eax, dword ptr [esp + 8]
// 004bcf34  53                   push ebx
// 004bcf35  56                   push esi
// 004bcf36  57                   push edi
// 004bcf37  85c0                 test eax, eax
// 004bcf39  745a                 je 0x4bcf95
// 004bcf3b  8b10                 mov edx, dword ptr [eax]
// 004bcf3d  8b700c               mov esi, dword ptr [eax + 0xc]
// 004bcf40  8b442440             mov eax, dword ptr [esp + 0x40]
// 004bcf44  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 004bcf48  50                   push eax
// 004bcf49  83ec0c               sub esp, 0xc
// 004bcf4c  8bc4                 mov eax, esp
// 004bcf4e  8918                 mov dword ptr [eax], ebx
// 004bcf50  8b5c2448             mov ebx, dword ptr [esp + 0x48]
// 004bcf54  895804               mov dword ptr [eax + 4], ebx
// 004bcf57  8b5c244c             mov ebx, dword ptr [esp + 0x4c]
// 004bcf5b  8b39                 mov edi, dword ptr [ecx]
// 004bcf5d  895808               mov dword ptr [eax + 8], ebx
// 004bcf60  8b442440             mov eax, dword ptr [esp + 0x40]
// 004bcf64  50                   push eax
// 004bcf65  8b442440             mov eax, dword ptr [esp + 0x40]
// 004bcf69  50                   push eax
// 004bcf6a  8b442440             mov eax, dword ptr [esp + 0x40]
// 004bcf6e  50                   push eax
// 004bcf6f  8b442440             mov eax, dword ptr [esp + 0x40]
// 004bcf73  50                   push eax
// 004bcf74  8b442440             mov eax, dword ptr [esp + 0x40]
// 004bcf78  50                   push eax
// 004bcf79  8b442440             mov eax, dword ptr [esp + 0x40]
// 004bcf7d  50                   push eax
// 004bcf7e  8b442440             mov eax, dword ptr [esp + 0x40]
// 004bcf82  50                   push eax
// 004bcf83  8b4760               mov eax, dword ptr [edi + 0x60]
// 004bcf86  52                   push edx
// 004bcf87  8b542440             mov edx, dword ptr [esp + 0x40]
// 004bcf8b  56                   push esi
// 004bcf8c  52                   push edx
// 004bcf8d  ffd0                 call eax
// 004bcf8f  5f                   pop edi
// 004bcf90  5e                   pop esi
// 004bcf91  5b                   pop ebx
// 004bcf92  c23400               ret 0x34
// 004bcf95  8b442440             mov eax, dword ptr [esp + 0x40]
// 004bcf99  8b742434             mov esi, dword ptr [esp + 0x34]
// 004bcf9d  50                   push eax
// 004bcf9e  83ec0c               sub esp, 0xc
// 004bcfa1  8bc4                 mov eax, esp
// 004bcfa3  8930                 mov dword ptr [eax], esi
// 004bcfa5  8b742448             mov esi, dword ptr [esp + 0x48]
// 004bcfa9  897004               mov dword ptr [eax + 4], esi
// 004bcfac  8b74244c             mov esi, dword ptr [esp + 0x4c]
// 004bcfb0  8b11                 mov edx, dword ptr [ecx]
// 004bcfb2  897008               mov dword ptr [eax + 8], esi
// 004bcfb5  8b442440             mov eax, dword ptr [esp + 0x40]
// 004bcfb9  50                   push eax
// 004bcfba  8b442440             mov eax, dword ptr [esp + 0x40]
// 004bcfbe  50                   push eax
// 004bcfbf  8b442440             mov eax, dword ptr [esp + 0x40]
// 004bcfc3  8b5260               mov edx, dword ptr [edx + 0x60]
// 004bcfc6  50                   push eax
// 004bcfc7  8b442440             mov eax, dword ptr [esp + 0x40]
// 004bcfcb  50                   push eax
// 004bcfcc  8b442440             mov eax, dword ptr [esp + 0x40]
// 004bcfd0  50                   push eax
// 004bcfd1  8b442440             mov eax, dword ptr [esp + 0x40]
// 004bcfd5  50                   push eax
// 004bcfd6  8b442440             mov eax, dword ptr [esp + 0x40]
// 004bcfda  50                   push eax
// 004bcfdb  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 004bcfdf  6a00                 push 0
// 004bcfe1  6a00                 push 0
// 004bcfe3  50                   push eax
// 004bcfe4  ffd2                 call edx
// 004bcfe6  5f                   pop edi
// 004bcfe7  5e                   pop esi
// 004bcfe8  5b                   pop ebx
// 004bcfe9  c23400               ret 0x34
// library openrbx-raknet/RakPeer.cpp (function ?RPC@RakPeer@@UAE_NPBDPBVBitStream@RakNet@@W4PacketPriority@@W4PacketReliability@@DUSystemAddress@@_NPAIUNetworkID@@PAV23@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
