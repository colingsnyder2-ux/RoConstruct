// roc 2012-06 00929030  unit: RBX::MovingAssemblyStage  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00929030
//
// 00929030  8b4108               mov eax, dword ptr [ecx + 8]
// 00929033  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00929037  8b0488               mov eax, dword ptr [eax + ecx*4]
// 0092903a  c20400               ret 4
// library raknet-4.081/StatisticsHistory.cpp (function ?GetObjectAtIndex@StatisticsHistory@RakNet@@QBEPAUTrackedObjectData@12@I@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 StatisticsHistory.cpp
