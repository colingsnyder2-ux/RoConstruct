// from server: 100% by colin
// roc 2007-08 004c1f10  unit: RakPeer  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004c1f10
//
// 004c1f10  56                   push esi
// 004c1f11  57                   push edi
// 004c1f12  8bf9                 mov edi, ecx
// 004c1f14  e827f7ffff           call 0x4c1640
// 004c1f19  8bf0                 mov esi, eax
// 004c1f1b  85f6                 test esi, esi
// 004c1f1d  7449                 je 0x4c1f68
// 004c1f1f  90                   nop 
// 004c1f20  8b4614               mov eax, dword ptr [esi + 0x14]
// 004c1f23  8a08                 mov cl, byte ptr [eax]
// 004c1f25  80f90b               cmp cl, 0xb
// 004c1f28  7411                 je 0x4c1f3b
// 004c1f2a  837e0c05             cmp dword ptr [esi + 0xc], 5
// 004c1f2e  7636                 jbe 0x4c1f66
// 004c1f30  80f918               cmp cl, 0x18
// 004c1f33  7531                 jne 0x4c1f66
// 004c1f35  8078050b             cmp byte ptr [eax + 5], 0xb
// 004c1f39  752b                 jne 0x4c1f66
// 004c1f3b  8b4e08               mov ecx, dword ptr [esi + 8]
// 004c1f3e  8b5604               mov edx, dword ptr [esi + 4]
// 004c1f41  51                   push ecx
// 004c1f42  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004c1f45  52                   push edx
// 004c1f46  51                   push ecx
// 004c1f47  50                   push eax
// 004c1f48  8bcf                 mov ecx, edi
// 004c1f4a  e881adffff           call 0x4bccd0
// 004c1f4f  8b17                 mov edx, dword ptr [edi]
// 004c1f51  8b4240               mov eax, dword ptr [edx + 0x40]
// 004c1f54  56                   push esi
// 004c1f55  8bcf                 mov ecx, edi
// 004c1f57  ffd0                 call eax
// 004c1f59  8bcf                 mov ecx, edi
// 004c1f5b  e8e0f6ffff           call 0x4c1640
// 004c1f60  8bf0                 mov esi, eax
// 004c1f62  85f6                 test esi, esi
// 004c1f64  75ba                 jne 0x4c1f20
// 004c1f66  8bc6                 mov eax, esi
// 004c1f68  5f                   pop edi
// 004c1f69  5e                   pop esi
// 004c1f6a  c3                   ret 
// copied from an identical function in another client (function ?Receive@RakPeer@@UAEPAUPacket@@XZ)

// from server: 100% by tester
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-raknet RakPeer.cpp