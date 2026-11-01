// from server: 100% by auto
// roc 2011-06 00969060  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00969060
//
// 00969060  83c11c               add ecx, 0x1c
// 00969063  51                   push ecx
// 00969064  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00969068  e84369dfff           call 0x75f9b0
// 0096906d  c20400               ret 4
// library raknet-4.081/TeamManager.cpp (function ?GetParticipantList@TM_World@RakNet@@QAEXAAV?$List@URakNetGUID@RakNet@@@DataStructures@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 TeamManager.cpp
