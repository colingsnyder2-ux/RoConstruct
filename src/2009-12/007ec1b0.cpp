// from server: 100% by auto
// roc 2009-12 007ec1b0  unit: RBX::TaskScheduler::VThread::?$sp_counted_impl_p  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007ec1b0
//
// 007ec1b0  6aff                 push -1
// 007ec1b2  68a8819500           push 0x9581a8
// 007ec1b7  64a100000000         mov eax, dword ptr fs:[0]
// 007ec1bd  50                   push eax
// 007ec1be  83ec0c               sub esp, 0xc
// 007ec1c1  56                   push esi
// 007ec1c2  a10052b600           mov eax, dword ptr [0xb65200]
// 007ec1c7  33c4                 xor eax, esp
// 007ec1c9  50                   push eax
// 007ec1ca  8d442414             lea eax, [esp + 0x14]
// 007ec1ce  64a300000000         mov dword ptr fs:[0], eax
// 007ec1d4  8bf1                 mov esi, ecx
// 007ec1d6  89742408             mov dword ptr [esp + 8], esi
// 007ec1da  8b4618               mov eax, dword ptr [esi + 0x18]
// 007ec1dd  8b0e                 mov ecx, dword ptr [esi]
// 007ec1df  8b10                 mov edx, dword ptr [eax]
// 007ec1e1  50                   push eax
// 007ec1e2  51                   push ecx
// 007ec1e3  52                   push edx
// 007ec1e4  51                   push ecx
// 007ec1e5  8d44241c             lea eax, [esp + 0x1c]
// 007ec1e9  50                   push eax
// 007ec1ea  8bce                 mov ecx, esi
// 007ec1ec  c744243000000000     mov dword ptr [esp + 0x30], 0
// 007ec1f4  e8d7feffff           call 0x7ec0d0
// 007ec1f9  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007ec1fc  51                   push ecx
// 007ec1fd  e858760000           call 0x7f385a
// 007ec202  8b16                 mov edx, dword ptr [esi]
// 007ec204  52                   push edx
// 007ec205  c7461800000000       mov dword ptr [esi + 0x18], 0
// 007ec20c  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007ec213  e842760000           call 0x7f385a
// 007ec218  83c408               add esp, 8
// 007ec21b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007ec21f  64890d00000000       mov dword ptr fs:[0], ecx
// 007ec226  59                   pop ecx
// 007ec227  5e                   pop esi
// 007ec228  83c418               add esp, 0x18
// 007ec22b  c3                   ret 
// library ogre-1.7.0/OgreAnimationState.cpp (function ??1?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAVAnimationState@Ogre@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAVAnimationState@Ogre@@@std@@@2@$0A@@std@@@std@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationState.cpp
