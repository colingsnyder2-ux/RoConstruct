// from server: 100% by auto
// roc 2011-06 0050f8b0  unit: Exposer  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0050f8b0
//
// 0050f8b0  8a442404             mov al, byte ptr [esp + 4]
// 0050f8b4  88410e               mov byte ptr [ecx + 0xe], al
// 0050f8b7  c20400               ret 4
// library raknet-4.081/PacketLogger.cpp (function ?SetPrintAcks@PacketLogger@RakNet@@UAEX_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 PacketLogger.cpp
