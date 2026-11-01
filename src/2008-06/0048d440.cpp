// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 0048d440  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048d440
//
// 0048d440  55                   push ebp
// 0048d441  8bec                 mov ebp, esp
// 0048d443  6aff                 push -1
// 0048d445  68d8627c00           push 0x7c62d8
// 0048d44a  64a100000000         mov eax, dword ptr fs:[0]
// 0048d450  50                   push eax
// 0048d451  64892500000000       mov dword ptr fs:[0], esp
// 0048d458  83ec08               sub esp, 8
// 0048d45b  53                   push ebx
// 0048d45c  56                   push esi
// 0048d45d  57                   push edi
// 0048d45e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0048d461  8bf1                 mov esi, ecx
// 0048d463  6a04                 push 4
// 0048d465  8975ec               mov dword ptr [ebp - 0x14], esi
// 0048d468  e8b3342100           call 0x6a0920
// 0048d46d  83c404               add esp, 4
// 0048d470  85c0                 test eax, eax
// 0048d472  7404                 je 0x48d478
// 0048d474  8930                 mov dword ptr [eax], esi
// 0048d476  eb02                 jmp 0x48d47a
// 0048d478  33c0                 xor eax, eax
// 0048d47a  8906                 mov dword ptr [esi], eax
// 0048d47c  8bce                 mov ecx, esi
// 0048d47e  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0048d485  e896deffff           call 0x48b320
// 0048d48a  894618               mov dword ptr [esi + 0x18], eax
// 0048d48d  b101                 mov cl, 1
// 0048d48f  88480e               mov byte ptr [eax + 0xe], cl
// 0048d492  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048d495  894004               mov dword ptr [eax + 4], eax
// 0048d498  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048d49b  8900                 mov dword ptr [eax], eax
// 0048d49d  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048d4a0  894008               mov dword ptr [eax + 8], eax
// 0048d4a3  8b4508               mov eax, dword ptr [ebp + 8]
// 0048d4a6  884dfc               mov byte ptr [ebp - 4], cl
// 0048d4a9  50                   push eax
// 0048d4aa  8bce                 mov ecx, esi
// 0048d4ac  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0048d4b3  e8e8f1ffff           call 0x48c6a0
// 0048d4b8  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0048d4bb  5f                   pop edi
// 0048d4bc  8bc6                 mov eax, esi
// 0048d4be  5e                   pop esi
// 0048d4bf  64890d00000000       mov dword ptr fs:[0], ecx
// 0048d4c6  5b                   pop ebx
// 0048d4c7  8be5                 mov esp, ebp
// 0048d4c9  5d                   pop ebp
// 0048d4ca  c20400               ret 4
// library ogre-1.6.4/OgreAutoParamDataSource.cpp (function ??0?$_Tree@V?$_Tset_traits@EU?$less@E@std@@V?$allocator@E@2@$0A@@std@@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAutoParamDataSource.cpp
