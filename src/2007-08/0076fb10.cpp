// from server: 100% by auto
// roc 2007-08 0076fb10  unit: seg_00760000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0076fb10
//
// 0076fb10  b9f4f98b00           mov ecx, 0x8bf9f4
// 0076fb15  e8268bd6ff           call 0x4d8640
// 0076fb1a  a3f8f98b00           mov dword ptr [0x8bf9f8], eax
// 0076fb1f  c6402101             mov byte ptr [eax + 0x21], 1
// 0076fb23  a1f8f98b00           mov eax, dword ptr [0x8bf9f8]
// 0076fb28  894004               mov dword ptr [eax + 4], eax
// 0076fb2b  a1f8f98b00           mov eax, dword ptr [0x8bf9f8]
// 0076fb30  8900                 mov dword ptr [eax], eax
// 0076fb32  a1f8f98b00           mov eax, dword ptr [0x8bf9f8]
// 0076fb37  894008               mov dword ptr [eax + 8], eax
// 0076fb3a  68e08c7700           push 0x778ce0
// 0076fb3f  c705fcf98b0000000000 mov dword ptr [0x8bf9fc], 0
// 0076fb49  e8d511ecff           call 0x630d23
// 0076fb4e  59                   pop ecx
// 0076fb4f  c3                   ret 
// library ogre-1.6.4/OgreCompositorScriptCompiler.cpp (function ??__E?mTokenActionMap@CompositorScriptCompiler@Ogre@@1V?$map@IP8CompositorScriptCompiler@Ogre@@AEXXZU?$less@I@std@@V?$allocator@U?$pair@$$CBIP8CompositorScriptCompiler@Ogre@@AEXXZ@std@@@4@@std@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompositorScriptCompiler.cpp
