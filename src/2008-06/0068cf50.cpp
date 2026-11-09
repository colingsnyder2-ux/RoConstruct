// from server: 100% by auto
// roc 2008-06 0068cf50  unit: Ogre::RbxSceneManagerFactory  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068cf50
//
// 0068cf50  8bc1                 mov eax, ecx
// 0068cf52  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0068cf56  33d2                 xor edx, edx
// 0068cf58  895004               mov dword ptr [eax + 4], edx
// 0068cf5b  895008               mov dword ptr [eax + 8], edx
// 0068cf5e  56                   push esi
// 0068cf5f  c7002cec8400         mov dword ptr [eax], 0x84ec2c
// 0068cf65  8b7104               mov esi, dword ptr [ecx + 4]
// 0068cf68  897004               mov dword ptr [eax + 4], esi
// 0068cf6b  8b4908               mov ecx, dword ptr [ecx + 8]
// 0068cf6e  894808               mov dword ptr [eax + 8], ecx
// 0068cf71  5e                   pop esi
// 0068cf72  3bca                 cmp ecx, edx
// 0068cf74  7402                 je 0x68cf78
// 0068cf76  ff01                 inc dword ptr [ecx]
// 0068cf78  c20400               ret 4
// library ogre-1.4.9/OgreAlignedAllocator.cpp (function ??0?$SharedPtr@VHardwareVertexBuffer@Ogre@@@Ogre@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAlignedAllocator.cpp
