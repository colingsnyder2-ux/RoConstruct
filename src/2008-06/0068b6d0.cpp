// from server: 100% by auto
// roc 2008-06 0068b6d0  unit: Ogre::RbxSceneManager  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068b6d0
//
// 0068b6d0  56                   push esi
// 0068b6d1  8bf1                 mov esi, ecx
// 0068b6d3  837e2000             cmp dword ptr [esi + 0x20], 0
// 0068b6d7  7506                 jne 0x68b6df
// 0068b6d9  8b06                 mov eax, dword ptr [esi]
// 0068b6db  8b10                 mov edx, dword ptr [eax]
// 0068b6dd  ffd2                 call edx
// 0068b6df  8b4620               mov eax, dword ptr [esi + 0x20]
// 0068b6e2  5e                   pop esi
// 0068b6e3  c3                   ret 
// library ogre-1.4.9/OgreSceneManager.cpp (function ?getRenderQueue@SceneManager@Ogre@@UAEPAVRenderQueue@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
