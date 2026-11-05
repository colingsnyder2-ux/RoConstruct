// from server: 100% by auto
// roc 2008-06 0068fe50  unit: Ogre::RbxSceneManagerFactory  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068fe50
//
// 0068fe50  64a100000000         mov eax, dword ptr fs:[0]
// 0068fe56  6aff                 push -1
// 0068fe58  68a8e27d00           push 0x7de2a8
// 0068fe5d  50                   push eax
// 0068fe5e  64892500000000       mov dword ptr fs:[0], esp
// 0068fe65  83ec0c               sub esp, 0xc
// 0068fe68  56                   push esi
// 0068fe69  8bf1                 mov esi, ecx
// 0068fe6b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0068fe6f  8b4104               mov eax, dword ptr [ecx + 4]
// 0068fe72  394604               cmp dword ptr [esi + 4], eax
// 0068fe75  745f                 je 0x68fed6
// 0068fe77  89442408             mov dword ptr [esp + 8], eax
// 0068fe7b  8b4108               mov eax, dword ptr [ecx + 8]
// 0068fe7e  c74424042cec8400     mov dword ptr [esp + 4], 0x84ec2c
// 0068fe86  8944240c             mov dword ptr [esp + 0xc], eax
// 0068fe8a  85c0                 test eax, eax
// 0068fe8c  7402                 je 0x68fe90
// 0068fe8e  ff00                 inc dword ptr [eax]
// 0068fe90  8b06                 mov eax, dword ptr [esi]
// 0068fe92  8b5008               mov edx, dword ptr [eax + 8]
// 0068fe95  8d4c2404             lea ecx, [esp + 4]
// 0068fe99  51                   push ecx
// 0068fe9a  8bce                 mov ecx, esi
// 0068fe9c  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0068fea4  ffd2                 call edx
// 0068fea6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068feaa  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0068feb2  c74424042cec8400     mov dword ptr [esp + 4], 0x84ec2c
// 0068feba  85c0                 test eax, eax
// 0068febc  7418                 je 0x68fed6
// 0068febe  ff08                 dec dword ptr [eax]
// 0068fec0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068fec4  833800               cmp dword ptr [eax], 0
// 0068fec7  750d                 jne 0x68fed6
// 0068fec9  8b542404             mov edx, dword ptr [esp + 4]
// 0068fecd  8b4204               mov eax, dword ptr [edx + 4]
// 0068fed0  8d4c2404             lea ecx, [esp + 4]
// 0068fed4  ffd0                 call eax
// 0068fed6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0068feda  8bc6                 mov eax, esi
// 0068fedc  5e                   pop esi
// 0068fedd  64890d00000000       mov dword ptr fs:[0], ecx
// 0068fee4  83c418               add esp, 0x18
// 0068fee7  c20400               ret 4
// library ogre-1.4.9/OgreAlignedAllocator.cpp (function ??4?$SharedPtr@VHardwareVertexBuffer@Ogre@@@Ogre@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAlignedAllocator.cpp
