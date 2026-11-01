// from server: 100% by auto
// roc 2011-06 00a15870  unit: seg_00a10000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00a15870
//
// 00a15870  b9a015cb00           mov ecx, 0xcb15a0
// 00a15875  e8067bd7ff           call 0x78d380
// 00a1587a  a3a415cb00           mov dword ptr [0xcb15a4], eax
// 00a1587f  c6401101             mov byte ptr [eax + 0x11], 1
// 00a15883  a1a415cb00           mov eax, dword ptr [0xcb15a4]
// 00a15888  894004               mov dword ptr [eax + 4], eax
// 00a1588b  a1a415cb00           mov eax, dword ptr [0xcb15a4]
// 00a15890  8900                 mov dword ptr [eax], eax
// 00a15892  a1a415cb00           mov eax, dword ptr [0xcb15a4]
// 00a15897  894008               mov dword ptr [eax + 8], eax
// 00a1589a  6880ffa200           push 0xa2ff80
// 00a1589f  c705a815cb0000000000 mov dword ptr [0xcb15a8], 0
// 00a158a9  e8af58dfff           call 0x80b15d
// 00a158ae  59                   pop ecx
// 00a158af  c3                   ret 
// library ogre-1.6.4/OgrePass.cpp (function ??__E?msDirtyHashList@Pass@Ogre@@1V?$set@PAVPass@Ogre@@U?$less@PAVPass@Ogre@@@std@@V?$allocator@PAVPass@Ogre@@@4@@std@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgrePass.cpp
