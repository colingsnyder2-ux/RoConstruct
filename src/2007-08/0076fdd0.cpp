// from server: 100% by auto
// roc 2007-08 0076fdd0  unit: seg_00760000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0076fdd0
//
// 0076fdd0  b960fa8b00           mov ecx, 0x8bfa60
// 0076fdd5  e86688d6ff           call 0x4d8640
// 0076fdda  a364fa8b00           mov dword ptr [0x8bfa64], eax
// 0076fddf  c6402101             mov byte ptr [eax + 0x21], 1
// 0076fde3  a164fa8b00           mov eax, dword ptr [0x8bfa64]
// 0076fde8  894004               mov dword ptr [eax + 4], eax
// 0076fdeb  a164fa8b00           mov eax, dword ptr [0x8bfa64]
// 0076fdf0  8900                 mov dword ptr [eax], eax
// 0076fdf2  a164fa8b00           mov eax, dword ptr [0x8bfa64]
// 0076fdf7  894008               mov dword ptr [eax + 8], eax
// 0076fdfa  68e08e7700           push 0x778ee0
// 0076fdff  c70568fa8b0000000000 mov dword ptr [0x8bfa68], 0
// 0076fe09  e8150fecff           call 0x630d23
// 0076fe0e  59                   pop ecx
// 0076fe0f  c3                   ret 
// library ogre-1.6.4/OgreCompositorScriptCompiler.cpp (function ??__E?mTokenActionMap@CompositorScriptCompiler@Ogre@@1V?$map@IP8CompositorScriptCompiler@Ogre@@AEXXZU?$less@I@std@@V?$allocator@U?$pair@$$CBIP8CompositorScriptCompiler@Ogre@@AEXXZ@std@@@4@@std@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompositorScriptCompiler.cpp
