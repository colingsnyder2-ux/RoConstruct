// from server: 100% by auto
// roc 2011-06 007c51d0  unit: RBX::StepJointsStage  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007c51d0
//
// 007c51d0  8b4108               mov eax, dword ptr [ecx + 8]
// 007c51d3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007c51d7  8b0488               mov eax, dword ptr [eax + ecx*4]
// 007c51da  c20400               ret 4
// library raknet-4.081/StatisticsHistory.cpp (function ?GetObjectAtIndex@StatisticsHistory@RakNet@@QBEPAUTrackedObjectData@12@I@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 StatisticsHistory.cpp
