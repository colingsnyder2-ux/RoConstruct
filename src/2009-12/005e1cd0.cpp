// from server: 100% by auto
// roc 2009-12 005e1cd0  unit: G3D::Lighting  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005e1cd0
//
// 005e1cd0  c701d4169c00         mov dword ptr [ecx], 0x9c16d4
// 005e1cd6  83c104               add ecx, 4
// 005e1cd9  e9a2faffff           jmp 0x5e1780
// library ogre-1.6.4/OgreHardwareVertexBuffer.cpp (function ??1VertexDeclaration@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreHardwareVertexBuffer.cpp
