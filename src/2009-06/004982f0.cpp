// from server: 100% by EspClaude
// roc 2009-06 004982f0  unit: VThreadLogManager::?$thread_specific_ptr::delete_data  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004982f0
//
// 004982f0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004982f4  83ec0c               sub esp, 0xc
// 004982f7  85c9                 test ecx, ecx
// 004982f9  7715                 ja 0x498310
// 004982fb  33c9                 xor ecx, ecx
// 004982fd  8d1449               lea edx, [ecx + ecx*2]
// 00498300  c1e205               shl edx, 5
// 00498303  52                   push edx
// 00498304  e82f072800           call 0x718a38
// 00498309  83c404               add esp, 4
// 0049830c  83c40c               add esp, 0xc
// 0049830f  c3                   ret 
// 00498310  83c8ff               or eax, 0xffffffff
// 00498313  33d2                 xor edx, edx
// 00498315  f7f1                 div ecx
// 00498317  83f860               cmp eax, 0x60
// 0049831a  73e1                 jae 0x4982fd
// 0049831c  8d442410             lea eax, [esp + 0x10]
// 00498320  50                   push eax
// 00498321  8d4c2404             lea ecx, [esp + 4]
// 00498325  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0049832d  ff15c4e98900         call dword ptr [0x89e9c4]
// 00498333  6888919700           push 0x979188
// 00498338  8d4c2404             lea ecx, [esp + 4]
// 0049833c  51                   push ecx
// 0049833d  c744240838c98a00     mov dword ptr [esp + 8], 0x8ac938
// 00498345  e800172800           call 0x719a4a
// copied from an identical function in another client (function ??$_Allocate@UFileInfo@Ogre@@@std@@YAPAUFileInfo@Ogre@@IPAU12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreBillboardSet.cpp