// from server: 92% by EspClaude
// from server: 100% by auto
// roc 2008-06 004a1f90  unit: RBX::Network::P8Players::?$GetImpl  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a1f90
//
// 004a1f90  55                   push ebp
// 004a1f91  8bec                 mov ebp, esp
// 004a1f93  6aff                 push -1
// 004a1f95  68a17b7c00           push 0x7c7ba1
// 004a1f9a  64a100000000         mov eax, dword ptr fs:[0]
// 004a1fa0  50                   push eax
// 004a1fa1  64892500000000       mov dword ptr fs:[0], esp
// 004a1fa8  83ec0c               sub esp, 0xc
// 004a1fab  53                   push ebx
// 004a1fac  56                   push esi
// 004a1fad  57                   push edi
// 004a1fae  8965f0               mov dword ptr [ebp - 0x10], esp
// 004a1fb1  6a2c                 push 0x2c
// 004a1fb3  e868e91f00           call 0x6a0920
// 004a1fb8  8bf0                 mov esi, eax
// 004a1fba  83c404               add esp, 4
// 004a1fbd  8975ec               mov dword ptr [ebp - 0x14], esi
// 004a1fc0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004a1fc7  8975e8               mov dword ptr [ebp - 0x18], esi
// 004a1fca  c645fc01             mov byte ptr [ebp - 4], 1
// 004a1fce  85f6                 test esi, esi
// 004a1fd0  7428                 je 0x4a1ffa
// 004a1fd2  8b4508               mov eax, dword ptr [ebp + 8]
// 004a1fd5  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004a1fd8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004a1fdb  8906                 mov dword ptr [esi], eax
// 004a1fdd  8b4514               mov eax, dword ptr [ebp + 0x14]
// 004a1fe0  894e04               mov dword ptr [esi + 4], ecx
// 004a1fe3  50                   push eax
// 004a1fe4  8d4e0c               lea ecx, [esi + 0xc]
// 004a1fe7  895608               mov dword ptr [esi + 8], edx
// 004a1fea  ff155c248000         call dword ptr [0x80245c]
// 004a1ff0  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 004a1ff3  884e28               mov byte ptr [esi + 0x28], cl
// 004a1ff6  c6462900             mov byte ptr [esi + 0x29], 0
// 004a1ffa  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004a1ffd  5f                   pop edi
// 004a1ffe  8bc6                 mov eax, esi
// 004a2000  5e                   pop esi
// 004a2001  64890d00000000       mov dword ptr fs:[0], ecx
// 004a2008  5b                   pop ebx
// 004a2009  8be5                 mov esp, ebp
// 004a200b  5d                   pop ebp
// 004a200c  c21400               ret 0x14

// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreBillboardChain.cpp
