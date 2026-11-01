// from server: 100% by auto
// roc 2009-12 007ed960  unit: W4_D3DFORMAT::?$EnumDesc  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007ed960
//
// 007ed960  6aff                 push -1
// 007ed962  6868849500           push 0x958468
// 007ed967  64a100000000         mov eax, dword ptr fs:[0]
// 007ed96d  50                   push eax
// 007ed96e  51                   push ecx
// 007ed96f  56                   push esi
// 007ed970  a10052b600           mov eax, dword ptr [0xb65200]
// 007ed975  33c4                 xor eax, esp
// 007ed977  50                   push eax
// 007ed978  8d44240c             lea eax, [esp + 0xc]
// 007ed97c  64a300000000         mov dword ptr fs:[0], eax
// 007ed982  8bf1                 mov esi, ecx
// 007ed984  6a04                 push 4
// 007ed986  e8d55e0000           call 0x7f3860
// 007ed98b  33c9                 xor ecx, ecx
// 007ed98d  83c404               add esp, 4
// 007ed990  3bc1                 cmp eax, ecx
// 007ed992  7404                 je 0x7ed998
// 007ed994  8930                 mov dword ptr [eax], esi
// 007ed996  eb02                 jmp 0x7ed99a
// 007ed998  33c0                 xor eax, eax
// 007ed99a  8906                 mov dword ptr [esi], eax
// 007ed99c  894e0c               mov dword ptr [esi + 0xc], ecx
// 007ed99f  894e10               mov dword ptr [esi + 0x10], ecx
// 007ed9a2  894e14               mov dword ptr [esi + 0x14], ecx
// 007ed9a5  8bc6                 mov eax, esi
// 007ed9a7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007ed9ab  64890d00000000       mov dword ptr fs:[0], ecx
// 007ed9b2  59                   pop ecx
// 007ed9b3  5e                   pop esi
// 007ed9b4  83c410               add esp, 0x10
// 007ed9b7  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??0?$vector@PAVKeyFrame@Ogre@@V?$allocator@PAVKeyFrame@Ogre@@@std@@@std@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
