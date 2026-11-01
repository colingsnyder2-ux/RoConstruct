// from server: 100% by auto
// roc 2007-08 0076fd10  unit: seg_00760000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0076fd10
//
// 0076fd10  b918fa8b00           mov ecx, 0x8bfa18
// 0076fd15  e82689d6ff           call 0x4d8640
// 0076fd1a  a31cfa8b00           mov dword ptr [0x8bfa1c], eax
// 0076fd1f  c6402101             mov byte ptr [eax + 0x21], 1
// 0076fd23  a11cfa8b00           mov eax, dword ptr [0x8bfa1c]
// 0076fd28  894004               mov dword ptr [eax + 4], eax
// 0076fd2b  a11cfa8b00           mov eax, dword ptr [0x8bfa1c]
// 0076fd30  8900                 mov dword ptr [eax], eax
// 0076fd32  a11cfa8b00           mov eax, dword ptr [0x8bfa1c]
// 0076fd37  894008               mov dword ptr [eax + 8], eax
// 0076fd3a  68608f7700           push 0x778f60
// 0076fd3f  c70520fa8b0000000000 mov dword ptr [0x8bfa20], 0
// 0076fd49  e8d50fecff           call 0x630d23
// 0076fd4e  59                   pop ecx
// 0076fd4f  c3                   ret 
// library ogre-1.6.4/OgreCompositorScriptCompiler.cpp (function ??__E?mTokenActionMap@CompositorScriptCompiler@Ogre@@1V?$map@IP8CompositorScriptCompiler@Ogre@@AEXXZU?$less@I@std@@V?$allocator@U?$pair@$$CBIP8CompositorScriptCompiler@Ogre@@AEXXZ@std@@@4@@std@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompositorScriptCompiler.cpp
