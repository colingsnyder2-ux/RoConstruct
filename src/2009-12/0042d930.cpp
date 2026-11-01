// from server: 100% by auto
// roc 2009-12 0042d930  unit: CNullDoc  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0042d930
//
// 0042d930  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042d934  8b01                 mov eax, dword ptr [ecx]
// 0042d936  8b10                 mov edx, dword ptr [eax]
// 0042d938  c744240400000000     mov dword ptr [esp + 4], 0
// 0042d940  ffe2                 jmp edx
// library ogre-1.6.4/OgreAutoParamDataSource.cpp (function ?destroy@?$allocator@VTexturePtr@Ogre@@@std@@QAEXPAVTexturePtr@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAutoParamDataSource.cpp
