// from server: 100% by auto
// roc 2010-06 008c6430  unit: Ogre::RbxFont::CodePointMap7Bit  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c6430
//
// 008c6430  0fbe442404           movsx eax, byte ptr [esp + 4]
// 008c6435  c20400               ret 4
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??R?$hash@D@boost@@QBEID@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
