// from server: 100% by auto
// roc 2011-06 0050f440  unit: RBX::Network::VMarker::?$EventDesc  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0050f440
//
// 0050f440  56                   push esi
// 0050f441  8bf1                 mov esi, ecx
// 0050f443  e8b89efdff           call 0x4e9300
// 0050f448  b001                 mov al, 1
// 0050f44a  32c9                 xor cl, cl
// 0050f44c  88460d               mov byte ptr [esi + 0xd], al
// 0050f44f  88460e               mov byte ptr [esi + 0xe], al
// 0050f452  88460c               mov byte ptr [esi + 0xc], al
// 0050f455  c7060cd0a700         mov dword ptr [esi], 0xa7d00c
// 0050f45b  884e0f               mov byte ptr [esi + 0xf], cl
// 0050f45e  888e0f010000         mov byte ptr [esi + 0x10f], cl
// 0050f464  8bc6                 mov eax, esi
// 0050f466  5e                   pop esi
// 0050f467  c3                   ret 
// library raknet-4.081/PacketLogger.cpp (function ??0PacketLogger@RakNet@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 PacketLogger.cpp
