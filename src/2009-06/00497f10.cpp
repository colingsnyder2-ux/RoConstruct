// from server: 100% by EspClaude
// roc 2009-06 00497f10  unit: Ogre::TwoDManager  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00497f10
//
// 00497f10  6aff                 push -1
// 00497f12  6878678500           push 0x856778
// 00497f17  64a100000000         mov eax, dword ptr fs:[0]
// 00497f1d  50                   push eax
// 00497f1e  64892500000000       mov dword ptr fs:[0], esp
// 00497f25  51                   push ecx
// 00497f26  56                   push esi
// 00497f27  8bf1                 mov esi, ecx
// 00497f29  89742404             mov dword ptr [esp + 4], esi
// 00497f2d  8d4e3c               lea ecx, [esi + 0x3c]
// 00497f30  c744241001000000     mov dword ptr [esp + 0x10], 1
// 00497f38  ff15c4e48900         call dword ptr [0x89e4c4]
// 00497f3e  8d4e20               lea ecx, [esi + 0x20]
// 00497f41  c644241000           mov byte ptr [esp + 0x10], 0
// 00497f46  ff15c4e48900         call dword ptr [0x89e4c4]
// 00497f4c  8d4e04               lea ecx, [esi + 4]
// 00497f4f  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00497f57  ff15c4e48900         call dword ptr [0x89e4c4]
// 00497f5d  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00497f61  5e                   pop esi
// 00497f62  64890d00000000       mov dword ptr fs:[0], ecx
// 00497f69  83c410               add esp, 0x10
// 00497f6c  c3                   ret 
// copied from an identical function in another client (function ??1FileInfo@Ogre@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreBillboardSet.cpp