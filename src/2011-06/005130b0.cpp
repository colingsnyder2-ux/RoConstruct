// from server: 100% by auto
// roc 2011-06 005130b0  unit: RBX::Network::PhysicsPacketCache::VCachedBitStream::?$sp_counted_impl_p  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005130b0
//
// 005130b0  8d442404             lea eax, [esp + 4]
// 005130b4  50                   push eax
// 005130b5  81c194000000         add ecx, 0x94
// 005130bb  e820ffffff           call 0x512fe0
// 005130c0  c20400               ret 4
// library ogre-1.7.0/OgreRenderTarget.cpp (function ?addListener@RenderTarget@Ogre@@UAEXPAVRenderTargetListener@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreRenderTarget.cpp
