// from server: 100% by EspClaude
// roc 2009-06 00497eb0  unit: Ogre::TwoDManager  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00497eb0
//
// 00497eb0  6aff                 push -1
// 00497eb2  6878678500           push 0x856778
// 00497eb7  64a100000000         mov eax, dword ptr fs:[0]
// 00497ebd  50                   push eax
// 00497ebe  64892500000000       mov dword ptr fs:[0], esp
// 00497ec5  51                   push ecx
// 00497ec6  56                   push esi
// 00497ec7  8bf1                 mov esi, ecx
// 00497ec9  8d4e04               lea ecx, [esi + 4]
// 00497ecc  89742404             mov dword ptr [esp + 4], esi
// 00497ed0  ff15c0e48900         call dword ptr [0x89e4c0]
// 00497ed6  8d4e20               lea ecx, [esi + 0x20]
// 00497ed9  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00497ee1  ff15c0e48900         call dword ptr [0x89e4c0]
// 00497ee7  8d4e3c               lea ecx, [esi + 0x3c]
// 00497eea  c644241001           mov byte ptr [esp + 0x10], 1
// 00497eef  ff15c0e48900         call dword ptr [0x89e4c0]
// 00497ef5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00497ef9  8bc6                 mov eax, esi
// 00497efb  5e                   pop esi
// 00497efc  64890d00000000       mov dword ptr fs:[0], ecx
// 00497f03  83c410               add esp, 0x10
// 00497f06  c3                   ret 
// copied from an identical function in another client (function ??0FileInfo@Ogre@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreFileSystem.cpp