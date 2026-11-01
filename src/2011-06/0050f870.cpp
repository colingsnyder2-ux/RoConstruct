// from server: 100% by auto
// roc 2011-06 0050f870  unit: Exposer  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0050f870
//
// 0050f870  8b01                 mov eax, dword ptr [ecx]
// 0050f872  8b404c               mov eax, dword ptr [eax + 0x4c]
// 0050f875  ffe0                 jmp eax
// library ogre-1.6.4/OgreRenderSystem.cpp (function ?destroyRenderWindow@RenderSystem@Ogre@@UAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreRenderSystem.cpp
