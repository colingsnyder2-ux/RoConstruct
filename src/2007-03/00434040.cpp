// from server: 100% by auto
// roc 2007-03 00434040  unit: seg_00430000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00434040
//
// 00434040  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00434044  8b01                 mov eax, dword ptr [ecx]
// 00434046  8b10                 mov edx, dword ptr [eax]
// 00434048  c744240400000000     mov dword ptr [esp + 4], 0
// 00434050  ffe2                 jmp edx
// library ogre-1.6.4/OgreAutoParamDataSource.cpp (function ?destroy@?$allocator@VTexturePtr@Ogre@@@std@@QAEXPAVTexturePtr@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAutoParamDataSource.cpp
