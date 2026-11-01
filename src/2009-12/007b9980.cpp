// from server: 100% by auto
// roc 2009-12 007b9980  unit: RBX::GroundStage  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b9980
//
// 007b9980  51                   push ecx
// 007b9981  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007b9985  e89695ffff           call 0x7b2f20
// 007b998a  c20400               ret 4
// library raknet-4.081/CloudCommon.cpp (function ??$Write@VRakString@RakNet@@@BitStream@RakNet@@QAEXABVRakString@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 CloudCommon.cpp
