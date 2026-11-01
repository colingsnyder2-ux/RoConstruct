// from server: 100% by auto
// roc 2011-06 00a172b0  unit: seg_00a10000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00a172b0
//
// 00a172b0  b95441cb00           mov ecx, 0xcb4154
// 00a172b5  e8c665c1ff           call 0x62d880
// 00a172ba  a35841cb00           mov dword ptr [0xcb4158], eax
// 00a172bf  c6401501             mov byte ptr [eax + 0x15], 1
// 00a172c3  a15841cb00           mov eax, dword ptr [0xcb4158]
// 00a172c8  894004               mov dword ptr [eax + 4], eax
// 00a172cb  a15841cb00           mov eax, dword ptr [0xcb4158]
// 00a172d0  8900                 mov dword ptr [eax], eax
// 00a172d2  a15841cb00           mov eax, dword ptr [0xcb4158]
// 00a172d7  894008               mov dword ptr [eax + 8], eax
// 00a172da  68301ea300           push 0xa31e30
// 00a172df  c7055c41cb0000000000 mov dword ptr [0xcb415c], 0
// 00a172e9  e86f3edfff           call 0x80b15d
// 00a172ee  59                   pop ecx
// 00a172ef  c3                   ret 
// library ogre-1.6.4/OgreWindowEventUtilities.cpp (function ??__E?_msListeners@WindowEventUtilities@Ogre@@2V?$multimap@PAVRenderWindow@Ogre@@PAVWindowEventListener@2@U?$less@PAVRenderWindow@Ogre@@@std@@V?$allocator@U?$pair@QAVRenderWindow@Ogre@@PAVWindowEventListener@2@@std@@@5@@std@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreWindowEventUtilities.cpp
