// from server: 100% by auto
// roc 2010-06 007a0340  unit: RBX::TaskScheduler::VThread::?$sp_counted_impl_p  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007a0340
//
// 007a0340  6aff                 push -1
// 007a0342  68d8e09a00           push 0x9ae0d8
// 007a0347  64a100000000         mov eax, dword ptr fs:[0]
// 007a034d  50                   push eax
// 007a034e  83ec0c               sub esp, 0xc
// 007a0351  56                   push esi
// 007a0352  a1b05fbe00           mov eax, dword ptr [0xbe5fb0]
// 007a0357  33c4                 xor eax, esp
// 007a0359  50                   push eax
// 007a035a  8d442414             lea eax, [esp + 0x14]
// 007a035e  64a300000000         mov dword ptr fs:[0], eax
// 007a0364  8bf1                 mov esi, ecx
// 007a0366  89742408             mov dword ptr [esp + 8], esi
// 007a036a  8b4618               mov eax, dword ptr [esi + 0x18]
// 007a036d  8b0e                 mov ecx, dword ptr [esi]
// 007a036f  8b10                 mov edx, dword ptr [eax]
// 007a0371  50                   push eax
// 007a0372  51                   push ecx
// 007a0373  52                   push edx
// 007a0374  51                   push ecx
// 007a0375  8d44241c             lea eax, [esp + 0x1c]
// 007a0379  50                   push eax
// 007a037a  8bce                 mov ecx, esi
// 007a037c  c744243000000000     mov dword ptr [esp + 0x30], 0
// 007a0384  e8d7feffff           call 0x7a0260
// 007a0389  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007a038c  51                   push ecx
// 007a038d  e808760000           call 0x7a799a
// 007a0392  8b16                 mov edx, dword ptr [esi]
// 007a0394  52                   push edx
// 007a0395  c7461800000000       mov dword ptr [esi + 0x18], 0
// 007a039c  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007a03a3  e8f2750000           call 0x7a799a
// 007a03a8  83c408               add esp, 8
// 007a03ab  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a03af  64890d00000000       mov dword ptr fs:[0], ecx
// 007a03b6  59                   pop ecx
// 007a03b7  5e                   pop esi
// 007a03b8  83c418               add esp, 0x18
// 007a03bb  c3                   ret 
// library ogre-1.7.0/OgreAnimationState.cpp (function ??1?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAVAnimationState@Ogre@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAVAnimationState@Ogre@@@std@@@2@$0A@@std@@@std@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationState.cpp
