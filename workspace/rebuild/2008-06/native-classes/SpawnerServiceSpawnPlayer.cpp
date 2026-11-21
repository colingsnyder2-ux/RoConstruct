// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /fp:fast /DNDEBUG /D_MBCS /I{headers}/part-embedded
// Retired staging unit (batch 27). RBX::SpawnerService::SpawnPlayer 005d2b80 now lives in its original unit,
// native-classes/SpawnLocation.cpp (005d1ba0..005d39f0), where SpawnLocation::getTeamColor 005d1ba0 is defined and
// inlined as in the target: byte-exact there (with /fp:fast added to that unit; SpawnLocation.cpp kept every baseline
// exact). Every exact row this unit used to produce is also exact in SpawnLocation.cpp. This file no longer defines
// anything; it can be removed by the owner.
