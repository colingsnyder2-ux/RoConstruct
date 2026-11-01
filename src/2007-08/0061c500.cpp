// from server: 100% by colin
// roc 2007-08 0061c500  unit: RBX::ImageButton  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061c500
//
// 0061c500  6aff                 push -1
// 0061c502  684cc77500           push 0x75c74c
// 0061c507  64a100000000         mov eax, dword ptr fs:[0]
// 0061c50d  50                   push eax
// 0061c50e  64892500000000       mov dword ptr fs:[0], esp
// 0061c515  51                   push ecx
// 0061c516  56                   push esi
// 0061c517  8bf1                 mov esi, ecx
// 0061c519  89742404             mov dword ptr [esp + 4], esi
// 0061c51d  8d4e28               lea ecx, [esi + 0x28]
// 0061c520  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0061c528  ff15ace67700         call dword ptr [0x77e6ac]
// 0061c52e  8d4e0c               lea ecx, [esi + 0xc]
// 0061c531  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0061c539  ff15ace67700         call dword ptr [0x77e6ac]
// 0061c53f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0061c543  5e                   pop esi
// 0061c544  64890d00000000       mov dword ptr fs:[0], ecx
// 0061c54b  83c410               add esp, 0x10
// 0061c54e  c3                   ret 
// copied from an identical function in another client (function ??1RenderSystemCapabilities@Ogre@@QAE@XZ)

// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreRenderSystemCapabilities.cpp