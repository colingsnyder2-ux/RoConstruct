// from server: 100% by auto
// roc 2007-08 00434050  unit: CNullDoc  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00434050
//
// 00434050  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00434054  8b01                 mov eax, dword ptr [ecx]
// 00434056  8b10                 mov edx, dword ptr [eax]
// 00434058  c744240400000000     mov dword ptr [esp + 4], 0
// 00434060  ffe2                 jmp edx
// library ogre-1.7.0/OgreScriptLexer.cpp (function ?destroy@?$allocator@V?$SharedPtr@UScriptToken@Ogre@@@Ogre@@@std@@QAEXPAV?$SharedPtr@UScriptToken@Ogre@@@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptLexer.cpp
