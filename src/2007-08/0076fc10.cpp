// from server: 100% by auto
// roc 2007-08 0076fc10  unit: seg_00760000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0076fc10
//
// 0076fc10  b9e8f98b00           mov ecx, 0x8bf9e8
// 0076fc15  e8268ad6ff           call 0x4d8640
// 0076fc1a  a3ecf98b00           mov dword ptr [0x8bf9ec], eax
// 0076fc1f  c6402101             mov byte ptr [eax + 0x21], 1
// 0076fc23  a1ecf98b00           mov eax, dword ptr [0x8bf9ec]
// 0076fc28  894004               mov dword ptr [eax + 4], eax
// 0076fc2b  a1ecf98b00           mov eax, dword ptr [0x8bf9ec]
// 0076fc30  8900                 mov dword ptr [eax], eax
// 0076fc32  a1ecf98b00           mov eax, dword ptr [0x8bf9ec]
// 0076fc37  894008               mov dword ptr [eax + 8], eax
// 0076fc3a  68208c7700           push 0x778c20
// 0076fc3f  c705f0f98b0000000000 mov dword ptr [0x8bf9f0], 0
// 0076fc49  e8d510ecff           call 0x630d23
// 0076fc4e  59                   pop ecx
// 0076fc4f  c3                   ret 
// library ogre-1.6.4/OgreCompositorScriptCompiler.cpp (function ??__E?mTokenActionMap@CompositorScriptCompiler@Ogre@@1V?$map@IP8CompositorScriptCompiler@Ogre@@AEXXZU?$less@I@std@@V?$allocator@U?$pair@$$CBIP8CompositorScriptCompiler@Ogre@@AEXXZ@std@@@4@@std@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompositorScriptCompiler.cpp
