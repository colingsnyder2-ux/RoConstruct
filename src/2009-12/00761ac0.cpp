// from server: 100% by auto
// roc 2009-12 00761ac0  unit: RBX::VInstance::?$NonFactoryProduct  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00761ac0
//
// 00761ac0  55                   push ebp
// 00761ac1  8bec                 mov ebp, esp
// 00761ac3  6aff                 push -1
// 00761ac5  68281c9500           push 0x951c28
// 00761aca  64a100000000         mov eax, dword ptr fs:[0]
// 00761ad0  50                   push eax
// 00761ad1  64892500000000       mov dword ptr fs:[0], esp
// 00761ad8  83ec08               sub esp, 8
// 00761adb  53                   push ebx
// 00761adc  56                   push esi
// 00761add  57                   push edi
// 00761ade  8965f0               mov dword ptr [ebp - 0x10], esp
// 00761ae1  8bf1                 mov esi, ecx
// 00761ae3  6a04                 push 4
// 00761ae5  8975ec               mov dword ptr [ebp - 0x14], esi
// 00761ae8  e8731d0900           call 0x7f3860
// 00761aed  83c404               add esp, 4
// 00761af0  85c0                 test eax, eax
// 00761af2  7404                 je 0x761af8
// 00761af4  8930                 mov dword ptr [eax], esi
// 00761af6  eb02                 jmp 0x761afa
// 00761af8  33c0                 xor eax, eax
// 00761afa  8906                 mov dword ptr [esi], eax
// 00761afc  8bce                 mov ecx, esi
// 00761afe  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00761b05  e84689fbff           call 0x71a450
// 00761b0a  894618               mov dword ptr [esi + 0x18], eax
// 00761b0d  b101                 mov cl, 1
// 00761b0f  884811               mov byte ptr [eax + 0x11], cl
// 00761b12  8b4618               mov eax, dword ptr [esi + 0x18]
// 00761b15  894004               mov dword ptr [eax + 4], eax
// 00761b18  8b4618               mov eax, dword ptr [esi + 0x18]
// 00761b1b  8900                 mov dword ptr [eax], eax
// 00761b1d  8b4618               mov eax, dword ptr [esi + 0x18]
// 00761b20  894008               mov dword ptr [eax + 8], eax
// 00761b23  8b4508               mov eax, dword ptr [ebp + 8]
// 00761b26  884dfc               mov byte ptr [ebp - 4], cl
// 00761b29  50                   push eax
// 00761b2a  8bce                 mov ecx, esi
// 00761b2c  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00761b33  e8784f0200           call 0x786ab0
// 00761b38  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00761b3b  5f                   pop edi
// 00761b3c  8bc6                 mov eax, esi
// 00761b3e  5e                   pop esi
// 00761b3f  64890d00000000       mov dword ptr fs:[0], ecx
// 00761b46  5b                   pop ebx
// 00761b47  8be5                 mov esp, ebp
// 00761b49  5d                   pop ebp
// 00761b4a  c20400               ret 4
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ??0?$_Tree@V?$_Tset_traits@PAVPMVertex@ProgressiveMesh@Ogre@@U?$less@PAVPMVertex@ProgressiveMesh@Ogre@@@std@@V?$allocator@PAVPMVertex@ProgressiveMesh@Ogre@@@5@$0A@@std@@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp
