// from server: 100% by auto
// roc 2009-12 004b8420  unit: Ogre::RbxArchiveFactory  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b8420
//
// 004b8420  6aff                 push -1
// 004b8422  68d8c59300           push 0x93c5d8
// 004b8427  64a100000000         mov eax, dword ptr fs:[0]
// 004b842d  50                   push eax
// 004b842e  64892500000000       mov dword ptr fs:[0], esp
// 004b8435  51                   push ecx
// 004b8436  56                   push esi
// 004b8437  8bf1                 mov esi, ecx
// 004b8439  89742404             mov dword ptr [esp + 4], esi
// 004b843d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004b8445  e8b601f6ff           call 0x418600
// 004b844a  8b06                 mov eax, dword ptr [esi]
// 004b844c  50                   push eax
// 004b844d  e808b43300           call 0x7f385a
// 004b8452  83c404               add esp, 4
// 004b8455  f644241801           test byte ptr [esp + 0x18], 1
// 004b845a  7409                 je 0x4b8465
// 004b845c  56                   push esi
// 004b845d  e8f8b33300           call 0x7f385a
// 004b8462  83c404               add esp, 4
// 004b8465  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004b8469  8bc6                 mov eax, esi
// 004b846b  5e                   pop esi
// 004b846c  64890d00000000       mov dword ptr fs:[0], ecx
// 004b8473  83c410               add esp, 0x10
// 004b8476  c20400               ret 4
// library ogre-1.7.0/OgreScriptLexer.cpp (function ??_G?$vector@V?$SharedPtr@UScriptToken@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@UScriptToken@Ogre@@@Ogre@@@std@@@std@@QAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptLexer.cpp
