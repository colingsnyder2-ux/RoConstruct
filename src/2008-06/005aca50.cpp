// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 005aca50  unit: RBX::VScriptContext::?$FactoryProduct  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005aca50
//
// 005aca50  55                   push ebp
// 005aca51  8bec                 mov ebp, esp
// 005aca53  6aff                 push -1
// 005aca55  6808327d00           push 0x7d3208
// 005aca5a  64a100000000         mov eax, dword ptr fs:[0]
// 005aca60  50                   push eax
// 005aca61  64892500000000       mov dword ptr fs:[0], esp
// 005aca68  83ec08               sub esp, 8
// 005aca6b  53                   push ebx
// 005aca6c  56                   push esi
// 005aca6d  57                   push edi
// 005aca6e  8965f0               mov dword ptr [ebp - 0x10], esp
// 005aca71  8bf1                 mov esi, ecx
// 005aca73  6a04                 push 4
// 005aca75  8975ec               mov dword ptr [ebp - 0x14], esi
// 005aca78  e8a33e0f00           call 0x6a0920
// 005aca7d  83c404               add esp, 4
// 005aca80  85c0                 test eax, eax
// 005aca82  7404                 je 0x5aca88
// 005aca84  8930                 mov dword ptr [eax], esi
// 005aca86  eb02                 jmp 0x5aca8a
// 005aca88  33c0                 xor eax, eax
// 005aca8a  8906                 mov dword ptr [esi], eax
// 005aca8c  8bce                 mov ecx, esi
// 005aca8e  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005aca95  e8b6e2f1ff           call 0x4cad50
// 005aca9a  894618               mov dword ptr [esi + 0x18], eax
// 005aca9d  b101                 mov cl, 1
// 005aca9f  884811               mov byte ptr [eax + 0x11], cl
// 005acaa2  8b4618               mov eax, dword ptr [esi + 0x18]
// 005acaa5  894004               mov dword ptr [eax + 4], eax
// 005acaa8  8b4618               mov eax, dword ptr [esi + 0x18]
// 005acaab  8900                 mov dword ptr [eax], eax
// 005acaad  8b4618               mov eax, dword ptr [esi + 0x18]
// 005acab0  894008               mov dword ptr [eax + 8], eax
// 005acab3  8b4508               mov eax, dword ptr [ebp + 8]
// 005acab6  884dfc               mov byte ptr [ebp - 4], cl
// 005acab9  50                   push eax
// 005acaba  8bce                 mov ecx, esi
// 005acabc  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005acac3  e888f5ffff           call 0x5ac050
// 005acac8  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005acacb  5f                   pop edi
// 005acacc  8bc6                 mov eax, esi
// 005acace  5e                   pop esi
// 005acacf  64890d00000000       mov dword ptr fs:[0], ecx
// 005acad6  5b                   pop ebx
// 005acad7  8be5                 mov esp, ebp
// 005acad9  5d                   pop ebp
// 005acada  c20400               ret 4
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ??0?$_Tree@V?$_Tset_traits@PAVPMVertex@ProgressiveMesh@Ogre@@U?$less@PAVPMVertex@ProgressiveMesh@Ogre@@@std@@V?$allocator@PAVPMVertex@ProgressiveMesh@Ogre@@@5@$0A@@std@@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp
