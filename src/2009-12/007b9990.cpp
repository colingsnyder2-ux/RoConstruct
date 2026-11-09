// from server: 100% by auto
// roc 2009-12 007b9990  unit: RBX::GroundStage  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b9990
//
// 007b9990  51                   push ecx
// 007b9991  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007b9995  e8a695ffff           call 0x7b2f40
// 007b999a  c20400               ret 4
// library raknet-4.081/CloudCommon.cpp (function ??$Write@VRakString@RakNet@@@BitStream@RakNet@@QAEXABVRakString@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 CloudCommon.cpp
