// from server: 100% by auto
// roc 2009-12 004b7980  unit: VThreadLogManager::?$thread_specific_ptr::delete_data  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b7980
//
// 004b7980  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004b7984  85c9                 test ecx, ecx
// 004b7986  740e                 je 0x4b7996
// 004b7988  8b01                 mov eax, dword ptr [ecx]
// 004b798a  8b10                 mov edx, dword ptr [eax]
// 004b798c  c744240401000000     mov dword ptr [esp + 4], 1
// 004b7994  ffe2                 jmp edx
// 004b7996  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?destroyInstance@FileSystemArchiveFactory@Ogre@@UAEXPAVArchive@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
