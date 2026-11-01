// from server: 100% by auto
// roc 2009-12 0047e6b0  unit: Ogre::VResource::?$SharedPtr  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047e6b0
//
// 0047e6b0  56                   push esi
// 0047e6b1  8b742408             mov esi, dword ptr [esp + 8]
// 0047e6b5  85f6                 test esi, esi
// 0047e6b7  7516                 jne 0x47e6cf
// 0047e6b9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0047e6bd  8b5104               mov edx, dword ptr [ecx + 4]
// 0047e6c0  33c0                 xor eax, eax
// 0047e6c2  52                   push edx
// 0047e6c3  50                   push eax
// 0047e6c4  8b01                 mov eax, dword ptr [ecx]
// 0047e6c6  ffd0                 call eax
// 0047e6c8  83c408               add esp, 8
// 0047e6cb  8bc6                 mov eax, esi
// 0047e6cd  5e                   pop esi
// 0047e6ce  c3                   ret 
// 0047e6cf  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0047e6d3  8b06                 mov eax, dword ptr [esi]
// 0047e6d5  8b4004               mov eax, dword ptr [eax + 4]
// 0047e6d8  8b5104               mov edx, dword ptr [ecx + 4]
// 0047e6db  03c6                 add eax, esi
// 0047e6dd  52                   push edx
// 0047e6de  50                   push eax
// 0047e6df  8b01                 mov eax, dword ptr [ecx]
// 0047e6e1  ffd0                 call eax
// 0047e6e3  83c408               add esp, 8
// 0047e6e6  8bc6                 mov eax, esi
// 0047e6e8  5e                   pop esi
// 0047e6e9  c3                   ret 
// library ogre-1.6.4/OgreLog.cpp (function ??$?6DU?$char_traits@D@std@@H@std@@YAAAV?$basic_ostream@DU?$char_traits@D@std@@@0@AAV10@ABU?$_Smanip@H@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreLog.cpp
