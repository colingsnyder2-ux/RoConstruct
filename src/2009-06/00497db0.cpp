// from server: 100% by EspClaude
// roc 2009-06 00497db0  unit: Ogre::TwoDManager  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00497db0
//
// 00497db0  0fb606               movzx eax, byte ptr [esi]
// 00497db3  50                   push eax
// 00497db4  ff15cce88900         call dword ptr [0x89e8cc]
// 00497dba  83c404               add esp, 4
// 00497dbd  85c0                 test eax, eax
// 00497dbf  7409                 je 0x497dca
// 00497dc1  807e013a             cmp byte ptr [esi + 1], 0x3a
// 00497dc5  7503                 jne 0x497dca
// 00497dc7  b001                 mov al, 1
// 00497dc9  c3                   ret 
// 00497dca  8a06                 mov al, byte ptr [esi]
// 00497dcc  3c2f                 cmp al, 0x2f
// 00497dce  7407                 je 0x497dd7
// 00497dd0  3c5c                 cmp al, 0x5c
// 00497dd2  7403                 je 0x497dd7
// 00497dd4  33c0                 xor eax, eax
// 00497dd6  c3                   ret 
// 00497dd7  b801000000           mov eax, 1
// 00497ddc  c3                   ret 
// copied from an identical function in another client (function ?is_absolute_path@Ogre@@YA_NPBD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreFileSystem.cpp