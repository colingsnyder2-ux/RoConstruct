// roc 2012-06 0050c710  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0050c710
//
// 0050c710  83c11c               add ecx, 0x1c
// 0050c713  51                   push ecx
// 0050c714  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0050c718  e8b34b2b00           call 0x7c12d0
// 0050c71d  c20400               ret 4
// library raknet-4.081/TeamManager.cpp (function ?GetParticipantList@TM_World@RakNet@@QAEXAAV?$List@URakNetGUID@RakNet@@@DataStructures@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 TeamManager.cpp
