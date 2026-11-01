// from server: 100% by auto
// roc 2009-12 0048b930  unit: G3D::Shader  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048b930
//
// 0048b930  8a442404             mov al, byte ptr [esp + 4]
// 0048b934  884114               mov byte ptr [ecx + 0x14], al
// 0048b937  c20400               ret 4
// library ogre-1.6.4/OgreAutoParamDataSource.cpp (function ?setShadowsEnabled@RenderQueueGroup@Ogre@@QAEX_N@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAutoParamDataSource.cpp
