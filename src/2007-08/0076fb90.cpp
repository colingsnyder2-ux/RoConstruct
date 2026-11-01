// from server: 100% by auto
// roc 2007-08 0076fb90  unit: seg_00760000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0076fb90
//
// 0076fb90  b9dcf98b00           mov ecx, 0x8bf9dc
// 0076fb95  e8a68ad6ff           call 0x4d8640
// 0076fb9a  a3e0f98b00           mov dword ptr [0x8bf9e0], eax
// 0076fb9f  c6402101             mov byte ptr [eax + 0x21], 1
// 0076fba3  a1e0f98b00           mov eax, dword ptr [0x8bf9e0]
// 0076fba8  894004               mov dword ptr [eax + 4], eax
// 0076fbab  a1e0f98b00           mov eax, dword ptr [0x8bf9e0]
// 0076fbb0  8900                 mov dword ptr [eax], eax
// 0076fbb2  a1e0f98b00           mov eax, dword ptr [0x8bf9e0]
// 0076fbb7  894008               mov dword ptr [eax + 8], eax
// 0076fbba  68808c7700           push 0x778c80
// 0076fbbf  c705e4f98b0000000000 mov dword ptr [0x8bf9e4], 0
// 0076fbc9  e85511ecff           call 0x630d23
// 0076fbce  59                   pop ecx
// 0076fbcf  c3                   ret 
// library ogre-1.6.4/OgreCompositorScriptCompiler.cpp (function ??__E?mTokenActionMap@CompositorScriptCompiler@Ogre@@1V?$map@IP8CompositorScriptCompiler@Ogre@@AEXXZU?$less@I@std@@V?$allocator@U?$pair@$$CBIP8CompositorScriptCompiler@Ogre@@AEXXZ@std@@@4@@std@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompositorScriptCompiler.cpp
