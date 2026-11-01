// from server: 100% by auto
// roc 2007-08 0076ff10  unit: seg_00760000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0076ff10
//
// 0076ff10  b930fa8b00           mov ecx, 0x8bfa30
// 0076ff15  e82687d6ff           call 0x4d8640
// 0076ff1a  a334fa8b00           mov dword ptr [0x8bfa34], eax
// 0076ff1f  c6402101             mov byte ptr [eax + 0x21], 1
// 0076ff23  a134fa8b00           mov eax, dword ptr [0x8bfa34]
// 0076ff28  894004               mov dword ptr [eax + 4], eax
// 0076ff2b  a134fa8b00           mov eax, dword ptr [0x8bfa34]
// 0076ff30  8900                 mov dword ptr [eax], eax
// 0076ff32  a134fa8b00           mov eax, dword ptr [0x8bfa34]
// 0076ff37  894008               mov dword ptr [eax + 8], eax
// 0076ff3a  68e08d7700           push 0x778de0
// 0076ff3f  c70538fa8b0000000000 mov dword ptr [0x8bfa38], 0
// 0076ff49  e8d50decff           call 0x630d23
// 0076ff4e  59                   pop ecx
// 0076ff4f  c3                   ret 
// library ogre-1.6.4/OgreCompositorScriptCompiler.cpp (function ??__E?mTokenActionMap@CompositorScriptCompiler@Ogre@@1V?$map@IP8CompositorScriptCompiler@Ogre@@AEXXZU?$less@I@std@@V?$allocator@U?$pair@$$CBIP8CompositorScriptCompiler@Ogre@@AEXXZ@std@@@4@@std@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompositorScriptCompiler.cpp
