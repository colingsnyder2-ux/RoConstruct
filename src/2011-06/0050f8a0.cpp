// from server: 100% by auto
// roc 2011-06 0050f8a0  unit: Exposer  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0050f8a0
//
// 0050f8a0  8a442404             mov al, byte ptr [esp + 4]
// 0050f8a4  88410d               mov byte ptr [ecx + 0xd], al
// 0050f8a7  c20400               ret 4
// library raknet-4.081/PacketLogger.cpp (function ?SetPrintID@PacketLogger@RakNet@@UAEX_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 PacketLogger.cpp
