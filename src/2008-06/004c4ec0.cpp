// from server: 100% by auto
// roc 2008-06 004c4ec0  unit: ProfiledRakPeer  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c4ec0
//
// 004c4ec0  56                   push esi
// 004c4ec1  57                   push edi
// 004c4ec2  8bf9                 mov edi, ecx
// 004c4ec4  e8c7f1ffff           call 0x4c4090
// 004c4ec9  8bf0                 mov esi, eax
// 004c4ecb  85f6                 test esi, esi
// 004c4ecd  7449                 je 0x4c4f18
// 004c4ecf  90                   nop 
// 004c4ed0  8b4614               mov eax, dword ptr [esi + 0x14]
// 004c4ed3  8a08                 mov cl, byte ptr [eax]
// 004c4ed5  80f90b               cmp cl, 0xb
// 004c4ed8  7411                 je 0x4c4eeb
// 004c4eda  837e0c05             cmp dword ptr [esi + 0xc], 5
// 004c4ede  7636                 jbe 0x4c4f16
// 004c4ee0  80f918               cmp cl, 0x18
// 004c4ee3  7531                 jne 0x4c4f16
// 004c4ee5  8078050b             cmp byte ptr [eax + 5], 0xb
// 004c4ee9  752b                 jne 0x4c4f16
// 004c4eeb  8b4e08               mov ecx, dword ptr [esi + 8]
// 004c4eee  8b5604               mov edx, dword ptr [esi + 4]
// 004c4ef1  51                   push ecx
// 004c4ef2  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004c4ef5  52                   push edx
// 004c4ef6  51                   push ecx
// 004c4ef7  50                   push eax
// 004c4ef8  8bcf                 mov ecx, edi
// 004c4efa  e841b0ffff           call 0x4bff40
// 004c4eff  8b17                 mov edx, dword ptr [edi]
// 004c4f01  8b4240               mov eax, dword ptr [edx + 0x40]
// 004c4f04  56                   push esi
// 004c4f05  8bcf                 mov ecx, edi
// 004c4f07  ffd0                 call eax
// 004c4f09  8bcf                 mov ecx, edi
// 004c4f0b  e880f1ffff           call 0x4c4090
// 004c4f10  8bf0                 mov esi, eax
// 004c4f12  85f6                 test esi, esi
// 004c4f14  75ba                 jne 0x4c4ed0
// 004c4f16  8bc6                 mov eax, esi
// 004c4f18  5f                   pop edi
// 004c4f19  5e                   pop esi
// 004c4f1a  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ?Receive@RakPeer@@UAEPAUPacket@@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
