// from server: 100% by auto
// roc 2009-06 00498230  unit: VThreadLogManager::?$thread_specific_ptr::delete_data  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00498230
//
// 00498230  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00498234  85c9                 test ecx, ecx
// 00498236  740e                 je 0x498246
// 00498238  8b01                 mov eax, dword ptr [ecx]
// 0049823a  8b10                 mov edx, dword ptr [eax]
// 0049823c  c744240401000000     mov dword ptr [esp + 4], 1
// 00498244  ffe2                 jmp edx
// 00498246  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?destroyInstance@FileSystemArchiveFactory@Ogre@@UAEXPAVArchive@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
