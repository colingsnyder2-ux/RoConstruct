// from server: 100% by auto
// roc 2009-12 0047f310  unit: RBX::AdornRbxGfx  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047f310
//
// 0047f310  64a100000000         mov eax, dword ptr fs:[0]
// 0047f316  6aff                 push -1
// 0047f318  6848ea9200           push 0x92ea48
// 0047f31d  50                   push eax
// 0047f31e  8b442410             mov eax, dword ptr [esp + 0x10]
// 0047f322  64892500000000       mov dword ptr fs:[0], esp
// 0047f329  83ec10               sub esp, 0x10
// 0047f32c  56                   push esi
// 0047f32d  8bf1                 mov esi, ecx
// 0047f32f  8b4804               mov ecx, dword ptr [eax + 4]
// 0047f332  394e04               cmp dword ptr [esi + 4], ecx
// 0047f335  7466                 je 0x47f39d
// 0047f337  894c2408             mov dword ptr [esp + 8], ecx
// 0047f33b  8b4808               mov ecx, dword ptr [eax + 8]
// 0047f33e  8b400c               mov eax, dword ptr [eax + 0xc]
// 0047f341  c7442404f0219b00     mov dword ptr [esp + 4], 0x9b21f0
// 0047f349  894c240c             mov dword ptr [esp + 0xc], ecx
// 0047f34d  89442410             mov dword ptr [esp + 0x10], eax
// 0047f351  85c9                 test ecx, ecx
// 0047f353  7402                 je 0x47f357
// 0047f355  ff01                 inc dword ptr [ecx]
// 0047f357  8b16                 mov edx, dword ptr [esi]
// 0047f359  8b5208               mov edx, dword ptr [edx + 8]
// 0047f35c  8d442404             lea eax, [esp + 4]
// 0047f360  50                   push eax
// 0047f361  8bce                 mov ecx, esi
// 0047f363  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0047f36b  ffd2                 call edx
// 0047f36d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0047f371  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0047f379  c7442404f0219b00     mov dword ptr [esp + 4], 0x9b21f0
// 0047f381  85c0                 test eax, eax
// 0047f383  7418                 je 0x47f39d
// 0047f385  ff08                 dec dword ptr [eax]
// 0047f387  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0047f38b  833800               cmp dword ptr [eax], 0
// 0047f38e  750d                 jne 0x47f39d
// 0047f390  8b542404             mov edx, dword ptr [esp + 4]
// 0047f394  8b4204               mov eax, dword ptr [edx + 4]
// 0047f397  8d4c2404             lea ecx, [esp + 4]
// 0047f39b  ffd0                 call eax
// 0047f39d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0047f3a1  8bc6                 mov eax, esi
// 0047f3a3  5e                   pop esi
// 0047f3a4  64890d00000000       mov dword ptr fs:[0], ecx
// 0047f3ab  83c41c               add esp, 0x1c
// 0047f3ae  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??4?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
