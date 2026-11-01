// from server: 100% by auto
// roc 2010-06 007a1aa0  unit: W4_D3DFORMAT::?$EnumDesc  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007a1aa0
//
// 007a1aa0  6aff                 push -1
// 007a1aa2  6898e39a00           push 0x9ae398
// 007a1aa7  64a100000000         mov eax, dword ptr fs:[0]
// 007a1aad  50                   push eax
// 007a1aae  51                   push ecx
// 007a1aaf  56                   push esi
// 007a1ab0  a1b05fbe00           mov eax, dword ptr [0xbe5fb0]
// 007a1ab5  33c4                 xor eax, esp
// 007a1ab7  50                   push eax
// 007a1ab8  8d44240c             lea eax, [esp + 0xc]
// 007a1abc  64a300000000         mov dword ptr fs:[0], eax
// 007a1ac2  8bf1                 mov esi, ecx
// 007a1ac4  6a04                 push 4
// 007a1ac6  e8d55e0000           call 0x7a79a0
// 007a1acb  33c9                 xor ecx, ecx
// 007a1acd  83c404               add esp, 4
// 007a1ad0  3bc1                 cmp eax, ecx
// 007a1ad2  7404                 je 0x7a1ad8
// 007a1ad4  8930                 mov dword ptr [eax], esi
// 007a1ad6  eb02                 jmp 0x7a1ada
// 007a1ad8  33c0                 xor eax, eax
// 007a1ada  8906                 mov dword ptr [esi], eax
// 007a1adc  894e0c               mov dword ptr [esi + 0xc], ecx
// 007a1adf  894e10               mov dword ptr [esi + 0x10], ecx
// 007a1ae2  894e14               mov dword ptr [esi + 0x14], ecx
// 007a1ae5  8bc6                 mov eax, esi
// 007a1ae7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007a1aeb  64890d00000000       mov dword ptr fs:[0], ecx
// 007a1af2  59                   pop ecx
// 007a1af3  5e                   pop esi
// 007a1af4  83c410               add esp, 0x10
// 007a1af7  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??0?$vector@PAVKeyFrame@Ogre@@V?$allocator@PAVKeyFrame@Ogre@@@std@@@std@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
