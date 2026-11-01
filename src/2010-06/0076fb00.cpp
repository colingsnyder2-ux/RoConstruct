// from server: 100% by auto
// roc 2010-06 0076fb00  unit: RBX::ScoreHud  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076fb00
//
// 0076fb00  6aff                 push -1
// 0076fb02  6858a29900           push 0x99a258
// 0076fb07  64a100000000         mov eax, dword ptr fs:[0]
// 0076fb0d  50                   push eax
// 0076fb0e  64892500000000       mov dword ptr fs:[0], esp
// 0076fb15  51                   push ecx
// 0076fb16  56                   push esi
// 0076fb17  8bf1                 mov esi, ecx
// 0076fb19  89742404             mov dword ptr [esp + 4], esi
// 0076fb1d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0076fb25  e8868acaff           call 0x4185b0
// 0076fb2a  8b06                 mov eax, dword ptr [esi]
// 0076fb2c  50                   push eax
// 0076fb2d  e8687e0300           call 0x7a799a
// 0076fb32  83c404               add esp, 4
// 0076fb35  f644241801           test byte ptr [esp + 0x18], 1
// 0076fb3a  7409                 je 0x76fb45
// 0076fb3c  56                   push esi
// 0076fb3d  e8587e0300           call 0x7a799a
// 0076fb42  83c404               add esp, 4
// 0076fb45  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0076fb49  8bc6                 mov eax, esi
// 0076fb4b  5e                   pop esi
// 0076fb4c  64890d00000000       mov dword ptr fs:[0], ecx
// 0076fb53  83c410               add esp, 0x10
// 0076fb56  c20400               ret 4
// library ogre-1.7.0/OgreScriptLexer.cpp (function ??_G?$vector@V?$SharedPtr@UScriptToken@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@UScriptToken@Ogre@@@Ogre@@@std@@@std@@QAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptLexer.cpp
