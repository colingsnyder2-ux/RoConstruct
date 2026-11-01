// from server: 100% by auto
// roc 2007-08 0076ce20  unit: seg_00760000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0076ce20
//
// 0076ce20  b930b98b00           mov ecx, 0x8bb930
// 0076ce25  e88667e1ff           call 0x5835b0
// 0076ce2a  a334b98b00           mov dword ptr [0x8bb934], eax
// 0076ce2f  c6401501             mov byte ptr [eax + 0x15], 1
// 0076ce33  a134b98b00           mov eax, dword ptr [0x8bb934]
// 0076ce38  894004               mov dword ptr [eax + 4], eax
// 0076ce3b  a134b98b00           mov eax, dword ptr [0x8bb934]
// 0076ce40  8900                 mov dword ptr [eax], eax
// 0076ce42  a134b98b00           mov eax, dword ptr [0x8bb934]
// 0076ce47  894008               mov dword ptr [eax + 8], eax
// 0076ce4a  6880797700           push 0x777980
// 0076ce4f  c70538b98b0000000000 mov dword ptr [0x8bb938], 0
// 0076ce59  e8c53eecff           call 0x630d23
// 0076ce5e  59                   pop ecx
// 0076ce5f  c3                   ret 
// library ogre-1.6.4/OgreWindowEventUtilities.cpp (function ??__E?_msListeners@WindowEventUtilities@Ogre@@2V?$multimap@PAVRenderWindow@Ogre@@PAVWindowEventListener@2@U?$less@PAVRenderWindow@Ogre@@@std@@V?$allocator@U?$pair@QAVRenderWindow@Ogre@@PAVWindowEventListener@2@@std@@@5@@std@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreWindowEventUtilities.cpp
