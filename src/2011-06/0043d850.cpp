// from server: 100% by auto
// roc 2011-06 0043d850  unit: CNullDoc  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0043d850
//
// 0043d850  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0043d854  8b01                 mov eax, dword ptr [ecx]
// 0043d856  8b10                 mov edx, dword ptr [eax]
// 0043d858  c744240400000000     mov dword ptr [esp + 4], 0
// 0043d860  ffe2                 jmp edx
// library ogre-1.7.0/OgreScriptLexer.cpp (function ?destroy@?$allocator@V?$SharedPtr@UScriptToken@Ogre@@@Ogre@@@std@@QAEXPAV?$SharedPtr@UScriptToken@Ogre@@@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptLexer.cpp
