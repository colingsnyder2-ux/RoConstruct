// from server: 100% by auto
// roc 2011-06 004c7020  unit: RBX::Network::VPlayer::?$EventDesc  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004c7020
//
// 004c7020  33c0                 xor eax, eax
// 004c7022  398158010000         cmp dword ptr [ecx + 0x158], eax
// 004c7028  0f95c0               setne al
// 004c702b  c3                   ret 
// library ogre-1.4.9/OgreMesh.cpp (function ?hasVertexAnimation@Mesh@Ogre@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreMesh.cpp
