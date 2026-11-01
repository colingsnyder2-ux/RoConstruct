// from server: 100% by auto
// roc 2011-06 0067dbb0  unit: RBX::KernelJoint  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0067dbb0
//
// 0067dbb0  8a442404             mov al, byte ptr [esp + 4]
// 0067dbb4  88811c020000         mov byte ptr [ecx + 0x21c], al
// 0067dbba  c20400               ret 4
// library ogre-1.6.4/OgreParticleSystem.cpp (function ?setCullIndividually@ParticleSystem@Ogre@@UAEX_N@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreParticleSystem.cpp
