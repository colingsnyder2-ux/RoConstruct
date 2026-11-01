// from server: 100% by auto
// roc 2009-12 00427de0  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00427de0
//
// 00427de0  8b01                 mov eax, dword ptr [ecx]
// 00427de2  50                   push eax
// 00427de3  e83a744e00           call 0x90f222
// 00427de8  c3                   ret 
// library ogre-1.7.0/OgreTextureUnitState.cpp (function ?_getTexturePtr@TextureUnitState@Ogre@@QBEABVTexturePtr@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreTextureUnitState.cpp
