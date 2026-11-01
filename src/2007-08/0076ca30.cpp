// from server: 100% by auto
// roc 2007-08 0076ca30  unit: seg_00760000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0076ca30
//
// 0076ca30  b9f4b18b00           mov ecx, 0x8bb1f4
// 0076ca35  e8766be1ff           call 0x5835b0
// 0076ca3a  a3f8b18b00           mov dword ptr [0x8bb1f8], eax
// 0076ca3f  c6401501             mov byte ptr [eax + 0x15], 1
// 0076ca43  a1f8b18b00           mov eax, dword ptr [0x8bb1f8]
// 0076ca48  894004               mov dword ptr [eax + 4], eax
// 0076ca4b  a1f8b18b00           mov eax, dword ptr [0x8bb1f8]
// 0076ca50  8900                 mov dword ptr [eax], eax
// 0076ca52  a1f8b18b00           mov eax, dword ptr [0x8bb1f8]
// 0076ca57  894008               mov dword ptr [eax + 8], eax
// 0076ca5a  6830747700           push 0x777430
// 0076ca5f  c705fcb18b0000000000 mov dword ptr [0x8bb1fc], 0
// 0076ca69  e8b542ecff           call 0x630d23
// 0076ca6e  59                   pop ecx
// 0076ca6f  c3                   ret 
// library ogre-1.6.4/OgreWindowEventUtilities.cpp (function ??__E?_msListeners@WindowEventUtilities@Ogre@@2V?$multimap@PAVRenderWindow@Ogre@@PAVWindowEventListener@2@U?$less@PAVRenderWindow@Ogre@@@std@@V?$allocator@U?$pair@QAVRenderWindow@Ogre@@PAVWindowEventListener@2@@std@@@5@@std@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreWindowEventUtilities.cpp
