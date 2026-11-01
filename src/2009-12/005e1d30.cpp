// from server: 100% by auto
// roc 2009-12 005e1d30  unit: RBX::RenderSceneBase  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005e1d30
//
// 005e1d30  56                   push esi
// 005e1d31  8bf1                 mov esi, ecx
// 005e1d33  8d4e04               lea ecx, [esi + 4]
// 005e1d36  c706d4169c00         mov dword ptr [esi], 0x9c16d4
// 005e1d3c  e83ffaffff           call 0x5e1780
// 005e1d41  f644240801           test byte ptr [esp + 8], 1
// 005e1d46  7409                 je 0x5e1d51
// 005e1d48  56                   push esi
// 005e1d49  e80c1b2100           call 0x7f385a
// 005e1d4e  83c404               add esp, 4
// 005e1d51  8bc6                 mov eax, esi
// 005e1d53  5e                   pop esi
// 005e1d54  c20400               ret 4
// library ogre-1.6.4/OgreHardwareVertexBuffer.cpp (function ??_GVertexDeclaration@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreHardwareVertexBuffer.cpp
