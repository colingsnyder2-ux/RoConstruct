// from server: 100% by auto
// roc 2008-06 004d0550  unit: RBX::Network::PhysicsSender  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d0550
//
// 004d0550  80b98c07000000       cmp byte ptr [ecx + 0x78c], 0
// 004d0557  7405                 je 0x4d055e
// 004d0559  33c0                 xor eax, eax
// 004d055b  c20400               ret 4
// 004d055e  8b5114               mov edx, dword ptr [ecx + 0x14]
// 004d0561  56                   push esi
// 004d0562  8b7110               mov esi, dword ptr [ecx + 0x10]
// 004d0565  3bf2                 cmp esi, edx
// 004d0567  7706                 ja 0x4d056f
// 004d0569  2bd6                 sub edx, esi
// 004d056b  8bc2                 mov eax, edx
// 004d056d  eb07                 jmp 0x4d0576
// 004d056f  8b4118               mov eax, dword ptr [ecx + 0x18]
// 004d0572  2bc6                 sub eax, esi
// 004d0574  03c2                 add eax, edx
// 004d0576  85c0                 test eax, eax
// 004d0578  7649                 jbe 0x4d05c3
// 004d057a  ff4110               inc dword ptr [ecx + 0x10]
// 004d057d  8b4110               mov eax, dword ptr [ecx + 0x10]
// 004d0580  8b5118               mov edx, dword ptr [ecx + 0x18]
// 004d0583  3bc2                 cmp eax, edx
// 004d0585  7507                 jne 0x4d058e
// 004d0587  c7411000000000       mov dword ptr [ecx + 0x10], 0
// 004d058e  8b4110               mov eax, dword ptr [ecx + 0x10]
// 004d0591  85c0                 test eax, eax
// 004d0593  7509                 jne 0x4d059e
// 004d0595  8b410c               mov eax, dword ptr [ecx + 0xc]
// 004d0598  8b4490fc             mov eax, dword ptr [eax + edx*4 - 4]
// 004d059c  eb07                 jmp 0x4d05a5
// 004d059e  8b510c               mov edx, dword ptr [ecx + 0xc]
// 004d05a1  8b4482fc             mov eax, dword ptr [edx + eax*4 - 4]
// 004d05a5  8b503c               mov edx, dword ptr [eax + 0x3c]
// 004d05a8  8b742408             mov esi, dword ptr [esp + 8]
// 004d05ac  8916                 mov dword ptr [esi], edx
// 004d05ae  8b7038               mov esi, dword ptr [eax + 0x38]
// 004d05b1  50                   push eax
// 004d05b2  81c1b0070000         add ecx, 0x7b0
// 004d05b8  e8e3f3ffff           call 0x4cf9a0
// 004d05bd  8bc6                 mov eax, esi
// 004d05bf  5e                   pop esi
// 004d05c0  c20400               ret 4
// 004d05c3  33c0                 xor eax, eax
// 004d05c5  5e                   pop esi
// 004d05c6  c20400               ret 4
// library openrbx-raknet/ReliabilityLayer.cpp (function ?Receive@ReliabilityLayer@@QAEHPAPAE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
