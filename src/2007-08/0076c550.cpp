// from server: 100% by auto
// roc 2007-08 0076c550  unit: seg_00760000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0076c550
//
// 0076c550  b930ae8b00           mov ecx, 0x8bae30
// 0076c555  e856cee3ff           call 0x5a93b0
// 0076c55a  a334ae8b00           mov dword ptr [0x8bae34], eax
// 0076c55f  c6401101             mov byte ptr [eax + 0x11], 1
// 0076c563  a134ae8b00           mov eax, dword ptr [0x8bae34]
// 0076c568  894004               mov dword ptr [eax + 4], eax
// 0076c56b  a134ae8b00           mov eax, dword ptr [0x8bae34]
// 0076c570  8900                 mov dword ptr [eax], eax
// 0076c572  a134ae8b00           mov eax, dword ptr [0x8bae34]
// 0076c577  894008               mov dword ptr [eax + 8], eax
// 0076c57a  6810717700           push 0x777110
// 0076c57f  c70538ae8b0000000000 mov dword ptr [0x8bae38], 0
// 0076c589  e89547ecff           call 0x630d23
// 0076c58e  59                   pop ecx
// 0076c58f  c3                   ret 
// library ogre-1.6.4/OgrePass.cpp (function ??__E?msDirtyHashList@Pass@Ogre@@1V?$set@PAVPass@Ogre@@U?$less@PAVPass@Ogre@@@std@@V?$allocator@PAVPass@Ogre@@@4@@std@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgrePass.cpp
